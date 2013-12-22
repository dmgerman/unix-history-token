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
comment|// Test LLVM IR codegen of cmpXY instructions
end_comment

begin_comment
comment|//
end_comment

begin_function
name|__m128d
name|test_cmp_pd
parameter_list|(
name|__m128d
name|a
parameter_list|,
name|__m128d
name|b
parameter_list|)
block|{
comment|// Expects that the third argument in LLVM IR is immediate expression
comment|// CHECK: @llvm.x86.sse2.cmp.pd({{.*}}, i8 13)
return|return
name|_mm_cmp_pd
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|_CMP_GE_OS
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_cmp_ps
parameter_list|(
name|__m128
name|a
parameter_list|,
name|__m128
name|b
parameter_list|)
block|{
comment|// Expects that the third argument in LLVM IR is immediate expression
comment|// CHECK: @llvm.x86.sse.cmp.ps({{.*}}, i8 13)
return|return
name|_mm_cmp_ps
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|_CMP_GE_OS
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_cmp_pd256
parameter_list|(
name|__m256d
name|a
parameter_list|,
name|__m256d
name|b
parameter_list|)
block|{
comment|// Expects that the third argument in LLVM IR is immediate expression
comment|// CHECK: @llvm.x86.avx.cmp.pd.256({{.*}}, i8 13)
return|return
name|_mm256_cmp_pd
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|_CMP_GE_OS
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_cmp_ps256
parameter_list|(
name|__m256
name|a
parameter_list|,
name|__m256
name|b
parameter_list|)
block|{
comment|// Expects that the third argument in LLVM IR is immediate expression
comment|// CHECK: @llvm.x86.avx.cmp.ps.256({{.*}}, i8 13)
return|return
name|_mm256_cmp_ps
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|_CMP_GE_OS
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_cmp_sd
parameter_list|(
name|__m128d
name|a
parameter_list|,
name|__m128d
name|b
parameter_list|)
block|{
comment|// Expects that the third argument in LLVM IR is immediate expression
comment|// CHECK: @llvm.x86.sse2.cmp.sd({{.*}}, i8 13)
return|return
name|_mm_cmp_sd
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|_CMP_GE_OS
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_cmp_ss
parameter_list|(
name|__m128
name|a
parameter_list|,
name|__m128
name|b
parameter_list|)
block|{
comment|// Expects that the third argument in LLVM IR is immediate expression
comment|// CHECK: @llvm.x86.sse.cmp.ss({{.*}}, i8 13)
return|return
name|_mm_cmp_ss
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|_CMP_GE_OS
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_cmpgt_ss
parameter_list|(
name|__m128
name|a
parameter_list|,
name|__m128
name|b
parameter_list|)
block|{
comment|// CHECK: @llvm.x86.sse.cmp.ss({{.*}}, i8 1)
comment|// CHECK: shufflevector<{{.*}},<4 x i32><i32 4, i32 1, i32 2, i32 3>
return|return
name|_mm_cmpgt_ss
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_cmpge_ss
parameter_list|(
name|__m128
name|a
parameter_list|,
name|__m128
name|b
parameter_list|)
block|{
comment|// CHECK: @llvm.x86.sse.cmp.ss({{.*}}, i8 2)
comment|// CHECK: shufflevector<{{.*}},<4 x i32><i32 4, i32 1, i32 2, i32 3>
return|return
name|_mm_cmpge_ss
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_cmpngt_ss
parameter_list|(
name|__m128
name|a
parameter_list|,
name|__m128
name|b
parameter_list|)
block|{
comment|// CHECK: @llvm.x86.sse.cmp.ss({{.*}}, i8 5)
comment|// CHECK: shufflevector<{{.*}},<4 x i32><i32 4, i32 1, i32 2, i32 3>
return|return
name|_mm_cmpngt_ss
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_cmpnge_ss
parameter_list|(
name|__m128
name|a
parameter_list|,
name|__m128
name|b
parameter_list|)
block|{
comment|// CHECK: @llvm.x86.sse.cmp.ss({{.*}}, i8 6)
comment|// CHECK: shufflevector<{{.*}},<4 x i32><i32 4, i32 1, i32 2, i32 3>
return|return
name|_mm_cmpnge_ss
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_cmpgt_sd
parameter_list|(
name|__m128d
name|a
parameter_list|,
name|__m128d
name|b
parameter_list|)
block|{
comment|// CHECK: @llvm.x86.sse2.cmp.sd({{.*}}, i8 1)
comment|// CHECK: shufflevector<{{.*}},<2 x i32><i32 0, i32 3>
return|return
name|_mm_cmpgt_sd
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_cmpge_sd
parameter_list|(
name|__m128d
name|a
parameter_list|,
name|__m128d
name|b
parameter_list|)
block|{
comment|// CHECK: @llvm.x86.sse2.cmp.sd({{.*}}, i8 2)
comment|// CHECK: shufflevector<{{.*}},<2 x i32><i32 0, i32 3>
return|return
name|_mm_cmpge_sd
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_cmpngt_sd
parameter_list|(
name|__m128d
name|a
parameter_list|,
name|__m128d
name|b
parameter_list|)
block|{
comment|// CHECK: @llvm.x86.sse2.cmp.sd({{.*}}, i8 5)
comment|// CHECK: shufflevector<{{.*}},<2 x i32><i32 0, i32 3>
return|return
name|_mm_cmpngt_sd
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_cmpnge_sd
parameter_list|(
name|__m128d
name|a
parameter_list|,
name|__m128d
name|b
parameter_list|)
block|{
comment|// CHECK: @llvm.x86.sse2.cmp.sd({{.*}}, i8 6)
comment|// CHECK: shufflevector<{{.*}},<2 x i32><i32 0, i32 3>
return|return
name|_mm_cmpnge_sd
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

end_unit

