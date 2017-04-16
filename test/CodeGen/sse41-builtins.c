begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ffreestanding %s -triple=x86_64-apple-darwin -target-feature +sse4.1 -emit-llvm -o - -Wall -Werror | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -ffreestanding %s -triple=x86_64-apple-darwin -target-feature +sse4.1 -fno-signed-char -emit-llvm -o - -Wall -Werror | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<x86intrin.h>
end_include

begin_comment
comment|// NOTE: This should match the tests in llvm/test/CodeGen/X86/sse41-intrinsics-fast-isel.ll
end_comment

begin_function
name|__m128i
name|test_mm_blend_epi16
parameter_list|(
name|__m128i
name|V1
parameter_list|,
name|__m128i
name|V2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_blend_epi16
comment|// CHECK: shufflevector<8 x i16> %{{.*}},<8 x i16> %{{.*}},<8 x i32><i32 0, i32 9, i32 2, i32 11, i32 4, i32 13, i32 6, i32 7>
return|return
name|_mm_blend_epi16
argument_list|(
name|V1
argument_list|,
name|V2
argument_list|,
literal|42
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_blend_pd
parameter_list|(
name|__m128d
name|V1
parameter_list|,
name|__m128d
name|V2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_blend_pd
comment|// CHECK: shufflevector<2 x double> %{{.*}},<2 x double> %{{.*}},<2 x i32><i32 0, i32 3>
return|return
name|_mm_blend_pd
argument_list|(
name|V1
argument_list|,
name|V2
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_blend_ps
parameter_list|(
name|__m128
name|V1
parameter_list|,
name|__m128
name|V2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_blend_ps
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> %{{.*}},<4 x i32><i32 0, i32 5, i32 6, i32 3>
return|return
name|_mm_blend_ps
argument_list|(
name|V1
argument_list|,
name|V2
argument_list|,
literal|6
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_blendv_epi8
parameter_list|(
name|__m128i
name|V1
parameter_list|,
name|__m128i
name|V2
parameter_list|,
name|__m128i
name|V3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_blendv_epi8
comment|// CHECK: call<16 x i8> @llvm.x86.sse41.pblendvb(<16 x i8> %{{.*}},<16 x i8> %{{.*}},<16 x i8> %{{.*}})
return|return
name|_mm_blendv_epi8
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
name|__m128d
name|test_mm_blendv_pd
parameter_list|(
name|__m128d
name|V1
parameter_list|,
name|__m128d
name|V2
parameter_list|,
name|__m128d
name|V3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_blendv_pd
comment|// CHECK: call<2 x double> @llvm.x86.sse41.blendvpd(<2 x double> %{{.*}},<2 x double> %{{.*}},<2 x double> %{{.*}})
return|return
name|_mm_blendv_pd
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
name|__m128
name|test_mm_blendv_ps
parameter_list|(
name|__m128
name|V1
parameter_list|,
name|__m128
name|V2
parameter_list|,
name|__m128
name|V3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_blendv_ps
comment|// CHECK: call<4 x float> @llvm.x86.sse41.blendvps(<4 x float> %{{.*}},<4 x float> %{{.*}},<4 x float> %{{.*}})
return|return
name|_mm_blendv_ps
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
name|__m128d
name|test_mm_ceil_pd
parameter_list|(
name|__m128d
name|x
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_ceil_pd
comment|// CHECK: call<2 x double> @llvm.x86.sse41.round.pd(<2 x double> %{{.*}}, i32 2)
return|return
name|_mm_ceil_pd
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_ceil_ps
parameter_list|(
name|__m128
name|x
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_ceil_ps
comment|// CHECK: call<4 x float> @llvm.x86.sse41.round.ps(<4 x float> %{{.*}}, i32 2)
return|return
name|_mm_ceil_ps
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_ceil_sd
parameter_list|(
name|__m128d
name|x
parameter_list|,
name|__m128d
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_ceil_sd
comment|// CHECK: call<2 x double> @llvm.x86.sse41.round.sd(<2 x double> %{{.*}},<2 x double> %{{.*}}, i32 2)
return|return
name|_mm_ceil_sd
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_ceil_ss
parameter_list|(
name|__m128
name|x
parameter_list|,
name|__m128
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_ceil_ss
comment|// CHECK: call<4 x float> @llvm.x86.sse41.round.ss(<4 x float> %{{.*}},<4 x float> %{{.*}}, i32 2)
return|return
name|_mm_ceil_ss
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
name|test_mm_cmpeq_epi64
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cmpeq_epi64
comment|// CHECK: icmp eq<2 x i64>
comment|// CHECK: sext<2 x i1> %{{.*}} to<2 x i64>
return|return
name|_mm_cmpeq_epi64
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
name|test_mm_cvtepi8_epi16
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvtepi8_epi16
comment|// CHECK: shufflevector<16 x i8> {{.*}},<16 x i8> {{.*}},<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: sext<8 x i8> {{.*}} to<8 x i16>
return|return
name|_mm_cvtepi8_epi16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_cvtepi8_epi32
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvtepi8_epi32
comment|// CHECK: shufflevector<16 x i8> {{.*}},<16 x i8> {{.*}},<4 x i32><i32 0, i32 1, i32 2, i32 3>
comment|// CHECK: sext<4 x i8> {{.*}} to<4 x i32>
return|return
name|_mm_cvtepi8_epi32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_cvtepi8_epi64
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvtepi8_epi64
comment|// CHECK: shufflevector<16 x i8> {{.*}},<16 x i8> {{.*}},<2 x i32><i32 0, i32 1>
comment|// CHECK: sext<2 x i8> {{.*}} to<2 x i64>
return|return
name|_mm_cvtepi8_epi64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_cvtepi16_epi32
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvtepi16_epi32
comment|// CHECK: shufflevector<8 x i16> {{.*}},<8 x i16> {{.*}},<4 x i32><i32 0, i32 1, i32 2, i32 3>
comment|// CHECK: sext<4 x i16> {{.*}} to<4 x i32>
return|return
name|_mm_cvtepi16_epi32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_cvtepi16_epi64
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvtepi16_epi64
comment|// CHECK: shufflevector<8 x i16> {{.*}},<8 x i16> {{.*}},<2 x i32><i32 0, i32 1>
comment|// CHECK: sext<2 x i16> {{.*}} to<2 x i64>
return|return
name|_mm_cvtepi16_epi64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_cvtepi32_epi64
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvtepi32_epi64
comment|// CHECK: shufflevector<4 x i32> {{.*}},<4 x i32> {{.*}},<2 x i32><i32 0, i32 1>
comment|// CHECK: sext<2 x i32> {{.*}} to<2 x i64>
return|return
name|_mm_cvtepi32_epi64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_cvtepu8_epi16
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvtepu8_epi16
comment|// CHECK: shufflevector<16 x i8> {{.*}},<16 x i8> {{.*}},<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: zext<8 x i8> {{.*}} to<8 x i16>
return|return
name|_mm_cvtepu8_epi16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_cvtepu8_epi32
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvtepu8_epi32
comment|// CHECK: shufflevector<16 x i8> {{.*}},<16 x i8> {{.*}},<4 x i32><i32 0, i32 1, i32 2, i32 3>
comment|// CHECK: zext<4 x i8> {{.*}} to<4 x i32>
return|return
name|_mm_cvtepu8_epi32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_cvtepu8_epi64
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvtepu8_epi64
comment|// CHECK: shufflevector<16 x i8> {{.*}},<16 x i8> {{.*}},<2 x i32><i32 0, i32 1>
comment|// CHECK: zext<2 x i8> {{.*}} to<2 x i64>
return|return
name|_mm_cvtepu8_epi64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_cvtepu16_epi32
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvtepu16_epi32
comment|// CHECK: shufflevector<8 x i16> {{.*}},<8 x i16> {{.*}},<4 x i32><i32 0, i32 1, i32 2, i32 3>
comment|// CHECK: zext<4 x i16> {{.*}} to<4 x i32>
return|return
name|_mm_cvtepu16_epi32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_cvtepu16_epi64
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvtepu16_epi64
comment|// CHECK: shufflevector<8 x i16> {{.*}},<8 x i16> {{.*}},<2 x i32><i32 0, i32 1>
comment|// CHECK: zext<2 x i16> {{.*}} to<2 x i64>
return|return
name|_mm_cvtepu16_epi64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_cvtepu32_epi64
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvtepu32_epi64
comment|// CHECK: shufflevector<4 x i32> {{.*}},<4 x i32> {{.*}},<2 x i32><i32 0, i32 1>
comment|// CHECK: zext<2 x i32> {{.*}} to<2 x i64>
return|return
name|_mm_cvtepu32_epi64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_dp_pd
parameter_list|(
name|__m128d
name|x
parameter_list|,
name|__m128d
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_dp_pd
comment|// CHECK: call<2 x double> @llvm.x86.sse41.dppd(<2 x double> {{.*}},<2 x double> {{.*}}, i8 7)
return|return
name|_mm_dp_pd
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_dp_ps
parameter_list|(
name|__m128
name|x
parameter_list|,
name|__m128
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_dp_ps
comment|// CHECK: call<4 x float> @llvm.x86.sse41.dpps(<4 x float> {{.*}},<4 x float> {{.*}}, i8 7)
return|return
name|_mm_dp_ps
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm_extract_epi8
parameter_list|(
name|__m128i
name|x
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_extract_epi8
comment|// CHECK: extractelement<16 x i8> %{{.*}}, i32 1
comment|// CHECK: zext i8 %{{.*}} to i32
return|return
name|_mm_extract_epi8
argument_list|(
name|x
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm_extract_epi32
parameter_list|(
name|__m128i
name|x
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_extract_epi32
comment|// CHECK: extractelement<4 x i32> %{{.*}}, i32 1
return|return
name|_mm_extract_epi32
argument_list|(
name|x
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|long
name|long
name|test_mm_extract_epi64
parameter_list|(
name|__m128i
name|x
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_extract_epi64
comment|// CHECK: extractelement<2 x i64> %{{.*}}, i32 1
return|return
name|_mm_extract_epi64
argument_list|(
name|x
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm_extract_ps
parameter_list|(
name|__m128
name|x
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_extract_ps
comment|// CHECK: extractelement<4 x float> %{{.*}}, i32 1
return|return
name|_mm_extract_ps
argument_list|(
name|x
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_floor_pd
parameter_list|(
name|__m128d
name|x
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_floor_pd
comment|// CHECK: call<2 x double> @llvm.x86.sse41.round.pd(<2 x double> %{{.*}}, i32 1)
return|return
name|_mm_floor_pd
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_floor_ps
parameter_list|(
name|__m128
name|x
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_floor_ps
comment|// CHECK: call<4 x float> @llvm.x86.sse41.round.ps(<4 x float> %{{.*}}, i32 1)
return|return
name|_mm_floor_ps
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_floor_sd
parameter_list|(
name|__m128d
name|x
parameter_list|,
name|__m128d
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_floor_sd
comment|// CHECK: call<2 x double> @llvm.x86.sse41.round.sd(<2 x double> %{{.*}},<2 x double> %{{.*}}, i32 1)
return|return
name|_mm_floor_sd
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_floor_ss
parameter_list|(
name|__m128
name|x
parameter_list|,
name|__m128
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_floor_ss
comment|// CHECK: call<4 x float> @llvm.x86.sse41.round.ss(<4 x float> %{{.*}},<4 x float> %{{.*}}, i32 1)
return|return
name|_mm_floor_ss
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
name|test_mm_insert_epi8
parameter_list|(
name|__m128i
name|x
parameter_list|,
name|char
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_insert_epi8
comment|// CHECK: insertelement<16 x i8> %{{.*}}, i8 %{{.*}}, i32 0
return|return
name|_mm_insert_epi8
argument_list|(
name|x
argument_list|,
name|b
argument_list|,
literal|16
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_insert_epi32
parameter_list|(
name|__m128i
name|x
parameter_list|,
name|int
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_insert_epi32
comment|// CHECK: insertelement<4 x i32> %{{.*}}, i32 %{{.*}}, i32 0
return|return
name|_mm_insert_epi32
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
name|__m128i
name|test_mm_insert_epi64
parameter_list|(
name|__m128i
name|x
parameter_list|,
name|long
name|long
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_insert_epi64
comment|// CHECK: insertelement<2 x i64> %{{.*}}, i64 %{{.*}}, i32 0
return|return
name|_mm_insert_epi64
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
name|__m128
name|test_mm_insert_ps
parameter_list|(
name|__m128
name|x
parameter_list|,
name|__m128
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_insert_ps
comment|// CHECK: call<4 x float> @llvm.x86.sse41.insertps(<4 x float> %{{.*}},<4 x float> %{{.*}}, i8 4)
return|return
name|_mm_insert_ps
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_max_epi8
parameter_list|(
name|__m128i
name|x
parameter_list|,
name|__m128i
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_max_epi8
comment|// CHECK:       [[CMP:%.*]] = icmp sgt<16 x i8> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  select<16 x i1> [[CMP]],<16 x i8> [[X]],<16 x i8> [[Y]]
return|return
name|_mm_max_epi8
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
name|test_mm_max_epi32
parameter_list|(
name|__m128i
name|x
parameter_list|,
name|__m128i
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_max_epi32
comment|// CHECK:       [[CMP:%.*]] = icmp sgt<4 x i32> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  select<4 x i1> [[CMP]],<4 x i32> [[X]],<4 x i32> [[Y]]
return|return
name|_mm_max_epi32
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
name|test_mm_max_epu16
parameter_list|(
name|__m128i
name|x
parameter_list|,
name|__m128i
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_max_epu16
comment|// CHECK:       [[CMP:%.*]] = icmp ugt<8 x i16> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  select<8 x i1> [[CMP]],<8 x i16> [[X]],<8 x i16> [[Y]]
return|return
name|_mm_max_epu16
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
name|test_mm_max_epu32
parameter_list|(
name|__m128i
name|x
parameter_list|,
name|__m128i
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_max_epu32
comment|// CHECK:       [[CMP:%.*]] = icmp ugt<4 x i32> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  select<4 x i1> [[CMP]],<4 x i32> [[X]],<4 x i32> [[Y]]
return|return
name|_mm_max_epu32
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
name|test_mm_min_epi8
parameter_list|(
name|__m128i
name|x
parameter_list|,
name|__m128i
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_min_epi8
comment|// CHECK:       [[CMP:%.*]] = icmp slt<16 x i8> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  select<16 x i1> [[CMP]],<16 x i8> [[X]],<16 x i8> [[Y]]
return|return
name|_mm_min_epi8
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
name|test_mm_min_epi32
parameter_list|(
name|__m128i
name|x
parameter_list|,
name|__m128i
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_min_epi32
comment|// CHECK:       [[CMP:%.*]] = icmp slt<4 x i32> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  select<4 x i1> [[CMP]],<4 x i32> [[X]],<4 x i32> [[Y]]
return|return
name|_mm_min_epi32
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
name|test_mm_min_epu16
parameter_list|(
name|__m128i
name|x
parameter_list|,
name|__m128i
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_min_epu16
comment|// CHECK:       [[CMP:%.*]] = icmp ult<8 x i16> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  select<8 x i1> [[CMP]],<8 x i16> [[X]],<8 x i16> [[Y]]
return|return
name|_mm_min_epu16
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
name|test_mm_min_epu32
parameter_list|(
name|__m128i
name|x
parameter_list|,
name|__m128i
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_min_epu32
comment|// CHECK:       [[CMP:%.*]] = icmp ult<4 x i32> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  select<4 x i1> [[CMP]],<4 x i32> [[X]],<4 x i32> [[Y]]
return|return
name|_mm_min_epu32
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
name|test_mm_minpos_epu16
parameter_list|(
name|__m128i
name|x
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_minpos_epu16
comment|// CHECK: call<8 x i16> @llvm.x86.sse41.phminposuw(<8 x i16> %{{.*}})
return|return
name|_mm_minpos_epu16
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mpsadbw_epu8
parameter_list|(
name|__m128i
name|x
parameter_list|,
name|__m128i
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_mpsadbw_epu8
comment|// CHECK: call<8 x i16> @llvm.x86.sse41.mpsadbw(<16 x i8> %{{.*}},<16 x i8> %{{.*}}, i8 1)
return|return
name|_mm_mpsadbw_epu8
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mul_epi32
parameter_list|(
name|__m128i
name|x
parameter_list|,
name|__m128i
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_mul_epi32
comment|// CHECK: call<2 x i64> @llvm.x86.sse41.pmuldq(<4 x i32> %{{.*}},<4 x i32> %{{.*}})
return|return
name|_mm_mul_epi32
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
name|test_mm_mullo_epi32
parameter_list|(
name|__m128i
name|x
parameter_list|,
name|__m128i
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_mullo_epi32
comment|// CHECK: mul<4 x i32>
return|return
name|_mm_mullo_epi32
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
name|test_mm_packus_epi32
parameter_list|(
name|__m128i
name|x
parameter_list|,
name|__m128i
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_packus_epi32
comment|// CHECK: call<8 x i16> @llvm.x86.sse41.packusdw(<4 x i32> %{{.*}},<4 x i32> %{{.*}})
return|return
name|_mm_packus_epi32
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
name|test_mm_round_pd
parameter_list|(
name|__m128d
name|x
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_round_pd
comment|// CHECK: call<2 x double> @llvm.x86.sse41.round.pd(<2 x double> %{{.*}}, i32 4)
return|return
name|_mm_round_pd
argument_list|(
name|x
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_round_ps
parameter_list|(
name|__m128
name|x
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_round_ps
comment|// CHECK: call<4 x float> @llvm.x86.sse41.round.ps(<4 x float> %{{.*}}, i32 4)
return|return
name|_mm_round_ps
argument_list|(
name|x
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_round_sd
parameter_list|(
name|__m128d
name|x
parameter_list|,
name|__m128d
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_round_sd
comment|// CHECK: call<2 x double> @llvm.x86.sse41.round.sd(<2 x double> %{{.*}},<2 x double> %{{.*}}, i32 4)
return|return
name|_mm_round_sd
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_round_ss
parameter_list|(
name|__m128
name|x
parameter_list|,
name|__m128
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_round_ss
comment|// CHECK: call<4 x float> @llvm.x86.sse41.round.ss(<4 x float> %{{.*}},<4 x float> %{{.*}}, i32 4)
return|return
name|_mm_round_ss
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_stream_load_si128
parameter_list|(
name|__m128i
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_stream_load_si128
comment|// CHECK: load<2 x i64>,<2 x i64>* %{{.*}}, align 16, !nontemporal
return|return
name|_mm_stream_load_si128
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm_test_all_ones
parameter_list|(
name|__m128i
name|x
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_test_all_ones
comment|// CHECK: call i32 @llvm.x86.sse41.ptestc(<2 x i64> %{{.*}},<2 x i64> %{{.*}})
return|return
name|_mm_test_all_ones
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm_test_all_zeros
parameter_list|(
name|__m128i
name|x
parameter_list|,
name|__m128i
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_test_all_zeros
comment|// CHECK: call i32 @llvm.x86.sse41.ptestz(<2 x i64> %{{.*}},<2 x i64> %{{.*}})
return|return
name|_mm_test_all_zeros
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm_test_mix_ones_zeros
parameter_list|(
name|__m128i
name|x
parameter_list|,
name|__m128i
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_test_mix_ones_zeros
comment|// CHECK: call i32 @llvm.x86.sse41.ptestnzc(<2 x i64> %{{.*}},<2 x i64> %{{.*}})
return|return
name|_mm_test_mix_ones_zeros
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm_testc_si128
parameter_list|(
name|__m128i
name|x
parameter_list|,
name|__m128i
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_testc_si128
comment|// CHECK: call i32 @llvm.x86.sse41.ptestc(<2 x i64> %{{.*}},<2 x i64> %{{.*}})
return|return
name|_mm_testc_si128
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm_testnzc_si128
parameter_list|(
name|__m128i
name|x
parameter_list|,
name|__m128i
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_testnzc_si128
comment|// CHECK: call i32 @llvm.x86.sse41.ptestnzc(<2 x i64> %{{.*}},<2 x i64> %{{.*}})
return|return
name|_mm_testnzc_si128
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm_testz_si128
parameter_list|(
name|__m128i
name|x
parameter_list|,
name|__m128i
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_testz_si128
comment|// CHECK: call i32 @llvm.x86.sse41.ptestz(<2 x i64> %{{.*}},<2 x i64> %{{.*}})
return|return
name|_mm_testz_si128
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
return|;
block|}
end_function

end_unit

