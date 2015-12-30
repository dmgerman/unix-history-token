begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -triple=x86_64-apple-darwin -target-feature +avx -emit-llvm -o - | FileCheck %s
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
comment|// CHECK: load<8 x float>,<8 x float>* %{{.*}}, align 1
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
comment|// CHECK: load<4 x double>,<4 x double>* %{{.*}}, align 1
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
comment|// CHECK: load<4 x i64>,<4 x i64>* %{{.+}}, align 1
return|return
name|_mm256_loadu_si256
argument_list|(
name|p
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_cmpestrm
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|int
name|LA
parameter_list|,
name|__m128i
name|B
parameter_list|,
name|int
name|LB
parameter_list|)
block|{
comment|// CHECK: @llvm.x86.sse42.pcmpestrm128
return|return
name|_mm_cmpestrm
argument_list|(
name|A
argument_list|,
name|LA
argument_list|,
name|B
argument_list|,
name|LB
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm_cmpestri
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|int
name|LA
parameter_list|,
name|__m128i
name|B
parameter_list|,
name|int
name|LB
parameter_list|)
block|{
comment|// CHECK: @llvm.x86.sse42.pcmpestri128
return|return
name|_mm_cmpestri
argument_list|(
name|A
argument_list|,
name|LA
argument_list|,
name|B
argument_list|,
name|LB
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm_cmpestra
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|int
name|LA
parameter_list|,
name|__m128i
name|B
parameter_list|,
name|int
name|LB
parameter_list|)
block|{
comment|// CHECK: @llvm.x86.sse42.pcmpestria128
return|return
name|_mm_cmpestra
argument_list|(
name|A
argument_list|,
name|LA
argument_list|,
name|B
argument_list|,
name|LB
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm_cmpestrc
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|int
name|LA
parameter_list|,
name|__m128i
name|B
parameter_list|,
name|int
name|LB
parameter_list|)
block|{
comment|// CHECK: @llvm.x86.sse42.pcmpestric128
return|return
name|_mm_cmpestrc
argument_list|(
name|A
argument_list|,
name|LA
argument_list|,
name|B
argument_list|,
name|LB
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm_cmpestro
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|int
name|LA
parameter_list|,
name|__m128i
name|B
parameter_list|,
name|int
name|LB
parameter_list|)
block|{
comment|// CHECK: @llvm.x86.sse42.pcmpestrio128
return|return
name|_mm_cmpestro
argument_list|(
name|A
argument_list|,
name|LA
argument_list|,
name|B
argument_list|,
name|LB
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm_cmpestrs
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|int
name|LA
parameter_list|,
name|__m128i
name|B
parameter_list|,
name|int
name|LB
parameter_list|)
block|{
comment|// CHECK: @llvm.x86.sse42.pcmpestris128
return|return
name|_mm_cmpestrs
argument_list|(
name|A
argument_list|,
name|LA
argument_list|,
name|B
argument_list|,
name|LB
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm_cmpestrz
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|int
name|LA
parameter_list|,
name|__m128i
name|B
parameter_list|,
name|int
name|LB
parameter_list|)
block|{
comment|// CHECK: @llvm.x86.sse42.pcmpestriz128
return|return
name|_mm_cmpestrz
argument_list|(
name|A
argument_list|,
name|LA
argument_list|,
name|B
argument_list|,
name|LB
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_cmpistrm
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK: @llvm.x86.sse42.pcmpistrm128
return|return
name|_mm_cmpistrm
argument_list|(
name|A
argument_list|,
name|B
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm_cmpistri
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK: @llvm.x86.sse42.pcmpistri128
return|return
name|_mm_cmpistri
argument_list|(
name|A
argument_list|,
name|B
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm_cmpistra
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK: @llvm.x86.sse42.pcmpistria128
return|return
name|_mm_cmpistra
argument_list|(
name|A
argument_list|,
name|B
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm_cmpistrc
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK: @llvm.x86.sse42.pcmpistric128
return|return
name|_mm_cmpistrc
argument_list|(
name|A
argument_list|,
name|B
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm_cmpistro
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK: @llvm.x86.sse42.pcmpistrio128
return|return
name|_mm_cmpistro
argument_list|(
name|A
argument_list|,
name|B
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm_cmpistrs
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK: @llvm.x86.sse42.pcmpistris128
return|return
name|_mm_cmpistrs
argument_list|(
name|A
argument_list|,
name|B
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm_cmpistrz
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK: @llvm.x86.sse42.pcmpistriz128
return|return
name|_mm_cmpistrz
argument_list|(
name|A
argument_list|,
name|B
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_extract_epi32
parameter_list|(
name|__m256i
name|__a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_extract_epi32
comment|// CHECK: [[SHIFT1:%[^ ]+]] = and i32 %{{.*}}, 7
comment|// CHECK: extractelement<8 x i32> %{{.*}}, i32 [[SHIFT1]]
return|return
name|_mm256_extract_epi32
argument_list|(
name|__a
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_extract_epi16
parameter_list|(
name|__m256i
name|__a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_extract_epi16
comment|// CHECK: [[SHIFT2:%[^ ]+]] = and i32 %{{.*}}, 15
comment|// CHECK: extractelement<16 x i16> %{{.*}}, i32 [[SHIFT2]]
return|return
name|_mm256_extract_epi16
argument_list|(
name|__a
argument_list|,
literal|16
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_extract_epi8
parameter_list|(
name|__m256i
name|__a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_extract_epi8
comment|// CHECK: [[SHIFT3:%[^ ]+]] = and i32 %{{.*}}, 31
comment|// CHECK: extractelement<32 x i8> %{{.*}}, i32 [[SHIFT3]]
return|return
name|_mm256_extract_epi8
argument_list|(
name|__a
argument_list|,
literal|32
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_256_blend_pd
parameter_list|(
name|__m256d
name|__a
parameter_list|,
name|__m256d
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_256_blend_pd
comment|// CHECK: shufflevector<4 x double> %{{.*}},<4 x double> %{{.*}},<4 x i32><i32 4, i32 1, i32 6, i32 3>
return|return
name|_mm256_blend_pd
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|,
literal|0x35
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_256_blend_ps
parameter_list|(
name|__m256
name|__a
parameter_list|,
name|__m256
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_256_blend_ps
comment|// CHECK: shufflevector<8 x float> %{{.*}},<8 x float> %{{.*}},<8 x i32><i32 8, i32 1, i32 10, i32 3, i32 12, i32 13, i32 6, i32 7>
return|return
name|_mm256_blend_ps
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|,
literal|0x35
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_256_insert_epi8
parameter_list|(
name|__m256i
name|__a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_256_insert_epi8
comment|// CHECK: insertelement<32 x i8> {{.*}}, i8 {{.*}}, i32 {{.*}}
return|return
name|_mm256_insert_epi8
argument_list|(
name|__a
argument_list|,
literal|42
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_256_insert_epi16
parameter_list|(
name|__m256i
name|__a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_256_insert_epi16
comment|// CHECK: insertelement<16 x i16> {{.*}}, i16 {{.*}}, i32 {{.*}}
return|return
name|_mm256_insert_epi16
argument_list|(
name|__a
argument_list|,
literal|42
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_256_insert_epi32
parameter_list|(
name|__m256i
name|__a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_256_insert_epi32
comment|// CHECK: insertelement<8 x i32> {{.*}}, i32 {{.*}}, i32 {{.*}}
return|return
name|_mm256_insert_epi32
argument_list|(
name|__a
argument_list|,
literal|42
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_256_insert_epi64
parameter_list|(
name|__m256i
name|__a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_256_insert_epi64
comment|// CHECK: insertelement<4 x i64> {{.*}}, i64 {{.*}}, i32 {{.*}}
return|return
name|_mm256_insert_epi64
argument_list|(
name|__a
argument_list|,
literal|42
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_undefined_ps
parameter_list|()
block|{
comment|// CHECK-LABEL: @test_mm256_undefined_ps
comment|// CHECK: ret<8 x float> undef
return|return
name|_mm256_undefined_ps
argument_list|()
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_undefined_pd
parameter_list|()
block|{
comment|// CHECK-LABEL: @test_mm256_undefined_pd
comment|// CHECK: ret<4 x double> undef
return|return
name|_mm256_undefined_pd
argument_list|()
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_undefined_si256
parameter_list|()
block|{
comment|// CHECK-LABEL: @test_mm256_undefined_si256
comment|// CHECK: ret<4 x i64> undef
return|return
name|_mm256_undefined_si256
argument_list|()
return|;
block|}
end_function

end_unit

