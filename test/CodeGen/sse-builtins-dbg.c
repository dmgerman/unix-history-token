begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ffreestanding -triple x86_64-apple-macosx10.8.0 -target-feature +sse4.1 -g -emit-llvm %s -o - | FileCheck %s
end_comment

begin_comment
comment|// Test that intrinsic calls inlined from _mm_* wrappers have debug metadata.
end_comment

begin_include
include|#
directive|include
file|<xmmintrin.h>
end_include

begin_function
name|__m128
name|test_rsqrt_ss
parameter_list|(
name|__m128
name|x
parameter_list|)
block|{
comment|// CHECK: define {{.*}} @test_rsqrt_ss
comment|// CHECK: call<4 x float> @llvm.x86.sse.rsqrt.ss({{.*}}, !dbg !{{.*}}
comment|// CHECK: ret<4 x float>
return|return
name|_mm_rsqrt_ss
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

end_unit

