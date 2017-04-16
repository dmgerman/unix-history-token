begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ffreestanding %s -triple=x86_64-apple-darwin -target-feature +avx512dq -target-feature +avx512vl -emit-llvm -o - -Wall -Werror | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<immintrin.h>
end_include

begin_function
name|__m256i
name|test_mm256_mullo_epi64
parameter_list|(
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mullo_epi64
comment|// CHECK: mul<4 x i64>
return|return
name|_mm256_mullo_epi64
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_mullo_epi64
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_mullo_epi64
comment|// CHECK: mul<4 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
operator|(
name|__m256i
operator|)
name|_mm256_mask_mullo_epi64
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
name|test_mm256_maskz_mullo_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_mullo_epi64
comment|// CHECK: mul<4 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
operator|(
name|__m256i
operator|)
name|_mm256_maskz_mullo_epi64
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
name|test_mm_mullo_epi64
parameter_list|(
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mullo_epi64
comment|// CHECK: mul<2 x i64>
return|return
operator|(
name|__m128i
operator|)
name|_mm_mullo_epi64
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_mullo_epi64
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
comment|// CHECK-LABEL: @test_mm_mask_mullo_epi64
comment|// CHECK: mul<2 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
operator|(
name|__m128i
operator|)
name|_mm_mask_mullo_epi64
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
name|test_mm_maskz_mullo_epi64
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
comment|// CHECK-LABEL: @test_mm_maskz_mullo_epi64
comment|// CHECK: mul<2 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
operator|(
name|__m128i
operator|)
name|_mm_maskz_mullo_epi64
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
name|__m256d
name|test_mm256_mask_andnot_pd
parameter_list|(
name|__m256d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|,
name|__m256d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_andnot_pd
comment|// CHECK: xor<4 x i64> %{{.*}},<i64 -1, i64 -1, i64 -1, i64 -1>
comment|// CHECK: and<4 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: select<4 x i1> %{{.*}},<4 x double> %{{.*}},<4 x double> %{{.*}}
return|return
operator|(
name|__m256d
operator|)
name|_mm256_mask_andnot_pd
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
name|__m256d
name|test_mm256_maskz_andnot_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|,
name|__m256d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_andnot_pd
comment|// CHECK: xor<4 x i64> %{{.*}},<i64 -1, i64 -1, i64 -1, i64 -1>
comment|// CHECK: and<4 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: select<4 x i1> %{{.*}},<4 x double> %{{.*}},<4 x double> %{{.*}}
return|return
operator|(
name|__m256d
operator|)
name|_mm256_maskz_andnot_pd
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
name|__m128d
name|test_mm_mask_andnot_pd
parameter_list|(
name|__m128d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_andnot_pd
comment|// CHECK: xor<2 x i64> %{{.*}},<i64 -1, i64 -1>
comment|// CHECK: and<2 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: select<2 x i1> %{{.*}},<2 x double> %{{.*}},<2 x double> %{{.*}}
return|return
operator|(
name|__m128d
operator|)
name|_mm_mask_andnot_pd
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
name|__m128d
name|test_mm_maskz_andnot_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_andnot_pd
comment|// CHECK: xor<2 x i64> %{{.*}},<i64 -1, i64 -1>
comment|// CHECK: and<2 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: select<2 x i1> %{{.*}},<2 x double> %{{.*}},<2 x double> %{{.*}}
return|return
operator|(
name|__m128d
operator|)
name|_mm_maskz_andnot_pd
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
name|__m256
name|test_mm256_mask_andnot_ps
parameter_list|(
name|__m256
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_andnot_ps
comment|// CHECK: xor<8 x i32> %{{.*}},<i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1>
comment|// CHECK: and<8 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: select<8 x i1> %{{.*}},<8 x float> %{{.*}},<8 x float> %{{.*}}
return|return
operator|(
name|__m256
operator|)
name|_mm256_mask_andnot_ps
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
name|__m256
name|test_mm256_maskz_andnot_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_andnot_ps
comment|// CHECK: xor<8 x i32> %{{.*}},<i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1>
comment|// CHECK: and<8 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: select<8 x i1> %{{.*}},<8 x float> %{{.*}},<8 x float> %{{.*}}
return|return
operator|(
name|__m256
operator|)
name|_mm256_maskz_andnot_ps
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
name|__m128
name|test_mm_mask_andnot_ps
parameter_list|(
name|__m128
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_andnot_ps
comment|// CHECK: xor<4 x i32> %{{.*}},<i32 -1, i32 -1, i32 -1, i32 -1>
comment|// CHECK: and<4 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: select<4 x i1> %{{.*}},<4 x float> %{{.*}},<4 x float> %{{.*}}
return|return
operator|(
name|__m128
operator|)
name|_mm_mask_andnot_ps
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
name|__m128
name|test_mm_maskz_andnot_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_andnot_ps
comment|// CHECK: xor<4 x i32> %{{.*}},<i32 -1, i32 -1, i32 -1, i32 -1>
comment|// CHECK: and<4 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: select<4 x i1> %{{.*}},<4 x float> %{{.*}},<4 x float> %{{.*}}
return|return
operator|(
name|__m128
operator|)
name|_mm_maskz_andnot_ps
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
name|__m256d
name|test_mm256_mask_and_pd
parameter_list|(
name|__m256d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|,
name|__m256d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_and_pd
comment|// CHECK: and<4 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: select<4 x i1> %{{.*}},<4 x double> %{{.*}},<4 x double> %{{.*}}
return|return
operator|(
name|__m256d
operator|)
name|_mm256_mask_and_pd
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
name|__m256d
name|test_mm256_maskz_and_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|,
name|__m256d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_and_pd
comment|// CHECK: and<4 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: select<4 x i1> %{{.*}},<4 x double> %{{.*}},<4 x double> %{{.*}}
return|return
operator|(
name|__m256d
operator|)
name|_mm256_maskz_and_pd
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
name|__m128d
name|test_mm_mask_and_pd
parameter_list|(
name|__m128d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_and_pd
comment|// CHECK: and<2 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: select<2 x i1> %{{.*}},<2 x double> %{{.*}},<2 x double> %{{.*}}
return|return
operator|(
name|__m128d
operator|)
name|_mm_mask_and_pd
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
name|__m128d
name|test_mm_maskz_and_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_and_pd
comment|// CHECK: and<2 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: select<2 x i1> %{{.*}},<2 x double> %{{.*}},<2 x double> %{{.*}}
return|return
operator|(
name|__m128d
operator|)
name|_mm_maskz_and_pd
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
name|__m256
name|test_mm256_mask_and_ps
parameter_list|(
name|__m256
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_and_ps
comment|// CHECK: and<8 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: select<8 x i1> %{{.*}},<8 x float> %{{.*}},<8 x float> %{{.*}}
return|return
operator|(
name|__m256
operator|)
name|_mm256_mask_and_ps
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
name|__m256
name|test_mm256_maskz_and_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_and_ps
comment|// CHECK: and<8 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: select<8 x i1> %{{.*}},<8 x float> %{{.*}},<8 x float> %{{.*}}
return|return
operator|(
name|__m256
operator|)
name|_mm256_maskz_and_ps
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
name|__m128
name|test_mm_mask_and_ps
parameter_list|(
name|__m128
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_and_ps
comment|// CHECK: and<4 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: select<4 x i1> %{{.*}},<4 x float> %{{.*}},<4 x float> %{{.*}}
return|return
operator|(
name|__m128
operator|)
name|_mm_mask_and_ps
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
name|__m128
name|test_mm_maskz_and_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_and_ps
comment|// CHECK: and<4 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: select<4 x i1> %{{.*}},<4 x float> %{{.*}},<4 x float> %{{.*}}
return|return
operator|(
name|__m128
operator|)
name|_mm_maskz_and_ps
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
name|__m256d
name|test_mm256_mask_xor_pd
parameter_list|(
name|__m256d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|,
name|__m256d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_xor_pd
comment|// CHECK: xor<4 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: select<4 x i1> %{{.*}},<4 x double> %{{.*}},<4 x double> %{{.*}}
return|return
operator|(
name|__m256d
operator|)
name|_mm256_mask_xor_pd
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
name|__m256d
name|test_mm256_maskz_xor_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|,
name|__m256d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_xor_pd
comment|// CHECK: xor<4 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: select<4 x i1> %{{.*}},<4 x double> %{{.*}},<4 x double> %{{.*}}
return|return
operator|(
name|__m256d
operator|)
name|_mm256_maskz_xor_pd
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
name|__m128d
name|test_mm_mask_xor_pd
parameter_list|(
name|__m128d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_xor_pd
comment|// CHECK: xor<2 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: select<2 x i1> %{{.*}},<2 x double> %{{.*}},<2 x double> %{{.*}}
return|return
operator|(
name|__m128d
operator|)
name|_mm_mask_xor_pd
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
name|__m128d
name|test_mm_maskz_xor_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_xor_pd
comment|// CHECK: xor<2 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: select<2 x i1> %{{.*}},<2 x double> %{{.*}},<2 x double> %{{.*}}
return|return
operator|(
name|__m128d
operator|)
name|_mm_maskz_xor_pd
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
name|__m256
name|test_mm256_mask_xor_ps
parameter_list|(
name|__m256
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_xor_ps
comment|// CHECK: xor<8 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: select<8 x i1> %{{.*}},<8 x float> %{{.*}},<8 x float> %{{.*}}
return|return
operator|(
name|__m256
operator|)
name|_mm256_mask_xor_ps
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
name|__m256
name|test_mm256_maskz_xor_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_xor_ps
comment|// CHECK: xor<8 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: select<8 x i1> %{{.*}},<8 x float> %{{.*}},<8 x float> %{{.*}}
return|return
operator|(
name|__m256
operator|)
name|_mm256_maskz_xor_ps
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
name|__m128
name|test_mm_mask_xor_ps
parameter_list|(
name|__m128
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_xor_ps
comment|// CHECK: xor<4 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: select<4 x i1> %{{.*}},<4 x float> %{{.*}},<4 x float> %{{.*}}
return|return
operator|(
name|__m128
operator|)
name|_mm_mask_xor_ps
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
name|__m128
name|test_mm_maskz_xor_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_xor_ps
comment|// CHECK: xor<4 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: select<4 x i1> %{{.*}},<4 x float> %{{.*}},<4 x float> %{{.*}}
return|return
operator|(
name|__m128
operator|)
name|_mm_maskz_xor_ps
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
name|__m256d
name|test_mm256_mask_or_pd
parameter_list|(
name|__m256d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|,
name|__m256d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_or_pd
comment|// CHECK: or<4 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: select<4 x i1> %{{.*}},<4 x double> %{{.*}},<4 x double> %{{.*}}
return|return
operator|(
name|__m256d
operator|)
name|_mm256_mask_or_pd
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
name|__m256d
name|test_mm256_maskz_or_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|,
name|__m256d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_or_pd
comment|// CHECK: or<4 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: select<4 x i1> %{{.*}},<4 x double> %{{.*}},<4 x double> %{{.*}}
return|return
operator|(
name|__m256d
operator|)
name|_mm256_maskz_or_pd
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
name|__m128d
name|test_mm_mask_or_pd
parameter_list|(
name|__m128d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_or_pd
comment|// CHECK: or<2 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: select<2 x i1> %{{.*}},<2 x double> %{{.*}},<2 x double> %{{.*}}
return|return
operator|(
name|__m128d
operator|)
name|_mm_mask_or_pd
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
name|__m128d
name|test_mm_maskz_or_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_or_pd
comment|// CHECK: or<2 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: select<2 x i1> %{{.*}},<2 x double> %{{.*}},<2 x double> %{{.*}}
return|return
operator|(
name|__m128d
operator|)
name|_mm_maskz_or_pd
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
name|__m256
name|test_mm256_mask_or_ps
parameter_list|(
name|__m256
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_or_ps
comment|// CHECK: or<8 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: select<8 x i1> %{{.*}},<8 x float> %{{.*}},<8 x float> %{{.*}}
return|return
operator|(
name|__m256
operator|)
name|_mm256_mask_or_ps
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
name|__m256
name|test_mm256_maskz_or_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_or_ps
comment|// CHECK: or<8 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: select<8 x i1> %{{.*}},<8 x float> %{{.*}},<8 x float> %{{.*}}
return|return
operator|(
name|__m256
operator|)
name|_mm256_maskz_or_ps
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
name|__m128
name|test_mm_mask_or_ps
parameter_list|(
name|__m128
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_or_ps
comment|// CHECK: or<4 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: select<4 x i1> %{{.*}},<4 x float> %{{.*}},<4 x float> %{{.*}}
return|return
operator|(
name|__m128
operator|)
name|_mm_mask_or_ps
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
name|__m128
name|test_mm_maskz_or_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_or_ps
comment|// CHECK: or<4 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: select<4 x i1> %{{.*}},<4 x float> %{{.*}},<4 x float> %{{.*}}
return|return
operator|(
name|__m128
operator|)
name|_mm_maskz_or_ps
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
name|test_mm_cvtpd_epi64
parameter_list|(
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtpd_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2qq.128
return|return
name|_mm_cvtpd_epi64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_cvtpd_epi64
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cvtpd_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2qq.128
return|return
name|_mm_mask_cvtpd_epi64
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
name|test_mm_maskz_cvtpd_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtpd_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2qq.128
return|return
name|_mm_maskz_cvtpd_epi64
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
name|test_mm256_cvtpd_epi64
parameter_list|(
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cvtpd_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2qq.256
return|return
name|_mm256_cvtpd_epi64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_cvtpd_epi64
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtpd_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2qq.256
return|return
name|_mm256_mask_cvtpd_epi64
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
name|test_mm256_maskz_cvtpd_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtpd_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2qq.256
return|return
name|_mm256_maskz_cvtpd_epi64
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
name|test_mm_cvtpd_epu64
parameter_list|(
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtpd_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2uqq.128
return|return
name|_mm_cvtpd_epu64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_cvtpd_epu64
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cvtpd_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2uqq.128
return|return
name|_mm_mask_cvtpd_epu64
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
name|test_mm_maskz_cvtpd_epu64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtpd_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2uqq.128
return|return
name|_mm_maskz_cvtpd_epu64
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
name|test_mm256_cvtpd_epu64
parameter_list|(
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cvtpd_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2uqq.256
return|return
name|_mm256_cvtpd_epu64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_cvtpd_epu64
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtpd_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2uqq.256
return|return
name|_mm256_mask_cvtpd_epu64
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
name|test_mm256_maskz_cvtpd_epu64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtpd_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2uqq.256
return|return
name|_mm256_maskz_cvtpd_epu64
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
name|test_mm_cvtps_epi64
parameter_list|(
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtps_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2qq.128
return|return
name|_mm_cvtps_epi64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_cvtps_epi64
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cvtps_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2qq.128
return|return
name|_mm_mask_cvtps_epi64
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
name|test_mm_maskz_cvtps_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtps_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2qq.128
return|return
name|_mm_maskz_cvtps_epi64
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
name|test_mm256_cvtps_epi64
parameter_list|(
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cvtps_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2qq.256
return|return
name|_mm256_cvtps_epi64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_cvtps_epi64
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtps_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2qq.256
return|return
name|_mm256_mask_cvtps_epi64
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
name|test_mm256_maskz_cvtps_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtps_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2qq.256
return|return
name|_mm256_maskz_cvtps_epi64
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
name|test_mm_cvtps_epu64
parameter_list|(
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtps_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2uqq.128
return|return
name|_mm_cvtps_epu64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_cvtps_epu64
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cvtps_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2uqq.128
return|return
name|_mm_mask_cvtps_epu64
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
name|test_mm_maskz_cvtps_epu64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtps_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2uqq.128
return|return
name|_mm_maskz_cvtps_epu64
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
name|test_mm256_cvtps_epu64
parameter_list|(
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cvtps_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2uqq.256
return|return
name|_mm256_cvtps_epu64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_cvtps_epu64
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtps_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2uqq.256
return|return
name|_mm256_mask_cvtps_epu64
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
name|test_mm256_maskz_cvtps_epu64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtps_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2uqq.256
return|return
name|_mm256_maskz_cvtps_epu64
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_cvtepi64_pd
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtepi64_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtqq2pd.128
return|return
name|_mm_cvtepi64_pd
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_cvtepi64_pd
parameter_list|(
name|__m128d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cvtepi64_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtqq2pd.128
return|return
name|_mm_mask_cvtepi64_pd
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
name|__m128d
name|test_mm_maskz_cvtepi64_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtepi64_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtqq2pd.128
return|return
name|_mm_maskz_cvtepi64_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_cvtepi64_pd
parameter_list|(
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cvtepi64_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtqq2pd.256
return|return
name|_mm256_cvtepi64_pd
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_mask_cvtepi64_pd
parameter_list|(
name|__m256d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtepi64_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtqq2pd.256
return|return
name|_mm256_mask_cvtepi64_pd
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
name|__m256d
name|test_mm256_maskz_cvtepi64_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtepi64_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtqq2pd.256
return|return
name|_mm256_maskz_cvtepi64_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_cvtepi64_ps
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtepi64_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtqq2ps.128
return|return
name|_mm_cvtepi64_ps
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_cvtepi64_ps
parameter_list|(
name|__m128
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cvtepi64_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtqq2ps.128
return|return
name|_mm_mask_cvtepi64_ps
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
name|__m128
name|test_mm_maskz_cvtepi64_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtepi64_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtqq2ps.128
return|return
name|_mm_maskz_cvtepi64_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm256_cvtepi64_ps
parameter_list|(
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cvtepi64_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtqq2ps.256
return|return
name|_mm256_cvtepi64_ps
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm256_mask_cvtepi64_ps
parameter_list|(
name|__m128
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtepi64_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtqq2ps.256
return|return
name|_mm256_mask_cvtepi64_ps
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
name|__m128
name|test_mm256_maskz_cvtepi64_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtepi64_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtqq2ps.256
return|return
name|_mm256_maskz_cvtepi64_ps
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
name|test_mm_cvttpd_epi64
parameter_list|(
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvttpd_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2qq.128
return|return
name|_mm_cvttpd_epi64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_cvttpd_epi64
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cvttpd_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2qq.128
return|return
name|_mm_mask_cvttpd_epi64
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
name|test_mm_maskz_cvttpd_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvttpd_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2qq.128
return|return
name|_mm_maskz_cvttpd_epi64
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
name|test_mm256_cvttpd_epi64
parameter_list|(
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cvttpd_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2qq.256
return|return
name|_mm256_cvttpd_epi64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_cvttpd_epi64
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvttpd_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2qq.256
return|return
name|_mm256_mask_cvttpd_epi64
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
name|test_mm256_maskz_cvttpd_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvttpd_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2qq.256
return|return
name|_mm256_maskz_cvttpd_epi64
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
name|test_mm_cvttpd_epu64
parameter_list|(
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvttpd_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2uqq.128
return|return
name|_mm_cvttpd_epu64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_cvttpd_epu64
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cvttpd_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2uqq.128
return|return
name|_mm_mask_cvttpd_epu64
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
name|test_mm_maskz_cvttpd_epu64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvttpd_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2uqq.128
return|return
name|_mm_maskz_cvttpd_epu64
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
name|test_mm256_cvttpd_epu64
parameter_list|(
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cvttpd_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2uqq.256
return|return
name|_mm256_cvttpd_epu64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_cvttpd_epu64
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvttpd_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2uqq.256
return|return
name|_mm256_mask_cvttpd_epu64
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
name|test_mm256_maskz_cvttpd_epu64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvttpd_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2uqq.256
return|return
name|_mm256_maskz_cvttpd_epu64
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
name|test_mm_cvttps_epi64
parameter_list|(
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvttps_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2qq.128
return|return
name|_mm_cvttps_epi64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_cvttps_epi64
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cvttps_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2qq.128
return|return
name|_mm_mask_cvttps_epi64
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
name|test_mm_maskz_cvttps_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvttps_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2qq.128
return|return
name|_mm_maskz_cvttps_epi64
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
name|test_mm256_cvttps_epi64
parameter_list|(
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cvttps_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2qq.256
return|return
name|_mm256_cvttps_epi64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_cvttps_epi64
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvttps_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2qq.256
return|return
name|_mm256_mask_cvttps_epi64
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
name|test_mm256_maskz_cvttps_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvttps_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2qq.256
return|return
name|_mm256_maskz_cvttps_epi64
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
name|test_mm_cvttps_epu64
parameter_list|(
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvttps_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2uqq.128
return|return
name|_mm_cvttps_epu64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_cvttps_epu64
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cvttps_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2uqq.128
return|return
name|_mm_mask_cvttps_epu64
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
name|test_mm_maskz_cvttps_epu64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvttps_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2uqq.128
return|return
name|_mm_maskz_cvttps_epu64
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
name|test_mm256_cvttps_epu64
parameter_list|(
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cvttps_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2uqq.256
return|return
name|_mm256_cvttps_epu64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_cvttps_epu64
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvttps_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2uqq.256
return|return
name|_mm256_mask_cvttps_epu64
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
name|test_mm256_maskz_cvttps_epu64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvttps_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2uqq.256
return|return
name|_mm256_maskz_cvttps_epu64
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_cvtepu64_pd
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtepu64_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtuqq2pd.128
return|return
name|_mm_cvtepu64_pd
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_cvtepu64_pd
parameter_list|(
name|__m128d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cvtepu64_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtuqq2pd.128
return|return
name|_mm_mask_cvtepu64_pd
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
name|__m128d
name|test_mm_maskz_cvtepu64_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtepu64_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtuqq2pd.128
return|return
name|_mm_maskz_cvtepu64_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_cvtepu64_pd
parameter_list|(
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cvtepu64_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtuqq2pd.256
return|return
name|_mm256_cvtepu64_pd
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_mask_cvtepu64_pd
parameter_list|(
name|__m256d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtepu64_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtuqq2pd.256
return|return
name|_mm256_mask_cvtepu64_pd
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
name|__m256d
name|test_mm256_maskz_cvtepu64_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtepu64_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtuqq2pd.256
return|return
name|_mm256_maskz_cvtepu64_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_cvtepu64_ps
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtepu64_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtuqq2ps.128
return|return
name|_mm_cvtepu64_ps
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_cvtepu64_ps
parameter_list|(
name|__m128
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cvtepu64_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtuqq2ps.128
return|return
name|_mm_mask_cvtepu64_ps
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
name|__m128
name|test_mm_maskz_cvtepu64_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtepu64_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtuqq2ps.128
return|return
name|_mm_maskz_cvtepu64_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm256_cvtepu64_ps
parameter_list|(
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cvtepu64_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtuqq2ps.256
return|return
name|_mm256_cvtepu64_ps
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm256_mask_cvtepu64_ps
parameter_list|(
name|__m128
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtepu64_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtuqq2ps.256
return|return
name|_mm256_mask_cvtepu64_ps
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
name|__m128
name|test_mm256_maskz_cvtepu64_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtepu64_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtuqq2ps.256
return|return
name|_mm256_maskz_cvtepu64_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_range_pd
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_range_pd
comment|// CHECK: @llvm.x86.avx512.mask.range.pd.128
return|return
name|_mm_range_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_range_pd
parameter_list|(
name|__m128d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_range_pd
comment|// CHECK: @llvm.x86.avx512.mask.range.pd.128
return|return
name|_mm_mask_range_pd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_maskz_range_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_range_pd
comment|// CHECK: @llvm.x86.avx512.mask.range.pd.128
return|return
name|_mm_maskz_range_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_range_pd
parameter_list|(
name|__m256d
name|__A
parameter_list|,
name|__m256d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_range_pd
comment|// CHECK: @llvm.x86.avx512.mask.range.pd.256
return|return
name|_mm256_range_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_mask_range_pd
parameter_list|(
name|__m256d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|,
name|__m256d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_range_pd
comment|// CHECK: @llvm.x86.avx512.mask.range.pd.256
return|return
name|_mm256_mask_range_pd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_maskz_range_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|,
name|__m256d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_range_pd
comment|// CHECK: @llvm.x86.avx512.mask.range.pd.256
return|return
name|_mm256_maskz_range_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_range_ps
parameter_list|(
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_range_ps
comment|// CHECK: @llvm.x86.avx512.mask.range.ps.128
return|return
name|_mm_range_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_range_ps
parameter_list|(
name|__m128
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_range_ps
comment|// CHECK: @llvm.x86.avx512.mask.range.ps.128
return|return
name|_mm_mask_range_ps
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_maskz_range_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_range_ps
comment|// CHECK: @llvm.x86.avx512.mask.range.ps.128
return|return
name|_mm_maskz_range_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_range_ps
parameter_list|(
name|__m256
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_range_ps
comment|// CHECK: @llvm.x86.avx512.mask.range.ps.256
return|return
name|_mm256_range_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_mask_range_ps
parameter_list|(
name|__m256
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_range_ps
comment|// CHECK: @llvm.x86.avx512.mask.range.ps.256
return|return
name|_mm256_mask_range_ps
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_maskz_range_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_range_ps
comment|// CHECK: @llvm.x86.avx512.mask.range.ps.256
return|return
name|_mm256_maskz_range_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_reduce_pd
parameter_list|(
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_reduce_pd
comment|// CHECK: @llvm.x86.avx512.mask.reduce.pd.128
return|return
name|_mm_reduce_pd
argument_list|(
name|__A
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_reduce_pd
parameter_list|(
name|__m128d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_reduce_pd
comment|// CHECK: @llvm.x86.avx512.mask.reduce.pd.128
return|return
name|_mm_mask_reduce_pd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_maskz_reduce_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_reduce_pd
comment|// CHECK: @llvm.x86.avx512.mask.reduce.pd.128
return|return
name|_mm_maskz_reduce_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_reduce_pd
parameter_list|(
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_reduce_pd
comment|// CHECK: @llvm.x86.avx512.mask.reduce.pd.256
return|return
name|_mm256_reduce_pd
argument_list|(
name|__A
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_mask_reduce_pd
parameter_list|(
name|__m256d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_reduce_pd
comment|// CHECK: @llvm.x86.avx512.mask.reduce.pd.256
return|return
name|_mm256_mask_reduce_pd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_maskz_reduce_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_reduce_pd
comment|// CHECK: @llvm.x86.avx512.mask.reduce.pd.256
return|return
name|_mm256_maskz_reduce_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_reduce_ps
parameter_list|(
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_reduce_ps
comment|// CHECK: @llvm.x86.avx512.mask.reduce.ps.128
return|return
name|_mm_reduce_ps
argument_list|(
name|__A
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_reduce_ps
parameter_list|(
name|__m128
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_reduce_ps
comment|// CHECK: @llvm.x86.avx512.mask.reduce.ps.128
return|return
name|_mm_mask_reduce_ps
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_maskz_reduce_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_reduce_ps
comment|// CHECK: @llvm.x86.avx512.mask.reduce.ps.128
return|return
name|_mm_maskz_reduce_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_reduce_ps
parameter_list|(
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_reduce_ps
comment|// CHECK: @llvm.x86.avx512.mask.reduce.ps.256
return|return
name|_mm256_reduce_ps
argument_list|(
name|__A
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_mask_reduce_ps
parameter_list|(
name|__m256
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_reduce_ps
comment|// CHECK: @llvm.x86.avx512.mask.reduce.ps.256
return|return
name|_mm256_mask_reduce_ps
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_maskz_reduce_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_reduce_ps
comment|// CHECK: @llvm.x86.avx512.mask.reduce.ps.256
return|return
name|_mm256_maskz_reduce_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm_movepi32_mask
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_movepi32_mask
comment|// CHECK: @llvm.x86.avx512.cvtd2mask.128
return|return
name|_mm_movepi32_mask
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm256_movepi32_mask
parameter_list|(
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_movepi32_mask
comment|// CHECK: @llvm.x86.avx512.cvtd2mask.256
return|return
name|_mm256_movepi32_mask
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_movm_epi32
parameter_list|(
name|__mmask8
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_movm_epi32
comment|// CHECK: %{{.*}} = bitcast i8 %{{.*}} to<8 x i1>
comment|// CHECK: %extract.i = shufflevector<8 x i1> %{{.*}},<8 x i1> %{{.*}},<4 x i32><i32 0, i32 1, i32 2, i32 3>
comment|// CHECK: %vpmovm2.i = sext<4 x i1> %extract.i to<4 x i32>
return|return
name|_mm_movm_epi32
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_movm_epi32
parameter_list|(
name|__mmask8
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_movm_epi32
comment|// CHECK: %{{.*}} = bitcast i8 %{{.*}} to<8 x i1>
comment|// CHECK: %vpmovm2.i = sext<8 x i1> %{{.*}} to<8 x i32>
return|return
name|_mm256_movm_epi32
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_movm_epi64
parameter_list|(
name|__mmask8
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_movm_epi64
comment|// CHECK: %{{.*}} = bitcast i8 %{{.*}} to<8 x i1>
comment|// CHECK: %extract.i = shufflevector<8 x i1> %{{.*}},<8 x i1> %{{.*}},<2 x i32><i32 0, i32 1>
comment|// CHECK: %vpmovm2.i = sext<2 x i1> %extract.i to<2 x i64>
return|return
name|_mm_movm_epi64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_movm_epi64
parameter_list|(
name|__mmask8
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_movm_epi64
comment|// CHECK: %{{.*}} = bitcast i8 %{{.*}} to<8 x i1>
comment|// CHECK: %extract.i = shufflevector<8 x i1> %{{.*}},<8 x i1> %{{.*}},<4 x i32><i32 0, i32 1, i32 2, i32 3>
comment|// CHECK: %vpmovm2.i = sext<4 x i1> %extract.i to<4 x i64>
return|return
name|_mm256_movm_epi64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm_movepi64_mask
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_movepi64_mask
comment|// CHECK: @llvm.x86.avx512.cvtq2mask.128
return|return
name|_mm_movepi64_mask
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm256_movepi64_mask
parameter_list|(
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_movepi64_mask
comment|// CHECK: @llvm.x86.avx512.cvtq2mask.256
return|return
name|_mm256_movepi64_mask
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_broadcast_f32x2
parameter_list|(
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_broadcast_f32x2
comment|// CHECK: @llvm.x86.avx512.mask.broadcastf32x2
return|return
name|_mm256_broadcast_f32x2
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_mask_broadcast_f32x2
parameter_list|(
name|__m256
name|__O
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_broadcast_f32x2
comment|// CHECK: @llvm.x86.avx512.mask.broadcastf32x2
return|return
name|_mm256_mask_broadcast_f32x2
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
name|__m256
name|test_mm256_maskz_broadcast_f32x2
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_broadcast_f32x2
comment|// CHECK: @llvm.x86.avx512.mask.broadcastf32x2
return|return
name|_mm256_maskz_broadcast_f32x2
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_broadcast_f64x2
parameter_list|(
name|double
specifier|const
modifier|*
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_broadcast_f64x2
comment|// CHECK: shufflevector<2 x double> %{{.*}},<2 x double> %{{.*}},<4 x i32><i32 0, i32 1, i32 0, i32 1>
return|return
name|_mm256_broadcast_f64x2
argument_list|(
name|_mm_loadu_pd
argument_list|(
name|__A
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_mask_broadcast_f64x2
parameter_list|(
name|__m256d
name|__O
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|double
specifier|const
modifier|*
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_broadcast_f64x2
comment|// CHECK: shufflevector<2 x double> %{{.*}},<2 x double> %{{.*}},<4 x i32><i32 0, i32 1, i32 0, i32 1>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x double> %{{.*}},<4 x double> %{{.*}}
return|return
name|_mm256_mask_broadcast_f64x2
argument_list|(
name|__O
argument_list|,
name|__M
argument_list|,
name|_mm_loadu_pd
argument_list|(
name|__A
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_maskz_broadcast_f64x2
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|double
specifier|const
modifier|*
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_broadcast_f64x2
comment|// CHECK: shufflevector<2 x double> %{{.*}},<2 x double> %{{.*}},<4 x i32><i32 0, i32 1, i32 0, i32 1>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x double> %{{.*}},<4 x double> %{{.*}}
return|return
name|_mm256_maskz_broadcast_f64x2
argument_list|(
name|__M
argument_list|,
name|_mm_loadu_pd
argument_list|(
name|__A
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_broadcast_i32x2
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_broadcast_i32x2
comment|// CHECK: @llvm.x86.avx512.mask.broadcasti32x2
return|return
name|_mm_broadcast_i32x2
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_broadcast_i32x2
parameter_list|(
name|__m128i
name|__O
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_broadcast_i32x2
comment|// CHECK: @llvm.x86.avx512.mask.broadcasti32x2
return|return
name|_mm_mask_broadcast_i32x2
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
name|__m128i
name|test_mm_maskz_broadcast_i32x2
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_broadcast_i32x2
comment|// CHECK: @llvm.x86.avx512.mask.broadcasti32x2
return|return
name|_mm_maskz_broadcast_i32x2
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
name|test_mm256_broadcast_i32x2
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_broadcast_i32x2
comment|// CHECK: @llvm.x86.avx512.mask.broadcasti32x2
return|return
name|_mm256_broadcast_i32x2
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_broadcast_i32x2
parameter_list|(
name|__m256i
name|__O
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_broadcast_i32x2
comment|// CHECK: @llvm.x86.avx512.mask.broadcasti32x2
return|return
name|_mm256_mask_broadcast_i32x2
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
name|test_mm256_maskz_broadcast_i32x2
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_broadcast_i32x2
comment|// CHECK: @llvm.x86.avx512.mask.broadcasti32x2
return|return
name|_mm256_maskz_broadcast_i32x2
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
name|test_mm256_broadcast_i64x2
parameter_list|(
name|__m128i
specifier|const
modifier|*
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_broadcast_i64x2
comment|// CHECK: shufflevector<2 x i64> %{{.*}},<2 x i64> %{{.*}},<4 x i32><i32 0, i32 1, i32 0, i32 1>
return|return
name|_mm256_broadcast_i64x2
argument_list|(
name|_mm_loadu_si128
argument_list|(
name|__A
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_broadcast_i64x2
parameter_list|(
name|__m256i
name|__O
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m128i
specifier|const
modifier|*
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_broadcast_i64x2
comment|// CHECK: shufflevector<2 x i64> %{{.*}},<2 x i64> %{{.*}},<4 x i32><i32 0, i32 1, i32 0, i32 1>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_mask_broadcast_i64x2
argument_list|(
name|__O
argument_list|,
name|__M
argument_list|,
name|_mm_loadu_si128
argument_list|(
name|__A
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_broadcast_i64x2
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128i
specifier|const
modifier|*
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_broadcast_i64x2
comment|// CHECK: shufflevector<2 x i64> %{{.*}},<2 x i64> %{{.*}},<4 x i32><i32 0, i32 1, i32 0, i32 1>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_maskz_broadcast_i64x2
argument_list|(
name|__M
argument_list|,
name|_mm_loadu_si128
argument_list|(
name|__A
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm256_extractf64x2_pd
parameter_list|(
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_extractf64x2_pd
comment|// CHECK: shufflevector<4 x double> %{{.*}},<4 x double> zeroinitializer,<2 x i32><i32 2, i32 3>
return|return
name|_mm256_extractf64x2_pd
argument_list|(
name|__A
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm256_mask_extractf64x2_pd
parameter_list|(
name|__m128d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_extractf64x2_pd
comment|// CHECK: shufflevector<4 x double> %{{.*}},<4 x double> zeroinitializer,<2 x i32><i32 2, i32 3>
comment|// CHECK: select<2 x i1> %{{.*}},<2 x double> %{{.*}},<2 x double> %{{.*}}
return|return
name|_mm256_mask_extractf64x2_pd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm256_maskz_extractf64x2_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_extractf64x2_pd
comment|// CHECK: shufflevector<4 x double> %{{.*}},<4 x double> zeroinitializer,<2 x i32><i32 2, i32 3>
comment|// CHECK: select<2 x i1> %{{.*}},<2 x double> %{{.*}},<2 x double> %{{.*}}
return|return
name|_mm256_maskz_extractf64x2_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm256_extracti64x2_epi64
parameter_list|(
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_extracti64x2_epi64
comment|// CHECK: shufflevector<4 x i64> %{{.*}},<4 x i64> zeroinitializer,<2 x i32><i32 2, i32 3>
return|return
name|_mm256_extracti64x2_epi64
argument_list|(
name|__A
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm256_mask_extracti64x2_epi64
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_extracti64x2_epi64
comment|// CHECK: shufflevector<4 x i64> %{{.*}},<4 x i64> zeroinitializer,<2 x i32><i32 2, i32 3>
comment|// CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm256_mask_extracti64x2_epi64
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm256_maskz_extracti64x2_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_extracti64x2_epi64
comment|// CHECK: shufflevector<4 x i64> %{{.*}},<4 x i64> zeroinitializer,<2 x i32><i32 2, i32 3>
comment|// CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm256_maskz_extracti64x2_epi64
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_insertf64x2
parameter_list|(
name|__m256d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_insertf64x2
comment|// CHECK: shufflevector<4 x double> %{{.*}},<4 x double> %{{.*}},<4 x i32><i32 0, i32 1, i32 4, i32 5>
return|return
name|_mm256_insertf64x2
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_mask_insertf64x2
parameter_list|(
name|__m256d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_insertf64x2
comment|// CHECK: shufflevector<4 x double> %{{.*}},<4 x double> %{{.*}},<4 x i32><i32 0, i32 1, i32 4, i32 5>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x double> %{{.*}},<4 x double> %{{.*}}
return|return
name|_mm256_mask_insertf64x2
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_maskz_insertf64x2
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_insertf64x2
comment|// CHECK: shufflevector<4 x double> %{{.*}},<4 x double> %{{.*}},<4 x i32><i32 0, i32 1, i32 4, i32 5>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x double> %{{.*}},<4 x double> %{{.*}}
return|return
name|_mm256_maskz_insertf64x2
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_inserti64x2
parameter_list|(
name|__m256i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_inserti64x2
comment|// CHECK: shufflevector<4 x i64> %{{.*}},<4 x i64> %{{.*}},<4 x i32><i32 0, i32 1, i32 4, i32 5>
return|return
name|_mm256_inserti64x2
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_inserti64x2
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_inserti64x2
comment|// CHECK: shufflevector<4 x i64> %{{.*}},<4 x i64> %{{.*}},<4 x i32><i32 0, i32 1, i32 4, i32 5>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_mask_inserti64x2
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_inserti64x2
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_inserti64x2
comment|// CHECK: shufflevector<4 x i64> %{{.*}},<4 x i64> %{{.*}},<4 x i32><i32 0, i32 1, i32 4, i32 5>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_maskz_inserti64x2
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm_mask_fpclass_pd_mask
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_fpclass_pd_mask
comment|// CHECK: @llvm.x86.avx512.mask.fpclass.pd.128
return|return
name|_mm_mask_fpclass_pd_mask
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm_fpclass_pd_mask
parameter_list|(
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_fpclass_pd_mask
comment|// CHECK: @llvm.x86.avx512.mask.fpclass.pd.128
return|return
name|_mm_fpclass_pd_mask
argument_list|(
name|__A
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm256_mask_fpclass_pd_mask
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_fpclass_pd_mask
comment|// CHECK: @llvm.x86.avx512.mask.fpclass.pd.256
return|return
name|_mm256_mask_fpclass_pd_mask
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm256_fpclass_pd_mask
parameter_list|(
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_fpclass_pd_mask
comment|// CHECK: @llvm.x86.avx512.mask.fpclass.pd.256
return|return
name|_mm256_fpclass_pd_mask
argument_list|(
name|__A
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm_mask_fpclass_ps_mask
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_fpclass_ps_mask
comment|// CHECK: @llvm.x86.avx512.mask.fpclass.ps.128
return|return
name|_mm_mask_fpclass_ps_mask
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm_fpclass_ps_mask
parameter_list|(
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_fpclass_ps_mask
comment|// CHECK: @llvm.x86.avx512.mask.fpclass.ps.128
return|return
name|_mm_fpclass_ps_mask
argument_list|(
name|__A
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm256_mask_fpclass_ps_mask
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_fpclass_ps_mask
comment|// CHECK: @llvm.x86.avx512.mask.fpclass.ps.256
return|return
name|_mm256_mask_fpclass_ps_mask
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm256_fpclass_ps_mask
parameter_list|(
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_fpclass_ps_mask
comment|// CHECK: @llvm.x86.avx512.mask.fpclass.ps.256
return|return
name|_mm256_fpclass_ps_mask
argument_list|(
name|__A
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

end_unit

