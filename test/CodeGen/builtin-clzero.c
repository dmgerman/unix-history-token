begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -triple=x86_64-apple-darwin -target-feature +clzero  -emit-llvm -o - -Wall -Werror | FileCheck %s
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
name|void
name|test_mm_clzero
parameter_list|(
name|void
modifier|*
name|__m
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm_clzero
comment|//CHECK: @llvm.x86.clzero
name|_mm_clzero
argument_list|(
name|__m
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

