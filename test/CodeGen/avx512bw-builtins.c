begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -triple=x86_64-apple-darwin -target-feature +avx512bw -emit-llvm -o - -Werror | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -triple=x86_64-apple-darwin -target-feature +avx512bw -fno-signed-char -emit-llvm -o - -Werror | FileCheck %s
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
name|__mmask64
name|test_mm512_cmpeq_epi8_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpeq_epi8_mask
comment|// CHECK: @llvm.x86.avx512.mask.pcmpeq.b.512
return|return
operator|(
name|__mmask64
operator|)
name|_mm512_cmpeq_epi8_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask64
name|test_mm512_mask_cmpeq_epi8_mask
parameter_list|(
name|__mmask64
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpeq_epi8_mask
comment|// CHECK: @llvm.x86.avx512.mask.pcmpeq.b.512
return|return
operator|(
name|__mmask64
operator|)
name|_mm512_mask_cmpeq_epi8_mask
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
name|test_mm512_cmpeq_epi16_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpeq_epi16_mask
comment|// CHECK: @llvm.x86.avx512.mask.pcmpeq.w.512
return|return
operator|(
name|__mmask32
operator|)
name|_mm512_cmpeq_epi16_mask
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
name|test_mm512_mask_cmpeq_epi16_mask
parameter_list|(
name|__mmask32
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpeq_epi16_mask
comment|// CHECK: @llvm.x86.avx512.mask.pcmpeq.w.512
return|return
operator|(
name|__mmask32
operator|)
name|_mm512_mask_cmpeq_epi16_mask
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
name|__mmask64
name|test_mm512_cmpgt_epi8_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpgt_epi8_mask
comment|// CHECK: @llvm.x86.avx512.mask.pcmpgt.b.512
return|return
operator|(
name|__mmask64
operator|)
name|_mm512_cmpgt_epi8_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask64
name|test_mm512_mask_cmpgt_epi8_mask
parameter_list|(
name|__mmask64
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpgt_epi8_mask
comment|// CHECK: @llvm.x86.avx512.mask.pcmpgt.b.512
return|return
operator|(
name|__mmask64
operator|)
name|_mm512_mask_cmpgt_epi8_mask
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
name|test_mm512_cmpgt_epi16_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpgt_epi16_mask
comment|// CHECK: @llvm.x86.avx512.mask.pcmpgt.w.512
return|return
operator|(
name|__mmask32
operator|)
name|_mm512_cmpgt_epi16_mask
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
name|test_mm512_mask_cmpgt_epi16_mask
parameter_list|(
name|__mmask32
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpgt_epi16_mask
comment|// CHECK: @llvm.x86.avx512.mask.pcmpgt.w.512
return|return
operator|(
name|__mmask32
operator|)
name|_mm512_mask_cmpgt_epi16_mask
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
name|__mmask64
name|test_mm512_cmpeq_epu8_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpeq_epu8_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.b.512(<64 x i8> {{.*}},<64 x i8> {{.*}}, i32 0, i64 -1)
return|return
operator|(
name|__mmask64
operator|)
name|_mm512_cmpeq_epu8_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask64
name|test_mm512_mask_cmpeq_epu8_mask
parameter_list|(
name|__mmask64
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpeq_epu8_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.b.512(<64 x i8> {{.*}},<64 x i8> {{.*}}, i32 0, i64 {{.*}})
return|return
operator|(
name|__mmask64
operator|)
name|_mm512_mask_cmpeq_epu8_mask
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
name|test_mm512_cmpeq_epu16_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpeq_epu16_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.w.512(<32 x i16> {{.*}},<32 x i16> {{.*}}, i32 0, i32 -1)
return|return
operator|(
name|__mmask32
operator|)
name|_mm512_cmpeq_epu16_mask
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
name|test_mm512_mask_cmpeq_epu16_mask
parameter_list|(
name|__mmask32
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpeq_epu16_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.w.512(<32 x i16> {{.*}},<32 x i16> {{.*}}, i32 0, i32 {{.*}})
return|return
operator|(
name|__mmask32
operator|)
name|_mm512_mask_cmpeq_epu16_mask
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
name|__mmask64
name|test_mm512_cmpgt_epu8_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpgt_epu8_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.b.512(<64 x i8> {{.*}},<64 x i8> {{.*}}, i32 6, i64 -1)
return|return
operator|(
name|__mmask64
operator|)
name|_mm512_cmpgt_epu8_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask64
name|test_mm512_mask_cmpgt_epu8_mask
parameter_list|(
name|__mmask64
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpgt_epu8_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.b.512(<64 x i8> {{.*}},<64 x i8> {{.*}}, i32 6, i64 {{.*}})
return|return
operator|(
name|__mmask64
operator|)
name|_mm512_mask_cmpgt_epu8_mask
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
name|test_mm512_cmpgt_epu16_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpgt_epu16_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.w.512(<32 x i16> {{.*}},<32 x i16> {{.*}}, i32 6, i32 -1)
return|return
operator|(
name|__mmask32
operator|)
name|_mm512_cmpgt_epu16_mask
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
name|test_mm512_mask_cmpgt_epu16_mask
parameter_list|(
name|__mmask32
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpgt_epu16_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.w.512(<32 x i16> {{.*}},<32 x i16> {{.*}}, i32 6, i32 {{.*}})
return|return
operator|(
name|__mmask32
operator|)
name|_mm512_mask_cmpgt_epu16_mask
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
name|__mmask64
name|test_mm512_cmpge_epi8_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpge_epi8_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.b.512(<64 x i8> {{.*}},<64 x i8> {{.*}}, i32 5, i64 -1)
return|return
operator|(
name|__mmask64
operator|)
name|_mm512_cmpge_epi8_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask64
name|test_mm512_mask_cmpge_epi8_mask
parameter_list|(
name|__mmask64
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpge_epi8_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.b.512(<64 x i8> {{.*}},<64 x i8> {{.*}}, i32 5, i64 {{.*}})
return|return
operator|(
name|__mmask64
operator|)
name|_mm512_mask_cmpge_epi8_mask
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
name|__mmask64
name|test_mm512_cmpge_epu8_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpge_epu8_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.b.512(<64 x i8> {{.*}},<64 x i8> {{.*}}, i32 5, i64 -1)
return|return
operator|(
name|__mmask64
operator|)
name|_mm512_cmpge_epu8_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask64
name|test_mm512_mask_cmpge_epu8_mask
parameter_list|(
name|__mmask64
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpge_epu8_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.b.512(<64 x i8> {{.*}},<64 x i8> {{.*}}, i32 5, i64 {{.*}})
return|return
operator|(
name|__mmask64
operator|)
name|_mm512_mask_cmpge_epu8_mask
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
name|test_mm512_cmpge_epi16_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpge_epi16_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.w.512(<32 x i16> {{.*}},<32 x i16> {{.*}}, i32 5, i32 -1)
return|return
operator|(
name|__mmask32
operator|)
name|_mm512_cmpge_epi16_mask
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
name|test_mm512_mask_cmpge_epi16_mask
parameter_list|(
name|__mmask32
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpge_epi16_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.w.512(<32 x i16> {{.*}},<32 x i16> {{.*}}, i32 5, i32 {{.*}})
return|return
operator|(
name|__mmask32
operator|)
name|_mm512_mask_cmpge_epi16_mask
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
name|test_mm512_cmpge_epu16_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpge_epu16_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.w.512(<32 x i16> {{.*}},<32 x i16> {{.*}}, i32 5, i32 -1)
return|return
operator|(
name|__mmask32
operator|)
name|_mm512_cmpge_epu16_mask
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
name|test_mm512_mask_cmpge_epu16_mask
parameter_list|(
name|__mmask32
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpge_epu16_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.w.512(<32 x i16> {{.*}},<32 x i16> {{.*}}, i32 5, i32 {{.*}})
return|return
operator|(
name|__mmask32
operator|)
name|_mm512_mask_cmpge_epu16_mask
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
name|__mmask64
name|test_mm512_cmple_epi8_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmple_epi8_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.b.512(<64 x i8> {{.*}},<64 x i8> {{.*}}, i32 2, i64 -1)
return|return
operator|(
name|__mmask64
operator|)
name|_mm512_cmple_epi8_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask64
name|test_mm512_mask_cmple_epi8_mask
parameter_list|(
name|__mmask64
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmple_epi8_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.b.512(<64 x i8> {{.*}},<64 x i8> {{.*}}, i32 2, i64 {{.*}})
return|return
operator|(
name|__mmask64
operator|)
name|_mm512_mask_cmple_epi8_mask
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
name|__mmask64
name|test_mm512_cmple_epu8_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmple_epu8_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.b.512(<64 x i8> {{.*}},<64 x i8> {{.*}}, i32 2, i64 -1)
return|return
operator|(
name|__mmask64
operator|)
name|_mm512_cmple_epu8_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask64
name|test_mm512_mask_cmple_epu8_mask
parameter_list|(
name|__mmask64
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmple_epu8_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.b.512(<64 x i8> {{.*}},<64 x i8> {{.*}}, i32 2, i64 {{.*}})
return|return
operator|(
name|__mmask64
operator|)
name|_mm512_mask_cmple_epu8_mask
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
name|test_mm512_cmple_epi16_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmple_epi16_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.w.512(<32 x i16> {{.*}},<32 x i16> {{.*}}, i32 2, i32 -1)
return|return
operator|(
name|__mmask32
operator|)
name|_mm512_cmple_epi16_mask
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
name|test_mm512_mask_cmple_epi16_mask
parameter_list|(
name|__mmask32
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmple_epi16_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.w.512(<32 x i16> {{.*}},<32 x i16> {{.*}}, i32 2, i32 {{.*}})
return|return
operator|(
name|__mmask32
operator|)
name|_mm512_mask_cmple_epi16_mask
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
name|test_mm512_cmple_epu16_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmple_epu16_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.w.512(<32 x i16> {{.*}},<32 x i16> {{.*}}, i32 2, i32 -1)
return|return
operator|(
name|__mmask32
operator|)
name|_mm512_cmple_epu16_mask
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
name|test_mm512_mask_cmple_epu16_mask
parameter_list|(
name|__mmask32
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmple_epu16_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.w.512(<32 x i16> {{.*}},<32 x i16> {{.*}}, i32 2, i32 {{.*}})
return|return
operator|(
name|__mmask32
operator|)
name|_mm512_mask_cmple_epu16_mask
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
name|__mmask64
name|test_mm512_cmplt_epi8_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmplt_epi8_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.b.512(<64 x i8> {{.*}},<64 x i8> {{.*}}, i32 1, i64 -1)
return|return
operator|(
name|__mmask64
operator|)
name|_mm512_cmplt_epi8_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask64
name|test_mm512_mask_cmplt_epi8_mask
parameter_list|(
name|__mmask64
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmplt_epi8_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.b.512(<64 x i8> {{.*}},<64 x i8> {{.*}}, i32 1, i64 {{.*}})
return|return
operator|(
name|__mmask64
operator|)
name|_mm512_mask_cmplt_epi8_mask
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
name|__mmask64
name|test_mm512_cmplt_epu8_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmplt_epu8_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.b.512(<64 x i8> {{.*}},<64 x i8> {{.*}}, i32 1, i64 -1)
return|return
operator|(
name|__mmask64
operator|)
name|_mm512_cmplt_epu8_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask64
name|test_mm512_mask_cmplt_epu8_mask
parameter_list|(
name|__mmask64
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmplt_epu8_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.b.512(<64 x i8> {{.*}},<64 x i8> {{.*}}, i32 1, i64 {{.*}})
return|return
operator|(
name|__mmask64
operator|)
name|_mm512_mask_cmplt_epu8_mask
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
name|test_mm512_cmplt_epi16_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmplt_epi16_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.w.512(<32 x i16> {{.*}},<32 x i16> {{.*}}, i32 1, i32 -1)
return|return
operator|(
name|__mmask32
operator|)
name|_mm512_cmplt_epi16_mask
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
name|test_mm512_mask_cmplt_epi16_mask
parameter_list|(
name|__mmask32
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmplt_epi16_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.w.512(<32 x i16> {{.*}},<32 x i16> {{.*}}, i32 1, i32 {{.*}})
return|return
operator|(
name|__mmask32
operator|)
name|_mm512_mask_cmplt_epi16_mask
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
name|test_mm512_cmplt_epu16_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmplt_epu16_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.w.512(<32 x i16> {{.*}},<32 x i16> {{.*}}, i32 1, i32 -1)
return|return
operator|(
name|__mmask32
operator|)
name|_mm512_cmplt_epu16_mask
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
name|test_mm512_mask_cmplt_epu16_mask
parameter_list|(
name|__mmask32
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmplt_epu16_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.w.512(<32 x i16> {{.*}},<32 x i16> {{.*}}, i32 1, i32 {{.*}})
return|return
operator|(
name|__mmask32
operator|)
name|_mm512_mask_cmplt_epu16_mask
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
name|__mmask64
name|test_mm512_cmpneq_epi8_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpneq_epi8_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.b.512(<64 x i8> {{.*}},<64 x i8> {{.*}}, i32 4, i64 -1)
return|return
operator|(
name|__mmask64
operator|)
name|_mm512_cmpneq_epi8_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask64
name|test_mm512_mask_cmpneq_epi8_mask
parameter_list|(
name|__mmask64
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpneq_epi8_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.b.512(<64 x i8> {{.*}},<64 x i8> {{.*}}, i32 4, i64 {{.*}})
return|return
operator|(
name|__mmask64
operator|)
name|_mm512_mask_cmpneq_epi8_mask
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
name|__mmask64
name|test_mm512_cmpneq_epu8_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpneq_epu8_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.b.512(<64 x i8> {{.*}},<64 x i8> {{.*}}, i32 4, i64 -1)
return|return
operator|(
name|__mmask64
operator|)
name|_mm512_cmpneq_epu8_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask64
name|test_mm512_mask_cmpneq_epu8_mask
parameter_list|(
name|__mmask64
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpneq_epu8_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.b.512(<64 x i8> {{.*}},<64 x i8> {{.*}}, i32 4, i64 {{.*}})
return|return
operator|(
name|__mmask64
operator|)
name|_mm512_mask_cmpneq_epu8_mask
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
name|test_mm512_cmpneq_epi16_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpneq_epi16_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.w.512(<32 x i16> {{.*}},<32 x i16> {{.*}}, i32 4, i32 -1)
return|return
operator|(
name|__mmask32
operator|)
name|_mm512_cmpneq_epi16_mask
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
name|test_mm512_mask_cmpneq_epi16_mask
parameter_list|(
name|__mmask32
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpneq_epi16_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.w.512(<32 x i16> {{.*}},<32 x i16> {{.*}}, i32 4, i32 {{.*}})
return|return
operator|(
name|__mmask32
operator|)
name|_mm512_mask_cmpneq_epi16_mask
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
name|test_mm512_cmpneq_epu16_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpneq_epu16_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.w.512(<32 x i16> {{.*}},<32 x i16> {{.*}}, i32 4, i32 -1)
return|return
operator|(
name|__mmask32
operator|)
name|_mm512_cmpneq_epu16_mask
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
name|test_mm512_mask_cmpneq_epu16_mask
parameter_list|(
name|__mmask32
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpneq_epu16_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.w.512(<32 x i16> {{.*}},<32 x i16> {{.*}}, i32 4, i32 {{.*}})
return|return
operator|(
name|__mmask32
operator|)
name|_mm512_mask_cmpneq_epu16_mask
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
name|__mmask64
name|test_mm512_cmp_epi8_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmp_epi8_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.b.512(<64 x i8> {{.*}},<64 x i8> {{.*}}, i32 7, i64 -1)
return|return
operator|(
name|__mmask64
operator|)
name|_mm512_cmp_epi8_mask
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
name|__mmask64
name|test_mm512_mask_cmp_epi8_mask
parameter_list|(
name|__mmask64
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmp_epi8_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.b.512(<64 x i8> {{.*}},<64 x i8> {{.*}}, i32 7, i64 {{.*}})
return|return
operator|(
name|__mmask64
operator|)
name|_mm512_mask_cmp_epi8_mask
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
name|__mmask64
name|test_mm512_cmp_epu8_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmp_epu8_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.b.512(<64 x i8> {{.*}},<64 x i8> {{.*}}, i32 7, i64 -1)
return|return
operator|(
name|__mmask64
operator|)
name|_mm512_cmp_epu8_mask
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
name|__mmask64
name|test_mm512_mask_cmp_epu8_mask
parameter_list|(
name|__mmask64
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmp_epu8_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.b.512(<64 x i8> {{.*}},<64 x i8> {{.*}}, i32 7, i64 {{.*}})
return|return
operator|(
name|__mmask64
operator|)
name|_mm512_mask_cmp_epu8_mask
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
name|test_mm512_cmp_epi16_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmp_epi16_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.w.512(<32 x i16> {{.*}},<32 x i16> {{.*}}, i32 7, i32 -1)
return|return
operator|(
name|__mmask32
operator|)
name|_mm512_cmp_epi16_mask
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
name|test_mm512_mask_cmp_epi16_mask
parameter_list|(
name|__mmask32
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmp_epi16_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.w.512(<32 x i16> {{.*}},<32 x i16> {{.*}}, i32 7, i32 {{.*}})
return|return
operator|(
name|__mmask32
operator|)
name|_mm512_mask_cmp_epi16_mask
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
name|test_mm512_cmp_epu16_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmp_epu16_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.w.512(<32 x i16> {{.*}},<32 x i16> {{.*}}, i32 7, i32 -1)
return|return
operator|(
name|__mmask32
operator|)
name|_mm512_cmp_epu16_mask
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
name|test_mm512_mask_cmp_epu16_mask
parameter_list|(
name|__mmask32
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmp_epu16_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.w.512(<32 x i16> {{.*}},<32 x i16> {{.*}}, i32 7, i32 {{.*}})
return|return
operator|(
name|__mmask32
operator|)
name|_mm512_mask_cmp_epu16_mask
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
name|__m512i
name|test_mm512_add_epi8
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_add_epi8
comment|//CHECK: add<64 x i8>
return|return
name|_mm512_add_epi8
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
name|test_mm512_mask_add_epi8
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask64
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_mask_add_epi8
comment|//CHECK: @llvm.x86.avx512.mask.padd.b.512
return|return
name|_mm512_mask_add_epi8
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
name|test_mm512_maskz_add_epi8
parameter_list|(
name|__mmask64
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_maskz_add_epi8
comment|//CHECK: @llvm.x86.avx512.mask.padd.b.512
return|return
name|_mm512_maskz_add_epi8
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
name|test_mm512_sub_epi8
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_sub_epi8
comment|//CHECK: sub<64 x i8>
return|return
name|_mm512_sub_epi8
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
name|test_mm512_mask_sub_epi8
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask64
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_mask_sub_epi8
comment|//CHECK: @llvm.x86.avx512.mask.psub.b.512
return|return
name|_mm512_mask_sub_epi8
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
name|test_mm512_maskz_sub_epi8
parameter_list|(
name|__mmask64
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_maskz_sub_epi8
comment|//CHECK: @llvm.x86.avx512.mask.psub.b.512
return|return
name|_mm512_maskz_sub_epi8
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
name|test_mm512_add_epi16
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_add_epi16
comment|//CHECK: add<32 x i16>
return|return
name|_mm512_add_epi16
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
name|test_mm512_mask_add_epi16
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask32
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_mask_add_epi16
comment|//CHECK: @llvm.x86.avx512.mask.padd.w.512
return|return
name|_mm512_mask_add_epi16
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
name|test_mm512_maskz_add_epi16
parameter_list|(
name|__mmask32
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_maskz_add_epi16
comment|//CHECK: @llvm.x86.avx512.mask.padd.w.512
return|return
name|_mm512_maskz_add_epi16
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
name|test_mm512_sub_epi16
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_sub_epi16
comment|//CHECK: sub<32 x i16>
return|return
name|_mm512_sub_epi16
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
name|test_mm512_mask_sub_epi16
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask32
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_mask_sub_epi16
comment|//CHECK: @llvm.x86.avx512.mask.psub.w.512
return|return
name|_mm512_mask_sub_epi16
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
name|test_mm512_maskz_sub_epi16
parameter_list|(
name|__mmask32
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_maskz_sub_epi16
comment|//CHECK: @llvm.x86.avx512.mask.psub.w.512
return|return
name|_mm512_maskz_sub_epi16
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
name|test_mm512_mullo_epi16
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_mullo_epi16
comment|//CHECK: mul<32 x i16>
return|return
name|_mm512_mullo_epi16
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
name|test_mm512_mask_mullo_epi16
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask32
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_mask_mullo_epi16
comment|//CHECK: @llvm.x86.avx512.mask.pmull.w.512
return|return
name|_mm512_mask_mullo_epi16
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
name|test_mm512_maskz_mullo_epi16
parameter_list|(
name|__mmask32
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_maskz_mullo_epi16
comment|//CHECK: @llvm.x86.avx512.mask.pmull.w.512
return|return
name|_mm512_maskz_mullo_epi16
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
name|test_mm512_mask_blend_epi8
parameter_list|(
name|__mmask64
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__W
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_blend_epi8
comment|// CHECK: @llvm.x86.avx512.mask.blend.b.512
return|return
name|_mm512_mask_blend_epi8
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__W
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_blend_epi16
parameter_list|(
name|__mmask32
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__W
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_blend_epi16
comment|// CHECK: @llvm.x86.avx512.mask.blend.w.512
return|return
name|_mm512_mask_blend_epi16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__W
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_abs_epi8
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_abs_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pabs.b.512
return|return
name|_mm512_abs_epi8
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_abs_epi8
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask64
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_abs_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pabs.b.512
return|return
name|_mm512_mask_abs_epi8
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
name|test_mm512_maskz_abs_epi8
parameter_list|(
name|__mmask64
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_abs_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pabs.b.512
return|return
name|_mm512_maskz_abs_epi8
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
name|test_mm512_abs_epi16
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_abs_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pabs.w.512
return|return
name|_mm512_abs_epi16
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_abs_epi16
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask32
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_abs_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pabs.w.512
return|return
name|_mm512_mask_abs_epi16
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
name|test_mm512_maskz_abs_epi16
parameter_list|(
name|__mmask32
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_abs_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pabs.w.512
return|return
name|_mm512_maskz_abs_epi16
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
name|test_mm512_packs_epi32
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_packs_epi32
comment|// CHECK: @llvm.x86.avx512.mask.packssdw.512
return|return
name|_mm512_packs_epi32
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
name|test_mm512_maskz_packs_epi32
parameter_list|(
name|__mmask32
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_packs_epi32
comment|// CHECK: @llvm.x86.avx512.mask.packssdw.512
return|return
name|_mm512_maskz_packs_epi32
argument_list|(
name|__M
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
name|test_mm512_mask_packs_epi32
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask32
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_packs_epi32
comment|// CHECK: @llvm.x86.avx512.mask.packssdw.512
return|return
name|_mm512_mask_packs_epi32
argument_list|(
name|__W
argument_list|,
name|__M
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
name|test_mm512_packs_epi16
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_packs_epi16
comment|// CHECK: @llvm.x86.avx512.mask.packsswb.512
return|return
name|_mm512_packs_epi16
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
name|test_mm512_mask_packs_epi16
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask64
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_packs_epi16
comment|// CHECK: @llvm.x86.avx512.mask.packsswb.512
return|return
name|_mm512_mask_packs_epi16
argument_list|(
name|__W
argument_list|,
name|__M
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
name|test_mm512_maskz_packs_epi16
parameter_list|(
name|__mmask64
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_packs_epi16
comment|// CHECK: @llvm.x86.avx512.mask.packsswb.512
return|return
name|_mm512_maskz_packs_epi16
argument_list|(
name|__M
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
name|test_mm512_packus_epi32
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_packus_epi32
comment|// CHECK: @llvm.x86.avx512.mask.packusdw.512
return|return
name|_mm512_packus_epi32
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
name|test_mm512_maskz_packus_epi32
parameter_list|(
name|__mmask32
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_packus_epi32
comment|// CHECK: @llvm.x86.avx512.mask.packusdw.512
return|return
name|_mm512_maskz_packus_epi32
argument_list|(
name|__M
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
name|test_mm512_mask_packus_epi32
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask32
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_packus_epi32
comment|// CHECK: @llvm.x86.avx512.mask.packusdw.512
return|return
name|_mm512_mask_packus_epi32
argument_list|(
name|__W
argument_list|,
name|__M
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
name|test_mm512_packus_epi16
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_packus_epi16
comment|// CHECK: @llvm.x86.avx512.mask.packuswb.512
return|return
name|_mm512_packus_epi16
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
name|test_mm512_mask_packus_epi16
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask64
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_packus_epi16
comment|// CHECK: @llvm.x86.avx512.mask.packuswb.512
return|return
name|_mm512_mask_packus_epi16
argument_list|(
name|__W
argument_list|,
name|__M
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
name|test_mm512_maskz_packus_epi16
parameter_list|(
name|__mmask64
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_packus_epi16
comment|// CHECK: @llvm.x86.avx512.mask.packuswb.512
return|return
name|_mm512_maskz_packus_epi16
argument_list|(
name|__M
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
name|test_mm512_adds_epi8
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_adds_epi8
comment|// CHECK: @llvm.x86.avx512.mask.padds.b.512
return|return
name|_mm512_adds_epi8
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
name|test_mm512_mask_adds_epi8
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask64
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_adds_epi8
comment|// CHECK: @llvm.x86.avx512.mask.padds.b.512
return|return
name|_mm512_mask_adds_epi8
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
name|test_mm512_maskz_adds_epi8
parameter_list|(
name|__mmask64
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_adds_epi8
comment|// CHECK: @llvm.x86.avx512.mask.padds.b.512
return|return
name|_mm512_maskz_adds_epi8
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
name|test_mm512_adds_epi16
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_adds_epi16
comment|// CHECK: @llvm.x86.avx512.mask.padds.w.512
return|return
name|_mm512_adds_epi16
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
name|test_mm512_mask_adds_epi16
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask32
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_adds_epi16
comment|// CHECK: @llvm.x86.avx512.mask.padds.w.512
return|return
name|_mm512_mask_adds_epi16
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
name|test_mm512_maskz_adds_epi16
parameter_list|(
name|__mmask32
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_adds_epi16
comment|// CHECK: @llvm.x86.avx512.mask.padds.w.512
return|return
name|_mm512_maskz_adds_epi16
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
name|test_mm512_adds_epu8
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_adds_epu8
comment|// CHECK: @llvm.x86.avx512.mask.paddus.b.512
return|return
name|_mm512_adds_epu8
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
name|test_mm512_mask_adds_epu8
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask64
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_adds_epu8
comment|// CHECK: @llvm.x86.avx512.mask.paddus.b.512
return|return
name|_mm512_mask_adds_epu8
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
name|test_mm512_maskz_adds_epu8
parameter_list|(
name|__mmask64
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_adds_epu8
comment|// CHECK: @llvm.x86.avx512.mask.paddus.b.512
return|return
name|_mm512_maskz_adds_epu8
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
name|test_mm512_adds_epu16
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_adds_epu16
comment|// CHECK: @llvm.x86.avx512.mask.paddus.w.512
return|return
name|_mm512_adds_epu16
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
name|test_mm512_mask_adds_epu16
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask32
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_adds_epu16
comment|// CHECK: @llvm.x86.avx512.mask.paddus.w.512
return|return
name|_mm512_mask_adds_epu16
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
name|test_mm512_maskz_adds_epu16
parameter_list|(
name|__mmask32
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_adds_epu16
comment|// CHECK: @llvm.x86.avx512.mask.paddus.w.512
return|return
name|_mm512_maskz_adds_epu16
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
name|test_mm512_avg_epu8
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_avg_epu8
comment|// CHECK: @llvm.x86.avx512.mask.pavg.b.512
return|return
name|_mm512_avg_epu8
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
name|test_mm512_mask_avg_epu8
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask64
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_avg_epu8
comment|// CHECK: @llvm.x86.avx512.mask.pavg.b.512
return|return
name|_mm512_mask_avg_epu8
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
name|test_mm512_maskz_avg_epu8
parameter_list|(
name|__mmask64
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_avg_epu8
comment|// CHECK: @llvm.x86.avx512.mask.pavg.b.512
return|return
name|_mm512_maskz_avg_epu8
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
name|test_mm512_avg_epu16
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_avg_epu16
comment|// CHECK: @llvm.x86.avx512.mask.pavg.w.512
return|return
name|_mm512_avg_epu16
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
name|test_mm512_mask_avg_epu16
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask32
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_avg_epu16
comment|// CHECK: @llvm.x86.avx512.mask.pavg.w.512
return|return
name|_mm512_mask_avg_epu16
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
name|test_mm512_maskz_avg_epu16
parameter_list|(
name|__mmask32
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_avg_epu16
comment|// CHECK: @llvm.x86.avx512.mask.pavg.w.512
return|return
name|_mm512_maskz_avg_epu16
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
name|test_mm512_max_epi8
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_max_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmaxs.b.512
return|return
name|_mm512_max_epi8
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
name|test_mm512_maskz_max_epi8
parameter_list|(
name|__mmask64
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_max_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmaxs.b.512
return|return
name|_mm512_maskz_max_epi8
argument_list|(
name|__M
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
name|test_mm512_mask_max_epi8
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask64
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_max_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmaxs.b.512
return|return
name|_mm512_mask_max_epi8
argument_list|(
name|__W
argument_list|,
name|__M
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
name|test_mm512_max_epi16
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_max_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmaxs.w.512
return|return
name|_mm512_max_epi16
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
name|test_mm512_maskz_max_epi16
parameter_list|(
name|__mmask32
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_max_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmaxs.w.512
return|return
name|_mm512_maskz_max_epi16
argument_list|(
name|__M
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
name|test_mm512_mask_max_epi16
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask32
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_max_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmaxs.w.512
return|return
name|_mm512_mask_max_epi16
argument_list|(
name|__W
argument_list|,
name|__M
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
name|test_mm512_max_epu8
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_max_epu8
comment|// CHECK: @llvm.x86.avx512.mask.pmaxu.b.512
return|return
name|_mm512_max_epu8
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
name|test_mm512_maskz_max_epu8
parameter_list|(
name|__mmask64
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_max_epu8
comment|// CHECK: @llvm.x86.avx512.mask.pmaxu.b.512
return|return
name|_mm512_maskz_max_epu8
argument_list|(
name|__M
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
name|test_mm512_mask_max_epu8
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask64
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_max_epu8
comment|// CHECK: @llvm.x86.avx512.mask.pmaxu.b.512
return|return
name|_mm512_mask_max_epu8
argument_list|(
name|__W
argument_list|,
name|__M
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
name|test_mm512_max_epu16
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_max_epu16
comment|// CHECK: @llvm.x86.avx512.mask.pmaxu.w.512
return|return
name|_mm512_max_epu16
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
name|test_mm512_maskz_max_epu16
parameter_list|(
name|__mmask32
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_max_epu16
comment|// CHECK: @llvm.x86.avx512.mask.pmaxu.w.512
return|return
name|_mm512_maskz_max_epu16
argument_list|(
name|__M
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
name|test_mm512_mask_max_epu16
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask32
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_max_epu16
comment|// CHECK: @llvm.x86.avx512.mask.pmaxu.w.512
return|return
name|_mm512_mask_max_epu16
argument_list|(
name|__W
argument_list|,
name|__M
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
name|test_mm512_min_epi8
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_min_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmins.b.512
return|return
name|_mm512_min_epi8
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
name|test_mm512_maskz_min_epi8
parameter_list|(
name|__mmask64
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_min_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmins.b.512
return|return
name|_mm512_maskz_min_epi8
argument_list|(
name|__M
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
name|test_mm512_mask_min_epi8
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask64
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_min_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmins.b.512
return|return
name|_mm512_mask_min_epi8
argument_list|(
name|__W
argument_list|,
name|__M
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
name|test_mm512_min_epi16
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_min_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmins.w.512
return|return
name|_mm512_min_epi16
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
name|test_mm512_maskz_min_epi16
parameter_list|(
name|__mmask32
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_min_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmins.w.512
return|return
name|_mm512_maskz_min_epi16
argument_list|(
name|__M
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
name|test_mm512_mask_min_epi16
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask32
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_min_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmins.w.512
return|return
name|_mm512_mask_min_epi16
argument_list|(
name|__W
argument_list|,
name|__M
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
name|test_mm512_min_epu8
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_min_epu8
comment|// CHECK: @llvm.x86.avx512.mask.pminu.b.512
return|return
name|_mm512_min_epu8
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
name|test_mm512_maskz_min_epu8
parameter_list|(
name|__mmask64
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_min_epu8
comment|// CHECK: @llvm.x86.avx512.mask.pminu.b.512
return|return
name|_mm512_maskz_min_epu8
argument_list|(
name|__M
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
name|test_mm512_mask_min_epu8
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask64
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_min_epu8
comment|// CHECK: @llvm.x86.avx512.mask.pminu.b.512
return|return
name|_mm512_mask_min_epu8
argument_list|(
name|__W
argument_list|,
name|__M
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
name|test_mm512_min_epu16
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_min_epu16
comment|// CHECK: @llvm.x86.avx512.mask.pminu.w.512
return|return
name|_mm512_min_epu16
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
name|test_mm512_maskz_min_epu16
parameter_list|(
name|__mmask32
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_min_epu16
comment|// CHECK: @llvm.x86.avx512.mask.pminu.w.512
return|return
name|_mm512_maskz_min_epu16
argument_list|(
name|__M
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
name|test_mm512_mask_min_epu16
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask32
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_min_epu16
comment|// CHECK: @llvm.x86.avx512.mask.pminu.w.512
return|return
name|_mm512_mask_min_epu16
argument_list|(
name|__W
argument_list|,
name|__M
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
name|test_mm512_shuffle_epi8
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_shuffle_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pshuf.b.512
return|return
name|_mm512_shuffle_epi8
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
name|test_mm512_mask_shuffle_epi8
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask64
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_shuffle_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pshuf.b.512
return|return
name|_mm512_mask_shuffle_epi8
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
name|test_mm512_maskz_shuffle_epi8
parameter_list|(
name|__mmask64
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_shuffle_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pshuf.b.512
return|return
name|_mm512_maskz_shuffle_epi8
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
name|test_mm512_subs_epi8
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_subs_epi8
comment|// CHECK: @llvm.x86.avx512.mask.psubs.b.512
return|return
name|_mm512_subs_epi8
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
name|test_mm512_mask_subs_epi8
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask64
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_subs_epi8
comment|// CHECK: @llvm.x86.avx512.mask.psubs.b.512
return|return
name|_mm512_mask_subs_epi8
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
name|test_mm512_maskz_subs_epi8
parameter_list|(
name|__mmask64
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_subs_epi8
comment|// CHECK: @llvm.x86.avx512.mask.psubs.b.512
return|return
name|_mm512_maskz_subs_epi8
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
name|test_mm512_subs_epi16
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_subs_epi16
comment|// CHECK: @llvm.x86.avx512.mask.psubs.w.512
return|return
name|_mm512_subs_epi16
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
name|test_mm512_mask_subs_epi16
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask32
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_subs_epi16
comment|// CHECK: @llvm.x86.avx512.mask.psubs.w.512
return|return
name|_mm512_mask_subs_epi16
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
name|test_mm512_maskz_subs_epi16
parameter_list|(
name|__mmask32
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_subs_epi16
comment|// CHECK: @llvm.x86.avx512.mask.psubs.w.512
return|return
name|_mm512_maskz_subs_epi16
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
name|test_mm512_subs_epu8
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_subs_epu8
comment|// CHECK: @llvm.x86.avx512.mask.psubus.b.512
return|return
name|_mm512_subs_epu8
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
name|test_mm512_mask_subs_epu8
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask64
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_subs_epu8
comment|// CHECK: @llvm.x86.avx512.mask.psubus.b.512
return|return
name|_mm512_mask_subs_epu8
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
name|test_mm512_maskz_subs_epu8
parameter_list|(
name|__mmask64
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_subs_epu8
comment|// CHECK: @llvm.x86.avx512.mask.psubus.b.512
return|return
name|_mm512_maskz_subs_epu8
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
name|test_mm512_subs_epu16
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_subs_epu16
comment|// CHECK: @llvm.x86.avx512.mask.psubus.w.512
return|return
name|_mm512_subs_epu16
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
name|test_mm512_mask_subs_epu16
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask32
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_subs_epu16
comment|// CHECK: @llvm.x86.avx512.mask.psubus.w.512
return|return
name|_mm512_mask_subs_epu16
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
name|test_mm512_maskz_subs_epu16
parameter_list|(
name|__mmask32
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_subs_epu16
comment|// CHECK: @llvm.x86.avx512.mask.psubus.w.512
return|return
name|_mm512_maskz_subs_epu16
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
name|test_mm512_mask2_permutex2var_epi16
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__I
parameter_list|,
name|__mmask32
name|__U
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask2_permutex2var_epi16
comment|// CHECK: @llvm.x86.avx512.mask.vpermi2var.hi.512
return|return
name|_mm512_mask2_permutex2var_epi16
argument_list|(
name|__A
argument_list|,
name|__I
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_permutex2var_epi16
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__I
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_permutex2var_epi16
comment|// CHECK: @llvm.x86.avx512.mask.vpermt2var.hi.512
return|return
name|_mm512_permutex2var_epi16
argument_list|(
name|__A
argument_list|,
name|__I
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_permutex2var_epi16
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__mmask32
name|__U
parameter_list|,
name|__m512i
name|__I
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_permutex2var_epi16
comment|// CHECK: @llvm.x86.avx512.mask.vpermt2var.hi.512
return|return
name|_mm512_mask_permutex2var_epi16
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__I
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_permutex2var_epi16
parameter_list|(
name|__mmask32
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__I
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_permutex2var_epi16
comment|// CHECK: @llvm.x86.avx512.maskz.vpermt2var.hi.512
return|return
name|_mm512_maskz_permutex2var_epi16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__I
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mulhrs_epi16
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mulhrs_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmul.hr.sw.512
return|return
name|_mm512_mulhrs_epi16
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
name|test_mm512_mask_mulhrs_epi16
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask32
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_mulhrs_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmul.hr.sw.512
return|return
name|_mm512_mask_mulhrs_epi16
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
name|test_mm512_maskz_mulhrs_epi16
parameter_list|(
name|__mmask32
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_mulhrs_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmul.hr.sw.512
return|return
name|_mm512_maskz_mulhrs_epi16
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
name|test_mm512_mulhi_epi16
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mulhi_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmulh.w.512
return|return
name|_mm512_mulhi_epi16
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
name|test_mm512_mask_mulhi_epi16
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask32
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_mulhi_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmulh.w.512
return|return
name|_mm512_mask_mulhi_epi16
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
name|test_mm512_maskz_mulhi_epi16
parameter_list|(
name|__mmask32
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_mulhi_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmulh.w.512
return|return
name|_mm512_maskz_mulhi_epi16
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
name|test_mm512_mulhi_epu16
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mulhi_epu16
comment|// CHECK: @llvm.x86.avx512.mask.pmulhu.w.512
return|return
name|_mm512_mulhi_epu16
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
name|test_mm512_mask_mulhi_epu16
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask32
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_mulhi_epu16
comment|// CHECK: @llvm.x86.avx512.mask.pmulhu.w.512
return|return
name|_mm512_mask_mulhi_epu16
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
name|test_mm512_maskz_mulhi_epu16
parameter_list|(
name|__mmask32
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_mulhi_epu16
comment|// CHECK: @llvm.x86.avx512.mask.pmulhu.w.512
return|return
name|_mm512_maskz_mulhi_epu16
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
name|test_mm512_maddubs_epi16
parameter_list|(
name|__m512i
name|__X
parameter_list|,
name|__m512i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maddubs_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmaddubs.w.512
return|return
name|_mm512_maddubs_epi16
argument_list|(
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_maddubs_epi16
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask32
name|__U
parameter_list|,
name|__m512i
name|__X
parameter_list|,
name|__m512i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_maddubs_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmaddubs.w.512
return|return
name|_mm512_mask_maddubs_epi16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_maddubs_epi16
parameter_list|(
name|__mmask32
name|__U
parameter_list|,
name|__m512i
name|__X
parameter_list|,
name|__m512i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_maddubs_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmaddubs.w.512
return|return
name|_mm512_maskz_maddubs_epi16
argument_list|(
name|__U
argument_list|,
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_madd_epi16
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_madd_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmaddw.d.512
return|return
name|_mm512_madd_epi16
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
name|test_mm512_mask_madd_epi16
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
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_madd_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmaddw.d.512
return|return
name|_mm512_mask_madd_epi16
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
name|test_mm512_maskz_madd_epi16
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_madd_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmaddw.d.512
return|return
name|_mm512_maskz_madd_epi16
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
name|test_mm512_cvtsepi16_epi8
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtsepi16_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.wb.512
return|return
name|_mm512_cvtsepi16_epi8
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm512_mask_cvtsepi16_epi8
parameter_list|(
name|__m256i
name|__O
parameter_list|,
name|__mmask32
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtsepi16_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.wb.512
return|return
name|_mm512_mask_cvtsepi16_epi8
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
name|__m256i
name|test_mm512_maskz_cvtsepi16_epi8
parameter_list|(
name|__mmask32
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtsepi16_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.wb.512
return|return
name|_mm512_maskz_cvtsepi16_epi8
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm512_cvtusepi16_epi8
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtusepi16_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.wb.512
return|return
name|_mm512_cvtusepi16_epi8
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm512_mask_cvtusepi16_epi8
parameter_list|(
name|__m256i
name|__O
parameter_list|,
name|__mmask32
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtusepi16_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.wb.512
return|return
name|_mm512_mask_cvtusepi16_epi8
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
name|__m256i
name|test_mm512_maskz_cvtusepi16_epi8
parameter_list|(
name|__mmask32
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtusepi16_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.wb.512
return|return
name|_mm512_maskz_cvtusepi16_epi8
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm512_cvtepi16_epi8
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtepi16_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmov.wb.512
return|return
name|_mm512_cvtepi16_epi8
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm512_mask_cvtepi16_epi8
parameter_list|(
name|__m256i
name|__O
parameter_list|,
name|__mmask32
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtepi16_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmov.wb.512
return|return
name|_mm512_mask_cvtepi16_epi8
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
name|__m256i
name|test_mm512_maskz_cvtepi16_epi8
parameter_list|(
name|__mmask32
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtepi16_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmov.wb.512
return|return
name|_mm512_maskz_cvtepi16_epi8
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
name|test_mm512_unpackhi_epi8
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_unpackhi_epi8
comment|// CHECK: @llvm.x86.avx512.mask.punpckhb.w.512
return|return
name|_mm512_unpackhi_epi8
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
name|test_mm512_mask_unpackhi_epi8
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask64
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_unpackhi_epi8
comment|// CHECK: @llvm.x86.avx512.mask.punpckhb.w.512
return|return
name|_mm512_mask_unpackhi_epi8
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
name|test_mm512_maskz_unpackhi_epi8
parameter_list|(
name|__mmask64
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_unpackhi_epi8
comment|// CHECK: @llvm.x86.avx512.mask.punpckhb.w.512
return|return
name|_mm512_maskz_unpackhi_epi8
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
name|test_mm512_unpackhi_epi16
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_unpackhi_epi16
comment|// CHECK: @llvm.x86.avx512.mask.punpckhw.d.512
return|return
name|_mm512_unpackhi_epi16
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
name|test_mm512_mask_unpackhi_epi16
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask32
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_unpackhi_epi16
comment|// CHECK: @llvm.x86.avx512.mask.punpckhw.d.512
return|return
name|_mm512_mask_unpackhi_epi16
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
name|test_mm512_maskz_unpackhi_epi16
parameter_list|(
name|__mmask32
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_unpackhi_epi16
comment|// CHECK: @llvm.x86.avx512.mask.punpckhw.d.512
return|return
name|_mm512_maskz_unpackhi_epi16
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
name|test_mm512_unpacklo_epi8
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_unpacklo_epi8
comment|// CHECK: @llvm.x86.avx512.mask.punpcklb.w.512
return|return
name|_mm512_unpacklo_epi8
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
name|test_mm512_mask_unpacklo_epi8
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask64
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_unpacklo_epi8
comment|// CHECK: @llvm.x86.avx512.mask.punpcklb.w.512
return|return
name|_mm512_mask_unpacklo_epi8
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
name|test_mm512_maskz_unpacklo_epi8
parameter_list|(
name|__mmask64
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_unpacklo_epi8
comment|// CHECK: @llvm.x86.avx512.mask.punpcklb.w.512
return|return
name|_mm512_maskz_unpacklo_epi8
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
name|test_mm512_unpacklo_epi16
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_unpacklo_epi16
comment|// CHECK: @llvm.x86.avx512.mask.punpcklw.d.512
return|return
name|_mm512_unpacklo_epi16
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
name|test_mm512_mask_unpacklo_epi16
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask32
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_unpacklo_epi16
comment|// CHECK: @llvm.x86.avx512.mask.punpcklw.d.512
return|return
name|_mm512_mask_unpacklo_epi16
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
name|test_mm512_maskz_unpacklo_epi16
parameter_list|(
name|__mmask32
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_unpacklo_epi16
comment|// CHECK: @llvm.x86.avx512.mask.punpcklw.d.512
return|return
name|_mm512_maskz_unpacklo_epi16
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

