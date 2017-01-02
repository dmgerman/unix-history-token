begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ffreestanding %s -O3 -triple=x86_64-apple-darwin -target-feature +avx -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// FIXME: This is testing optimized generation of shuffle instructions and should be fixed.
end_comment

begin_include
include|#
directive|include
file|<immintrin.h>
end_include

begin_comment
comment|//
end_comment

begin_comment
comment|// Test LLVM IR codegen of shuffle instructions
end_comment

begin_comment
comment|//
end_comment

begin_function
name|__m256
name|x
parameter_list|(
name|__m256
name|a
parameter_list|,
name|__m256
name|b
parameter_list|)
block|{
comment|// Check if the mask is correct
comment|// CHECK: shufflevector{{.*}}<i32 3, i32 2, i32 8, i32 11, i32 7, i32 6, i32 12, i32 15>
return|return
name|_mm256_shuffle_ps
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|203
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_permute_pd
parameter_list|(
name|__m128d
name|a
parameter_list|)
block|{
comment|// Check if the mask is correct
comment|// CHECK: shufflevector{{.*}}<i32 1, i32 0>
return|return
name|_mm_permute_pd
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_permute_pd
parameter_list|(
name|__m256d
name|a
parameter_list|)
block|{
comment|// Check if the mask is correct
comment|// CHECK: shufflevector{{.*}}<i32 1, i32 0, i32 3, i32 2>
return|return
name|_mm256_permute_pd
argument_list|(
name|a
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_permute_ps
parameter_list|(
name|__m128
name|a
parameter_list|)
block|{
comment|// Check if the mask is correct
comment|// CHECK: shufflevector{{.*}}<i32 3, i32 2, i32 1, i32 0>
return|return
name|_mm_permute_ps
argument_list|(
name|a
argument_list|,
literal|0x1b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Test case for PR12401
end_comment

begin_function
name|__m128
name|test_mm_permute_ps2
parameter_list|(
name|__m128
name|a
parameter_list|)
block|{
comment|// Check if the mask is correct
comment|// CHECK: shufflevector{{.*}}<i32 2, i32 1, i32 2, i32 3>
return|return
name|_mm_permute_ps
argument_list|(
name|a
argument_list|,
literal|0xe6
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_permute_ps
parameter_list|(
name|__m256
name|a
parameter_list|)
block|{
comment|// Check if the mask is correct
comment|// CHECK: shufflevector{{.*}}<i32 3, i32 2, i32 1, i32 0, i32 7, i32 6, i32 5, i32 4>
return|return
name|_mm256_permute_ps
argument_list|(
name|a
argument_list|,
literal|0x1b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_permute2f128_pd
parameter_list|(
name|__m256d
name|a
parameter_list|,
name|__m256d
name|b
parameter_list|)
block|{
comment|// Check if the mask is correct
comment|// CHECK: shufflevector{{.*}}<i32 2, i32 3, i32 6, i32 7>
return|return
name|_mm256_permute2f128_pd
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
name|__m256
name|test_mm256_permute2f128_ps
parameter_list|(
name|__m256
name|a
parameter_list|,
name|__m256
name|b
parameter_list|)
block|{
comment|// Check if the mask is correct
comment|// CHECK: shufflevector{{.*}}<i32 4, i32 5, i32 6, i32 7, i32 12, i32 13, i32 14, i32 15>
return|return
name|_mm256_permute2f128_ps
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0x13
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_permute2f128_si256
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// Check if the mask is correct
comment|// CHECK: shufflevector{{.*}}<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 8, i32 9, i32 10, i32 11>
return|return
name|_mm256_permute2f128_si256
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0x20
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_broadcast_ss
parameter_list|(
name|float
specifier|const
modifier|*
name|__a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_broadcast_ss
comment|// CHECK: insertelement<4 x float> {{.*}}, i32 0
comment|// CHECK: shufflevector<4 x float> {{.*}},<4 x float> undef,<4 x i32> zeroinitializer
return|return
name|_mm_broadcast_ss
argument_list|(
name|__a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_broadcast_sd
parameter_list|(
name|double
specifier|const
modifier|*
name|__a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_broadcast_sd
comment|// CHECK: insertelement<4 x double> {{.*}}, i32 0
comment|// CHECK: shufflevector<4 x double> {{.*}},<4 x double> undef,<4 x i32> zeroinitializer
return|return
name|_mm256_broadcast_sd
argument_list|(
name|__a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_broadcast_ss
parameter_list|(
name|float
specifier|const
modifier|*
name|__a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_broadcast_ss
comment|// CHECK: insertelement<8 x float> {{.*}}, i32 0
comment|// CHECK: shufflevector<8 x float> {{.*}},<8 x float> undef,<8 x i32> zeroinitializer
return|return
name|_mm256_broadcast_ss
argument_list|(
name|__a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Make sure we have the correct mask for each insertf128 case.
end_comment

begin_function
name|__m256
name|test_mm256_insertf128_ps_0
parameter_list|(
name|__m256
name|a
parameter_list|,
name|__m128
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_insertf128_ps_0
comment|// CHECK: shufflevector{{.*}}<i32 8, i32 9, i32 10, i32 11, i32 4, i32 5, i32 6, i32 7>
return|return
name|_mm256_insertf128_ps
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
name|__m256d
name|test_mm256_insertf128_pd_0
parameter_list|(
name|__m256d
name|a
parameter_list|,
name|__m128d
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_insertf128_pd_0
comment|// CHECK: shufflevector{{.*}}<i32 4, i32 5, i32 2, i32 3>
return|return
name|_mm256_insertf128_pd
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
name|test_mm256_insertf128_si256_0
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_insertf128_si256_0
comment|// CHECK: shufflevector{{.*}}<i32 4, i32 5, i32 2, i32 3>
return|return
name|_mm256_insertf128_si256
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
name|__m256
name|test_mm256_insertf128_ps_1
parameter_list|(
name|__m256
name|a
parameter_list|,
name|__m128
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_insertf128_ps_1
comment|// CHECK: shufflevector{{.*}}<i32 0, i32 1, i32 2, i32 3, i32 8, i32 9, i32 10, i32 11>
return|return
name|_mm256_insertf128_ps
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

begin_function
name|__m256d
name|test_mm256_insertf128_pd_1
parameter_list|(
name|__m256d
name|a
parameter_list|,
name|__m128d
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_insertf128_pd_1
comment|// CHECK: shufflevector{{.*}}<i32 0, i32 1, i32 4, i32 5>
return|return
name|_mm256_insertf128_pd
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

begin_function
name|__m256i
name|test_mm256_insertf128_si256_1
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_insertf128_si256_1
comment|// CHECK: shufflevector{{.*}}<i32 0, i32 1, i32 4, i32 5>
return|return
name|_mm256_insertf128_si256
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
comment|// Make sure we have the correct mask for each extractf128 case.
end_comment

begin_function
name|__m128
name|test_mm256_extractf128_ps_0
parameter_list|(
name|__m256
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_extractf128_ps_0
comment|// CHECK: shufflevector{{.*}}<i32 0, i32 1, i32 2, i32 3>
return|return
name|_mm256_extractf128_ps
argument_list|(
name|a
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm256_extractf128_pd_0
parameter_list|(
name|__m256d
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_extractf128_pd_0
comment|// CHECK: shufflevector{{.*}}<i32 0, i32 1>
return|return
name|_mm256_extractf128_pd
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
name|test_mm256_extractf128_si256_0
parameter_list|(
name|__m256i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_extractf128_si256_0
comment|// CHECK: shufflevector{{.*}}<i32 0, i32 1>
return|return
name|_mm256_extractf128_si256
argument_list|(
name|a
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm256_extractf128_ps_1
parameter_list|(
name|__m256
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_extractf128_ps_1
comment|// CHECK: shufflevector{{.*}}<i32 4, i32 5, i32 6, i32 7>
return|return
name|_mm256_extractf128_ps
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm256_extractf128_pd_1
parameter_list|(
name|__m256d
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_extractf128_pd_1
comment|// CHECK: shufflevector{{.*}}<i32 2, i32 3>
return|return
name|_mm256_extractf128_pd
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
name|test_mm256_extractf128_si256_1
parameter_list|(
name|__m256i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_extractf128_si256_1
comment|// CHECK: shufflevector{{.*}}<i32 2, i32 3>
return|return
name|_mm256_extractf128_si256
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_set_m128
parameter_list|(
name|__m128
name|hi
parameter_list|,
name|__m128
name|lo
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_set_m128
comment|// CHECK: shufflevector{{.*}}<i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
return|return
name|_mm256_set_m128
argument_list|(
name|hi
argument_list|,
name|lo
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_set_m128d
parameter_list|(
name|__m128d
name|hi
parameter_list|,
name|__m128d
name|lo
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_set_m128d
comment|// CHECK: shufflevector{{.*}}<i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
return|return
name|_mm256_set_m128d
argument_list|(
name|hi
argument_list|,
name|lo
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_set_m128i
parameter_list|(
name|__m128i
name|hi
parameter_list|,
name|__m128i
name|lo
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_set_m128i
comment|// CHECK: shufflevector{{.*}}<i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
return|return
name|_mm256_set_m128i
argument_list|(
name|hi
argument_list|,
name|lo
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_setr_m128
parameter_list|(
name|__m128
name|hi
parameter_list|,
name|__m128
name|lo
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_setr_m128
comment|// CHECK: shufflevector{{.*}}<i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
return|return
name|_mm256_setr_m128
argument_list|(
name|lo
argument_list|,
name|hi
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_setr_m128d
parameter_list|(
name|__m128d
name|hi
parameter_list|,
name|__m128d
name|lo
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_setr_m128d
comment|// CHECK: shufflevector{{.*}}<i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
return|return
name|_mm256_setr_m128d
argument_list|(
name|lo
argument_list|,
name|hi
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_setr_m128i
parameter_list|(
name|__m128i
name|hi
parameter_list|,
name|__m128i
name|lo
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_setr_m128i
comment|// CHECK: shufflevector{{.*}}<i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
return|return
name|_mm256_setr_m128i
argument_list|(
name|lo
argument_list|,
name|hi
argument_list|)
return|;
block|}
end_function

end_unit

