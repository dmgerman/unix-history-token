begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -O3 -triple=x86_64-apple-darwin -target-feature +f16c -emit-llvm -o - | FileCheck %s
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
name|__m128
name|test_mm_cvtph_ps
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK: @llvm.x86.vcvtph2ps.128
return|return
name|_mm_cvtph_ps
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_cvtph_ps
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK: @llvm.x86.vcvtph2ps.256
return|return
name|_mm256_cvtph_ps
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_cvtps_ph
parameter_list|(
name|__m128
name|a
parameter_list|)
block|{
comment|// CHECK: @llvm.x86.vcvtps2ph.128
return|return
name|_mm_cvtps_ph
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
name|test_mm256_cvtps_ph
parameter_list|(
name|__m256
name|a
parameter_list|)
block|{
comment|// CHECK: @llvm.x86.vcvtps2ph.256
return|return
name|_mm256_cvtps_ph
argument_list|(
name|a
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

end_unit

