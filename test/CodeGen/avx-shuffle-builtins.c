begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -O3 -triple=x86_64-apple-darwin -target-feature +avx -emit-llvm -o - | FileCheck %s
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
comment|// CHECK: @llvm.x86.avx.vperm2f128.pd.256
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
comment|// CHECK: @llvm.x86.avx.vperm2f128.ps.256
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
comment|// CHECK: @llvm.x86.avx.vperm2f128.si.256
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
comment|// CHECK: insertelement<4 x float> {{.*}}, i32 1
comment|// CHECK: insertelement<4 x float> {{.*}}, i32 2
comment|// CHECK: insertelement<4 x float> {{.*}}, i32 3
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
comment|// CHECK: insertelement<4 x double> {{.*}}, i32 1
comment|// CHECK: insertelement<4 x double> {{.*}}, i32 2
comment|// CHECK: insertelement<4 x double> {{.*}}, i32 3
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
comment|// CHECK: insertelement<8 x float> {{.*}}, i32 1
comment|// CHECK: insertelement<8 x float> {{.*}}, i32 2
comment|// CHECK: insertelement<8 x float> {{.*}}, i32 3
comment|// CHECK: insertelement<8 x float> {{.*}}, i32 4
comment|// CHECK: insertelement<8 x float> {{.*}}, i32 5
comment|// CHECK: insertelement<8 x float> {{.*}}, i32 6
comment|// CHECK: insertelement<8 x float> {{.*}}, i32 7
return|return
name|_mm256_broadcast_ss
argument_list|(
name|__a
argument_list|)
return|;
block|}
end_function

end_unit

