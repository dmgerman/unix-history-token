begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ffreestanding %s -triple=x86_64-apple-darwin -target-feature +sse4a -emit-llvm -o - -Wall -Werror | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<x86intrin.h>
end_include

begin_comment
comment|// NOTE: This should match the tests in llvm/test/CodeGen/X86/sse4a-intrinsics-fast-isel.ll
end_comment

begin_function
name|__m128i
name|test_mm_extracti_si64
parameter_list|(
name|__m128i
name|x
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_extracti_si64
comment|// CHECK: call<2 x i64> @llvm.x86.sse4a.extrqi(<2 x i64> %{{[^,]+}}, i8 3, i8 2)
return|return
name|_mm_extracti_si64
argument_list|(
name|x
argument_list|,
literal|3
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_extract_si64
parameter_list|(
name|__m128i
name|x
parameter_list|,
name|__m128i
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_extract_si64
comment|// CHECK: call<2 x i64> @llvm.x86.sse4a.extrq(<2 x i64> %{{[^,]+}},<16 x i8> %{{[^,]+}})
return|return
name|_mm_extract_si64
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_inserti_si64
parameter_list|(
name|__m128i
name|x
parameter_list|,
name|__m128i
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_inserti_si64
comment|// CHECK: call<2 x i64> @llvm.x86.sse4a.insertqi(<2 x i64> %{{[^,]+}},<2 x i64> %{{[^,]+}}, i8 5, i8 6)
return|return
name|_mm_inserti_si64
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
literal|5
argument_list|,
literal|6
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_insert_si64
parameter_list|(
name|__m128i
name|x
parameter_list|,
name|__m128i
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_insert_si64
comment|// CHECK: call<2 x i64> @llvm.x86.sse4a.insertq(<2 x i64> %{{[^,]+}},<2 x i64> %{{[^,]+}})
return|return
name|_mm_insert_si64
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm_stream_sd
parameter_list|(
name|double
modifier|*
name|p
parameter_list|,
name|__m128d
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_stream_sd
comment|// CHECK: extractelement<2 x double> %{{.*}}, i64 0
comment|// CHECK: store double %{{.*}}, double* %{{.*}}, align 1, !nontemporal
name|_mm_stream_sd
argument_list|(
name|p
argument_list|,
name|a
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_mm_stream_ss
parameter_list|(
name|float
modifier|*
name|p
parameter_list|,
name|__m128
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_stream_ss
comment|// CHECK: extractelement<4 x float> %{{.*}}, i64 0
comment|// CHECK: store float %{{.*}}, float* %{{.*}}, align 1, !nontemporal
name|_mm_stream_ss
argument_list|(
name|p
argument_list|,
name|a
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

