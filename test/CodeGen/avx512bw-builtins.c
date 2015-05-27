begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -O0 -triple=x86_64-apple-darwin -ffreestanding -target-feature +avx512bw -emit-llvm -o - -Werror | FileCheck %s
end_comment

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

end_unit

