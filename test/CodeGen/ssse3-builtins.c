begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ffreestanding %s -triple=x86_64-apple-darwin -target-feature +ssse3 -emit-llvm -o - -Wall -Werror | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<x86intrin.h>
end_include

begin_comment
comment|// NOTE: This should match the tests in llvm/test/CodeGen/X86/ssse3-intrinsics-fast-isel.ll
end_comment

begin_function
name|__m128i
name|test_mm_abs_epi8
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_abs_epi8
comment|// CHECK: call<16 x i8> @llvm.x86.ssse3.pabs.b.128(<16 x i8> %{{.*}})
return|return
name|_mm_abs_epi8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_abs_epi16
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_abs_epi16
comment|// CHECK: call<8 x i16> @llvm.x86.ssse3.pabs.w.128(<8 x i16> %{{.*}})
return|return
name|_mm_abs_epi16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_abs_epi32
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_abs_epi32
comment|// CHECK: call<4 x i32> @llvm.x86.ssse3.pabs.d.128(<4 x i32> %{{.*}})
return|return
name|_mm_abs_epi32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_alignr_epi8
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_alignr_epi8
comment|// CHECK: shufflevector<16 x i8> %{{.*}},<16 x i8> %{{.*}},<16 x i32><i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15, i32 16, i32 17>
return|return
name|_mm_alignr_epi8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test2_mm_alignr_epi8
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test2_mm_alignr_epi8
comment|// CHECK: shufflevector<16 x i8> %{{.*}},<16 x i8> zeroinitializer,<16 x i32><i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15, i32 16>
return|return
name|_mm_alignr_epi8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|17
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_hadd_epi16
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_hadd_epi16
comment|// CHECK: call<8 x i16> @llvm.x86.ssse3.phadd.w.128(<8 x i16> %{{.*}},<8 x i16> %{{.*}})
return|return
name|_mm_hadd_epi16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_hadd_epi32
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_hadd_epi32
comment|// CHECK: call<4 x i32> @llvm.x86.ssse3.phadd.d.128(<4 x i32> %{{.*}},<4 x i32> %{{.*}})
return|return
name|_mm_hadd_epi32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_hadds_epi16
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_hadds_epi16
comment|// CHECK: call<8 x i16> @llvm.x86.ssse3.phadd.sw.128(<8 x i16> %{{.*}},<8 x i16> %{{.*}})
return|return
name|_mm_hadds_epi16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_hsub_epi16
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_hsub_epi16
comment|// CHECK: call<8 x i16> @llvm.x86.ssse3.phsub.w.128(<8 x i16> %{{.*}},<8 x i16> %{{.*}})
return|return
name|_mm_hsub_epi16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_hsub_epi32
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_hsub_epi32
comment|// CHECK: call<4 x i32> @llvm.x86.ssse3.phsub.d.128(<4 x i32> %{{.*}},<4 x i32> %{{.*}})
return|return
name|_mm_hsub_epi32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_hsubs_epi16
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_hsubs_epi16
comment|// CHECK: call<8 x i16> @llvm.x86.ssse3.phsub.sw.128(<8 x i16> %{{.*}},<8 x i16> %{{.*}})
return|return
name|_mm_hsubs_epi16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maddubs_epi16
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_maddubs_epi16
comment|// CHECK: call<8 x i16> @llvm.x86.ssse3.pmadd.ub.sw.128(<16 x i8> %{{.*}},<16 x i8> %{{.*}})
return|return
name|_mm_maddubs_epi16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mulhrs_epi16
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_mulhrs_epi16
comment|// CHECK: call<8 x i16> @llvm.x86.ssse3.pmul.hr.sw.128(<8 x i16> %{{.*}},<8 x i16> %{{.*}})
return|return
name|_mm_mulhrs_epi16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_shuffle_epi8
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_shuffle_epi8
comment|// CHECK: call<16 x i8> @llvm.x86.ssse3.pshuf.b.128(<16 x i8> %{{.*}},<16 x i8> %{{.*}})
return|return
name|_mm_shuffle_epi8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_sign_epi8
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_sign_epi8
comment|// CHECK: call<16 x i8> @llvm.x86.ssse3.psign.b.128(<16 x i8> %{{.*}},<16 x i8> %{{.*}})
return|return
name|_mm_sign_epi8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_sign_epi16
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_sign_epi16
comment|// CHECK: call<8 x i16> @llvm.x86.ssse3.psign.w.128(<8 x i16> %{{.*}},<8 x i16> %{{.*}})
return|return
name|_mm_sign_epi16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_sign_epi32
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_sign_epi32
comment|// CHECK: call<4 x i32> @llvm.x86.ssse3.psign.d.128(<4 x i32> %{{.*}},<4 x i32> %{{.*}})
return|return
name|_mm_sign_epi32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

end_unit

