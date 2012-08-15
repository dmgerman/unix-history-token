begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ffreestanding -triple i386-apple-darwin9 -target-cpu pentium4 -target-feature +sse4a -g -emit-llvm %s -o - | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<ammintrin.h>
end_include

begin_function
name|__m128i
name|test_extracti_si64
parameter_list|(
name|__m128i
name|x
parameter_list|)
block|{
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
comment|// CHECK: @test_extracti_si64
comment|// CHECK: @llvm.x86.sse4a.extrqi(<2 x i64> %{{[^,]+}}, i8 3, i8 2)
block|}
end_function

begin_function
name|__m128i
name|test_extract_si64
parameter_list|(
name|__m128i
name|x
parameter_list|,
name|__m128i
name|y
parameter_list|)
block|{
return|return
name|_mm_extract_si64
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
return|;
comment|// CHECK: @test_extract_si64
comment|// CHECK: @llvm.x86.sse4a.extrq(<2 x i64> %{{[^,]+}},<16 x i8> %{{[^,]+}})
block|}
end_function

begin_function
name|__m128i
name|test_inserti_si64
parameter_list|(
name|__m128i
name|x
parameter_list|,
name|__m128i
name|y
parameter_list|)
block|{
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
comment|// CHECK: @test_inserti_si64
comment|// CHECK: @llvm.x86.sse4a.insertqi(<2 x i64> %{{[^,]+}},<2 x i64> %{{[^,]+}}, i8 5, i8 6)
block|}
end_function

begin_function
name|__m128i
name|test_insert_si64
parameter_list|(
name|__m128i
name|x
parameter_list|,
name|__m128i
name|y
parameter_list|)
block|{
return|return
name|_mm_insert_si64
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
return|;
comment|// CHECK: @test_insert_si64
comment|// CHECK: @llvm.x86.sse4a.insertq(<2 x i64> %{{[^,]+}},<2 x i64> %{{[^,]+}})
block|}
end_function

begin_function
name|void
name|test_stream_sd
parameter_list|(
name|double
modifier|*
name|p
parameter_list|,
name|__m128d
name|a
parameter_list|)
block|{
name|_mm_stream_sd
argument_list|(
name|p
argument_list|,
name|a
argument_list|)
expr_stmt|;
comment|// CHECK: @test_stream_sd
comment|// CHECK: @llvm.x86.sse4a.movnt.sd(i8* %{{[^,]+}},<2 x double> %{{[^,]+}})
block|}
end_function

begin_function
name|void
name|test_stream_ss
parameter_list|(
name|float
modifier|*
name|p
parameter_list|,
name|__m128
name|a
parameter_list|)
block|{
name|_mm_stream_ss
argument_list|(
name|p
argument_list|,
name|a
argument_list|)
expr_stmt|;
comment|// CHECK: @test_stream_ss
comment|// CHECK: @llvm.x86.sse4a.movnt.ss(i8* %{{[^,]+}},<4 x float> %{{[^,]+}})
block|}
end_function

end_unit

