begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ffreestanding %s -triple=x86_64-apple-darwin -target-feature +sse2 -emit-llvm -o - -Wall -Werror | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -ffreestanding %s -triple=x86_64-apple-darwin -target-feature +sse2 -fno-signed-char -emit-llvm -o - -Wall -Werror | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<x86intrin.h>
end_include

begin_comment
comment|// NOTE: This should match the tests in llvm/test/CodeGen/X86/sse2-intrinsics-fast-isel.ll
end_comment

begin_function
name|__m128i
name|test_mm_add_epi8
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_add_epi8
comment|// CHECK: add<16 x i8>
return|return
name|_mm_add_epi8
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_add_epi16
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_add_epi16
comment|// CHECK: add<8 x i16>
return|return
name|_mm_add_epi16
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_add_epi32
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_add_epi32
comment|// CHECK: add<4 x i32>
return|return
name|_mm_add_epi32
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_add_epi64
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_add_epi64
comment|// CHECK: add<2 x i64>
return|return
name|_mm_add_epi64
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
name|test_mm_add_pd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_add_pd
comment|// CHECK: fadd<2 x double>
return|return
name|_mm_add_pd
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
name|test_mm_add_sd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_add_sd
comment|// CHECK: extractelement<2 x double> %{{.*}}, i32 0
comment|// CHECK: extractelement<2 x double> %{{.*}}, i32 0
comment|// CHECK: fadd double
comment|// CHECK: insertelement<2 x double> %{{.*}}, double %{{.*}}, i32 0
return|return
name|_mm_add_sd
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_adds_epi8
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_adds_epi8
comment|// CHECK: call<16 x i8> @llvm.x86.sse2.padds.b(<16 x i8> %{{.*}},<16 x i8> %{{.*}})
return|return
name|_mm_adds_epi8
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_adds_epi16
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_adds_epi16
comment|// CHECK: call<8 x i16> @llvm.x86.sse2.padds.w(<8 x i16> %{{.*}},<8 x i16> %{{.*}})
return|return
name|_mm_adds_epi16
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_adds_epu8
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_adds_epu8
comment|// CHECK: call<16 x i8> @llvm.x86.sse2.paddus.b(<16 x i8> %{{.*}},<16 x i8> %{{.*}})
return|return
name|_mm_adds_epu8
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_adds_epu16
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_adds_epu16
comment|// CHECK: call<8 x i16> @llvm.x86.sse2.paddus.w(<8 x i16> %{{.*}},<8 x i16> %{{.*}})
return|return
name|_mm_adds_epu16
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
name|test_mm_and_pd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_and_pd
comment|// CHECK: and<2 x i64>
return|return
name|_mm_and_pd
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_and_si128
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_and_si128
comment|// CHECK: and<2 x i64>
return|return
name|_mm_and_si128
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
name|test_mm_andnot_pd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_andnot_pd
comment|// CHECK: xor<2 x i64> %{{.*}},<i64 -1, i64 -1>
comment|// CHECK: and<2 x i64>
return|return
name|_mm_andnot_pd
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_andnot_si128
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_andnot_si128
comment|// CHECK: xor<2 x i64> %{{.*}},<i64 -1, i64 -1>
comment|// CHECK: and<2 x i64>
return|return
name|_mm_andnot_si128
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_avg_epu8
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_avg_epu8
comment|// CHECK: call<16 x i8> @llvm.x86.sse2.pavg.b(<16 x i8> %{{.*}},<16 x i8> %{{.*}})
return|return
name|_mm_avg_epu8
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_avg_epu16
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_avg_epu16
comment|// CHECK: call<8 x i16> @llvm.x86.sse2.pavg.w(<8 x i16> %{{.*}},<8 x i16> %{{.*}})
return|return
name|_mm_avg_epu16
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_bslli_si128
parameter_list|(
name|__m128i
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_bslli_si128
comment|// CHECK: shufflevector<16 x i8> %{{.*}},<16 x i8> %{{.*}},<16 x i32><i32 11, i32 12, i32 13, i32 14, i32 15, i32 16, i32 17, i32 18, i32 19, i32 20, i32 21, i32 22, i32 23, i32 24, i32 25, i32 26>
return|return
name|_mm_bslli_si128
argument_list|(
name|A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_bsrli_si128
parameter_list|(
name|__m128i
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_bsrli_si128
comment|// CHECK: shufflevector<16 x i8> %{{.*}},<16 x i8> %{{.*}},<16 x i32><i32 5, i32 6, i32 7, i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15, i32 16, i32 17, i32 18, i32 19, i32 20>
return|return
name|_mm_bsrli_si128
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
name|test_mm_castpd_ps
parameter_list|(
name|__m128d
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_castpd_ps
comment|// CHECK: bitcast<2 x double> %{{.*}} to<4 x float>
return|return
name|_mm_castpd_ps
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_castpd_si128
parameter_list|(
name|__m128d
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_castpd_si128
comment|// CHECK: bitcast<2 x double> %{{.*}} to<2 x i64>
return|return
name|_mm_castpd_si128
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_castps_pd
parameter_list|(
name|__m128
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_castps_pd
comment|// CHECK: bitcast<4 x float> %{{.*}} to<2 x double>
return|return
name|_mm_castps_pd
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_castps_si128
parameter_list|(
name|__m128
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_castps_si128
comment|// CHECK: bitcast<4 x float> %{{.*}} to<2 x i64>
return|return
name|_mm_castps_si128
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_castsi128_pd
parameter_list|(
name|__m128i
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_castsi128_pd
comment|// CHECK: bitcast<2 x i64> %{{.*}} to<2 x double>
return|return
name|_mm_castsi128_pd
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_castsi128_ps
parameter_list|(
name|__m128i
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_castsi128_ps
comment|// CHECK: bitcast<2 x i64> %{{.*}} to<4 x float>
return|return
name|_mm_castsi128_ps
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm_clflush
parameter_list|(
name|void
modifier|*
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_clflush
comment|// CHECK: call void @llvm.x86.sse2.clflush(i8* %{{.*}})
name|_mm_clflush
argument_list|(
name|A
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_cmpeq_epi8
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cmpeq_epi8
comment|// CHECK: icmp eq<16 x i8>
return|return
name|_mm_cmpeq_epi8
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_cmpeq_epi16
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cmpeq_epi16
comment|// CHECK: icmp eq<8 x i16>
return|return
name|_mm_cmpeq_epi16
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_cmpeq_epi32
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cmpeq_epi32
comment|// CHECK: icmp eq<4 x i32>
return|return
name|_mm_cmpeq_epi32
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
name|test_mm_cmpeq_pd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cmpeq_pd
comment|// CHECK:         [[CMP:%.*]] = fcmp oeq<2 x double>
comment|// CHECK-NEXT:    [[SEXT:%.*]] = sext<2 x i1> [[CMP]] to<2 x i64>
comment|// CHECK-NEXT:    [[BC:%.*]] = bitcast<2 x i64> [[SEXT]] to<2 x double>
comment|// CHECK-NEXT:    ret<2 x double> [[BC]]
return|return
name|_mm_cmpeq_pd
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
name|test_mm_cmpeq_sd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cmpeq_sd
comment|// CHECK: call<2 x double> @llvm.x86.sse2.cmp.sd(<2 x double> %{{.*}},<2 x double> %{{.*}}, i8 0)
return|return
name|_mm_cmpeq_sd
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
name|test_mm_cmpge_pd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cmpge_pd
comment|// CHECK:         [[CMP:%.*]] = fcmp ole<2 x double>
comment|// CHECK-NEXT:    [[SEXT:%.*]] = sext<2 x i1> [[CMP]] to<2 x i64>
comment|// CHECK-NEXT:    [[BC:%.*]] = bitcast<2 x i64> [[SEXT]] to<2 x double>
comment|// CHECK-NEXT:    ret<2 x double> [[BC]]
return|return
name|_mm_cmpge_pd
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
name|test_mm_cmpge_sd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cmpge_sd
comment|// CHECK: call<2 x double> @llvm.x86.sse2.cmp.sd(<2 x double> %{{.*}},<2 x double> %{{.*}}, i8 2)
comment|// CHECK: extractelement<2 x double> %{{.*}}, i32 0
comment|// CHECK: insertelement<2 x double> undef, double %{{.*}}, i32 0
comment|// CHECK: extractelement<2 x double> %{{.*}}, i32 1
comment|// CHECK: insertelement<2 x double> %{{.*}}, double %{{.*}}, i32 1
return|return
name|_mm_cmpge_sd
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_cmpgt_epi8
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cmpgt_epi8
comment|// CHECK: icmp sgt<16 x i8>
return|return
name|_mm_cmpgt_epi8
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_cmpgt_epi16
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cmpgt_epi16
comment|// CHECK: icmp sgt<8 x i16>
return|return
name|_mm_cmpgt_epi16
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_cmpgt_epi32
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cmpgt_epi32
comment|// CHECK: icmp sgt<4 x i32>
return|return
name|_mm_cmpgt_epi32
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
name|test_mm_cmpgt_pd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cmpgt_pd
comment|// CHECK:         [[CMP:%.*]] = fcmp olt<2 x double>
comment|// CHECK-NEXT:    [[SEXT:%.*]] = sext<2 x i1> [[CMP]] to<2 x i64>
comment|// CHECK-NEXT:    [[BC:%.*]] = bitcast<2 x i64> [[SEXT]] to<2 x double>
comment|// CHECK-NEXT:    ret<2 x double> [[BC]]
return|return
name|_mm_cmpgt_pd
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
name|test_mm_cmpgt_sd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cmpgt_sd
comment|// CHECK: call<2 x double> @llvm.x86.sse2.cmp.sd(<2 x double> %{{.*}},<2 x double> %{{.*}}, i8 1)
comment|// CHECK: extractelement<2 x double> %{{.*}}, i32 0
comment|// CHECK: insertelement<2 x double> undef, double %{{.*}}, i32 0
comment|// CHECK: extractelement<2 x double> %{{.*}}, i32 1
comment|// CHECK: insertelement<2 x double> %{{.*}}, double %{{.*}}, i32 1
return|return
name|_mm_cmpgt_sd
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
name|test_mm_cmple_pd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cmple_pd
comment|// CHECK:         [[CMP:%.*]] = fcmp ole<2 x double>
comment|// CHECK-NEXT:    [[SEXT:%.*]] = sext<2 x i1> [[CMP]] to<2 x i64>
comment|// CHECK-NEXT:    [[BC:%.*]] = bitcast<2 x i64> [[SEXT]] to<2 x double>
comment|// CHECK-NEXT:    ret<2 x double> [[BC]]
return|return
name|_mm_cmple_pd
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
name|test_mm_cmple_sd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cmple_sd
comment|// CHECK: call<2 x double> @llvm.x86.sse2.cmp.sd(<2 x double> %{{.*}},<2 x double> %{{.*}}, i8 2)
return|return
name|_mm_cmple_sd
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_cmplt_epi8
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cmplt_epi8
comment|// CHECK: icmp sgt<16 x i8>
return|return
name|_mm_cmplt_epi8
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_cmplt_epi16
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cmplt_epi16
comment|// CHECK: icmp sgt<8 x i16>
return|return
name|_mm_cmplt_epi16
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_cmplt_epi32
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cmplt_epi32
comment|// CHECK: icmp sgt<4 x i32>
return|return
name|_mm_cmplt_epi32
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
name|test_mm_cmplt_pd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cmplt_pd
comment|// CHECK:         [[CMP:%.*]] = fcmp olt<2 x double>
comment|// CHECK-NEXT:    [[SEXT:%.*]] = sext<2 x i1> [[CMP]] to<2 x i64>
comment|// CHECK-NEXT:    [[BC:%.*]] = bitcast<2 x i64> [[SEXT]] to<2 x double>
comment|// CHECK-NEXT:    ret<2 x double> [[BC]]
return|return
name|_mm_cmplt_pd
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
name|test_mm_cmplt_sd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cmplt_sd
comment|// CHECK: call<2 x double> @llvm.x86.sse2.cmp.sd(<2 x double> %{{.*}},<2 x double> %{{.*}}, i8 1)
return|return
name|_mm_cmplt_sd
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
name|test_mm_cmpneq_pd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cmpneq_pd
comment|// CHECK:         [[CMP:%.*]] = fcmp une<2 x double>
comment|// CHECK-NEXT:    [[SEXT:%.*]] = sext<2 x i1> [[CMP]] to<2 x i64>
comment|// CHECK-NEXT:    [[BC:%.*]] = bitcast<2 x i64> [[SEXT]] to<2 x double>
comment|// CHECK-NEXT:    ret<2 x double> [[BC]]
return|return
name|_mm_cmpneq_pd
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
name|test_mm_cmpneq_sd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cmpneq_sd
comment|// CHECK: call<2 x double> @llvm.x86.sse2.cmp.sd(<2 x double> %{{.*}},<2 x double> %{{.*}}, i8 4)
return|return
name|_mm_cmpneq_sd
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
name|test_mm_cmpnge_pd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cmpnge_pd
comment|// CHECK:         [[CMP:%.*]] = fcmp ugt<2 x double>
comment|// CHECK-NEXT:    [[SEXT:%.*]] = sext<2 x i1> [[CMP]] to<2 x i64>
comment|// CHECK-NEXT:    [[BC:%.*]] = bitcast<2 x i64> [[SEXT]] to<2 x double>
comment|// CHECK-NEXT:    ret<2 x double> [[BC]]
return|return
name|_mm_cmpnge_pd
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
name|test_mm_cmpnge_sd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cmpnge_sd
comment|// CHECK: call<2 x double> @llvm.x86.sse2.cmp.sd(<2 x double> %{{.*}},<2 x double> %{{.*}}, i8 6)
comment|// CHECK: extractelement<2 x double> %{{.*}}, i32 0
comment|// CHECK: insertelement<2 x double> undef, double %{{.*}}, i32 0
comment|// CHECK: extractelement<2 x double> %{{.*}}, i32 1
comment|// CHECK: insertelement<2 x double> %{{.*}}, double %{{.*}}, i32 1
return|return
name|_mm_cmpnge_sd
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
name|test_mm_cmpngt_pd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cmpngt_pd
comment|// CHECK:         [[CMP:%.*]] = fcmp uge<2 x double>
comment|// CHECK-NEXT:    [[SEXT:%.*]] = sext<2 x i1> [[CMP]] to<2 x i64>
comment|// CHECK-NEXT:    [[BC:%.*]] = bitcast<2 x i64> [[SEXT]] to<2 x double>
comment|// CHECK-NEXT:    ret<2 x double> [[BC]]
return|return
name|_mm_cmpngt_pd
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
name|test_mm_cmpngt_sd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cmpngt_sd
comment|// CHECK: call<2 x double> @llvm.x86.sse2.cmp.sd(<2 x double> %{{.*}},<2 x double> %{{.*}}, i8 5)
comment|// CHECK: extractelement<2 x double> %{{.*}}, i32 0
comment|// CHECK: insertelement<2 x double> undef, double %{{.*}}, i32 0
comment|// CHECK: extractelement<2 x double> %{{.*}}, i32 1
comment|// CHECK: insertelement<2 x double> %{{.*}}, double %{{.*}}, i32 1
return|return
name|_mm_cmpngt_sd
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
name|test_mm_cmpnle_pd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cmpnle_pd
comment|// CHECK:         [[CMP:%.*]] = fcmp ugt<2 x double>
comment|// CHECK-NEXT:    [[SEXT:%.*]] = sext<2 x i1> [[CMP]] to<2 x i64>
comment|// CHECK-NEXT:    [[BC:%.*]] = bitcast<2 x i64> [[SEXT]] to<2 x double>
comment|// CHECK-NEXT:    ret<2 x double> [[BC]]
return|return
name|_mm_cmpnle_pd
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
name|test_mm_cmpnle_sd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cmpnle_sd
comment|// CHECK: call<2 x double> @llvm.x86.sse2.cmp.sd(<2 x double> %{{.*}},<2 x double> %{{.*}}, i8 6)
return|return
name|_mm_cmpnle_sd
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
name|test_mm_cmpnlt_pd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cmpnlt_pd
comment|// CHECK:         [[CMP:%.*]] = fcmp uge<2 x double>
comment|// CHECK-NEXT:    [[SEXT:%.*]] = sext<2 x i1> [[CMP]] to<2 x i64>
comment|// CHECK-NEXT:    [[BC:%.*]] = bitcast<2 x i64> [[SEXT]] to<2 x double>
comment|// CHECK-NEXT:    ret<2 x double> [[BC]]
return|return
name|_mm_cmpnlt_pd
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
name|test_mm_cmpnlt_sd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cmpnlt_sd
comment|// CHECK: call<2 x double> @llvm.x86.sse2.cmp.sd(<2 x double> %{{.*}},<2 x double> %{{.*}}, i8 5)
return|return
name|_mm_cmpnlt_sd
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
name|test_mm_cmpord_pd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cmpord_pd
comment|// CHECK:         [[CMP:%.*]] = fcmp ord<2 x double>
comment|// CHECK-NEXT:    [[SEXT:%.*]] = sext<2 x i1> [[CMP]] to<2 x i64>
comment|// CHECK-NEXT:    [[BC:%.*]] = bitcast<2 x i64> [[SEXT]] to<2 x double>
comment|// CHECK-NEXT:    ret<2 x double> [[BC]]
return|return
name|_mm_cmpord_pd
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
name|test_mm_cmpord_sd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cmpord_sd
comment|// CHECK: call<2 x double> @llvm.x86.sse2.cmp.sd(<2 x double> %{{.*}},<2 x double> %{{.*}}, i8 7)
return|return
name|_mm_cmpord_sd
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
name|test_mm_cmpunord_pd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cmpunord_pd
comment|// CHECK:         [[CMP:%.*]] = fcmp uno<2 x double>
comment|// CHECK-NEXT:    [[SEXT:%.*]] = sext<2 x i1> [[CMP]] to<2 x i64>
comment|// CHECK-NEXT:    [[BC:%.*]] = bitcast<2 x i64> [[SEXT]] to<2 x double>
comment|// CHECK-NEXT:    ret<2 x double> [[BC]]
return|return
name|_mm_cmpunord_pd
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
name|test_mm_cmpunord_sd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cmpunord_sd
comment|// CHECK: call<2 x double> @llvm.x86.sse2.cmp.sd(<2 x double> %{{.*}},<2 x double> %{{.*}}, i8 3)
return|return
name|_mm_cmpunord_sd
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
name|test_mm_comieq_sd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comieq_sd
comment|// CHECK: call i32 @llvm.x86.sse2.comieq.sd(<2 x double> %{{.*}},<2 x double> %{{.*}})
return|return
name|_mm_comieq_sd
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
name|test_mm_comige_sd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comige_sd
comment|// CHECK: call i32 @llvm.x86.sse2.comige.sd(<2 x double> %{{.*}},<2 x double> %{{.*}})
return|return
name|_mm_comige_sd
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
name|test_mm_comigt_sd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comigt_sd
comment|// CHECK: call i32 @llvm.x86.sse2.comigt.sd(<2 x double> %{{.*}},<2 x double> %{{.*}})
return|return
name|_mm_comigt_sd
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
name|test_mm_comile_sd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comile_sd
comment|// CHECK: call i32 @llvm.x86.sse2.comile.sd(<2 x double> %{{.*}},<2 x double> %{{.*}})
return|return
name|_mm_comile_sd
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
name|test_mm_comilt_sd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comilt_sd
comment|// CHECK: call i32 @llvm.x86.sse2.comilt.sd(<2 x double> %{{.*}},<2 x double> %{{.*}})
return|return
name|_mm_comilt_sd
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
name|test_mm_comineq_sd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comineq_sd
comment|// CHECK: call i32 @llvm.x86.sse2.comineq.sd(<2 x double> %{{.*}},<2 x double> %{{.*}})
return|return
name|_mm_comineq_sd
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
name|test_mm_cvtepi32_pd
parameter_list|(
name|__m128i
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvtepi32_pd
comment|// CHECK: shufflevector<4 x i32> %{{.*}},<4 x i32> %{{.*}},<2 x i32><i32 0, i32 1>
comment|// CHECK: sitofp<2 x i32> %{{.*}} to<2 x double>
return|return
name|_mm_cvtepi32_pd
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_cvtepi32_ps
parameter_list|(
name|__m128i
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvtepi32_ps
comment|// CHECK: call<4 x float> @llvm.x86.sse2.cvtdq2ps(<4 x i32> %{{.*}})
return|return
name|_mm_cvtepi32_ps
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_cvtpd_epi32
parameter_list|(
name|__m128d
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvtpd_epi32
comment|// CHECK: call<4 x i32> @llvm.x86.sse2.cvtpd2dq(<2 x double> %{{.*}})
return|return
name|_mm_cvtpd_epi32
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_cvtpd_ps
parameter_list|(
name|__m128d
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvtpd_ps
comment|// CHECK: call<4 x float> @llvm.x86.sse2.cvtpd2ps(<2 x double> %{{.*}})
return|return
name|_mm_cvtpd_ps
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_cvtps_epi32
parameter_list|(
name|__m128
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvtps_epi32
comment|// CHECK: call<4 x i32> @llvm.x86.sse2.cvtps2dq(<4 x float> %{{.*}})
return|return
name|_mm_cvtps_epi32
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_cvtps_pd
parameter_list|(
name|__m128
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvtps_pd
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> %{{.*}},<2 x i32><i32 0, i32 1>
comment|// CHECK: fpext<2 x float> %{{.*}} to<2 x double>
return|return
name|_mm_cvtps_pd
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|double
name|test_mm_cvtsd_f64
parameter_list|(
name|__m128d
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvtsd_f64
comment|// CHECK: extractelement<2 x double> %{{.*}}, i32 0
return|return
name|_mm_cvtsd_f64
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm_cvtsd_si32
parameter_list|(
name|__m128d
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvtsd_si32
comment|// CHECK: call i32 @llvm.x86.sse2.cvtsd2si(<2 x double> %{{.*}})
return|return
name|_mm_cvtsd_si32
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|long
name|long
name|test_mm_cvtsd_si64
parameter_list|(
name|__m128d
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvtsd_si64
comment|// CHECK: call i64 @llvm.x86.sse2.cvtsd2si64(<2 x double> %{{.*}})
return|return
name|_mm_cvtsd_si64
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_cvtsd_ss
parameter_list|(
name|__m128
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvtsd_ss
comment|// CHECK: call<4 x float> @llvm.x86.sse2.cvtsd2ss(<4 x float> %{{.*}},<2 x double> %{{.*}})
return|return
name|_mm_cvtsd_ss
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
name|test_mm_cvtsi128_si32
parameter_list|(
name|__m128i
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvtsi128_si32
comment|// CHECK: extractelement<4 x i32> %{{.*}}, i32 0
return|return
name|_mm_cvtsi128_si32
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|long
name|long
name|test_mm_cvtsi128_si64
parameter_list|(
name|__m128i
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvtsi128_si64
comment|// CHECK: extractelement<2 x i64> %{{.*}}, i32 0
return|return
name|_mm_cvtsi128_si64
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_cvtsi32_sd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|int
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvtsi32_sd
comment|// CHECK: sitofp i32 %{{.*}} to double
comment|// CHECK: insertelement<2 x double> %{{.*}}, double %{{.*}}, i32 0
return|return
name|_mm_cvtsi32_sd
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_cvtsi32_si128
parameter_list|(
name|int
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvtsi32_si128
comment|// CHECK: insertelement<4 x i32> undef, i32 %{{.*}}, i32 0
comment|// CHECK: insertelement<4 x i32> %{{.*}}, i32 0, i32 1
comment|// CHECK: insertelement<4 x i32> %{{.*}}, i32 0, i32 2
comment|// CHECK: insertelement<4 x i32> %{{.*}}, i32 0, i32 3
return|return
name|_mm_cvtsi32_si128
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_cvtsi64_sd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|long
name|long
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvtsi64_sd
comment|// CHECK: sitofp i64 %{{.*}} to double
comment|// CHECK: insertelement<2 x double> %{{.*}}, double %{{.*}}, i32 0
return|return
name|_mm_cvtsi64_sd
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_cvtsi64_si128
parameter_list|(
name|long
name|long
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvtsi64_si128
comment|// CHECK: insertelement<2 x i64> undef, i64 %{{.*}}, i32 0
comment|// CHECK: insertelement<2 x i64> %{{.*}}, i64 0, i32 1
return|return
name|_mm_cvtsi64_si128
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_cvtss_sd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvtss_sd
comment|// CHECK: extractelement<4 x float> %{{.*}}, i32 0
comment|// CHECK: fpext float %{{.*}} to double
comment|// CHECK: insertelement<2 x double> %{{.*}}, double %{{.*}}, i32 0
return|return
name|_mm_cvtss_sd
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_cvttpd_epi32
parameter_list|(
name|__m128d
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvttpd_epi32
comment|// CHECK: call<4 x i32> @llvm.x86.sse2.cvttpd2dq(<2 x double> %{{.*}})
return|return
name|_mm_cvttpd_epi32
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_cvttps_epi32
parameter_list|(
name|__m128
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvttps_epi32
comment|// CHECK: call<4 x i32> @llvm.x86.sse2.cvttps2dq(<4 x float> %{{.*}})
return|return
name|_mm_cvttps_epi32
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm_cvttsd_si32
parameter_list|(
name|__m128d
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvttsd_si32
comment|// CHECK: call i32 @llvm.x86.sse2.cvttsd2si(<2 x double> %{{.*}})
return|return
name|_mm_cvttsd_si32
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|long
name|long
name|test_mm_cvttsd_si64
parameter_list|(
name|__m128d
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvttsd_si64
comment|// CHECK: call i64 @llvm.x86.sse2.cvttsd2si64(<2 x double> %{{.*}})
return|return
name|_mm_cvttsd_si64
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_div_pd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_div_pd
comment|// CHECK: fdiv<2 x double>
return|return
name|_mm_div_pd
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
name|test_mm_div_sd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_div_sd
comment|// CHECK: extractelement<2 x double> %{{.*}}, i32 0
comment|// CHECK: extractelement<2 x double> %{{.*}}, i32 0
comment|// CHECK: fdiv double
comment|// CHECK: insertelement<2 x double> %{{.*}}, double %{{.*}}, i32 0
return|return
name|_mm_div_sd
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Lowering to pextrw requires optimization.
end_comment

begin_function
name|int
name|test_mm_extract_epi16
parameter_list|(
name|__m128i
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_extract_epi16
comment|// CHECK: [[x:%.*]] = and i32 %{{.*}}, 7
comment|// CHECK: extractelement<8 x i16> %{{.*}}, i32 [[x]]
comment|// CHECK: zext i16 %{{.*}} to i32
return|return
name|_mm_extract_epi16
argument_list|(
name|A
argument_list|,
literal|9
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_insert_epi16
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|int
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_insert_epi16
comment|// CHECK: [[x:%.*]] = and i32 %{{.*}}, 7
comment|// CHECK: insertelement<8 x i16> %{{.*}}, i32 [[x]]
return|return
name|_mm_insert_epi16
argument_list|(
name|A
argument_list|,
name|B
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm_lfence
parameter_list|()
block|{
comment|// CHECK-LABEL: test_mm_lfence
comment|// CHECK: call void @llvm.x86.sse2.lfence()
name|_mm_lfence
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_load_pd
parameter_list|(
name|double
specifier|const
modifier|*
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_load_pd
comment|// CHECK: load<2 x double>,<2 x double>* %{{.*}}, align 16
return|return
name|_mm_load_pd
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_load_pd1
parameter_list|(
name|double
specifier|const
modifier|*
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_load_pd1
comment|// CHECK: load double, double* %{{.*}}, align 8
comment|// CHECK: insertelement<2 x double> undef, double %{{.*}}, i32 0
comment|// CHECK: insertelement<2 x double> %{{.*}}, double %{{.*}}, i32 1
return|return
name|_mm_load_pd1
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_load_sd
parameter_list|(
name|double
specifier|const
modifier|*
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_load_sd
comment|// CHECK: load double, double* %{{.*}}, align 1{{$}}
return|return
name|_mm_load_sd
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_load_si128
parameter_list|(
name|__m128i
specifier|const
modifier|*
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_load_si128
comment|// CHECK: load<2 x i64>,<2 x i64>* %{{.*}}, align 16
return|return
name|_mm_load_si128
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_load1_pd
parameter_list|(
name|double
specifier|const
modifier|*
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_load1_pd
comment|// CHECK: load double, double* %{{.*}}, align 8
comment|// CHECK: insertelement<2 x double> undef, double %{{.*}}, i32 0
comment|// CHECK: insertelement<2 x double> %{{.*}}, double %{{.*}}, i32 1
return|return
name|_mm_load1_pd
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_loadh_pd
parameter_list|(
name|__m128d
name|x
parameter_list|,
name|void
modifier|*
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_loadh_pd
comment|// CHECK: load double, double* %{{.*}}, align 1{{$}}
comment|// CHECK: insertelement<2 x double> %{{.*}}, double %{{.*}}, i32 1
return|return
name|_mm_loadh_pd
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_loadl_epi64
parameter_list|(
name|__m128i
modifier|*
name|y
parameter_list|)
block|{
comment|// CHECK: test_mm_loadl_epi64
comment|// CHECK: load i64, i64* {{.*}}, align 1{{$}}
comment|// CHECK: insertelement<2 x i64> undef, i64 {{.*}}, i32 0
comment|// CHECK: insertelement<2 x i64> {{.*}}, i64 0, i32 1
return|return
name|_mm_loadl_epi64
argument_list|(
name|y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_loadl_pd
parameter_list|(
name|__m128d
name|x
parameter_list|,
name|void
modifier|*
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_loadl_pd
comment|// CHECK: load double, double* %{{.*}}, align 1{{$}}
comment|// CHECK: insertelement<2 x double> undef, double %{{.*}}, i32 0
comment|// CHECK: extractelement<2 x double> %{{.*}}, i32 1
comment|// CHECK: insertelement<2 x double> %{{.*}}, double %{{.*}}, i32 1
return|return
name|_mm_loadl_pd
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_loadr_pd
parameter_list|(
name|double
specifier|const
modifier|*
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_loadr_pd
comment|// CHECK: load<2 x double>,<2 x double>* %{{.*}}, align 16
comment|// CHECK: shufflevector<2 x double> %{{.*}},<2 x double> %{{.*}},<2 x i32><i32 1, i32 0>
return|return
name|_mm_loadr_pd
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_loadu_pd
parameter_list|(
name|double
specifier|const
modifier|*
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_loadu_pd
comment|// CHECK: load<2 x double>,<2 x double>* %{{.*}}, align 1{{$}}
return|return
name|_mm_loadu_pd
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_loadu_si128
parameter_list|(
name|__m128i
specifier|const
modifier|*
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_loadu_si128
comment|// CHECK: load<2 x i64>,<2 x i64>* %{{.*}}, align 1{{$}}
return|return
name|_mm_loadu_si128
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_loadu_si64
parameter_list|(
name|void
specifier|const
modifier|*
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_loadu_si64
comment|// CHECK: load i64, i64* %{{.*}}, align 1{{$}}
comment|// CHECK: insertelement<2 x i64> undef, i64 %{{.*}}, i32 0
comment|// CHECK: insertelement<2 x i64> %{{.*}}, i64 0, i32 1
return|return
name|_mm_loadu_si64
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_madd_epi16
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_madd_epi16
comment|// CHECK: call<4 x i32> @llvm.x86.sse2.pmadd.wd(<8 x i16> %{{.*}},<8 x i16> %{{.*}})
return|return
name|_mm_madd_epi16
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
name|test_mm_maskmoveu_si128
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|,
name|char
modifier|*
name|C
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_maskmoveu_si128
comment|// CHECK: call void @llvm.x86.sse2.maskmov.dqu(<16 x i8> %{{.*}},<16 x i8> %{{.*}}, i8* %{{.*}})
name|_mm_maskmoveu_si128
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
name|__m128i
name|test_mm_max_epi16
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_max_epi16
comment|// CHECK:       [[CMP:%.*]] = icmp sgt<8 x i16> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  select<8 x i1> [[CMP]],<8 x i16> [[X]],<8 x i16> [[Y]]
return|return
name|_mm_max_epi16
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_max_epu8
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_max_epu8
comment|// CHECK:       [[CMP:%.*]] = icmp ugt<16 x i8> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  select<16 x i1> [[CMP]],<16 x i8> [[X]],<16 x i8> [[Y]]
return|return
name|_mm_max_epu8
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
name|test_mm_max_pd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_max_pd
comment|// CHECK: call<2 x double> @llvm.x86.sse2.max.pd(<2 x double> %{{.*}},<2 x double> %{{.*}})
return|return
name|_mm_max_pd
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
name|test_mm_max_sd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_max_sd
comment|// CHECK: call<2 x double> @llvm.x86.sse2.max.sd(<2 x double> %{{.*}},<2 x double> %{{.*}})
return|return
name|_mm_max_sd
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
name|test_mm_mfence
parameter_list|()
block|{
comment|// CHECK-LABEL: test_mm_mfence
comment|// CHECK: call void @llvm.x86.sse2.mfence()
name|_mm_mfence
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_min_epi16
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_min_epi16
comment|// CHECK:       [[CMP:%.*]] = icmp slt<8 x i16> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  select<8 x i1> [[CMP]],<8 x i16> [[X]],<8 x i16> [[Y]]
return|return
name|_mm_min_epi16
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_min_epu8
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_min_epu8
comment|// CHECK:       [[CMP:%.*]] = icmp ult<16 x i8> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  select<16 x i1> [[CMP]],<16 x i8> [[X]],<16 x i8> [[Y]]
return|return
name|_mm_min_epu8
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
name|test_mm_min_pd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_min_pd
comment|// CHECK: call<2 x double> @llvm.x86.sse2.min.pd(<2 x double> %{{.*}},<2 x double> %{{.*}})
return|return
name|_mm_min_pd
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
name|test_mm_min_sd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_min_sd
comment|// CHECK: call<2 x double> @llvm.x86.sse2.min.sd(<2 x double> %{{.*}},<2 x double> %{{.*}})
return|return
name|_mm_min_sd
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_move_epi64
parameter_list|(
name|__m128i
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_move_epi64
comment|// CHECK: shufflevector<2 x i64> %{{.*}},<2 x i64> %{{.*}},<2 x i32><i32 0, i32 2>
return|return
name|_mm_move_epi64
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_move_sd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_move_sd
comment|// CHECK: extractelement<2 x double> %{{.*}}, i32 0
comment|// CHECK: insertelement<2 x double> undef, double %{{.*}}, i32 0
comment|// CHECK: extractelement<2 x double> %{{.*}}, i32 1
comment|// CHECK: insertelement<2 x double> %{{.*}}, double %{{.*}}, i32 1
return|return
name|_mm_move_sd
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
name|test_mm_movemask_epi8
parameter_list|(
name|__m128i
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_movemask_epi8
comment|// CHECK: call i32 @llvm.x86.sse2.pmovmskb.128(<16 x i8> %{{.*}})
return|return
name|_mm_movemask_epi8
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm_movemask_pd
parameter_list|(
name|__m128d
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_movemask_pd
comment|// CHECK: call i32 @llvm.x86.sse2.movmsk.pd(<2 x double> %{{.*}})
return|return
name|_mm_movemask_pd
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mul_epu32
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_mul_epu32
comment|// CHECK: call<2 x i64> @llvm.x86.sse2.pmulu.dq(<4 x i32> %{{.*}},<4 x i32> %{{.*}})
return|return
name|_mm_mul_epu32
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
name|test_mm_mul_pd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_mul_pd
comment|// CHECK: fmul<2 x double> %{{.*}}, %{{.*}}
return|return
name|_mm_mul_pd
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
name|test_mm_mul_sd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_mul_sd
comment|// CHECK: extractelement<2 x double> %{{.*}}, i32 0
comment|// CHECK: extractelement<2 x double> %{{.*}}, i32 0
comment|// CHECK: fmul double
comment|// CHECK: insertelement<2 x double> %{{.*}}, double %{{.*}}, i32 0
return|return
name|_mm_mul_sd
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mulhi_epi16
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_mulhi_epi16
comment|// CHECK: call<8 x i16> @llvm.x86.sse2.pmulh.w(<8 x i16> %{{.*}},<8 x i16> %{{.*}})
return|return
name|_mm_mulhi_epi16
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mulhi_epu16
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_mulhi_epu16
comment|// CHECK: call<8 x i16> @llvm.x86.sse2.pmulhu.w(<8 x i16> %{{.*}},<8 x i16> %{{.*}})
return|return
name|_mm_mulhi_epu16
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mullo_epi16
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_mullo_epi16
comment|// CHECK: mul<8 x i16> %{{.*}}, %{{.*}}
return|return
name|_mm_mullo_epi16
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
name|test_mm_or_pd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_or_pd
comment|// CHECK: or<2 x i64> %{{.*}}, %{{.*}}
return|return
name|_mm_or_pd
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_or_si128
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_or_si128
comment|// CHECK: or<2 x i64> %{{.*}}, %{{.*}}
return|return
name|_mm_or_si128
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_packs_epi16
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_packs_epi16
comment|// CHECK: call<16 x i8> @llvm.x86.sse2.packsswb.128(<8 x i16> %{{.*}},<8 x i16> %{{.*}})
return|return
name|_mm_packs_epi16
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_packs_epi32
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_packs_epi32
comment|// CHECK: call<8 x i16> @llvm.x86.sse2.packssdw.128(<4 x i32> %{{.*}},<4 x i32> %{{.*}})
return|return
name|_mm_packs_epi32
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_packus_epi16
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_packus_epi16
comment|// CHECK: call<16 x i8> @llvm.x86.sse2.packuswb.128(<8 x i16> %{{.*}},<8 x i16> %{{.*}})
return|return
name|_mm_packus_epi16
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
name|test_mm_pause
parameter_list|()
block|{
comment|// CHECK-LABEL: test_mm_pause
comment|// CHECK: call void @llvm.x86.sse2.pause()
return|return
name|_mm_pause
argument_list|()
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_sad_epu8
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_sad_epu8
comment|// CHECK: call<2 x i64> @llvm.x86.sse2.psad.bw(<16 x i8> %{{.*}},<16 x i8> %{{.*}})
return|return
name|_mm_sad_epu8
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_set_epi8
parameter_list|(
name|char
name|A
parameter_list|,
name|char
name|B
parameter_list|,
name|char
name|C
parameter_list|,
name|char
name|D
parameter_list|,
name|char
name|E
parameter_list|,
name|char
name|F
parameter_list|,
name|char
name|G
parameter_list|,
name|char
name|H
parameter_list|,
name|char
name|I
parameter_list|,
name|char
name|J
parameter_list|,
name|char
name|K
parameter_list|,
name|char
name|L
parameter_list|,
name|char
name|M
parameter_list|,
name|char
name|N
parameter_list|,
name|char
name|O
parameter_list|,
name|char
name|P
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_set_epi8
comment|// CHECK: insertelement<16 x i8> undef, i8 %{{.*}}, i32 0
comment|// CHECK: insertelement<16 x i8> %{{.*}}, i8 %{{.*}}, i32 1
comment|// CHECK: insertelement<16 x i8> %{{.*}}, i8 %{{.*}}, i32 2
comment|// CHECK: insertelement<16 x i8> %{{.*}}, i8 %{{.*}}, i32 3
comment|// CHECK: insertelement<16 x i8> %{{.*}}, i8 %{{.*}}, i32 4
comment|// CHECK: insertelement<16 x i8> %{{.*}}, i8 %{{.*}}, i32 5
comment|// CHECK: insertelement<16 x i8> %{{.*}}, i8 %{{.*}}, i32 6
comment|// CHECK: insertelement<16 x i8> %{{.*}}, i8 %{{.*}}, i32 7
comment|// CHECK: insertelement<16 x i8> %{{.*}}, i8 %{{.*}}, i32 8
comment|// CHECK: insertelement<16 x i8> %{{.*}}, i8 %{{.*}}, i32 9
comment|// CHECK: insertelement<16 x i8> %{{.*}}, i8 %{{.*}}, i32 10
comment|// CHECK: insertelement<16 x i8> %{{.*}}, i8 %{{.*}}, i32 11
comment|// CHECK: insertelement<16 x i8> %{{.*}}, i8 %{{.*}}, i32 12
comment|// CHECK: insertelement<16 x i8> %{{.*}}, i8 %{{.*}}, i32 13
comment|// CHECK: insertelement<16 x i8> %{{.*}}, i8 %{{.*}}, i32 14
comment|// CHECK: insertelement<16 x i8> %{{.*}}, i8 %{{.*}}, i32 15
return|return
name|_mm_set_epi8
argument_list|(
name|A
argument_list|,
name|B
argument_list|,
name|C
argument_list|,
name|D
argument_list|,
name|E
argument_list|,
name|F
argument_list|,
name|G
argument_list|,
name|H
argument_list|,
name|I
argument_list|,
name|J
argument_list|,
name|K
argument_list|,
name|L
argument_list|,
name|M
argument_list|,
name|N
argument_list|,
name|O
argument_list|,
name|P
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_set_epi16
parameter_list|(
name|short
name|A
parameter_list|,
name|short
name|B
parameter_list|,
name|short
name|C
parameter_list|,
name|short
name|D
parameter_list|,
name|short
name|E
parameter_list|,
name|short
name|F
parameter_list|,
name|short
name|G
parameter_list|,
name|short
name|H
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_set_epi16
comment|// CHECK: insertelement<8 x i16> undef, i16 %{{.*}}, i32 0
comment|// CHECK: insertelement<8 x i16> %{{.*}}, i16 %{{.*}}, i32 1
comment|// CHECK: insertelement<8 x i16> %{{.*}}, i16 %{{.*}}, i32 2
comment|// CHECK: insertelement<8 x i16> %{{.*}}, i16 %{{.*}}, i32 3
comment|// CHECK: insertelement<8 x i16> %{{.*}}, i16 %{{.*}}, i32 4
comment|// CHECK: insertelement<8 x i16> %{{.*}}, i16 %{{.*}}, i32 5
comment|// CHECK: insertelement<8 x i16> %{{.*}}, i16 %{{.*}}, i32 6
comment|// CHECK: insertelement<8 x i16> %{{.*}}, i16 %{{.*}}, i32 7
return|return
name|_mm_set_epi16
argument_list|(
name|A
argument_list|,
name|B
argument_list|,
name|C
argument_list|,
name|D
argument_list|,
name|E
argument_list|,
name|F
argument_list|,
name|G
argument_list|,
name|H
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_set_epi32
parameter_list|(
name|int
name|A
parameter_list|,
name|int
name|B
parameter_list|,
name|int
name|C
parameter_list|,
name|int
name|D
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_set_epi32
comment|// CHECK: insertelement<4 x i32> undef, i32 %{{.*}}, i32 0
comment|// CHECK: insertelement<4 x i32> %{{.*}}, i32 %{{.*}}, i32 1
comment|// CHECK: insertelement<4 x i32> %{{.*}}, i32 %{{.*}}, i32 2
comment|// CHECK: insertelement<4 x i32> %{{.*}}, i32 %{{.*}}, i32 3
return|return
name|_mm_set_epi32
argument_list|(
name|A
argument_list|,
name|B
argument_list|,
name|C
argument_list|,
name|D
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_set_epi64
parameter_list|(
name|__m64
name|A
parameter_list|,
name|__m64
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_set_epi64
comment|// CHECK: insertelement<2 x i64> undef, i64 %{{.*}}, i32 0
comment|// CHECK: insertelement<2 x i64> %{{.*}}, i64 %{{.*}}, i32 1
return|return
name|_mm_set_epi64
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_set_epi64x
parameter_list|(
name|long
name|long
name|A
parameter_list|,
name|long
name|long
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_set_epi64x
comment|// CHECK: insertelement<2 x i64> undef, i64 %{{.*}}, i32 0
comment|// CHECK: insertelement<2 x i64> %{{.*}}, i64 %{{.*}}, i32 1
return|return
name|_mm_set_epi64x
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
name|test_mm_set_pd
parameter_list|(
name|double
name|A
parameter_list|,
name|double
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_set_pd
comment|// CHECK: insertelement<2 x double> undef, double %{{.*}}, i32 0
comment|// CHECK: insertelement<2 x double> %{{.*}}, double %{{.*}}, i32 1
return|return
name|_mm_set_pd
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
name|test_mm_set_pd1
parameter_list|(
name|double
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_set_pd1
comment|// CHECK: insertelement<2 x double> undef, double %{{.*}}, i32 0
comment|// CHECK: insertelement<2 x double> %{{.*}}, double %{{.*}}, i32 1
return|return
name|_mm_set_pd1
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_set_sd
parameter_list|(
name|double
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_set_sd
comment|// CHECK: insertelement<2 x double> undef, double %{{.*}}, i32 0
comment|// CHECK: insertelement<2 x double> %{{.*}}, double 0.000000e+00, i32 1
return|return
name|_mm_set_sd
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_set1_epi8
parameter_list|(
name|char
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_set1_epi8
comment|// CHECK: insertelement<16 x i8> undef, i8 %{{.*}}, i32 0
comment|// CHECK: insertelement<16 x i8> %{{.*}}, i8 %{{.*}}, i32 1
comment|// CHECK: insertelement<16 x i8> %{{.*}}, i8 %{{.*}}, i32 2
comment|// CHECK: insertelement<16 x i8> %{{.*}}, i8 %{{.*}}, i32 3
comment|// CHECK: insertelement<16 x i8> %{{.*}}, i8 %{{.*}}, i32 4
comment|// CHECK: insertelement<16 x i8> %{{.*}}, i8 %{{.*}}, i32 5
comment|// CHECK: insertelement<16 x i8> %{{.*}}, i8 %{{.*}}, i32 6
comment|// CHECK: insertelement<16 x i8> %{{.*}}, i8 %{{.*}}, i32 7
comment|// CHECK: insertelement<16 x i8> %{{.*}}, i8 %{{.*}}, i32 8
comment|// CHECK: insertelement<16 x i8> %{{.*}}, i8 %{{.*}}, i32 9
comment|// CHECK: insertelement<16 x i8> %{{.*}}, i8 %{{.*}}, i32 10
comment|// CHECK: insertelement<16 x i8> %{{.*}}, i8 %{{.*}}, i32 11
comment|// CHECK: insertelement<16 x i8> %{{.*}}, i8 %{{.*}}, i32 12
comment|// CHECK: insertelement<16 x i8> %{{.*}}, i8 %{{.*}}, i32 13
comment|// CHECK: insertelement<16 x i8> %{{.*}}, i8 %{{.*}}, i32 14
comment|// CHECK: insertelement<16 x i8> %{{.*}}, i8 %{{.*}}, i32 15
return|return
name|_mm_set1_epi8
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_set1_epi16
parameter_list|(
name|short
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_set1_epi16
comment|// CHECK: insertelement<8 x i16> undef, i16 %{{.*}}, i32 0
comment|// CHECK: insertelement<8 x i16> %{{.*}}, i16 %{{.*}}, i32 1
comment|// CHECK: insertelement<8 x i16> %{{.*}}, i16 %{{.*}}, i32 2
comment|// CHECK: insertelement<8 x i16> %{{.*}}, i16 %{{.*}}, i32 3
comment|// CHECK: insertelement<8 x i16> %{{.*}}, i16 %{{.*}}, i32 4
comment|// CHECK: insertelement<8 x i16> %{{.*}}, i16 %{{.*}}, i32 5
comment|// CHECK: insertelement<8 x i16> %{{.*}}, i16 %{{.*}}, i32 6
comment|// CHECK: insertelement<8 x i16> %{{.*}}, i16 %{{.*}}, i32 7
return|return
name|_mm_set1_epi16
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_set1_epi32
parameter_list|(
name|int
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_set1_epi32
comment|// CHECK: insertelement<4 x i32> undef, i32 %{{.*}}, i32 0
comment|// CHECK: insertelement<4 x i32> %{{.*}}, i32 %{{.*}}, i32 1
comment|// CHECK: insertelement<4 x i32> %{{.*}}, i32 %{{.*}}, i32 2
comment|// CHECK: insertelement<4 x i32> %{{.*}}, i32 %{{.*}}, i32 3
return|return
name|_mm_set1_epi32
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_set1_epi64
parameter_list|(
name|__m64
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_set1_epi64
comment|// CHECK: insertelement<2 x i64> undef, i64 %{{.*}}, i32 0
comment|// CHECK: insertelement<2 x i64> %{{.*}}, i64 %{{.*}}, i32 1
return|return
name|_mm_set1_epi64
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_set1_epi64x
parameter_list|(
name|long
name|long
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_set1_epi64x
comment|// CHECK: insertelement<2 x i64> undef, i64 %{{.*}}, i32 0
comment|// CHECK: insertelement<2 x i64> %{{.*}}, i64 %{{.*}}, i32 1
return|return
name|_mm_set1_epi64x
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_set1_pd
parameter_list|(
name|double
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_set1_pd
comment|// CHECK: insertelement<2 x double> undef, double %{{.*}}, i32 0
comment|// CHECK: insertelement<2 x double> %{{.*}}, double %{{.*}}, i32 1
return|return
name|_mm_set1_pd
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_setr_epi8
parameter_list|(
name|char
name|A
parameter_list|,
name|char
name|B
parameter_list|,
name|char
name|C
parameter_list|,
name|char
name|D
parameter_list|,
name|char
name|E
parameter_list|,
name|char
name|F
parameter_list|,
name|char
name|G
parameter_list|,
name|char
name|H
parameter_list|,
name|char
name|I
parameter_list|,
name|char
name|J
parameter_list|,
name|char
name|K
parameter_list|,
name|char
name|L
parameter_list|,
name|char
name|M
parameter_list|,
name|char
name|N
parameter_list|,
name|char
name|O
parameter_list|,
name|char
name|P
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_setr_epi8
comment|// CHECK: insertelement<16 x i8> undef, i8 %{{.*}}, i32 0
comment|// CHECK: insertelement<16 x i8> %{{.*}}, i8 %{{.*}}, i32 1
comment|// CHECK: insertelement<16 x i8> %{{.*}}, i8 %{{.*}}, i32 2
comment|// CHECK: insertelement<16 x i8> %{{.*}}, i8 %{{.*}}, i32 3
comment|// CHECK: insertelement<16 x i8> %{{.*}}, i8 %{{.*}}, i32 4
comment|// CHECK: insertelement<16 x i8> %{{.*}}, i8 %{{.*}}, i32 5
comment|// CHECK: insertelement<16 x i8> %{{.*}}, i8 %{{.*}}, i32 6
comment|// CHECK: insertelement<16 x i8> %{{.*}}, i8 %{{.*}}, i32 7
comment|// CHECK: insertelement<16 x i8> %{{.*}}, i8 %{{.*}}, i32 8
comment|// CHECK: insertelement<16 x i8> %{{.*}}, i8 %{{.*}}, i32 9
comment|// CHECK: insertelement<16 x i8> %{{.*}}, i8 %{{.*}}, i32 10
comment|// CHECK: insertelement<16 x i8> %{{.*}}, i8 %{{.*}}, i32 11
comment|// CHECK: insertelement<16 x i8> %{{.*}}, i8 %{{.*}}, i32 12
comment|// CHECK: insertelement<16 x i8> %{{.*}}, i8 %{{.*}}, i32 13
comment|// CHECK: insertelement<16 x i8> %{{.*}}, i8 %{{.*}}, i32 14
comment|// CHECK: insertelement<16 x i8> %{{.*}}, i8 %{{.*}}, i32 15
return|return
name|_mm_setr_epi8
argument_list|(
name|A
argument_list|,
name|B
argument_list|,
name|C
argument_list|,
name|D
argument_list|,
name|E
argument_list|,
name|F
argument_list|,
name|G
argument_list|,
name|H
argument_list|,
name|I
argument_list|,
name|J
argument_list|,
name|K
argument_list|,
name|L
argument_list|,
name|M
argument_list|,
name|N
argument_list|,
name|O
argument_list|,
name|P
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_setr_epi16
parameter_list|(
name|short
name|A
parameter_list|,
name|short
name|B
parameter_list|,
name|short
name|C
parameter_list|,
name|short
name|D
parameter_list|,
name|short
name|E
parameter_list|,
name|short
name|F
parameter_list|,
name|short
name|G
parameter_list|,
name|short
name|H
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_setr_epi16
comment|// CHECK: insertelement<8 x i16> undef, i16 %{{.*}}, i32 0
comment|// CHECK: insertelement<8 x i16> %{{.*}}, i16 %{{.*}}, i32 1
comment|// CHECK: insertelement<8 x i16> %{{.*}}, i16 %{{.*}}, i32 2
comment|// CHECK: insertelement<8 x i16> %{{.*}}, i16 %{{.*}}, i32 3
comment|// CHECK: insertelement<8 x i16> %{{.*}}, i16 %{{.*}}, i32 4
comment|// CHECK: insertelement<8 x i16> %{{.*}}, i16 %{{.*}}, i32 5
comment|// CHECK: insertelement<8 x i16> %{{.*}}, i16 %{{.*}}, i32 6
comment|// CHECK: insertelement<8 x i16> %{{.*}}, i16 %{{.*}}, i32 7
return|return
name|_mm_setr_epi16
argument_list|(
name|A
argument_list|,
name|B
argument_list|,
name|C
argument_list|,
name|D
argument_list|,
name|E
argument_list|,
name|F
argument_list|,
name|G
argument_list|,
name|H
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_setr_epi32
parameter_list|(
name|int
name|A
parameter_list|,
name|int
name|B
parameter_list|,
name|int
name|C
parameter_list|,
name|int
name|D
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_setr_epi32
comment|// CHECK: insertelement<4 x i32> undef, i32 %{{.*}}, i32 0
comment|// CHECK: insertelement<4 x i32> %{{.*}}, i32 %{{.*}}, i32 1
comment|// CHECK: insertelement<4 x i32> %{{.*}}, i32 %{{.*}}, i32 2
comment|// CHECK: insertelement<4 x i32> %{{.*}}, i32 %{{.*}}, i32 3
return|return
name|_mm_setr_epi32
argument_list|(
name|A
argument_list|,
name|B
argument_list|,
name|C
argument_list|,
name|D
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_setr_epi64
parameter_list|(
name|__m64
name|A
parameter_list|,
name|__m64
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_setr_epi64
comment|// CHECK: insertelement<2 x i64> undef, i64 %{{.*}}, i32 0
comment|// CHECK: insertelement<2 x i64> %{{.*}}, i64 %{{.*}}, i32 1
return|return
name|_mm_setr_epi64
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
name|test_mm_setr_pd
parameter_list|(
name|double
name|A
parameter_list|,
name|double
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_setr_pd
comment|// CHECK: insertelement<2 x double> undef, double %{{.*}}, i32 0
comment|// CHECK: insertelement<2 x double> %{{.*}}, double %{{.*}}, i32 1
return|return
name|_mm_setr_pd
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
name|test_mm_setzero_pd
parameter_list|()
block|{
comment|// CHECK-LABEL: test_mm_setzero_pd
comment|// CHECK: store<2 x double> zeroinitializer
return|return
name|_mm_setzero_pd
argument_list|()
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_setzero_si128
parameter_list|()
block|{
comment|// CHECK-LABEL: test_mm_setzero_si128
comment|// CHECK: store<2 x i64> zeroinitializer
return|return
name|_mm_setzero_si128
argument_list|()
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_shuffle_epi32
parameter_list|(
name|__m128i
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_shuffle_epi32
comment|// CHECK: shufflevector<4 x i32> %{{.*}},<4 x i32> %{{.*}},<4 x i32> zeroinitializer
return|return
name|_mm_shuffle_epi32
argument_list|(
name|A
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_shuffle_pd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_shuffle_pd
comment|// CHECK: shufflevector<2 x double> %{{.*}},<2 x double> %{{.*}},<2 x i32><i32 1, i32 2>
return|return
name|_mm_shuffle_pd
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
name|__m128i
name|test_mm_shufflehi_epi16
parameter_list|(
name|__m128i
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_shufflehi_epi16
comment|// CHECK: shufflevector<8 x i16> %{{.*}},<8 x i16> %{{.*}},<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 4, i32 4, i32 4>
return|return
name|_mm_shufflehi_epi16
argument_list|(
name|A
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_shufflelo_epi16
parameter_list|(
name|__m128i
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_shufflelo_epi16
comment|// CHECK: shufflevector<8 x i16> %{{.*}},<8 x i16> %{{.*}},<8 x i32><i32 0, i32 0, i32 0, i32 0, i32 4, i32 5, i32 6, i32 7>
return|return
name|_mm_shufflelo_epi16
argument_list|(
name|A
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_sll_epi16
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_sll_epi16
comment|// CHECK: call<8 x i16> @llvm.x86.sse2.psll.w(<8 x i16> %{{.*}},<8 x i16> %{{.*}})
return|return
name|_mm_sll_epi16
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_sll_epi32
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_sll_epi32
comment|// CHECK: call<4 x i32> @llvm.x86.sse2.psll.d(<4 x i32> %{{.*}},<4 x i32> %{{.*}})
return|return
name|_mm_sll_epi32
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_sll_epi64
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_sll_epi64
comment|// CHECK: call<2 x i64> @llvm.x86.sse2.psll.q(<2 x i64> %{{.*}},<2 x i64> %{{.*}})
return|return
name|_mm_sll_epi64
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_slli_epi16
parameter_list|(
name|__m128i
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_slli_epi16
comment|// CHECK: call<8 x i16> @llvm.x86.sse2.pslli.w(<8 x i16> %{{.*}}, i32 %{{.*}})
return|return
name|_mm_slli_epi16
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
name|test_mm_slli_epi32
parameter_list|(
name|__m128i
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_slli_epi32
comment|// CHECK: call<4 x i32> @llvm.x86.sse2.pslli.d(<4 x i32> %{{.*}}, i32 %{{.*}})
return|return
name|_mm_slli_epi32
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
name|test_mm_slli_epi64
parameter_list|(
name|__m128i
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_slli_epi64
comment|// CHECK: call<2 x i64> @llvm.x86.sse2.pslli.q(<2 x i64> %{{.*}}, i32 %{{.*}})
return|return
name|_mm_slli_epi64
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
name|test_mm_slli_si128
parameter_list|(
name|__m128i
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_slli_si128
comment|// CHECK: shufflevector<16 x i8> %{{.*}},<16 x i8> %{{.*}},<16 x i32><i32 11, i32 12, i32 13, i32 14, i32 15, i32 16, i32 17, i32 18, i32 19, i32 20, i32 21, i32 22, i32 23, i32 24, i32 25, i32 26>
return|return
name|_mm_slli_si128
argument_list|(
name|A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_slli_si128_2
parameter_list|(
name|__m128i
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_slli_si128_2
comment|// CHECK: shufflevector<16 x i8> %{{.*}},<16 x i8> %{{.*}},<16 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15>
return|return
name|_mm_slli_si128
argument_list|(
name|A
argument_list|,
literal|17
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_sqrt_pd
parameter_list|(
name|__m128d
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_sqrt_pd
comment|// CHECK: call<2 x double> @llvm.x86.sse2.sqrt.pd(<2 x double> %{{.*}})
return|return
name|_mm_sqrt_pd
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_sqrt_sd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_sqrt_sd
comment|// CHECK: call<2 x double> @llvm.x86.sse2.sqrt.sd(<2 x double> %{{.*}})
comment|// CHECK: extractelement<2 x double> %{{.*}}, i32 0
comment|// CHECK: insertelement<2 x double> undef, double %{{.*}}, i32 0
comment|// CHECK: extractelement<2 x double> %{{.*}}, i32 1
comment|// CHECK: insertelement<2 x double> %{{.*}}, double %{{.*}}, i32 1
return|return
name|_mm_sqrt_sd
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_sra_epi16
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_sra_epi16
comment|// CHECK: call<8 x i16> @llvm.x86.sse2.psra.w(<8 x i16> %{{.*}},<8 x i16> %{{.*}})
return|return
name|_mm_sra_epi16
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_sra_epi32
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_sra_epi32
comment|// CHECK: call<4 x i32> @llvm.x86.sse2.psra.d(<4 x i32> %{{.*}},<4 x i32> %{{.*}})
return|return
name|_mm_sra_epi32
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_srai_epi16
parameter_list|(
name|__m128i
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_srai_epi16
comment|// CHECK: call<8 x i16> @llvm.x86.sse2.psrai.w(<8 x i16> %{{.*}}, i32 %{{.*}})
return|return
name|_mm_srai_epi16
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
name|test_mm_srai_epi32
parameter_list|(
name|__m128i
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_srai_epi32
comment|// CHECK: call<4 x i32> @llvm.x86.sse2.psrai.d(<4 x i32> %{{.*}}, i32 %{{.*}})
return|return
name|_mm_srai_epi32
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
name|test_mm_srl_epi16
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_srl_epi16
comment|// CHECK: call<8 x i16> @llvm.x86.sse2.psrl.w(<8 x i16> %{{.*}},<8 x i16> %{{.*}})
return|return
name|_mm_srl_epi16
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_srl_epi32
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_srl_epi32
comment|// CHECK: call<4 x i32> @llvm.x86.sse2.psrl.d(<4 x i32> %{{.*}},<4 x i32> %{{.*}})
return|return
name|_mm_srl_epi32
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_srl_epi64
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_srl_epi64
comment|// CHECK: call<2 x i64> @llvm.x86.sse2.psrl.q(<2 x i64> %{{.*}},<2 x i64> %{{.*}})
return|return
name|_mm_srl_epi64
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_srli_epi16
parameter_list|(
name|__m128i
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_srli_epi16
comment|// CHECK: call<8 x i16> @llvm.x86.sse2.psrli.w(<8 x i16> %{{.*}}, i32 %{{.*}})
return|return
name|_mm_srli_epi16
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
name|test_mm_srli_epi32
parameter_list|(
name|__m128i
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_srli_epi32
comment|// CHECK: call<4 x i32> @llvm.x86.sse2.psrli.d(<4 x i32> %{{.*}}, i32 %{{.*}})
return|return
name|_mm_srli_epi32
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
name|test_mm_srli_epi64
parameter_list|(
name|__m128i
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_srli_epi64
comment|// CHECK: call<2 x i64> @llvm.x86.sse2.psrli.q(<2 x i64> %{{.*}}, i32 %{{.*}})
return|return
name|_mm_srli_epi64
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
name|test_mm_srli_si128
parameter_list|(
name|__m128i
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_srli_si128
comment|// CHECK: shufflevector<16 x i8> %{{.*}},<16 x i8> %{{.*}},<16 x i32><i32 5, i32 6, i32 7, i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15, i32 16, i32 17, i32 18, i32 19, i32 20>
return|return
name|_mm_srli_si128
argument_list|(
name|A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_srli_si128_2
parameter_list|(
name|__m128i
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_srli_si128_2
comment|// CHECK: shufflevector<16 x i8> %{{.*}},<16 x i8> %{{.*}},<16 x i32><i32 16, i32 17, i32 18, i32 19, i32 20, i32 21, i32 22, i32 23, i32 24, i32 25, i32 26, i32 27, i32 28, i32 29, i32 30, i32 31>
return|return
name|_mm_srli_si128
argument_list|(
name|A
argument_list|,
literal|17
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm_store_pd
parameter_list|(
name|double
modifier|*
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_store_pd
comment|// CHECK: store<2 x double> %{{.*}},<2 x double>* %{{.*}}, align 16
name|_mm_store_pd
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
name|test_mm_store_pd1
parameter_list|(
name|double
modifier|*
name|x
parameter_list|,
name|__m128d
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_store_pd1
comment|// CHECK: shufflevector<2 x double> %{{.*}},<2 x double> %{{.*}},<2 x i32> zeroinitializer
comment|// CHECK: store<2 x double> %{{.*}},<2 x double>* {{.*}}, align 16
name|_mm_store_pd1
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_mm_store_sd
parameter_list|(
name|double
modifier|*
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_store_sd
comment|// CHECK: extractelement<2 x double> %{{.*}}, i32 0
comment|// CHECK: store double %{{.*}}, double* %{{.*}}, align 1{{$}}
name|_mm_store_sd
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
name|test_mm_store_si128
parameter_list|(
name|__m128i
modifier|*
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_store_si128
comment|// CHECK: store<2 x i64> %{{.*}},<2 x i64>* %{{.*}}, align 16
name|_mm_store_si128
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
name|test_mm_store1_pd
parameter_list|(
name|double
modifier|*
name|x
parameter_list|,
name|__m128d
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_store1_pd
comment|// CHECK: shufflevector<2 x double> %{{.*}},<2 x double> %{{.*}},<2 x i32> zeroinitializer
comment|// CHECK: store<2 x double> %{{.*}},<2 x double>* %{{.*}}, align 16
name|_mm_store1_pd
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_mm_storeh_pd
parameter_list|(
name|double
modifier|*
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_storeh_pd
comment|// CHECK: extractelement<2 x double> %{{.*}}, i32 1
comment|// CHECK: store double %{{.*}}, double* %{{.*}}, align 1{{$}}
name|_mm_storeh_pd
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
name|test_mm_storel_epi64
parameter_list|(
name|__m128i
name|x
parameter_list|,
name|void
modifier|*
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_storel_epi64
comment|// CHECK: extractelement<2 x i64> %{{.*}}, i32 0
comment|// CHECK: store {{.*}} i64* {{.*}}, align 1{{$}}
name|_mm_storel_epi64
argument_list|(
name|y
argument_list|,
name|x
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_mm_storel_pd
parameter_list|(
name|double
modifier|*
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_storel_pd
comment|// CHECK: extractelement<2 x double> %{{.*}}, i32 0
comment|// CHECK: store double %{{.*}}, double* %{{.*}}, align 1{{$}}
name|_mm_storel_pd
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
name|test_mm_storer_pd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|double
modifier|*
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_storer_pd
comment|// CHECK: shufflevector<2 x double> {{.*}},<2 x double> {{.*}},<2 x i32><i32 1, i32 0>
comment|// CHECK: store {{.*}}<2 x double>* {{.*}}, align 16{{$}}
name|_mm_storer_pd
argument_list|(
name|B
argument_list|,
name|A
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_mm_storeu_pd
parameter_list|(
name|double
modifier|*
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_storeu_pd
comment|// CHECK: store {{.*}}<2 x double>* {{.*}}, align 1{{$}}
comment|// CHECK-NEXT: ret void
name|_mm_storeu_pd
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
name|test_mm_storeu_si128
parameter_list|(
name|__m128i
modifier|*
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_storeu_si128
comment|// CHECK: store<2 x i64> %{{.*}},<2 x i64>* %{{.*}}, align 1{{$}}
comment|// CHECK-NEXT: ret void
name|_mm_storeu_si128
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
name|test_mm_stream_pd
parameter_list|(
name|double
modifier|*
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_stream_pd
comment|// CHECK: store<2 x double> %{{.*}},<2 x double>* %{{.*}}, align 16, !nontemporal
name|_mm_stream_pd
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
name|test_mm_stream_si32
parameter_list|(
name|int
modifier|*
name|A
parameter_list|,
name|int
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_stream_si32
comment|// CHECK: store i32 %{{.*}}, i32* %{{.*}}, align 1, !nontemporal
name|_mm_stream_si32
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
name|test_mm_stream_si64
parameter_list|(
name|long
name|long
modifier|*
name|A
parameter_list|,
name|long
name|long
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_stream_si64
comment|// CHECK: store i64 %{{.*}}, i64* %{{.*}}, align 1, !nontemporal
name|_mm_stream_si64
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
name|test_mm_stream_si128
parameter_list|(
name|__m128i
modifier|*
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_stream_si128
comment|// CHECK: store<2 x i64> %{{.*}},<2 x i64>* %{{.*}}, align 16, !nontemporal
name|_mm_stream_si128
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_sub_epi8
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_sub_epi8
comment|// CHECK: sub<16 x i8>
return|return
name|_mm_sub_epi8
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_sub_epi16
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_sub_epi16
comment|// CHECK: sub<8 x i16>
return|return
name|_mm_sub_epi16
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_sub_epi32
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_sub_epi32
comment|// CHECK: sub<4 x i32>
return|return
name|_mm_sub_epi32
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_sub_epi64
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_sub_epi64
comment|// CHECK: sub<2 x i64>
return|return
name|_mm_sub_epi64
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
name|test_mm_sub_pd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_sub_pd
comment|// CHECK: fsub<2 x double>
return|return
name|_mm_sub_pd
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
name|test_mm_sub_sd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_sub_sd
comment|// CHECK: extractelement<2 x double> %{{.*}}, i32 0
comment|// CHECK: extractelement<2 x double> %{{.*}}, i32 0
comment|// CHECK: fsub double
comment|// CHECK: insertelement<2 x double> %{{.*}}, double %{{.*}}, i32 0
return|return
name|_mm_sub_sd
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_subs_epi8
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_subs_epi8
comment|// CHECK: call<16 x i8> @llvm.x86.sse2.psubs.b(<16 x i8> %{{.*}},<16 x i8> %{{.*}})
return|return
name|_mm_subs_epi8
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_subs_epi16
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_subs_epi16
comment|// CHECK: call<8 x i16> @llvm.x86.sse2.psubs.w(<8 x i16> %{{.*}},<8 x i16> %{{.*}})
return|return
name|_mm_subs_epi16
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_subs_epu8
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_subs_epu8
comment|// CHECK: call<16 x i8> @llvm.x86.sse2.psubus.b(<16 x i8> %{{.*}},<16 x i8> %{{.*}})
return|return
name|_mm_subs_epu8
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_subs_epu16
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_subs_epu16
comment|// CHECK: call<8 x i16> @llvm.x86.sse2.psubus.w(<8 x i16> %{{.*}},<8 x i16> %{{.*}})
return|return
name|_mm_subs_epu16
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
name|test_mm_ucomieq_sd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_ucomieq_sd
comment|// CHECK: call i32 @llvm.x86.sse2.ucomieq.sd(<2 x double> %{{.*}},<2 x double> %{{.*}})
return|return
name|_mm_ucomieq_sd
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
name|test_mm_ucomige_sd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_ucomige_sd
comment|// CHECK: call i32 @llvm.x86.sse2.ucomige.sd(<2 x double> %{{.*}},<2 x double> %{{.*}})
return|return
name|_mm_ucomige_sd
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
name|test_mm_ucomigt_sd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_ucomigt_sd
comment|// CHECK: call i32 @llvm.x86.sse2.ucomigt.sd(<2 x double> %{{.*}},<2 x double> %{{.*}})
return|return
name|_mm_ucomigt_sd
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
name|test_mm_ucomile_sd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_ucomile_sd
comment|// CHECK: call i32 @llvm.x86.sse2.ucomile.sd(<2 x double> %{{.*}},<2 x double> %{{.*}})
return|return
name|_mm_ucomile_sd
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
name|test_mm_ucomilt_sd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_ucomilt_sd
comment|// CHECK: call i32 @llvm.x86.sse2.ucomilt.sd(<2 x double> %{{.*}},<2 x double> %{{.*}})
return|return
name|_mm_ucomilt_sd
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
name|test_mm_ucomineq_sd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_ucomineq_sd
comment|// CHECK: call i32 @llvm.x86.sse2.ucomineq.sd(<2 x double> %{{.*}},<2 x double> %{{.*}})
return|return
name|_mm_ucomineq_sd
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
name|test_mm_undefined_pd
parameter_list|()
block|{
comment|// CHECK-LABEL: @test_mm_undefined_pd
comment|// CHECK: ret<2 x double> zeroinitializer
return|return
name|_mm_undefined_pd
argument_list|()
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_undefined_si128
parameter_list|()
block|{
comment|// CHECK-LABEL: @test_mm_undefined_si128
comment|// CHECK: ret<2 x i64> zeroinitializer
return|return
name|_mm_undefined_si128
argument_list|()
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_unpackhi_epi8
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_unpackhi_epi8
comment|// CHECK: shufflevector<16 x i8> %{{.*}},<16 x i8> %{{.*}},<16 x i32><i32 8, i32 24, i32 9, i32 25, i32 10, i32 26, i32 11, i32 27, i32 12, i32 28, i32 13, i32 29, i32 14, i32 30, i32 15, i32 31>
return|return
name|_mm_unpackhi_epi8
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_unpackhi_epi16
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_unpackhi_epi16
comment|// CHECK: shufflevector<8 x i16> %{{.*}},<8 x i16> %{{.*}},<8 x i32><i32 4, i32 12, i32 5, i32 13, i32 6, i32 14, i32 7, i32 15>
return|return
name|_mm_unpackhi_epi16
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_unpackhi_epi32
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_unpackhi_epi32
comment|// CHECK: shufflevector<4 x i32> %{{.*}},<4 x i32> %{{.*}},<4 x i32><i32 2, i32 6, i32 3, i32 7>
return|return
name|_mm_unpackhi_epi32
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_unpackhi_epi64
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_unpackhi_epi64
comment|// CHECK: shufflevector<2 x i64> %{{.*}},<2 x i64> %{{.*}},<2 x i32><i32 1, i32 3>
return|return
name|_mm_unpackhi_epi64
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
name|test_mm_unpackhi_pd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_unpackhi_pd
comment|// CHECK: shufflevector<2 x double> %{{.*}},<2 x double> %{{.*}},<2 x i32><i32 1, i32 3>
return|return
name|_mm_unpackhi_pd
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_unpacklo_epi8
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_unpacklo_epi8
comment|// CHECK: shufflevector<16 x i8> %{{.*}},<16 x i8> %{{.*}},<16 x i32><i32 0, i32 16, i32 1, i32 17, i32 2, i32 18, i32 3, i32 19, i32 4, i32 20, i32 5, i32 21, i32 6, i32 22, i32 7, i32 23>
return|return
name|_mm_unpacklo_epi8
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_unpacklo_epi16
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_unpacklo_epi16
comment|// CHECK: shufflevector<8 x i16> %{{.*}},<8 x i16> %{{.*}},<8 x i32><i32 0, i32 8, i32 1, i32 9, i32 2, i32 10, i32 3, i32 11>
return|return
name|_mm_unpacklo_epi16
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_unpacklo_epi32
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_unpacklo_epi32
comment|// CHECK: shufflevector<4 x i32> %{{.*}},<4 x i32> %{{.*}},<4 x i32><i32 0, i32 4, i32 1, i32 5>
return|return
name|_mm_unpacklo_epi32
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_unpacklo_epi64
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_unpacklo_epi64
comment|// CHECK: shufflevector<2 x i64> %{{.*}},<2 x i64> %{{.*}},<2 x i32><i32 0, i32 2>
return|return
name|_mm_unpacklo_epi64
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
name|test_mm_unpacklo_pd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_unpacklo_pd
comment|// CHECK: shufflevector<2 x double> %{{.*}},<2 x double> %{{.*}},<2 x i32><i32 0, i32 2>
return|return
name|_mm_unpacklo_pd
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
name|test_mm_xor_pd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_xor_pd
comment|// CHECK: xor<2 x i64> %{{.*}}, %{{.*}}
return|return
name|_mm_xor_pd
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_xor_si128
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_xor_si128
comment|// CHECK: xor<2 x i64> %{{.*}}, %{{.*}}
return|return
name|_mm_xor_si128
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

end_unit

