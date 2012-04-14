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
name|test__mm256_loadu_ps
parameter_list|(
name|void
modifier|*
name|p
parameter_list|)
block|{
comment|// CHECK: load<8 x float>* %{{.*}}, align 1
return|return
name|_mm256_loadu_ps
argument_list|(
name|p
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test__mm256_loadu_pd
parameter_list|(
name|void
modifier|*
name|p
parameter_list|)
block|{
comment|// CHECK: load<4 x double>* %{{.*}}, align 1
return|return
name|_mm256_loadu_pd
argument_list|(
name|p
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test__mm256_loadu_si256
parameter_list|(
name|void
modifier|*
name|p
parameter_list|)
block|{
comment|// CHECK: load<4 x i64>* %{{.+}}, align 1
return|return
name|_mm256_loadu_si256
argument_list|(
name|p
argument_list|)
return|;
block|}
end_function

end_unit

