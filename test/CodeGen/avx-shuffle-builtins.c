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

end_unit

