begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -triple=x86_64-apple-darwin -target-feature +clflushopt  -emit-llvm -o - -Wall -Werror | FileCheck %s
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
name|void
name|test_mm_clflushopt
parameter_list|(
name|char
modifier|*
name|__m
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm_clflushopt
comment|//CHECK: @llvm.x86.clflushopt
name|_mm_clflushopt
argument_list|(
name|__m
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

