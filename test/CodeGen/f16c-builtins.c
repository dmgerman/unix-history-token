begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ffreestanding %s -triple=x86_64-apple-darwin -target-feature +f16c -emit-llvm -o - -Wall -Werror | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<x86intrin.h>
end_include

begin_function
name|float
name|test_cvtsh_ss
parameter_list|(
name|unsigned
name|short
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_cvtsh_ss
comment|// CHECK: insertelement<8 x i16> undef, i16 %{{.*}}, i32 0
comment|// CHECK: insertelement<8 x i16> %{{.*}}, i16 0, i32 1
comment|// CHECK: insertelement<8 x i16> %{{.*}}, i16 0, i32 2
comment|// CHECK: insertelement<8 x i16> %{{.*}}, i16 0, i32 3
comment|// CHECK: insertelement<8 x i16> %{{.*}}, i16 0, i32 4
comment|// CHECK: insertelement<8 x i16> %{{.*}}, i16 0, i32 5
comment|// CHECK: insertelement<8 x i16> %{{.*}}, i16 0, i32 6
comment|// CHECK: insertelement<8 x i16> %{{.*}}, i16 0, i32 7
comment|// CHECK: call<4 x float> @llvm.x86.vcvtph2ps.128(<8 x i16> %{{.*}})
comment|// CHECK: extractelement<4 x float> %{{.*}}, i32 0
return|return
name|_cvtsh_ss
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|short
name|test_cvtss_sh
parameter_list|(
name|float
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_cvtss_sh
comment|// CHECK: insertelement<4 x float> undef, float %{{.*}}, i32 0
comment|// CHECK: insertelement<4 x float> %{{.*}}, float 0.000000e+00, i32 1
comment|// CHECK: insertelement<4 x float> %{{.*}}, float 0.000000e+00, i32 2
comment|// CHECK: insertelement<4 x float> %{{.*}}, float 0.000000e+00, i32 3
comment|// CHECK: call<8 x i16> @llvm.x86.vcvtps2ph.128(<4 x float> %{{.*}}, i32 0)
comment|// CHECK: extractelement<8 x i16> %{{.*}}, i32 0
return|return
name|_cvtss_sh
argument_list|(
name|a
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_cvtph_ps
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvtph_ps
comment|// CHECK: call<4 x float> @llvm.x86.vcvtph2ps.128(<8 x i16> %{{.*}})
return|return
name|_mm_cvtph_ps
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_cvtph_ps
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_cvtph_ps
comment|// CHECK: call<8 x float> @llvm.x86.vcvtph2ps.256(<8 x i16> %{{.*}})
return|return
name|_mm256_cvtph_ps
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_cvtps_ph
parameter_list|(
name|__m128
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvtps_ph
comment|// CHECK: call<8 x i16> @llvm.x86.vcvtps2ph.128(<4 x float> %{{.*}}, i32 0)
return|return
name|_mm_cvtps_ph
argument_list|(
name|a
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm256_cvtps_ph
parameter_list|(
name|__m256
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_cvtps_ph
comment|// CHECK: call<8 x i16> @llvm.x86.vcvtps2ph.256(<8 x float> %{{.*}}, i32 0)
return|return
name|_mm256_cvtps_ph
argument_list|(
name|a
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

end_unit

