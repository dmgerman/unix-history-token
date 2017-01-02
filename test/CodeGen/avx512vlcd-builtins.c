begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ffreestanding %s -triple=x86_64-apple-darwin -target-feature +avx512vl -target-feature +avx512cd -emit-llvm -o - -Wall -Werror | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<immintrin.h>
end_include

begin_function
name|__m128i
name|test_mm_broadcastmb_epi64
parameter_list|(
name|__mmask8
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_broadcastmb_epi64
comment|// CHECK: @llvm.x86.avx512.broadcastmb.128
return|return
name|_mm_broadcastmb_epi64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_broadcastmb_epi64
parameter_list|(
name|__mmask8
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_broadcastmb_epi64
comment|// CHECK: @llvm.x86.avx512.broadcastmb.256
return|return
name|_mm256_broadcastmb_epi64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_broadcastmw_epi32
parameter_list|(
name|__mmask16
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_broadcastmw_epi32
comment|// CHECK: @llvm.x86.avx512.broadcastmw.128
return|return
name|_mm_broadcastmw_epi32
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_broadcastmw_epi32
parameter_list|(
name|__mmask16
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_broadcastmw_epi32
comment|// CHECK: @llvm.x86.avx512.broadcastmw.256
return|return
name|_mm256_broadcastmw_epi32
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_conflict_epi64
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_conflict_epi64
comment|// CHECK: @llvm.x86.avx512.mask.conflict.q.128
return|return
name|_mm_conflict_epi64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_conflict_epi64
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_conflict_epi64
comment|// CHECK: @llvm.x86.avx512.mask.conflict.q.128
return|return
name|_mm_mask_conflict_epi64
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
name|__m128i
name|test_mm_maskz_conflict_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_conflict_epi64
comment|// CHECK: @llvm.x86.avx512.mask.conflict.q.128
return|return
name|_mm_maskz_conflict_epi64
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_conflict_epi64
parameter_list|(
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_conflict_epi64
comment|// CHECK: @llvm.x86.avx512.mask.conflict.q.256
return|return
name|_mm256_conflict_epi64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_conflict_epi64
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_conflict_epi64
comment|// CHECK: @llvm.x86.avx512.mask.conflict.q.256
return|return
name|_mm256_mask_conflict_epi64
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
name|__m256i
name|test_mm256_maskz_conflict_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_conflict_epi64
comment|// CHECK: @llvm.x86.avx512.mask.conflict.q.256
return|return
name|_mm256_maskz_conflict_epi64
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_conflict_epi32
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_conflict_epi32
comment|// CHECK: @llvm.x86.avx512.mask.conflict.d.128
return|return
name|_mm_conflict_epi32
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_conflict_epi32
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_conflict_epi32
comment|// CHECK: @llvm.x86.avx512.mask.conflict.d.128
return|return
name|_mm_mask_conflict_epi32
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
name|__m128i
name|test_mm_maskz_conflict_epi32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_conflict_epi32
comment|// CHECK: @llvm.x86.avx512.mask.conflict.d.128
return|return
name|_mm_maskz_conflict_epi32
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_conflict_epi32
parameter_list|(
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_conflict_epi32
comment|// CHECK: @llvm.x86.avx512.mask.conflict.d.256
return|return
name|_mm256_conflict_epi32
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_conflict_epi32
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_conflict_epi32
comment|// CHECK: @llvm.x86.avx512.mask.conflict.d.256
return|return
name|_mm256_mask_conflict_epi32
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
name|__m256i
name|test_mm256_maskz_conflict_epi32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_conflict_epi32
comment|// CHECK: @llvm.x86.avx512.mask.conflict.d.256
return|return
name|_mm256_maskz_conflict_epi32
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_lzcnt_epi32
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_lzcnt_epi32
comment|// CHECK: call<4 x i32> @llvm.ctlz.v4i32(<4 x i32> %{{.*}}, i1 false)
return|return
name|_mm_lzcnt_epi32
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_lzcnt_epi32
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_lzcnt_epi32
comment|// CHECK: call<4 x i32> @llvm.ctlz.v4i32(<4 x i32> %{{.*}}, i1 false)
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm_mask_lzcnt_epi32
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
name|__m128i
name|test_mm_maskz_lzcnt_epi32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_lzcnt_epi32
comment|// CHECK: call<4 x i32> @llvm.ctlz.v4i32(<4 x i32> %{{.*}}, i1 false)
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm_maskz_lzcnt_epi32
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_lzcnt_epi32
parameter_list|(
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_lzcnt_epi32
comment|// CHECK: call<8 x i32> @llvm.ctlz.v8i32(<8 x i32> %{{.*}}, i1 false)
return|return
name|_mm256_lzcnt_epi32
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_lzcnt_epi32
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_lzcnt_epi32
comment|// CHECK: call<8 x i32> @llvm.ctlz.v8i32(<8 x i32> %{{.*}}, i1 false)
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_mask_lzcnt_epi32
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
name|__m256i
name|test_mm256_maskz_lzcnt_epi32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_lzcnt_epi32
comment|// CHECK: call<8 x i32> @llvm.ctlz.v8i32(<8 x i32> %{{.*}}, i1 false)
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_maskz_lzcnt_epi32
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_lzcnt_epi64
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_lzcnt_epi64
comment|// CHECK: call<2 x i64> @llvm.ctlz.v2i64(<2 x i64> %{{.*}}, i1 false)
return|return
name|_mm_lzcnt_epi64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_lzcnt_epi64
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_lzcnt_epi64
comment|// CHECK: call<2 x i64> @llvm.ctlz.v2i64(<2 x i64> %{{.*}}, i1 false)
comment|// CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm_mask_lzcnt_epi64
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
name|__m128i
name|test_mm_maskz_lzcnt_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_lzcnt_epi64
comment|// CHECK: call<2 x i64> @llvm.ctlz.v2i64(<2 x i64> %{{.*}}, i1 false)
comment|// CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm_maskz_lzcnt_epi64
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_lzcnt_epi64
parameter_list|(
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_lzcnt_epi64
comment|// CHECK: call<4 x i64> @llvm.ctlz.v4i64(<4 x i64> %{{.*}}, i1 false)
return|return
name|_mm256_lzcnt_epi64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_lzcnt_epi64
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_lzcnt_epi64
comment|// CHECK: call<4 x i64> @llvm.ctlz.v4i64(<4 x i64> %{{.*}}, i1 false)
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_mask_lzcnt_epi64
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
name|__m256i
name|test_mm256_maskz_lzcnt_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_lzcnt_epi64
comment|// CHECK: call<4 x i64> @llvm.ctlz.v4i64(<4 x i64> %{{.*}}, i1 false)
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_maskz_lzcnt_epi64
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

end_unit

