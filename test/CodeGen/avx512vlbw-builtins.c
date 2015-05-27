begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -O0 -triple=x86_64-apple-darwin -ffreestanding -target-feature +avx512bw -target-feature +avx512vl -emit-llvm -o - -Werror | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<immintrin.h>
end_include

begin_function
name|__mmask32
name|test_mm256_cmpeq_epi8_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmpeq_epi8_mask
comment|// CHECK: @llvm.x86.avx512.mask.pcmpeq.b.256
return|return
operator|(
name|__mmask32
operator|)
name|_mm256_cmpeq_epi8_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask32
name|test_mm256_mask_cmpeq_epi8_mask
parameter_list|(
name|__mmask32
name|__u
parameter_list|,
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmpeq_epi8_mask
comment|// CHECK: @llvm.x86.avx512.mask.pcmpeq.b.256
return|return
operator|(
name|__mmask32
operator|)
name|_mm256_mask_cmpeq_epi8_mask
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
name|test_mm_cmpeq_epi8_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpeq_epi8_mask
comment|// CHECK: @llvm.x86.avx512.mask.pcmpeq.b.128
return|return
operator|(
name|__mmask16
operator|)
name|_mm_cmpeq_epi8_mask
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
name|test_mm_mask_cmpeq_epi8_mask
parameter_list|(
name|__mmask16
name|__u
parameter_list|,
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cmpeq_epi8_mask
comment|// CHECK: @llvm.x86.avx512.mask.pcmpeq.b.128
return|return
operator|(
name|__mmask16
operator|)
name|_mm_mask_cmpeq_epi8_mask
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
name|test_mm256_cmpeq_epi16_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmpeq_epi16_mask
comment|// CHECK: @llvm.x86.avx512.mask.pcmpeq.w.256
return|return
operator|(
name|__mmask16
operator|)
name|_mm256_cmpeq_epi16_mask
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
name|test_mm256_mask_cmpeq_epi16_mask
parameter_list|(
name|__mmask16
name|__u
parameter_list|,
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmpeq_epi16_mask
comment|// CHECK: @llvm.x86.avx512.mask.pcmpeq.w.256
return|return
operator|(
name|__mmask16
operator|)
name|_mm256_mask_cmpeq_epi16_mask
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
name|test_mm_cmpeq_epi16_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpeq_epi16_mask
comment|// CHECK: @llvm.x86.avx512.mask.pcmpeq.w.128
return|return
operator|(
name|__mmask8
operator|)
name|_mm_cmpeq_epi16_mask
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
name|test_mm_mask_cmpeq_epi16_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cmpeq_epi16_mask
comment|// CHECK: @llvm.x86.avx512.mask.pcmpeq.w.128
return|return
operator|(
name|__mmask8
operator|)
name|_mm_mask_cmpeq_epi16_mask
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
name|__mmask32
name|test_mm256_cmpgt_epi8_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmpgt_epi8_mask
comment|// CHECK: @llvm.x86.avx512.mask.pcmpgt.b.256
return|return
operator|(
name|__mmask32
operator|)
name|_mm256_cmpgt_epi8_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask32
name|test_mm256_mask_cmpgt_epi8_mask
parameter_list|(
name|__mmask32
name|__u
parameter_list|,
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmpgt_epi8_mask
comment|// CHECK: @llvm.x86.avx512.mask.pcmpgt.b.256
return|return
operator|(
name|__mmask32
operator|)
name|_mm256_mask_cmpgt_epi8_mask
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
name|test_mm_cmpgt_epi8_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpgt_epi8_mask
comment|// CHECK: @llvm.x86.avx512.mask.pcmpgt.b.128
return|return
operator|(
name|__mmask16
operator|)
name|_mm_cmpgt_epi8_mask
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
name|test_mm_mask_cmpgt_epi8_mask
parameter_list|(
name|__mmask16
name|__u
parameter_list|,
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cmpgt_epi8_mask
comment|// CHECK: @llvm.x86.avx512.mask.pcmpgt.b.128
return|return
operator|(
name|__mmask16
operator|)
name|_mm_mask_cmpgt_epi8_mask
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
name|test_mm256_cmpgt_epi16_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmpgt_epi16_mask
comment|// CHECK: @llvm.x86.avx512.mask.pcmpgt.w.256
return|return
operator|(
name|__mmask16
operator|)
name|_mm256_cmpgt_epi16_mask
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
name|test_mm256_mask_cmpgt_epi16_mask
parameter_list|(
name|__mmask16
name|__u
parameter_list|,
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmpgt_epi16_mask
comment|// CHECK: @llvm.x86.avx512.mask.pcmpgt.w.256
return|return
operator|(
name|__mmask16
operator|)
name|_mm256_mask_cmpgt_epi16_mask
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
name|test_mm_cmpgt_epi16_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpgt_epi16_mask
comment|// CHECK: @llvm.x86.avx512.mask.pcmpgt.w.128
return|return
operator|(
name|__mmask8
operator|)
name|_mm_cmpgt_epi16_mask
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
name|test_mm_mask_cmpgt_epi16_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cmpgt_epi16_mask
comment|// CHECK: @llvm.x86.avx512.mask.pcmpgt.w.128
return|return
operator|(
name|__mmask8
operator|)
name|_mm_mask_cmpgt_epi16_mask
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
name|test_mm_cmpeq_epu8_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpeq_epu8_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.b.128(<16 x i8> {{.*}},<16 x i8> {{.*}}, i32 0, i16 -1)
return|return
operator|(
name|__mmask64
operator|)
name|_mm_cmpeq_epu8_mask
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
name|test_mm_mask_cmpeq_epu8_mask
parameter_list|(
name|__mmask64
name|__u
parameter_list|,
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cmpeq_epu8_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.b.128(<16 x i8> {{.*}},<16 x i8> {{.*}}, i32 0, i16 {{.*}})
return|return
operator|(
name|__mmask64
operator|)
name|_mm_mask_cmpeq_epu8_mask
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
name|test_mm_cmpeq_epu16_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpeq_epu16_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.w.128(<8 x i16> {{.*}},<8 x i16> {{.*}}, i32 0, i8 -1)
return|return
operator|(
name|__mmask32
operator|)
name|_mm_cmpeq_epu16_mask
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
name|test_mm_mask_cmpeq_epu16_mask
parameter_list|(
name|__mmask32
name|__u
parameter_list|,
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cmpeq_epu16_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.w.128(<8 x i16> {{.*}},<8 x i16> {{.*}}, i32 0, i8 {{.*}})
return|return
operator|(
name|__mmask32
operator|)
name|_mm_mask_cmpeq_epu16_mask
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
name|__mmask32
name|test_mm256_cmpeq_epu8_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmpeq_epu8_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.b.256(<32 x i8> {{.*}},<32 x i8> {{.*}}, i32 0, i32 -1)
return|return
operator|(
name|__mmask64
operator|)
name|_mm256_cmpeq_epu8_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask32
name|test_mm256_mask_cmpeq_epu8_mask
parameter_list|(
name|__mmask64
name|__u
parameter_list|,
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmpeq_epu8_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.b.256(<32 x i8> {{.*}},<32 x i8> {{.*}}, i32 0, i32 {{.*}})
return|return
operator|(
name|__mmask64
operator|)
name|_mm256_mask_cmpeq_epu8_mask
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
name|test_mm256_cmpeq_epu16_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmpeq_epu16_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.w.256(<16 x i16> {{.*}},<16 x i16> {{.*}}, i32 0, i16 -1)
return|return
operator|(
name|__mmask32
operator|)
name|_mm256_cmpeq_epu16_mask
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
name|test_mm256_mask_cmpeq_epu16_mask
parameter_list|(
name|__mmask32
name|__u
parameter_list|,
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmpeq_epu16_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.w.256(<16 x i16> {{.*}},<16 x i16> {{.*}}, i32 0, i16 {{.*}})
return|return
operator|(
name|__mmask32
operator|)
name|_mm256_mask_cmpeq_epu16_mask
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
name|test_mm_cmpgt_epu8_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpgt_epu8_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.b.128(<16 x i8> {{.*}},<16 x i8> {{.*}}, i32 6, i16 -1)
return|return
operator|(
name|__mmask64
operator|)
name|_mm_cmpgt_epu8_mask
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
name|test_mm_mask_cmpgt_epu8_mask
parameter_list|(
name|__mmask64
name|__u
parameter_list|,
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cmpgt_epu8_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.b.128(<16 x i8> {{.*}},<16 x i8> {{.*}}, i32 6, i16 {{.*}})
return|return
operator|(
name|__mmask64
operator|)
name|_mm_mask_cmpgt_epu8_mask
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
name|test_mm_cmpgt_epu16_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpgt_epu16_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.w.128(<8 x i16> {{.*}},<8 x i16> {{.*}}, i32 6, i8 -1)
return|return
operator|(
name|__mmask32
operator|)
name|_mm_cmpgt_epu16_mask
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
name|test_mm_mask_cmpgt_epu16_mask
parameter_list|(
name|__mmask32
name|__u
parameter_list|,
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cmpgt_epu16_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.w.128(<8 x i16> {{.*}},<8 x i16> {{.*}}, i32 6, i8 {{.*}})
return|return
operator|(
name|__mmask32
operator|)
name|_mm_mask_cmpgt_epu16_mask
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
name|__mmask32
name|test_mm256_cmpgt_epu8_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmpgt_epu8_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.b.256(<32 x i8> {{.*}},<32 x i8> {{.*}}, i32 6, i32 -1)
return|return
operator|(
name|__mmask64
operator|)
name|_mm256_cmpgt_epu8_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask32
name|test_mm256_mask_cmpgt_epu8_mask
parameter_list|(
name|__mmask64
name|__u
parameter_list|,
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmpgt_epu8_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.b.256(<32 x i8> {{.*}},<32 x i8> {{.*}}, i32 6, i32 {{.*}})
return|return
operator|(
name|__mmask64
operator|)
name|_mm256_mask_cmpgt_epu8_mask
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
name|test_mm256_cmpgt_epu16_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmpgt_epu16_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.w.256(<16 x i16> {{.*}},<16 x i16> {{.*}}, i32 6, i16 -1)
return|return
operator|(
name|__mmask32
operator|)
name|_mm256_cmpgt_epu16_mask
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
name|test_mm256_mask_cmpgt_epu16_mask
parameter_list|(
name|__mmask32
name|__u
parameter_list|,
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmpgt_epu16_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.w.256(<16 x i16> {{.*}},<16 x i16> {{.*}}, i32 6, i16 {{.*}})
return|return
operator|(
name|__mmask32
operator|)
name|_mm256_mask_cmpgt_epu16_mask
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
name|test_mm_cmpge_epi8_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpge_epi8_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.b.128(<16 x i8> {{.*}},<16 x i8> {{.*}}, i32 5, i16 -1)
return|return
operator|(
name|__mmask64
operator|)
name|_mm_cmpge_epi8_mask
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
name|test_mm_mask_cmpge_epi8_mask
parameter_list|(
name|__mmask64
name|__u
parameter_list|,
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cmpge_epi8_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.b.128(<16 x i8> {{.*}},<16 x i8> {{.*}}, i32 5, i16 {{.*}})
return|return
operator|(
name|__mmask64
operator|)
name|_mm_mask_cmpge_epi8_mask
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
name|test_mm_cmpge_epu8_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpge_epu8_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.b.128(<16 x i8> {{.*}},<16 x i8> {{.*}}, i32 5, i16 -1)
return|return
operator|(
name|__mmask64
operator|)
name|_mm_cmpge_epu8_mask
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
name|test_mm_mask_cmpge_epu8_mask
parameter_list|(
name|__mmask64
name|__u
parameter_list|,
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cmpge_epu8_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.b.128(<16 x i8> {{.*}},<16 x i8> {{.*}}, i32 5, i16 {{.*}})
return|return
operator|(
name|__mmask64
operator|)
name|_mm_mask_cmpge_epu8_mask
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
name|test_mm_cmpge_epi16_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpge_epi16_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.w.128(<8 x i16> {{.*}},<8 x i16> {{.*}}, i32 5, i8 -1)
return|return
operator|(
name|__mmask32
operator|)
name|_mm_cmpge_epi16_mask
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
name|test_mm_mask_cmpge_epi16_mask
parameter_list|(
name|__mmask32
name|__u
parameter_list|,
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cmpge_epi16_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.w.128(<8 x i16> {{.*}},<8 x i16> {{.*}}, i32 5, i8 {{.*}})
return|return
operator|(
name|__mmask32
operator|)
name|_mm_mask_cmpge_epi16_mask
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
name|test_mm_cmpge_epu16_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpge_epu16_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.w.128(<8 x i16> {{.*}},<8 x i16> {{.*}}, i32 5, i8 -1)
return|return
operator|(
name|__mmask32
operator|)
name|_mm_cmpge_epu16_mask
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
name|test_mm_mask_cmpge_epu16_mask
parameter_list|(
name|__mmask32
name|__u
parameter_list|,
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cmpge_epu16_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.w.128(<8 x i16> {{.*}},<8 x i16> {{.*}}, i32 5, i8 {{.*}})
return|return
operator|(
name|__mmask32
operator|)
name|_mm_mask_cmpge_epu16_mask
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
name|__mmask32
name|test_mm256_cmpge_epi8_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmpge_epi8_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.b.256(<32 x i8> {{.*}},<32 x i8> {{.*}}, i32 5, i32 -1)
return|return
operator|(
name|__mmask64
operator|)
name|_mm256_cmpge_epi8_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask32
name|test_mm256_mask_cmpge_epi8_mask
parameter_list|(
name|__mmask64
name|__u
parameter_list|,
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmpge_epi8_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.b.256(<32 x i8> {{.*}},<32 x i8> {{.*}}, i32 5, i32 {{.*}})
return|return
operator|(
name|__mmask64
operator|)
name|_mm256_mask_cmpge_epi8_mask
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
name|__mmask32
name|test_mm256_cmpge_epu8_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmpge_epu8_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.b.256(<32 x i8> {{.*}},<32 x i8> {{.*}}, i32 5, i32 -1)
return|return
operator|(
name|__mmask64
operator|)
name|_mm256_cmpge_epu8_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask32
name|test_mm256_mask_cmpge_epu8_mask
parameter_list|(
name|__mmask64
name|__u
parameter_list|,
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmpge_epu8_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.b.256(<32 x i8> {{.*}},<32 x i8> {{.*}}, i32 5, i32 {{.*}})
return|return
operator|(
name|__mmask64
operator|)
name|_mm256_mask_cmpge_epu8_mask
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
name|test_mm256_cmpge_epi16_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmpge_epi16_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.w.256(<16 x i16> {{.*}},<16 x i16> {{.*}}, i32 5, i16 -1)
return|return
operator|(
name|__mmask32
operator|)
name|_mm256_cmpge_epi16_mask
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
name|test_mm256_mask_cmpge_epi16_mask
parameter_list|(
name|__mmask32
name|__u
parameter_list|,
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmpge_epi16_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.w.256(<16 x i16> {{.*}},<16 x i16> {{.*}}, i32 5, i16 {{.*}})
return|return
operator|(
name|__mmask32
operator|)
name|_mm256_mask_cmpge_epi16_mask
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
name|test_mm256_cmpge_epu16_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmpge_epu16_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.w.256(<16 x i16> {{.*}},<16 x i16> {{.*}}, i32 5, i16 -1)
return|return
operator|(
name|__mmask32
operator|)
name|_mm256_cmpge_epu16_mask
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
name|test_mm256_mask_cmpge_epu16_mask
parameter_list|(
name|__mmask32
name|__u
parameter_list|,
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmpge_epu16_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.w.256(<16 x i16> {{.*}},<16 x i16> {{.*}}, i32 5, i16 {{.*}})
return|return
operator|(
name|__mmask32
operator|)
name|_mm256_mask_cmpge_epu16_mask
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
name|test_mm_cmple_epi8_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmple_epi8_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.b.128(<16 x i8> {{.*}},<16 x i8> {{.*}}, i32 2, i16 -1)
return|return
operator|(
name|__mmask64
operator|)
name|_mm_cmple_epi8_mask
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
name|test_mm_mask_cmple_epi8_mask
parameter_list|(
name|__mmask64
name|__u
parameter_list|,
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cmple_epi8_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.b.128(<16 x i8> {{.*}},<16 x i8> {{.*}}, i32 2, i16 {{.*}})
return|return
operator|(
name|__mmask64
operator|)
name|_mm_mask_cmple_epi8_mask
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
name|test_mm_cmple_epu8_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmple_epu8_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.b.128(<16 x i8> {{.*}},<16 x i8> {{.*}}, i32 2, i16 -1)
return|return
operator|(
name|__mmask64
operator|)
name|_mm_cmple_epu8_mask
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
name|test_mm_mask_cmple_epu8_mask
parameter_list|(
name|__mmask64
name|__u
parameter_list|,
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cmple_epu8_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.b.128(<16 x i8> {{.*}},<16 x i8> {{.*}}, i32 2, i16 {{.*}})
return|return
operator|(
name|__mmask64
operator|)
name|_mm_mask_cmple_epu8_mask
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
name|test_mm_cmple_epi16_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmple_epi16_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.w.128(<8 x i16> {{.*}},<8 x i16> {{.*}}, i32 2, i8 -1)
return|return
operator|(
name|__mmask32
operator|)
name|_mm_cmple_epi16_mask
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
name|test_mm_mask_cmple_epi16_mask
parameter_list|(
name|__mmask32
name|__u
parameter_list|,
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cmple_epi16_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.w.128(<8 x i16> {{.*}},<8 x i16> {{.*}}, i32 2, i8 {{.*}})
return|return
operator|(
name|__mmask32
operator|)
name|_mm_mask_cmple_epi16_mask
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
name|test_mm_cmple_epu16_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmple_epu16_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.w.128(<8 x i16> {{.*}},<8 x i16> {{.*}}, i32 2, i8 -1)
return|return
operator|(
name|__mmask32
operator|)
name|_mm_cmple_epu16_mask
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
name|test_mm_mask_cmple_epu16_mask
parameter_list|(
name|__mmask32
name|__u
parameter_list|,
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cmple_epu16_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.w.128(<8 x i16> {{.*}},<8 x i16> {{.*}}, i32 2, i8 {{.*}})
return|return
operator|(
name|__mmask32
operator|)
name|_mm_mask_cmple_epu16_mask
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
name|__mmask32
name|test_mm256_cmple_epi8_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmple_epi8_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.b.256(<32 x i8> {{.*}},<32 x i8> {{.*}}, i32 2, i32 -1)
return|return
operator|(
name|__mmask64
operator|)
name|_mm256_cmple_epi8_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask32
name|test_mm256_mask_cmple_epi8_mask
parameter_list|(
name|__mmask64
name|__u
parameter_list|,
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmple_epi8_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.b.256(<32 x i8> {{.*}},<32 x i8> {{.*}}, i32 2, i32 {{.*}})
return|return
operator|(
name|__mmask64
operator|)
name|_mm256_mask_cmple_epi8_mask
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
name|__mmask32
name|test_mm256_cmple_epu8_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmple_epu8_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.b.256(<32 x i8> {{.*}},<32 x i8> {{.*}}, i32 2, i32 -1)
return|return
operator|(
name|__mmask64
operator|)
name|_mm256_cmple_epu8_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask32
name|test_mm256_mask_cmple_epu8_mask
parameter_list|(
name|__mmask64
name|__u
parameter_list|,
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmple_epu8_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.b.256(<32 x i8> {{.*}},<32 x i8> {{.*}}, i32 2, i32 {{.*}})
return|return
operator|(
name|__mmask64
operator|)
name|_mm256_mask_cmple_epu8_mask
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
name|test_mm256_cmple_epi16_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmple_epi16_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.w.256(<16 x i16> {{.*}},<16 x i16> {{.*}}, i32 2, i16 -1)
return|return
operator|(
name|__mmask32
operator|)
name|_mm256_cmple_epi16_mask
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
name|test_mm256_mask_cmple_epi16_mask
parameter_list|(
name|__mmask32
name|__u
parameter_list|,
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmple_epi16_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.w.256(<16 x i16> {{.*}},<16 x i16> {{.*}}, i32 2, i16 {{.*}})
return|return
operator|(
name|__mmask32
operator|)
name|_mm256_mask_cmple_epi16_mask
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
name|test_mm256_cmple_epu16_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmple_epu16_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.w.256(<16 x i16> {{.*}},<16 x i16> {{.*}}, i32 2, i16 -1)
return|return
operator|(
name|__mmask32
operator|)
name|_mm256_cmple_epu16_mask
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
name|test_mm256_mask_cmple_epu16_mask
parameter_list|(
name|__mmask32
name|__u
parameter_list|,
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmple_epu16_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.w.256(<16 x i16> {{.*}},<16 x i16> {{.*}}, i32 2, i16 {{.*}})
return|return
operator|(
name|__mmask32
operator|)
name|_mm256_mask_cmple_epu16_mask
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
name|test_mm_cmplt_epi8_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmplt_epi8_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.b.128(<16 x i8> {{.*}},<16 x i8> {{.*}}, i32 1, i16 -1)
return|return
operator|(
name|__mmask64
operator|)
name|_mm_cmplt_epi8_mask
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
name|test_mm_mask_cmplt_epi8_mask
parameter_list|(
name|__mmask64
name|__u
parameter_list|,
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cmplt_epi8_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.b.128(<16 x i8> {{.*}},<16 x i8> {{.*}}, i32 1, i16 {{.*}})
return|return
operator|(
name|__mmask64
operator|)
name|_mm_mask_cmplt_epi8_mask
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
name|test_mm_cmplt_epu8_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmplt_epu8_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.b.128(<16 x i8> {{.*}},<16 x i8> {{.*}}, i32 1, i16 -1)
return|return
operator|(
name|__mmask64
operator|)
name|_mm_cmplt_epu8_mask
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
name|test_mm_mask_cmplt_epu8_mask
parameter_list|(
name|__mmask64
name|__u
parameter_list|,
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cmplt_epu8_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.b.128(<16 x i8> {{.*}},<16 x i8> {{.*}}, i32 1, i16 {{.*}})
return|return
operator|(
name|__mmask64
operator|)
name|_mm_mask_cmplt_epu8_mask
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
name|test_mm_cmplt_epi16_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmplt_epi16_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.w.128(<8 x i16> {{.*}},<8 x i16> {{.*}}, i32 1, i8 -1)
return|return
operator|(
name|__mmask32
operator|)
name|_mm_cmplt_epi16_mask
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
name|test_mm_mask_cmplt_epi16_mask
parameter_list|(
name|__mmask32
name|__u
parameter_list|,
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cmplt_epi16_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.w.128(<8 x i16> {{.*}},<8 x i16> {{.*}}, i32 1, i8 {{.*}})
return|return
operator|(
name|__mmask32
operator|)
name|_mm_mask_cmplt_epi16_mask
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
name|test_mm_cmplt_epu16_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmplt_epu16_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.w.128(<8 x i16> {{.*}},<8 x i16> {{.*}}, i32 1, i8 -1)
return|return
operator|(
name|__mmask32
operator|)
name|_mm_cmplt_epu16_mask
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
name|test_mm_mask_cmplt_epu16_mask
parameter_list|(
name|__mmask32
name|__u
parameter_list|,
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cmplt_epu16_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.w.128(<8 x i16> {{.*}},<8 x i16> {{.*}}, i32 1, i8 {{.*}})
return|return
operator|(
name|__mmask32
operator|)
name|_mm_mask_cmplt_epu16_mask
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
name|__mmask32
name|test_mm256_cmplt_epi8_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmplt_epi8_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.b.256(<32 x i8> {{.*}},<32 x i8> {{.*}}, i32 1, i32 -1)
return|return
operator|(
name|__mmask64
operator|)
name|_mm256_cmplt_epi8_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask32
name|test_mm256_mask_cmplt_epi8_mask
parameter_list|(
name|__mmask64
name|__u
parameter_list|,
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmplt_epi8_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.b.256(<32 x i8> {{.*}},<32 x i8> {{.*}}, i32 1, i32 {{.*}})
return|return
operator|(
name|__mmask64
operator|)
name|_mm256_mask_cmplt_epi8_mask
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
name|__mmask32
name|test_mm256_cmplt_epu8_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmplt_epu8_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.b.256(<32 x i8> {{.*}},<32 x i8> {{.*}}, i32 1, i32 -1)
return|return
operator|(
name|__mmask64
operator|)
name|_mm256_cmplt_epu8_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask32
name|test_mm256_mask_cmplt_epu8_mask
parameter_list|(
name|__mmask64
name|__u
parameter_list|,
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmplt_epu8_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.b.256(<32 x i8> {{.*}},<32 x i8> {{.*}}, i32 1, i32 {{.*}})
return|return
operator|(
name|__mmask64
operator|)
name|_mm256_mask_cmplt_epu8_mask
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
name|test_mm256_cmplt_epi16_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmplt_epi16_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.w.256(<16 x i16> {{.*}},<16 x i16> {{.*}}, i32 1, i16 -1)
return|return
operator|(
name|__mmask32
operator|)
name|_mm256_cmplt_epi16_mask
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
name|test_mm256_mask_cmplt_epi16_mask
parameter_list|(
name|__mmask32
name|__u
parameter_list|,
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmplt_epi16_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.w.256(<16 x i16> {{.*}},<16 x i16> {{.*}}, i32 1, i16 {{.*}})
return|return
operator|(
name|__mmask32
operator|)
name|_mm256_mask_cmplt_epi16_mask
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
name|test_mm256_cmplt_epu16_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmplt_epu16_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.w.256(<16 x i16> {{.*}},<16 x i16> {{.*}}, i32 1, i16 -1)
return|return
operator|(
name|__mmask32
operator|)
name|_mm256_cmplt_epu16_mask
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
name|test_mm256_mask_cmplt_epu16_mask
parameter_list|(
name|__mmask32
name|__u
parameter_list|,
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmplt_epu16_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.w.256(<16 x i16> {{.*}},<16 x i16> {{.*}}, i32 1, i16 {{.*}})
return|return
operator|(
name|__mmask32
operator|)
name|_mm256_mask_cmplt_epu16_mask
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
name|test_mm_cmpneq_epi8_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpneq_epi8_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.b.128(<16 x i8> {{.*}},<16 x i8> {{.*}}, i32 4, i16 -1)
return|return
operator|(
name|__mmask64
operator|)
name|_mm_cmpneq_epi8_mask
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
name|test_mm_mask_cmpneq_epi8_mask
parameter_list|(
name|__mmask64
name|__u
parameter_list|,
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cmpneq_epi8_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.b.128(<16 x i8> {{.*}},<16 x i8> {{.*}}, i32 4, i16 {{.*}})
return|return
operator|(
name|__mmask64
operator|)
name|_mm_mask_cmpneq_epi8_mask
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
name|test_mm_cmpneq_epu8_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpneq_epu8_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.b.128(<16 x i8> {{.*}},<16 x i8> {{.*}}, i32 4, i16 -1)
return|return
operator|(
name|__mmask64
operator|)
name|_mm_cmpneq_epu8_mask
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
name|test_mm_mask_cmpneq_epu8_mask
parameter_list|(
name|__mmask64
name|__u
parameter_list|,
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cmpneq_epu8_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.b.128(<16 x i8> {{.*}},<16 x i8> {{.*}}, i32 4, i16 {{.*}})
return|return
operator|(
name|__mmask64
operator|)
name|_mm_mask_cmpneq_epu8_mask
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
name|test_mm_cmpneq_epi16_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpneq_epi16_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.w.128(<8 x i16> {{.*}},<8 x i16> {{.*}}, i32 4, i8 -1)
return|return
operator|(
name|__mmask32
operator|)
name|_mm_cmpneq_epi16_mask
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
name|test_mm_mask_cmpneq_epi16_mask
parameter_list|(
name|__mmask32
name|__u
parameter_list|,
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cmpneq_epi16_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.w.128(<8 x i16> {{.*}},<8 x i16> {{.*}}, i32 4, i8 {{.*}})
return|return
operator|(
name|__mmask32
operator|)
name|_mm_mask_cmpneq_epi16_mask
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
name|test_mm_cmpneq_epu16_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpneq_epu16_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.w.128(<8 x i16> {{.*}},<8 x i16> {{.*}}, i32 4, i8 -1)
return|return
operator|(
name|__mmask32
operator|)
name|_mm_cmpneq_epu16_mask
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
name|test_mm_mask_cmpneq_epu16_mask
parameter_list|(
name|__mmask32
name|__u
parameter_list|,
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cmpneq_epu16_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.w.128(<8 x i16> {{.*}},<8 x i16> {{.*}}, i32 4, i8 {{.*}})
return|return
operator|(
name|__mmask32
operator|)
name|_mm_mask_cmpneq_epu16_mask
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
name|__mmask32
name|test_mm256_cmpneq_epi8_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmpneq_epi8_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.b.256(<32 x i8> {{.*}},<32 x i8> {{.*}}, i32 4, i32 -1)
return|return
operator|(
name|__mmask64
operator|)
name|_mm256_cmpneq_epi8_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask32
name|test_mm256_mask_cmpneq_epi8_mask
parameter_list|(
name|__mmask64
name|__u
parameter_list|,
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmpneq_epi8_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.b.256(<32 x i8> {{.*}},<32 x i8> {{.*}}, i32 4, i32 {{.*}})
return|return
operator|(
name|__mmask64
operator|)
name|_mm256_mask_cmpneq_epi8_mask
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
name|__mmask32
name|test_mm256_cmpneq_epu8_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmpneq_epu8_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.b.256(<32 x i8> {{.*}},<32 x i8> {{.*}}, i32 4, i32 -1)
return|return
operator|(
name|__mmask64
operator|)
name|_mm256_cmpneq_epu8_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask32
name|test_mm256_mask_cmpneq_epu8_mask
parameter_list|(
name|__mmask64
name|__u
parameter_list|,
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmpneq_epu8_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.b.256(<32 x i8> {{.*}},<32 x i8> {{.*}}, i32 4, i32 {{.*}})
return|return
operator|(
name|__mmask64
operator|)
name|_mm256_mask_cmpneq_epu8_mask
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
name|test_mm256_cmpneq_epi16_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmpneq_epi16_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.w.256(<16 x i16> {{.*}},<16 x i16> {{.*}}, i32 4, i16 -1)
return|return
operator|(
name|__mmask32
operator|)
name|_mm256_cmpneq_epi16_mask
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
name|test_mm256_mask_cmpneq_epi16_mask
parameter_list|(
name|__mmask32
name|__u
parameter_list|,
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmpneq_epi16_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.w.256(<16 x i16> {{.*}},<16 x i16> {{.*}}, i32 4, i16 {{.*}})
return|return
operator|(
name|__mmask32
operator|)
name|_mm256_mask_cmpneq_epi16_mask
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
name|test_mm256_cmpneq_epu16_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmpneq_epu16_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.w.256(<16 x i16> {{.*}},<16 x i16> {{.*}}, i32 4, i16 -1)
return|return
operator|(
name|__mmask32
operator|)
name|_mm256_cmpneq_epu16_mask
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
name|test_mm256_mask_cmpneq_epu16_mask
parameter_list|(
name|__mmask32
name|__u
parameter_list|,
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmpneq_epu16_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.w.256(<16 x i16> {{.*}},<16 x i16> {{.*}}, i32 4, i16 {{.*}})
return|return
operator|(
name|__mmask32
operator|)
name|_mm256_mask_cmpneq_epu16_mask
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
name|test_mm_cmp_epi8_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmp_epi8_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.b.128(<16 x i8> {{.*}},<16 x i8> {{.*}}, i32 7, i16 -1)
return|return
operator|(
name|__mmask64
operator|)
name|_mm_cmp_epi8_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm_mask_cmp_epi8_mask
parameter_list|(
name|__mmask64
name|__u
parameter_list|,
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cmp_epi8_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.b.128(<16 x i8> {{.*}},<16 x i8> {{.*}}, i32 7, i16 {{.*}})
return|return
operator|(
name|__mmask64
operator|)
name|_mm_mask_cmp_epi8_mask
argument_list|(
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm_cmp_epu8_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmp_epu8_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.b.128(<16 x i8> {{.*}},<16 x i8> {{.*}}, i32 7, i16 -1)
return|return
operator|(
name|__mmask64
operator|)
name|_mm_cmp_epu8_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm_mask_cmp_epu8_mask
parameter_list|(
name|__mmask64
name|__u
parameter_list|,
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cmp_epu8_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.b.128(<16 x i8> {{.*}},<16 x i8> {{.*}}, i32 7, i16 {{.*}})
return|return
operator|(
name|__mmask64
operator|)
name|_mm_mask_cmp_epu8_mask
argument_list|(
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm_cmp_epi16_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmp_epi16_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.w.128(<8 x i16> {{.*}},<8 x i16> {{.*}}, i32 7, i8 -1)
return|return
operator|(
name|__mmask32
operator|)
name|_mm_cmp_epi16_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm_mask_cmp_epi16_mask
parameter_list|(
name|__mmask32
name|__u
parameter_list|,
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cmp_epi16_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.w.128(<8 x i16> {{.*}},<8 x i16> {{.*}}, i32 7, i8 {{.*}})
return|return
operator|(
name|__mmask32
operator|)
name|_mm_mask_cmp_epi16_mask
argument_list|(
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm_cmp_epu16_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmp_epu16_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.w.128(<8 x i16> {{.*}},<8 x i16> {{.*}}, i32 7, i8 -1)
return|return
operator|(
name|__mmask32
operator|)
name|_mm_cmp_epu16_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm_mask_cmp_epu16_mask
parameter_list|(
name|__mmask32
name|__u
parameter_list|,
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cmp_epu16_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.w.128(<8 x i16> {{.*}},<8 x i16> {{.*}}, i32 7, i8 {{.*}})
return|return
operator|(
name|__mmask32
operator|)
name|_mm_mask_cmp_epu16_mask
argument_list|(
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask32
name|test_mm256_cmp_epi8_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmp_epi8_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.b.256(<32 x i8> {{.*}},<32 x i8> {{.*}}, i32 7, i32 -1)
return|return
operator|(
name|__mmask64
operator|)
name|_mm256_cmp_epi8_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask32
name|test_mm256_mask_cmp_epi8_mask
parameter_list|(
name|__mmask64
name|__u
parameter_list|,
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmp_epi8_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.b.256(<32 x i8> {{.*}},<32 x i8> {{.*}}, i32 7, i32 {{.*}})
return|return
operator|(
name|__mmask64
operator|)
name|_mm256_mask_cmp_epi8_mask
argument_list|(
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask32
name|test_mm256_cmp_epu8_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmp_epu8_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.b.256(<32 x i8> {{.*}},<32 x i8> {{.*}}, i32 7, i32 -1)
return|return
operator|(
name|__mmask64
operator|)
name|_mm256_cmp_epu8_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask32
name|test_mm256_mask_cmp_epu8_mask
parameter_list|(
name|__mmask64
name|__u
parameter_list|,
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmp_epu8_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.b.256(<32 x i8> {{.*}},<32 x i8> {{.*}}, i32 7, i32 {{.*}})
return|return
operator|(
name|__mmask64
operator|)
name|_mm256_mask_cmp_epu8_mask
argument_list|(
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm256_cmp_epi16_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmp_epi16_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.w.256(<16 x i16> {{.*}},<16 x i16> {{.*}}, i32 7, i16 -1)
return|return
operator|(
name|__mmask32
operator|)
name|_mm256_cmp_epi16_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm256_mask_cmp_epi16_mask
parameter_list|(
name|__mmask32
name|__u
parameter_list|,
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmp_epi16_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.w.256(<16 x i16> {{.*}},<16 x i16> {{.*}}, i32 7, i16 {{.*}})
return|return
operator|(
name|__mmask32
operator|)
name|_mm256_mask_cmp_epi16_mask
argument_list|(
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm256_cmp_epu16_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmp_epu16_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.w.256(<16 x i16> {{.*}},<16 x i16> {{.*}}, i32 7, i16 -1)
return|return
operator|(
name|__mmask32
operator|)
name|_mm256_cmp_epu16_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm256_mask_cmp_epu16_mask
parameter_list|(
name|__mmask32
name|__u
parameter_list|,
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmp_epu16_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.w.256(<16 x i16> {{.*}},<16 x i16> {{.*}}, i32 7, i16 {{.*}})
return|return
operator|(
name|__mmask32
operator|)
name|_mm256_mask_cmp_epu16_mask
argument_list|(
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_add_epi8
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask32
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm256_mask_add_epi8
comment|//CHECK: @llvm.x86.avx512.mask.padd.b.256
return|return
name|_mm256_mask_add_epi8
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
name|__m256i
name|test_mm256_maskz_add_epi8
parameter_list|(
name|__mmask32
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm256_maskz_add_epi8
comment|//CHECK: @llvm.x86.avx512.mask.padd.b.256
return|return
name|_mm256_maskz_add_epi8
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
name|__m256i
name|test_mm256_mask_add_epi16
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm256_mask_add_epi16
comment|//CHECK: @llvm.x86.avx512.mask.padd.w.256
return|return
name|_mm256_mask_add_epi16
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
name|__m256i
name|test_mm256_maskz_add_epi16
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm256_maskz_add_epi16
comment|//CHECK: @llvm.x86.avx512.mask.padd.w.256
return|return
name|_mm256_maskz_add_epi16
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
name|__m256i
name|test_mm256_mask_sub_epi8
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask32
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm256_mask_sub_epi8
comment|//CHECK: @llvm.x86.avx512.mask.psub.b.256
return|return
name|_mm256_mask_sub_epi8
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
name|__m256i
name|test_mm256_maskz_sub_epi8
parameter_list|(
name|__mmask32
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm256_maskz_sub_epi8
comment|//CHECK: @llvm.x86.avx512.mask.psub.b.256
return|return
name|_mm256_maskz_sub_epi8
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
name|__m256i
name|test_mm256_mask_sub_epi16
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm256_mask_sub_epi16
comment|//CHECK: @llvm.x86.avx512.mask.psub.w.256
return|return
name|_mm256_mask_sub_epi16
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
name|__m256i
name|test_mm256_maskz_sub_epi16
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm256_maskz_sub_epi16
comment|//CHECK: @llvm.x86.avx512.mask.psub.w.256
return|return
name|_mm256_maskz_sub_epi16
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
name|__m128i
name|test_mm_mask_add_epi8
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm_mask_add_epi8
comment|//CHECK: @llvm.x86.avx512.mask.padd.b.128
return|return
name|_mm_mask_add_epi8
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
name|__m128i
name|test_mm_maskz_add_epi8
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm_maskz_add_epi8
comment|//CHECK: @llvm.x86.avx512.mask.padd.b.128
return|return
name|_mm_maskz_add_epi8
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
name|__m128i
name|test_mm_mask_add_epi16
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm_mask_add_epi16
comment|//CHECK: @llvm.x86.avx512.mask.padd.w.128
return|return
name|_mm_mask_add_epi16
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
name|__m128i
name|test_mm_maskz_add_epi16
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm_maskz_add_epi16
comment|//CHECK: @llvm.x86.avx512.mask.padd.w.128
return|return
name|_mm_maskz_add_epi16
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
name|__m128i
name|test_mm_mask_sub_epi8
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm_mask_sub_epi8
comment|//CHECK: @llvm.x86.avx512.mask.psub.b.128
return|return
name|_mm_mask_sub_epi8
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
name|__m128i
name|test_mm_maskz_sub_epi8
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm_maskz_sub_epi8
comment|//CHECK: @llvm.x86.avx512.mask.psub.b.128
return|return
name|_mm_maskz_sub_epi8
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
name|__m128i
name|test_mm_mask_sub_epi16
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm_mask_sub_epi16
comment|//CHECK: @llvm.x86.avx512.mask.psub.w.128
return|return
name|_mm_mask_sub_epi16
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
name|__m128i
name|test_mm_maskz_sub_epi16
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm_maskz_sub_epi16
comment|//CHECK: @llvm.x86.avx512.mask.psub.w.128
return|return
name|_mm_maskz_sub_epi16
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
name|__m256i
name|test_mm256_mask_mullo_epi16
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm256_mask_mullo_epi16
comment|//CHECK: @llvm.x86.avx512.mask.pmull.w.256
return|return
name|_mm256_mask_mullo_epi16
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
name|__m256i
name|test_mm256_maskz_mullo_epi16
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm256_maskz_mullo_epi16
comment|//CHECK: @llvm.x86.avx512.mask.pmull.w.256
return|return
name|_mm256_maskz_mullo_epi16
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
name|__m128i
name|test_mm_mask_mullo_epi16
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm_mask_mullo_epi16
comment|//CHECK: @llvm.x86.avx512.mask.pmull.w.128
return|return
name|_mm_mask_mullo_epi16
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
name|__m128i
name|test_mm_maskz_mullo_epi16
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm_maskz_mullo_epi16
comment|//CHECK: @llvm.x86.avx512.mask.pmull.w.128
return|return
name|_mm_maskz_mullo_epi16
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

end_unit

