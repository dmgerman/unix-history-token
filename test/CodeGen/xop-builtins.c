begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ffreestanding %s -triple=x86_64-apple-darwin -target-feature +xop -emit-llvm -o - -Wall -Werror | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -ffreestanding %s -triple=x86_64-apple-darwin -target-feature +xop -fno-signed-char -emit-llvm -o - -Wall -Werror | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<x86intrin.h>
end_include

begin_comment
comment|// NOTE: This should match the tests in llvm/test/CodeGen/X86/xop-intrinsics-fast-isel.ll
end_comment

begin_function
name|__m128i
name|test_mm_maccs_epi16
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|,
name|__m128i
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_maccs_epi16
comment|// CHECK: call<8 x i16> @llvm.x86.xop.vpmacssww(<8 x i16> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}})
return|return
name|_mm_maccs_epi16
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
name|__m128i
name|test_mm_macc_epi16
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|,
name|__m128i
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_macc_epi16
comment|// CHECK: call<8 x i16> @llvm.x86.xop.vpmacsww(<8 x i16> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}})
return|return
name|_mm_macc_epi16
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
name|__m128i
name|test_mm_maccsd_epi16
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|,
name|__m128i
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_maccsd_epi16
comment|// CHECK: call<4 x i32> @llvm.x86.xop.vpmacsswd(<8 x i16> %{{.*}},<8 x i16> %{{.*}},<4 x i32> %{{.*}})
return|return
name|_mm_maccsd_epi16
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
name|__m128i
name|test_mm_maccd_epi16
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|,
name|__m128i
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_maccd_epi16
comment|// CHECK: call<4 x i32> @llvm.x86.xop.vpmacswd(<8 x i16> %{{.*}},<8 x i16> %{{.*}},<4 x i32> %{{.*}})
return|return
name|_mm_maccd_epi16
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
name|__m128i
name|test_mm_maccs_epi32
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|,
name|__m128i
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_maccs_epi32
comment|// CHECK: call<4 x i32> @llvm.x86.xop.vpmacssdd(<4 x i32> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}})
return|return
name|_mm_maccs_epi32
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
name|__m128i
name|test_mm_macc_epi32
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|,
name|__m128i
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_macc_epi32
comment|// CHECK: call<4 x i32> @llvm.x86.xop.vpmacsdd(<4 x i32> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}})
return|return
name|_mm_macc_epi32
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
name|__m128i
name|test_mm_maccslo_epi32
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|,
name|__m128i
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_maccslo_epi32
comment|// CHECK: call<2 x i64> @llvm.x86.xop.vpmacssdql(<4 x i32> %{{.*}},<4 x i32> %{{.*}},<2 x i64> %{{.*}})
return|return
name|_mm_maccslo_epi32
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
name|__m128i
name|test_mm_macclo_epi32
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|,
name|__m128i
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_macclo_epi32
comment|// CHECK: call<2 x i64> @llvm.x86.xop.vpmacsdql(<4 x i32> %{{.*}},<4 x i32> %{{.*}},<2 x i64> %{{.*}})
return|return
name|_mm_macclo_epi32
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
name|__m128i
name|test_mm_maccshi_epi32
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|,
name|__m128i
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_maccshi_epi32
comment|// CHECK: call<2 x i64> @llvm.x86.xop.vpmacssdqh(<4 x i32> %{{.*}},<4 x i32> %{{.*}},<2 x i64> %{{.*}})
return|return
name|_mm_maccshi_epi32
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
name|__m128i
name|test_mm_macchi_epi32
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|,
name|__m128i
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_macchi_epi32
comment|// CHECK: call<2 x i64> @llvm.x86.xop.vpmacsdqh(<4 x i32> %{{.*}},<4 x i32> %{{.*}},<2 x i64> %{{.*}})
return|return
name|_mm_macchi_epi32
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
name|__m128i
name|test_mm_maddsd_epi16
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|,
name|__m128i
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_maddsd_epi16
comment|// CHECK: call<4 x i32> @llvm.x86.xop.vpmadcsswd(<8 x i16> %{{.*}},<8 x i16> %{{.*}},<4 x i32> %{{.*}})
return|return
name|_mm_maddsd_epi16
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
name|__m128i
name|test_mm_maddd_epi16
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|,
name|__m128i
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_maddd_epi16
comment|// CHECK: call<4 x i32> @llvm.x86.xop.vpmadcswd(<8 x i16> %{{.*}},<8 x i16> %{{.*}},<4 x i32> %{{.*}})
return|return
name|_mm_maddd_epi16
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
name|__m128i
name|test_mm_haddw_epi8
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_haddw_epi8
comment|// CHECK: call<8 x i16> @llvm.x86.xop.vphaddbw(<16 x i8> %{{.*}})
return|return
name|_mm_haddw_epi8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_haddd_epi8
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_haddd_epi8
comment|// CHECK: call<4 x i32> @llvm.x86.xop.vphaddbd(<16 x i8> %{{.*}})
return|return
name|_mm_haddd_epi8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_haddq_epi8
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_haddq_epi8
comment|// CHECK: call<2 x i64> @llvm.x86.xop.vphaddbq(<16 x i8> %{{.*}})
return|return
name|_mm_haddq_epi8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_haddd_epi16
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_haddd_epi16
comment|// CHECK: call<4 x i32> @llvm.x86.xop.vphaddwd(<8 x i16> %{{.*}})
return|return
name|_mm_haddd_epi16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_haddq_epi16
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_haddq_epi16
comment|// CHECK: call<2 x i64> @llvm.x86.xop.vphaddwq(<8 x i16> %{{.*}})
return|return
name|_mm_haddq_epi16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_haddq_epi32
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_haddq_epi32
comment|// CHECK: call<2 x i64> @llvm.x86.xop.vphadddq(<4 x i32> %{{.*}})
return|return
name|_mm_haddq_epi32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_haddw_epu8
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_haddw_epu8
comment|// CHECK: call<8 x i16> @llvm.x86.xop.vphaddubw(<16 x i8> %{{.*}})
return|return
name|_mm_haddw_epu8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_haddd_epu8
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_haddd_epu8
comment|// CHECK: call<4 x i32> @llvm.x86.xop.vphaddubd(<16 x i8> %{{.*}})
return|return
name|_mm_haddd_epu8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_haddq_epu8
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_haddq_epu8
comment|// CHECK: call<2 x i64> @llvm.x86.xop.vphaddubq(<16 x i8> %{{.*}})
return|return
name|_mm_haddq_epu8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_haddd_epu16
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_haddd_epu16
comment|// CHECK: call<4 x i32> @llvm.x86.xop.vphadduwd(<8 x i16> %{{.*}})
return|return
name|_mm_haddd_epu16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_haddq_epu16
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_haddq_epu16
comment|// CHECK: call<2 x i64> @llvm.x86.xop.vphadduwq(<8 x i16> %{{.*}})
return|return
name|_mm_haddq_epu16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_haddq_epu32
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_haddq_epu32
comment|// CHECK: call<2 x i64> @llvm.x86.xop.vphaddudq(<4 x i32> %{{.*}})
return|return
name|_mm_haddq_epu32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_hsubw_epi8
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_hsubw_epi8
comment|// CHECK: call<8 x i16> @llvm.x86.xop.vphsubbw(<16 x i8> %{{.*}})
return|return
name|_mm_hsubw_epi8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_hsubd_epi16
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_hsubd_epi16
comment|// CHECK: call<4 x i32> @llvm.x86.xop.vphsubwd(<8 x i16> %{{.*}})
return|return
name|_mm_hsubd_epi16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_hsubq_epi32
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_hsubq_epi32
comment|// CHECK: call<2 x i64> @llvm.x86.xop.vphsubdq(<4 x i32> %{{.*}})
return|return
name|_mm_hsubq_epi32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_cmov_si128
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|,
name|__m128i
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cmov_si128
comment|// CHECK: [[AND:%.*]] = and<2 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: [[NEG:%.*]] = xor<2 x i64> %{{.*}},<i64 -1, i64 -1>
comment|// CHECK-NEXT: [[ANDN:%.*]] = and<2 x i64> %{{.*}}, [[NEG]]
comment|// CHECK-NEXT: %{{.*}} = or<2 x i64> [[AND]], [[ANDN]]
return|return
name|_mm_cmov_si128
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
name|__m256i
name|test_mm256_cmov_si256
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|,
name|__m256i
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_cmov_si256
comment|// CHECK: [[AND:%.*]] = and<4 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: [[NEG:%.*]] = xor<4 x i64> %{{.*}},<i64 -1, i64 -1, i64 -1, i64 -1>
comment|// CHECK-NEXT: [[ANDN:%.*]] = and<4 x i64> %{{.*}}, [[NEG]]
comment|// CHECK-NEXT: %{{.*}} = or<4 x i64> [[AND]], [[ANDN]]
return|return
name|_mm256_cmov_si256
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
name|__m128i
name|test_mm_perm_epi8
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|,
name|__m128i
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_perm_epi8
comment|// CHECK: call<16 x i8> @llvm.x86.xop.vpperm(<16 x i8> %{{.*}},<16 x i8> %{{.*}},<16 x i8> %{{.*}})
return|return
name|_mm_perm_epi8
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
name|__m128i
name|test_mm_rot_epi8
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_rot_epi8
comment|// CHECK: call<16 x i8> @llvm.x86.xop.vprotb(<16 x i8> %{{.*}},<16 x i8> %{{.*}})
return|return
name|_mm_rot_epi8
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
name|test_mm_rot_epi16
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_rot_epi16
comment|// CHECK: call<8 x i16> @llvm.x86.xop.vprotw(<8 x i16> %{{.*}},<8 x i16> %{{.*}})
return|return
name|_mm_rot_epi16
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
name|test_mm_rot_epi32
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_rot_epi32
comment|// CHECK: call<4 x i32> @llvm.x86.xop.vprotd(<4 x i32> %{{.*}},<4 x i32> %{{.*}})
return|return
name|_mm_rot_epi32
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
name|test_mm_rot_epi64
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_rot_epi64
comment|// CHECK: call<2 x i64> @llvm.x86.xop.vprotq(<2 x i64> %{{.*}},<2 x i64> %{{.*}})
return|return
name|_mm_rot_epi64
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
name|test_mm_roti_epi8
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_roti_epi8
comment|// CHECK: call<16 x i8> @llvm.x86.xop.vprotbi(<16 x i8> %{{.*}}, i8 1)
return|return
name|_mm_roti_epi8
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_roti_epi16
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_roti_epi16
comment|// CHECK: call<8 x i16> @llvm.x86.xop.vprotwi(<8 x i16> %{{.*}}, i8 50)
return|return
name|_mm_roti_epi16
argument_list|(
name|a
argument_list|,
literal|50
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_roti_epi32
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_roti_epi32
comment|// CHECK: call<4 x i32> @llvm.x86.xop.vprotdi(<4 x i32> %{{.*}}, i8 -30)
return|return
name|_mm_roti_epi32
argument_list|(
name|a
argument_list|,
operator|-
literal|30
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_roti_epi64
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_roti_epi64
comment|// CHECK: call<2 x i64> @llvm.x86.xop.vprotqi(<2 x i64> %{{.*}}, i8 100)
return|return
name|_mm_roti_epi64
argument_list|(
name|a
argument_list|,
literal|100
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_shl_epi8
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_shl_epi8
comment|// CHECK: call<16 x i8> @llvm.x86.xop.vpshlb(<16 x i8> %{{.*}},<16 x i8> %{{.*}})
return|return
name|_mm_shl_epi8
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
name|test_mm_shl_epi16
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_shl_epi16
comment|// CHECK: call<8 x i16> @llvm.x86.xop.vpshlw(<8 x i16> %{{.*}},<8 x i16> %{{.*}})
return|return
name|_mm_shl_epi16
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
name|test_mm_shl_epi32
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_shl_epi32
comment|// CHECK: call<4 x i32> @llvm.x86.xop.vpshld(<4 x i32> %{{.*}},<4 x i32> %{{.*}})
return|return
name|_mm_shl_epi32
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
name|test_mm_shl_epi64
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_shl_epi64
comment|// CHECK: call<2 x i64> @llvm.x86.xop.vpshlq(<2 x i64> %{{.*}},<2 x i64> %{{.*}})
return|return
name|_mm_shl_epi64
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
name|test_mm_sha_epi8
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_sha_epi8
comment|// CHECK: call<16 x i8> @llvm.x86.xop.vpshab(<16 x i8> %{{.*}},<16 x i8> %{{.*}})
return|return
name|_mm_sha_epi8
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
name|test_mm_sha_epi16
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_sha_epi16
comment|// CHECK: call<8 x i16> @llvm.x86.xop.vpshaw(<8 x i16> %{{.*}},<8 x i16> %{{.*}})
return|return
name|_mm_sha_epi16
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
name|test_mm_sha_epi32
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_sha_epi32
comment|// CHECK: call<4 x i32> @llvm.x86.xop.vpshad(<4 x i32> %{{.*}},<4 x i32> %{{.*}})
return|return
name|_mm_sha_epi32
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
name|test_mm_sha_epi64
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_sha_epi64
comment|// CHECK: call<2 x i64> @llvm.x86.xop.vpshaq(<2 x i64> %{{.*}},<2 x i64> %{{.*}})
return|return
name|_mm_sha_epi64
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
name|test_mm_com_epu8
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_com_epu8
comment|// CHECK: call<16 x i8> @llvm.x86.xop.vpcomub(<16 x i8> %{{.*}},<16 x i8> %{{.*}}, i8 0)
return|return
name|_mm_com_epu8
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
name|__m128i
name|test_mm_com_epu16
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_com_epu16
comment|// CHECK: call<8 x i16> @llvm.x86.xop.vpcomuw(<8 x i16> %{{.*}},<8 x i16> %{{.*}}, i8 0)
return|return
name|_mm_com_epu16
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
name|__m128i
name|test_mm_com_epu32
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_com_epu32
comment|// CHECK: call<4 x i32> @llvm.x86.xop.vpcomud(<4 x i32> %{{.*}},<4 x i32> %{{.*}}, i8 0)
return|return
name|_mm_com_epu32
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
name|__m128i
name|test_mm_com_epu64
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_com_epu64
comment|// CHECK: call<2 x i64> @llvm.x86.xop.vpcomuq(<2 x i64> %{{.*}},<2 x i64> %{{.*}}, i8 0)
return|return
name|_mm_com_epu64
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
name|__m128i
name|test_mm_com_epi8
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_com_epi8
comment|// CHECK: call<16 x i8> @llvm.x86.xop.vpcomb(<16 x i8> %{{.*}},<16 x i8> %{{.*}}, i8 0)
return|return
name|_mm_com_epi8
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
name|__m128i
name|test_mm_com_epi16
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_com_epi16
comment|// CHECK: call<8 x i16> @llvm.x86.xop.vpcomw(<8 x i16> %{{.*}},<8 x i16> %{{.*}}, i8 0)
return|return
name|_mm_com_epi16
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
name|__m128i
name|test_mm_com_epi32
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_com_epi32
comment|// CHECK: call<4 x i32> @llvm.x86.xop.vpcomd(<4 x i32> %{{.*}},<4 x i32> %{{.*}}, i8 0)
return|return
name|_mm_com_epi32
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
name|__m128i
name|test_mm_com_epi64
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_com_epi64
comment|// CHECK: call<2 x i64> @llvm.x86.xop.vpcomq(<2 x i64> %{{.*}},<2 x i64> %{{.*}}, i8 0)
return|return
name|_mm_com_epi64
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
name|__m128d
name|test_mm_permute2_pd
parameter_list|(
name|__m128d
name|a
parameter_list|,
name|__m128d
name|b
parameter_list|,
name|__m128i
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_permute2_pd
comment|// CHECK: call<2 x double> @llvm.x86.xop.vpermil2pd(<2 x double> %{{.*}},<2 x double> %{{.*}},<2 x i64> %{{.*}}, i8 0)
return|return
name|_mm_permute2_pd
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_permute2_pd
parameter_list|(
name|__m256d
name|a
parameter_list|,
name|__m256d
name|b
parameter_list|,
name|__m256i
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_permute2_pd
comment|// CHECK: call<4 x double> @llvm.x86.xop.vpermil2pd.256(<4 x double> %{{.*}},<4 x double> %{{.*}},<4 x i64> %{{.*}}, i8 0)
return|return
name|_mm256_permute2_pd
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_permute2_ps
parameter_list|(
name|__m128
name|a
parameter_list|,
name|__m128
name|b
parameter_list|,
name|__m128i
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_permute2_ps
comment|// CHECK: call<4 x float> @llvm.x86.xop.vpermil2ps(<4 x float> %{{.*}},<4 x float> %{{.*}},<4 x i32> %{{.*}}, i8 0)
return|return
name|_mm_permute2_ps
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_permute2_ps
parameter_list|(
name|__m256
name|a
parameter_list|,
name|__m256
name|b
parameter_list|,
name|__m256i
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_permute2_ps
comment|// CHECK: call<8 x float> @llvm.x86.xop.vpermil2ps.256(<8 x float> %{{.*}},<8 x float> %{{.*}},<8 x i32> %{{.*}}, i8 0)
return|return
name|_mm256_permute2_ps
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_frcz_ss
parameter_list|(
name|__m128
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_frcz_ss
comment|// CHECK: call<4 x float> @llvm.x86.xop.vfrcz.ss(<4 x float> %{{.*}})
return|return
name|_mm_frcz_ss
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_frcz_sd
parameter_list|(
name|__m128d
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_frcz_sd
comment|// CHECK: call<2 x double> @llvm.x86.xop.vfrcz.sd(<2 x double> %{{.*}})
return|return
name|_mm_frcz_sd
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_frcz_ps
parameter_list|(
name|__m128
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_frcz_ps
comment|// CHECK: call<4 x float> @llvm.x86.xop.vfrcz.ps(<4 x float> %{{.*}})
return|return
name|_mm_frcz_ps
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_frcz_pd
parameter_list|(
name|__m128d
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_frcz_pd
comment|// CHECK: call<2 x double> @llvm.x86.xop.vfrcz.pd(<2 x double> %{{.*}})
return|return
name|_mm_frcz_pd
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_frcz_ps
parameter_list|(
name|__m256
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_frcz_ps
comment|// CHECK: call<8 x float> @llvm.x86.xop.vfrcz.ps.256(<8 x float> %{{.*}})
return|return
name|_mm256_frcz_ps
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_frcz_pd
parameter_list|(
name|__m256d
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_frcz_pd
comment|// CHECK: call<4 x double> @llvm.x86.xop.vfrcz.pd.256(<4 x double> %{{.*}})
return|return
name|_mm256_frcz_pd
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

end_unit

