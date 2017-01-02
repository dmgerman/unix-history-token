begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ffreestanding %s -triple=x86_64-apple-darwin -target-feature +sse4.2 -emit-llvm -o - -Wall -Werror | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -ffreestanding %s -triple=x86_64-apple-darwin -target-feature +sse4.2 -fno-signed-char -emit-llvm -o - -Wall -Werror | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<x86intrin.h>
end_include

begin_comment
comment|// NOTE: This should match the tests in llvm/test/CodeGen/X86/sse42-intrinsics-fast-isel.ll
end_comment

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
comment|// CHECK-LABEL: test_mm_cmpestra
comment|// CHECK: call i32 @llvm.x86.sse42.pcmpestria128(<16 x i8> %{{.*}}, i32 %{{.*}},<16 x i8> %{{.*}}, i32 %{{.*}}, i8 7)
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
comment|// CHECK-LABEL: test_mm_cmpestrc
comment|// CHECK: call i32 @llvm.x86.sse42.pcmpestric128(<16 x i8> %{{.*}}, i32 %{{.*}},<16 x i8> %{{.*}}, i32 %{{.*}}, i8 7)
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
comment|// CHECK-LABEL: test_mm_cmpestri
comment|// CHECK: call i32 @llvm.x86.sse42.pcmpestri128(<16 x i8> %{{.*}}, i32 %{{.*}},<16 x i8> %{{.*}}, i32 %{{.*}}, i8 7)
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
comment|// CHECK-LABEL: test_mm_cmpestrm
comment|// CHECK: call<16 x i8> @llvm.x86.sse42.pcmpestrm128(<16 x i8> %{{.*}}, i32 %{{.*}},<16 x i8> %{{.*}}, i32 %{{.*}}, i8 7)
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
comment|// CHECK-LABEL: test_mm_cmpestro
comment|// CHECK: call i32 @llvm.x86.sse42.pcmpestrio128(<16 x i8> %{{.*}}, i32 %{{.*}},<16 x i8> %{{.*}}, i32 %{{.*}}, i8 7)
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
comment|// CHECK-LABEL: test_mm_cmpestrs
comment|// CHECK: call i32 @llvm.x86.sse42.pcmpestris128(<16 x i8> %{{.*}}, i32 %{{.*}},<16 x i8> %{{.*}}, i32 %{{.*}}, i8 7)
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
comment|// CHECK-LABEL: test_mm_cmpestrz
comment|// CHECK: call i32 @llvm.x86.sse42.pcmpestriz128(<16 x i8> %{{.*}}, i32 %{{.*}},<16 x i8> %{{.*}}, i32 %{{.*}}, i8 7)
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
name|test_mm_cmpgt_epi64
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cmpgt_epi64
comment|// CHECK: icmp sgt<2 x i64>
return|return
name|_mm_cmpgt_epi64
argument_list|(
name|A
argument_list|,
name|B
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
comment|// CHECK-LABEL: test_mm_cmpistra
comment|// CHECK: call i32 @llvm.x86.sse42.pcmpistria128(<16 x i8> %{{.*}},<16 x i8> %{{.*}}, i8 7)
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
comment|// CHECK-LABEL: test_mm_cmpistrc
comment|// CHECK: call i32 @llvm.x86.sse42.pcmpistric128(<16 x i8> %{{.*}},<16 x i8> %{{.*}}, i8 7)
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
name|test_mm_cmpistri
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cmpistri
comment|// CHECK: call i32 @llvm.x86.sse42.pcmpistri128(<16 x i8> %{{.*}},<16 x i8> %{{.*}}, i8 7)
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
comment|// CHECK-LABEL: test_mm_cmpistrm
comment|// CHECK: call<16 x i8> @llvm.x86.sse42.pcmpistrm128(<16 x i8> %{{.*}},<16 x i8> %{{.*}}, i8 7)
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
name|test_mm_cmpistro
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cmpistro
comment|// CHECK: call i32 @llvm.x86.sse42.pcmpistrio128(<16 x i8> %{{.*}},<16 x i8> %{{.*}}, i8 7)
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
comment|// CHECK-LABEL: test_mm_cmpistrs
comment|// CHECK: call i32 @llvm.x86.sse42.pcmpistris128(<16 x i8> %{{.*}},<16 x i8> %{{.*}}, i8 7)
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
comment|// CHECK-LABEL: test_mm_cmpistrz
comment|// CHECK: call i32 @llvm.x86.sse42.pcmpistriz128(<16 x i8> %{{.*}},<16 x i8> %{{.*}}, i8 7)
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
name|unsigned
name|int
name|test_mm_crc32_u8
parameter_list|(
name|unsigned
name|int
name|CRC
parameter_list|,
name|unsigned
name|char
name|V
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_crc32_u8
comment|// CHECK: call i32 @llvm.x86.sse42.crc32.32.8(i32 %{{.*}}, i8 %{{.*}})
return|return
name|_mm_crc32_u8
argument_list|(
name|CRC
argument_list|,
name|V
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|int
name|test_mm_crc32_u16
parameter_list|(
name|unsigned
name|int
name|CRC
parameter_list|,
name|unsigned
name|short
name|V
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_crc32_u16
comment|// CHECK: call i32 @llvm.x86.sse42.crc32.32.16(i32 %{{.*}}, i16 %{{.*}})
return|return
name|_mm_crc32_u16
argument_list|(
name|CRC
argument_list|,
name|V
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|int
name|test_mm_crc32_u32
parameter_list|(
name|unsigned
name|int
name|CRC
parameter_list|,
name|unsigned
name|int
name|V
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_crc32_u32
comment|// CHECK: call i32 @llvm.x86.sse42.crc32.32.32(i32 %{{.*}}, i32 %{{.*}})
return|return
name|_mm_crc32_u32
argument_list|(
name|CRC
argument_list|,
name|V
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|long
name|long
name|test_mm_crc32_u64
parameter_list|(
name|unsigned
name|long
name|long
name|CRC
parameter_list|,
name|unsigned
name|long
name|long
name|V
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_crc32_u64
comment|// CHECK: call i64 @llvm.x86.sse42.crc32.64.64(i64 %{{.*}}, i64 %{{.*}})
return|return
name|_mm_crc32_u64
argument_list|(
name|CRC
argument_list|,
name|V
argument_list|)
return|;
block|}
end_function

end_unit

