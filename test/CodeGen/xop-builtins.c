begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -triple=x86_64-apple-darwin -target-feature +xop -emit-llvm -o - -Werror | FileCheck %s
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
file|<x86intrin.h>
end_include

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
comment|// CHECK: @llvm.x86.xop.vpmacssww
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
comment|// CHECK: @llvm.x86.xop.vpmacsww
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
comment|// CHECK: @llvm.x86.xop.vpmacsswd
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
comment|// CHECK: @llvm.x86.xop.vpmacswd
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
comment|// CHECK: @llvm.x86.xop.vpmacssdd
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
comment|// CHECK: @llvm.x86.xop.vpmacsdd
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
comment|// CHECK: @llvm.x86.xop.vpmacssdql
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
comment|// CHECK: @llvm.x86.xop.vpmacsdql
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
comment|// CHECK: @llvm.x86.xop.vpmacssdqh
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
comment|// CHECK: @llvm.x86.xop.vpmacsdqh
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
comment|// CHECK: @llvm.x86.xop.vpmadcsswd
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
comment|// CHECK: @llvm.x86.xop.vpmadcswd
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
comment|// CHECK: @llvm.x86.xop.vphaddbw
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
comment|// CHECK: @llvm.x86.xop.vphaddbd
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
comment|// CHECK: @llvm.x86.xop.vphaddbq
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
comment|// CHECK: @llvm.x86.xop.vphaddwd
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
comment|// CHECK: @llvm.x86.xop.vphaddwq
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
comment|// CHECK: @llvm.x86.xop.vphadddq
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
comment|// CHECK: @llvm.x86.xop.vphaddubw
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
comment|// CHECK: @llvm.x86.xop.vphaddubd
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
comment|// CHECK: @llvm.x86.xop.vphaddubq
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
comment|// CHECK: @llvm.x86.xop.vphadduwd
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
comment|// CHECK: @llvm.x86.xop.vphadduwq
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
comment|// CHECK: @llvm.x86.xop.vphaddudq
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
comment|// CHECK: @llvm.x86.xop.vphsubbw
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
comment|// CHECK: @llvm.x86.xop.vphsubwd
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
comment|// CHECK: @llvm.x86.xop.vphsubdq
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
comment|// CHECK: @llvm.x86.xop.vpcmov
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
comment|// CHECK: @llvm.x86.xop.vpcmov.256
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
comment|// CHECK: @llvm.x86.xop.vpperm
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
comment|// CHECK: @llvm.x86.xop.vprotb
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
comment|// CHECK: @llvm.x86.xop.vprotw
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
comment|// CHECK: @llvm.x86.xop.vprotd
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
comment|// CHECK: @llvm.x86.xop.vprotq
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
comment|// CHECK: @llvm.x86.xop.vprotbi
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
comment|// CHECK: @llvm.x86.xop.vprotwi
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
comment|// CHECK: @llvm.x86.xop.vprotdi
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
comment|// CHECK: @llvm.x86.xop.vprotqi
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
comment|// CHECK: @llvm.x86.xop.vpshlb
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
comment|// CHECK: @llvm.x86.xop.vpshlw
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
comment|// CHECK: @llvm.x86.xop.vpshld
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
comment|// CHECK: @llvm.x86.xop.vpshlq
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
comment|// CHECK: @llvm.x86.xop.vpshab
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
comment|// CHECK: @llvm.x86.xop.vpshaw
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
comment|// CHECK: @llvm.x86.xop.vpshad
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
comment|// CHECK: @llvm.x86.xop.vpshaq
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
comment|// CHECK: @llvm.x86.xop.vpcomub
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
comment|// CHECK: @llvm.x86.xop.vpcomuw
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
comment|// CHECK: @llvm.x86.xop.vpcomud
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
comment|// CHECK: @llvm.x86.xop.vpcomuq
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
comment|// CHECK: @llvm.x86.xop.vpcomb
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
comment|// CHECK: @llvm.x86.xop.vpcomw
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
comment|// CHECK: @llvm.x86.xop.vpcomd
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
comment|// CHECK: @llvm.x86.xop.vpcomq
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
comment|// CHECK: @llvm.x86.xop.vpermil2pd
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
comment|// CHECK: @llvm.x86.xop.vpermil2pd.256
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
comment|// CHECK: @llvm.x86.xop.vpermil2ps
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
comment|// CHECK: @llvm.x86.xop.vpermil2ps.256
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
comment|// CHECK: @llvm.x86.xop.vfrcz.ss
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
comment|// CHECK: @llvm.x86.xop.vfrcz.sd
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
comment|// CHECK: @llvm.x86.xop.vfrcz.ps
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
comment|// CHECK: @llvm.x86.xop.vfrcz.pd
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
comment|// CHECK: @llvm.x86.xop.vfrcz.ps.256
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
comment|// CHECK: @llvm.x86.xop.vfrcz.pd.256
return|return
name|_mm256_frcz_pd
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

end_unit

