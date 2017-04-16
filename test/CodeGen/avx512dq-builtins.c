begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ffreestanding %s -triple=x86_64-apple-darwin -target-feature +avx512dq -emit-llvm -o - -Wall -Werror | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<immintrin.h>
end_include

begin_function
name|__m512i
name|test_mm512_mullo_epi64
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mullo_epi64
comment|// CHECK: mul<8 x i64>
return|return
call|(
name|__m512i
call|)
argument_list|(
operator|(
name|__v8di
operator|)
name|__A
operator|*
operator|(
name|__v8di
operator|)
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_mullo_epi64
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_mullo_epi64
comment|// CHECK: mul<8 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
operator|(
name|__m512i
operator|)
name|_mm512_mask_mullo_epi64
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_mullo_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_mullo_epi64
comment|// CHECK: mul<8 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
operator|(
name|__m512i
operator|)
name|_mm512_maskz_mullo_epi64
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_xor_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_xor_pd
comment|// CHECK: xor<8 x i64>
return|return
operator|(
name|__m512d
operator|)
name|_mm512_xor_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_xor_pd
parameter_list|(
name|__m512d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_xor_pd
comment|// CHECK: xor<8 x i64>
comment|// CHECK: %[[MASK:.*]] = bitcast i8 %{{.*}} to<8 x i1>
comment|// CHECK: select<8 x i1> %[[MASK]],<8 x double> %{{.*}},<8 x double> %{{.*}}
return|return
operator|(
name|__m512d
operator|)
name|_mm512_mask_xor_pd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_maskz_xor_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_xor_pd
comment|// CHECK: xor<8 x i64>
comment|// CHECK: %[[MASK:.*]] = bitcast i8 %{{.*}} to<8 x i1>
comment|// CHECK: select<8 x i1> %[[MASK]],<8 x double> %{{.*}},<8 x double> %{{.*}}
return|return
operator|(
name|__m512d
operator|)
name|_mm512_maskz_xor_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_xor_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_xor_ps
comment|// CHECK: xor<16 x i32>
return|return
operator|(
name|__m512
operator|)
name|_mm512_xor_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_xor_ps
parameter_list|(
name|__m512
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_xor_ps
comment|// CHECK: xor<16 x i32>
comment|// CHECK: %[[MASK:.*]] = bitcast i16 %{{.*}} to<16 x i1>
comment|// CHECK: select<16 x i1> %[[MASK]],<16 x float> %{{.*}},<16 x float> %{{.*}}
return|return
operator|(
name|__m512
operator|)
name|_mm512_mask_xor_ps
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_maskz_xor_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_xor_ps
comment|// CHECK: xor<16 x i32>
comment|// CHECK: %[[MASK:.*]] = bitcast i16 %{{.*}} to<16 x i1>
comment|// CHECK: select<16 x i1> %[[MASK]],<16 x float> %{{.*}},<16 x float> %{{.*}}
return|return
operator|(
name|__m512
operator|)
name|_mm512_maskz_xor_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_or_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_or_pd
comment|// CHECK: or<8 x i64>
return|return
operator|(
name|__m512d
operator|)
name|_mm512_or_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_or_pd
parameter_list|(
name|__m512d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_or_pd
comment|// CHECK: or<8 x i64>
comment|// CHECK: %[[MASK:.*]] = bitcast i8 %{{.*}} to<8 x i1>
comment|// CHECK: select<8 x i1> %[[MASK]],<8 x double> %{{.*}},<8 x double> %{{.*}}
return|return
operator|(
name|__m512d
operator|)
name|_mm512_mask_or_pd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_maskz_or_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_or_pd
comment|// CHECK: or<8 x i64>
comment|// CHECK: %[[MASK:.*]] = bitcast i8 %{{.*}} to<8 x i1>
comment|// CHECK: select<8 x i1> %[[MASK]],<8 x double> %{{.*}},<8 x double> %{{.*}}
return|return
operator|(
name|__m512d
operator|)
name|_mm512_maskz_or_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_or_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_or_ps
comment|// CHECK: or<16 x i32>
return|return
operator|(
name|__m512
operator|)
name|_mm512_or_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_or_ps
parameter_list|(
name|__m512
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_or_ps
comment|// CHECK: or<16 x i32>
comment|// CHECK: %[[MASK:.*]] = bitcast i16 %{{.*}} to<16 x i1>
comment|// CHECK: select<16 x i1> %[[MASK]],<16 x float> %{{.*}},<16 x float> %{{.*}}
return|return
operator|(
name|__m512
operator|)
name|_mm512_mask_or_ps
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_maskz_or_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_or_ps
comment|// CHECK: or<16 x i32>
comment|// CHECK: %[[MASK:.*]] = bitcast i16 %{{.*}} to<16 x i1>
comment|// CHECK: select<16 x i1> %[[MASK]],<16 x float> %{{.*}},<16 x float> %{{.*}}
return|return
operator|(
name|__m512
operator|)
name|_mm512_maskz_or_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_and_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_and_pd
comment|// CHECK: and<8 x i64>
return|return
operator|(
name|__m512d
operator|)
name|_mm512_and_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_and_pd
parameter_list|(
name|__m512d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_and_pd
comment|// CHECK: and<8 x i64>
comment|// CHECK: %[[MASK:.*]] = bitcast i8 %{{.*}} to<8 x i1>
comment|// CHECK: select<8 x i1> %[[MASK]],<8 x double> %{{.*}},<8 x double> %{{.*}}
return|return
operator|(
name|__m512d
operator|)
name|_mm512_mask_and_pd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_maskz_and_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_and_pd
comment|// CHECK: and<8 x i64>
comment|// CHECK: %[[MASK:.*]] = bitcast i8 %{{.*}} to<8 x i1>
comment|// CHECK: select<8 x i1> %[[MASK]],<8 x double> %{{.*}},<8 x double> %{{.*}}
return|return
operator|(
name|__m512d
operator|)
name|_mm512_maskz_and_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_and_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_and_ps
comment|// CHECK: and<16 x i32>
return|return
operator|(
name|__m512
operator|)
name|_mm512_and_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_and_ps
parameter_list|(
name|__m512
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_and_ps
comment|// CHECK: and<16 x i32>
comment|// CHECK: %[[MASK:.*]] = bitcast i16 %{{.*}} to<16 x i1>
comment|// CHECK: select<16 x i1> %[[MASK]],<16 x float> %{{.*}},<16 x float> %{{.*}}
return|return
operator|(
name|__m512
operator|)
name|_mm512_mask_and_ps
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_maskz_and_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_and_ps
comment|// CHECK: and<16 x i32>
comment|// CHECK: %[[MASK:.*]] = bitcast i16 %{{.*}} to<16 x i1>
comment|// CHECK: select<16 x i1> %[[MASK]],<16 x float> %{{.*}},<16 x float> %{{.*}}
return|return
operator|(
name|__m512
operator|)
name|_mm512_maskz_and_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_andnot_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_andnot_pd
comment|// CHECK: xor<8 x i64> %{{.*}},<i64 -1, i64 -1, i64 -1, i64 -1, i64 -1, i64 -1, i64 -1, i64 -1>
comment|// CHECK: and<8 x i64>
return|return
operator|(
name|__m512d
operator|)
name|_mm512_andnot_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_andnot_pd
parameter_list|(
name|__m512d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_andnot_pd
comment|// CHECK: xor<8 x i64> %{{.*}},<i64 -1, i64 -1, i64 -1, i64 -1, i64 -1, i64 -1, i64 -1, i64 -1>
comment|// CHECK: and<8 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: select<8 x i1> %{{.*}},<8 x double> %{{.*}},<8 x double> %{{.*}}
return|return
operator|(
name|__m512d
operator|)
name|_mm512_mask_andnot_pd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_maskz_andnot_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_andnot_pd
comment|// CHECK: xor<8 x i64> %{{.*}},<i64 -1, i64 -1, i64 -1, i64 -1, i64 -1, i64 -1, i64 -1, i64 -1>
comment|// CHECK: and<8 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: select<8 x i1> %{{.*}},<8 x double> %{{.*}},<8 x double> %{{.*}}
return|return
operator|(
name|__m512d
operator|)
name|_mm512_maskz_andnot_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_andnot_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_andnot_ps
comment|// CHECK: xor<16 x i32> %{{.*}},<i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1>
comment|// CHECK: and<16 x i32>
return|return
operator|(
name|__m512
operator|)
name|_mm512_andnot_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_andnot_ps
parameter_list|(
name|__m512
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_andnot_ps
comment|// CHECK: xor<16 x i32> %{{.*}},<i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1>
comment|// CHECK: and<16 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: select<16 x i1> %{{.*}},<16 x float> %{{.*}},<16 x float> %{{.*}}
return|return
operator|(
name|__m512
operator|)
name|_mm512_mask_andnot_ps
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_maskz_andnot_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_andnot_ps
comment|// CHECK: xor<16 x i32> %{{.*}},<i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1>
comment|// CHECK: and<16 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: select<16 x i1> %{{.*}},<16 x float> %{{.*}},<16 x float> %{{.*}}
return|return
operator|(
name|__m512
operator|)
name|_mm512_maskz_andnot_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_cvtpd_epi64
parameter_list|(
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtpd_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2qq.512
return|return
name|_mm512_cvtpd_epi64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_cvtpd_epi64
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtpd_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2qq.512
return|return
name|_mm512_mask_cvtpd_epi64
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_cvtpd_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtpd_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2qq.512
return|return
name|_mm512_maskz_cvtpd_epi64
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_cvt_roundpd_epi64
parameter_list|(
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvt_roundpd_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2qq.512
return|return
name|_mm512_cvt_roundpd_epi64
argument_list|(
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_cvt_roundpd_epi64
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvt_roundpd_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2qq.512
return|return
name|_mm512_mask_cvt_roundpd_epi64
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_cvt_roundpd_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvt_roundpd_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2qq.512
return|return
name|_mm512_maskz_cvt_roundpd_epi64
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_cvtpd_epu64
parameter_list|(
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtpd_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2uqq.512
return|return
name|_mm512_cvtpd_epu64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_cvtpd_epu64
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtpd_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2uqq.512
return|return
name|_mm512_mask_cvtpd_epu64
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_cvtpd_epu64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtpd_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2uqq.512
return|return
name|_mm512_maskz_cvtpd_epu64
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_cvt_roundpd_epu64
parameter_list|(
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvt_roundpd_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2uqq.512
return|return
name|_mm512_cvt_roundpd_epu64
argument_list|(
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_cvt_roundpd_epu64
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvt_roundpd_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2uqq.512
return|return
name|_mm512_mask_cvt_roundpd_epu64
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_cvt_roundpd_epu64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvt_roundpd_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2uqq.512
return|return
name|_mm512_maskz_cvt_roundpd_epu64
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_cvtps_epi64
parameter_list|(
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtps_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2qq.512
return|return
name|_mm512_cvtps_epi64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_cvtps_epi64
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtps_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2qq.512
return|return
name|_mm512_mask_cvtps_epi64
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_cvtps_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtps_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2qq.512
return|return
name|_mm512_maskz_cvtps_epi64
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_cvt_roundps_epi64
parameter_list|(
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvt_roundps_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2qq.512
return|return
name|_mm512_cvt_roundps_epi64
argument_list|(
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_cvt_roundps_epi64
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvt_roundps_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2qq.512
return|return
name|_mm512_mask_cvt_roundps_epi64
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_cvt_roundps_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvt_roundps_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2qq.512
return|return
name|_mm512_maskz_cvt_roundps_epi64
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_cvtps_epu64
parameter_list|(
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtps_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2uqq.512
return|return
name|_mm512_cvtps_epu64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_cvtps_epu64
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtps_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2uqq.512
return|return
name|_mm512_mask_cvtps_epu64
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_cvtps_epu64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtps_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2uqq.512
return|return
name|_mm512_maskz_cvtps_epu64
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_cvt_roundps_epu64
parameter_list|(
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvt_roundps_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2uqq.512
return|return
name|_mm512_cvt_roundps_epu64
argument_list|(
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_cvt_roundps_epu64
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvt_roundps_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2uqq.512
return|return
name|_mm512_mask_cvt_roundps_epu64
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_cvt_roundps_epu64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvt_roundps_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2uqq.512
return|return
name|_mm512_maskz_cvt_roundps_epu64
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_cvtepi64_pd
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtepi64_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtqq2pd.512
return|return
name|_mm512_cvtepi64_pd
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_cvtepi64_pd
parameter_list|(
name|__m512d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtepi64_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtqq2pd.512
return|return
name|_mm512_mask_cvtepi64_pd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_maskz_cvtepi64_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtepi64_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtqq2pd.512
return|return
name|_mm512_maskz_cvtepi64_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_cvt_roundepi64_pd
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvt_roundepi64_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtqq2pd.512
return|return
name|_mm512_cvt_roundepi64_pd
argument_list|(
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_cvt_roundepi64_pd
parameter_list|(
name|__m512d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvt_roundepi64_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtqq2pd.512
return|return
name|_mm512_mask_cvt_roundepi64_pd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_maskz_cvt_roundepi64_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvt_roundepi64_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtqq2pd.512
return|return
name|_mm512_maskz_cvt_roundepi64_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm512_cvtepi64_ps
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtepi64_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtqq2ps.512
return|return
name|_mm512_cvtepi64_ps
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm512_mask_cvtepi64_ps
parameter_list|(
name|__m256
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtepi64_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtqq2ps.512
return|return
name|_mm512_mask_cvtepi64_ps
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm512_maskz_cvtepi64_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtepi64_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtqq2ps.512
return|return
name|_mm512_maskz_cvtepi64_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm512_cvt_roundepi64_ps
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvt_roundepi64_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtqq2ps.512
return|return
name|_mm512_cvt_roundepi64_ps
argument_list|(
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm512_mask_cvt_roundepi64_ps
parameter_list|(
name|__m256
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvt_roundepi64_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtqq2ps.512
return|return
name|_mm512_mask_cvt_roundepi64_ps
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm512_maskz_cvt_roundepi64_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvt_roundepi64_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtqq2ps.512
return|return
name|_mm512_maskz_cvt_roundepi64_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_cvttpd_epi64
parameter_list|(
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvttpd_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2qq.512
return|return
name|_mm512_cvttpd_epi64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_cvttpd_epi64
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvttpd_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2qq.512
return|return
name|_mm512_mask_cvttpd_epi64
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_cvttpd_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvttpd_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2qq.512
return|return
name|_mm512_maskz_cvttpd_epi64
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_cvtt_roundpd_epi64
parameter_list|(
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtt_roundpd_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2qq.512
return|return
name|_mm512_cvtt_roundpd_epi64
argument_list|(
name|__A
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_cvtt_roundpd_epi64
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtt_roundpd_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2qq.512
return|return
name|_mm512_mask_cvtt_roundpd_epi64
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_cvtt_roundpd_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtt_roundpd_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2qq.512
return|return
name|_mm512_maskz_cvtt_roundpd_epi64
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_cvttpd_epu64
parameter_list|(
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvttpd_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2uqq.512
return|return
name|_mm512_cvttpd_epu64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_cvttpd_epu64
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvttpd_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2uqq.512
return|return
name|_mm512_mask_cvttpd_epu64
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_cvttpd_epu64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvttpd_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2uqq.512
return|return
name|_mm512_maskz_cvttpd_epu64
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_cvtt_roundpd_epu64
parameter_list|(
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtt_roundpd_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2uqq.512
return|return
name|_mm512_cvtt_roundpd_epu64
argument_list|(
name|__A
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_cvtt_roundpd_epu64
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtt_roundpd_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2uqq.512
return|return
name|_mm512_mask_cvtt_roundpd_epu64
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_cvtt_roundpd_epu64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtt_roundpd_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2uqq.512
return|return
name|_mm512_maskz_cvtt_roundpd_epu64
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_cvttps_epi64
parameter_list|(
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvttps_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2qq.512
return|return
name|_mm512_cvttps_epi64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_cvttps_epi64
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvttps_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2qq.512
return|return
name|_mm512_mask_cvttps_epi64
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_cvttps_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvttps_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2qq.512
return|return
name|_mm512_maskz_cvttps_epi64
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_cvtt_roundps_epi64
parameter_list|(
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtt_roundps_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2qq.512
return|return
name|_mm512_cvtt_roundps_epi64
argument_list|(
name|__A
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_cvtt_roundps_epi64
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtt_roundps_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2qq.512
return|return
name|_mm512_mask_cvtt_roundps_epi64
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_cvtt_roundps_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtt_roundps_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2qq.512
return|return
name|_mm512_maskz_cvtt_roundps_epi64
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_cvttps_epu64
parameter_list|(
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvttps_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2uqq.512
return|return
name|_mm512_cvttps_epu64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_cvttps_epu64
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvttps_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2uqq.512
return|return
name|_mm512_mask_cvttps_epu64
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_cvttps_epu64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvttps_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2uqq.512
return|return
name|_mm512_maskz_cvttps_epu64
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_cvtt_roundps_epu64
parameter_list|(
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtt_roundps_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2uqq.512
return|return
name|_mm512_cvtt_roundps_epu64
argument_list|(
name|__A
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_cvtt_roundps_epu64
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtt_roundps_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2uqq.512
return|return
name|_mm512_mask_cvtt_roundps_epu64
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_cvtt_roundps_epu64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtt_roundps_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2uqq.512
return|return
name|_mm512_maskz_cvtt_roundps_epu64
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_cvtepu64_pd
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtepu64_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtuqq2pd.512
return|return
name|_mm512_cvtepu64_pd
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_cvtepu64_pd
parameter_list|(
name|__m512d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtepu64_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtuqq2pd.512
return|return
name|_mm512_mask_cvtepu64_pd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_maskz_cvtepu64_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtepu64_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtuqq2pd.512
return|return
name|_mm512_maskz_cvtepu64_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_cvt_roundepu64_pd
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvt_roundepu64_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtuqq2pd.512
return|return
name|_mm512_cvt_roundepu64_pd
argument_list|(
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_cvt_roundepu64_pd
parameter_list|(
name|__m512d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvt_roundepu64_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtuqq2pd.512
return|return
name|_mm512_mask_cvt_roundepu64_pd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_maskz_cvt_roundepu64_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvt_roundepu64_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtuqq2pd.512
return|return
name|_mm512_maskz_cvt_roundepu64_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm512_cvtepu64_ps
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtepu64_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtuqq2ps.512
return|return
name|_mm512_cvtepu64_ps
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm512_mask_cvtepu64_ps
parameter_list|(
name|__m256
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtepu64_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtuqq2ps.512
return|return
name|_mm512_mask_cvtepu64_ps
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm512_maskz_cvtepu64_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtepu64_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtuqq2ps.512
return|return
name|_mm512_maskz_cvtepu64_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm512_cvt_roundepu64_ps
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvt_roundepu64_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtuqq2ps.512
return|return
name|_mm512_cvt_roundepu64_ps
argument_list|(
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm512_mask_cvt_roundepu64_ps
parameter_list|(
name|__m256
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvt_roundepu64_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtuqq2ps.512
return|return
name|_mm512_mask_cvt_roundepu64_ps
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm512_maskz_cvt_roundepu64_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvt_roundepu64_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtuqq2ps.512
return|return
name|_mm512_maskz_cvt_roundepu64_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_range_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_range_pd
comment|// CHECK: @llvm.x86.avx512.mask.range.pd.512
return|return
name|_mm512_range_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_range_pd
parameter_list|(
name|__m512d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_range_pd
comment|// CHECK: @llvm.x86.avx512.mask.range.pd.512
return|return
name|_mm512_mask_range_pd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_maskz_range_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_range_pd
comment|// CHECK: @llvm.x86.avx512.mask.range.pd.512
return|return
name|_mm512_maskz_range_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_range_round_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_range_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.range.pd.512
return|return
name|_mm512_range_round_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
literal|4
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_range_round_pd
parameter_list|(
name|__m512d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_range_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.range.pd.512
return|return
name|_mm512_mask_range_round_pd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|4
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_maskz_range_round_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_range_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.range.pd.512
return|return
name|_mm512_maskz_range_round_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|4
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm512_range_round_sd
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_range_round_sd
comment|// CHECK: @llvm.x86.avx512.mask.range.sd
return|return
name|_mm_range_round_sd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
literal|4
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm512_mask_range_round_sd
parameter_list|(
name|__m128d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm512_mask_range_round_sd
comment|// CHECK: @llvm.x86.avx512.mask.range.sd
return|return
name|_mm_mask_range_round_sd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|4
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm512_maskz_range_round_sd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_range_round_sd
comment|// CHECK: @llvm.x86.avx512.mask.range.sd
return|return
name|_mm_maskz_range_round_sd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|4
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm512_range_round_ss
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_range_round_ss
comment|// CHECK: @llvm.x86.avx512.mask.range.ss
return|return
name|_mm_range_round_ss
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
literal|4
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm512_mask_range_round_ss
parameter_list|(
name|__m128
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_range_round_ss
comment|// CHECK: @llvm.x86.avx512.mask.range.ss
return|return
name|_mm_mask_range_round_ss
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|4
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm512_maskz_range_round_ss
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_range_round_ss
comment|// CHECK: @llvm.x86.avx512.mask.range.ss
return|return
name|_mm_maskz_range_round_ss
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|4
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_range_sd
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_range_sd
comment|// CHECK: @llvm.x86.avx512.mask.range.sd
return|return
name|_mm_range_sd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_range_sd
parameter_list|(
name|__m128d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_mask_range_sd
comment|// CHECK: @llvm.x86.avx512.mask.range.sd
return|return
name|_mm_mask_range_sd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_maskz_range_sd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_range_sd
comment|// CHECK: @llvm.x86.avx512.mask.range.sd
return|return
name|_mm_maskz_range_sd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_range_ss
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_range_ss
comment|// CHECK: @llvm.x86.avx512.mask.range.ss
return|return
name|_mm_range_ss
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_range_ss
parameter_list|(
name|__m128
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_range_ss
comment|// CHECK: @llvm.x86.avx512.mask.range.ss
return|return
name|_mm_mask_range_ss
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_maskz_range_ss
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_range_ss
comment|// CHECK: @llvm.x86.avx512.mask.range.ss
return|return
name|_mm_maskz_range_ss
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_range_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_range_ps
comment|// CHECK: @llvm.x86.avx512.mask.range.ps.512
return|return
name|_mm512_range_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_range_ps
parameter_list|(
name|__m512
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_range_ps
comment|// CHECK: @llvm.x86.avx512.mask.range.ps.512
return|return
name|_mm512_mask_range_ps
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_maskz_range_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_range_ps
comment|// CHECK: @llvm.x86.avx512.mask.range.ps.512
return|return
name|_mm512_maskz_range_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_range_round_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_range_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.range.ps.512
return|return
name|_mm512_range_round_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
literal|4
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_range_round_ps
parameter_list|(
name|__m512
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_range_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.range.ps.512
return|return
name|_mm512_mask_range_round_ps
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|4
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_maskz_range_round_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_range_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.range.ps.512
return|return
name|_mm512_maskz_range_round_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|4
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_reduce_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_reduce_pd
comment|// CHECK: @llvm.x86.avx512.mask.reduce.pd.512
return|return
name|_mm512_reduce_pd
argument_list|(
name|__A
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_reduce_pd
parameter_list|(
name|__m512d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_reduce_pd
comment|// CHECK: @llvm.x86.avx512.mask.reduce.pd.512
return|return
name|_mm512_mask_reduce_pd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_maskz_reduce_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_reduce_pd
comment|// CHECK: @llvm.x86.avx512.mask.reduce.pd.512
return|return
name|_mm512_maskz_reduce_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_reduce_ps
parameter_list|(
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_reduce_ps
comment|// CHECK: @llvm.x86.avx512.mask.reduce.ps.512
return|return
name|_mm512_reduce_ps
argument_list|(
name|__A
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_reduce_ps
parameter_list|(
name|__m512
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_reduce_ps
comment|// CHECK: @llvm.x86.avx512.mask.reduce.ps.512
return|return
name|_mm512_mask_reduce_ps
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_maskz_reduce_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_reduce_ps
comment|// CHECK: @llvm.x86.avx512.mask.reduce.ps.512
return|return
name|_mm512_maskz_reduce_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_reduce_round_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_reduce_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.reduce.pd.512
return|return
name|_mm512_reduce_round_pd
argument_list|(
name|__A
argument_list|,
literal|4
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_reduce_round_pd
parameter_list|(
name|__m512d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_reduce_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.reduce.pd.512
return|return
name|_mm512_mask_reduce_round_pd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
literal|4
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_maskz_reduce_round_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_reduce_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.reduce.pd.512
return|return
name|_mm512_maskz_reduce_round_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
literal|4
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_reduce_round_ps
parameter_list|(
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_reduce_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.reduce.ps.512
return|return
name|_mm512_reduce_round_ps
argument_list|(
name|__A
argument_list|,
literal|4
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_reduce_round_ps
parameter_list|(
name|__m512
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_reduce_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.reduce.ps.512
return|return
name|_mm512_mask_reduce_round_ps
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
literal|4
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_maskz_reduce_round_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_reduce_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.reduce.ps.512
return|return
name|_mm512_maskz_reduce_round_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
literal|4
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_reduce_ss
parameter_list|(
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_reduce_ss
comment|// CHECK: @llvm.x86.avx512.mask.reduce.ss
return|return
name|_mm_reduce_ss
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_reduce_ss
parameter_list|(
name|__m128
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_reduce_ss
comment|// CHECK: @llvm.x86.avx512.mask.reduce.ss
return|return
name|_mm_mask_reduce_ss
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_maskz_reduce_ss
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_reduce_ss
comment|// CHECK: @llvm.x86.avx512.mask.reduce.ss
return|return
name|_mm_maskz_reduce_ss
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_reduce_round_ss
parameter_list|(
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_reduce_round_ss
comment|// CHECK: @llvm.x86.avx512.mask.reduce.ss
return|return
name|_mm_reduce_round_ss
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
literal|4
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_reduce_round_ss
parameter_list|(
name|__m128
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_reduce_round_ss
comment|// CHECK: @llvm.x86.avx512.mask.reduce.ss
return|return
name|_mm_mask_reduce_round_ss
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|4
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_maskz_reduce_round_ss
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_reduce_round_ss
comment|// CHECK: @llvm.x86.avx512.mask.reduce.ss
return|return
name|_mm_maskz_reduce_round_ss
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|4
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_reduce_sd
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_reduce_sd
comment|// CHECK: @llvm.x86.avx512.mask.reduce.sd
return|return
name|_mm_reduce_sd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_reduce_sd
parameter_list|(
name|__m128d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_reduce_sd
comment|// CHECK: @llvm.x86.avx512.mask.reduce.sd
return|return
name|_mm_mask_reduce_sd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_maskz_reduce_sd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_reduce_sd
comment|// CHECK: @llvm.x86.avx512.mask.reduce.sd
return|return
name|_mm_maskz_reduce_sd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_reduce_round_sd
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_reduce_round_sd
comment|// CHECK: @llvm.x86.avx512.mask.reduce.sd
return|return
name|_mm_reduce_round_sd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
literal|4
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_reduce_round_sd
parameter_list|(
name|__m128d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_reduce_round_sd
comment|// CHECK: @llvm.x86.avx512.mask.reduce.sd
return|return
name|_mm_mask_reduce_round_sd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|4
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_maskz_reduce_round_sd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_reduce_round_sd
comment|// CHECK: @llvm.x86.avx512.mask.reduce.sd
return|return
name|_mm_maskz_reduce_round_sd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|4
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm512_movepi32_mask
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_movepi32_mask
comment|// CHECK: @llvm.x86.avx512.cvtd2mask.512
return|return
name|_mm512_movepi32_mask
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_movm_epi32
parameter_list|(
name|__mmask16
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_movm_epi32
comment|// CHECK: %{{.*}} = bitcast i16 %{{.*}} to<16 x i1>
comment|// CHECK: %vpmovm2.i = sext<16 x i1> %{{.*}} to<16 x i32>
return|return
name|_mm512_movm_epi32
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_movm_epi64
parameter_list|(
name|__mmask8
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_movm_epi64
comment|// CHECK: %{{.*}} = bitcast i8 %{{.*}} to<8 x i1>
comment|// CHECK: %vpmovm2.i = sext<8 x i1> %{{.*}} to<8 x i64>
return|return
name|_mm512_movm_epi64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_movepi64_mask
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_movepi64_mask
comment|// CHECK: @llvm.x86.avx512.cvtq2mask.512
return|return
name|_mm512_movepi64_mask
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_broadcast_f32x2
parameter_list|(
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_broadcast_f32x2
comment|// CHECK: @llvm.x86.avx512.mask.broadcastf32x2
return|return
name|_mm512_broadcast_f32x2
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_broadcast_f32x2
parameter_list|(
name|__m512
name|__O
parameter_list|,
name|__mmask16
name|__M
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_broadcast_f32x2
comment|// CHECK: @llvm.x86.avx512.mask.broadcastf32x2
return|return
name|_mm512_mask_broadcast_f32x2
argument_list|(
name|__O
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_maskz_broadcast_f32x2
parameter_list|(
name|__mmask16
name|__M
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_broadcast_f32x2
comment|// CHECK: @llvm.x86.avx512.mask.broadcastf32x2
return|return
name|_mm512_maskz_broadcast_f32x2
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_broadcast_f32x8
parameter_list|(
name|float
specifier|const
modifier|*
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_broadcast_f32x8
comment|// CHECK: shufflevector<8 x float> %{{.*}},<8 x float> %{{.*}},<16 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
return|return
name|_mm512_broadcast_f32x8
argument_list|(
name|_mm256_loadu_ps
argument_list|(
name|__A
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_broadcast_f32x8
parameter_list|(
name|__m512
name|__O
parameter_list|,
name|__mmask16
name|__M
parameter_list|,
name|float
specifier|const
modifier|*
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_broadcast_f32x8
comment|// CHECK: shufflevector<8 x float> %{{.*}},<8 x float> %{{.*}},<16 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x float> %{{.*}},<16 x float> %{{.*}}
return|return
name|_mm512_mask_broadcast_f32x8
argument_list|(
name|__O
argument_list|,
name|__M
argument_list|,
name|_mm256_loadu_ps
argument_list|(
name|__A
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_maskz_broadcast_f32x8
parameter_list|(
name|__mmask16
name|__M
parameter_list|,
name|float
specifier|const
modifier|*
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_broadcast_f32x8
comment|// CHECK: shufflevector<8 x float> %{{.*}},<8 x float> %{{.*}},<16 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x float> %{{.*}},<16 x float> %{{.*}}
return|return
name|_mm512_maskz_broadcast_f32x8
argument_list|(
name|__M
argument_list|,
name|_mm256_loadu_ps
argument_list|(
name|__A
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_broadcast_f64x2
parameter_list|(
name|double
specifier|const
modifier|*
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_broadcast_f64x2
comment|// CHECK: shufflevector<2 x double> %{{.*}},<2 x double> %{{.*}},<8 x i32><i32 0, i32 1, i32 0, i32 1, i32 0, i32 1, i32 0, i32 1>
return|return
name|_mm512_broadcast_f64x2
argument_list|(
name|_mm_loadu_pd
argument_list|(
name|__A
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_broadcast_f64x2
parameter_list|(
name|__m512d
name|__O
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|double
specifier|const
modifier|*
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_broadcast_f64x2
comment|// CHECK: shufflevector<2 x double> %{{.*}},<2 x double> %{{.*}},<8 x i32><i32 0, i32 1, i32 0, i32 1, i32 0, i32 1, i32 0, i32 1>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x double> %{{.*}},<8 x double> %{{.*}}
return|return
name|_mm512_mask_broadcast_f64x2
argument_list|(
name|__O
argument_list|,
name|__M
argument_list|,
name|_mm_loadu_pd
argument_list|(
name|__A
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_maskz_broadcast_f64x2
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|double
specifier|const
modifier|*
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_broadcast_f64x2
comment|// CHECK: shufflevector<2 x double> %{{.*}},<2 x double> %{{.*}},<8 x i32><i32 0, i32 1, i32 0, i32 1, i32 0, i32 1, i32 0, i32 1>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x double> %{{.*}},<8 x double> %{{.*}}
return|return
name|_mm512_maskz_broadcast_f64x2
argument_list|(
name|__M
argument_list|,
name|_mm_loadu_pd
argument_list|(
name|__A
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_broadcast_i32x2
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_broadcast_i32x2
comment|// CHECK: @llvm.x86.avx512.mask.broadcasti32x2
return|return
name|_mm512_broadcast_i32x2
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_broadcast_i32x2
parameter_list|(
name|__m512i
name|__O
parameter_list|,
name|__mmask16
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_broadcast_i32x2
comment|// CHECK: @llvm.x86.avx512.mask.broadcasti32x2
return|return
name|_mm512_mask_broadcast_i32x2
argument_list|(
name|__O
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_broadcast_i32x2
parameter_list|(
name|__mmask16
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_broadcast_i32x2
comment|// CHECK: @llvm.x86.avx512.mask.broadcasti32x2
return|return
name|_mm512_maskz_broadcast_i32x2
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_broadcast_i32x8
parameter_list|(
name|__m256i
specifier|const
modifier|*
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_broadcast_i32x8
comment|// CHECK: shufflevector<8 x i32> %{{.*}},<8 x i32> %{{.*}},<16 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
return|return
name|_mm512_broadcast_i32x8
argument_list|(
name|_mm256_loadu_si256
argument_list|(
name|__A
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_broadcast_i32x8
parameter_list|(
name|__m512i
name|__O
parameter_list|,
name|__mmask16
name|__M
parameter_list|,
name|__m256i
specifier|const
modifier|*
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_broadcast_i32x8
comment|// CHECK: shufflevector<8 x i32> %{{.*}},<8 x i32> %{{.*}},<16 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_mask_broadcast_i32x8
argument_list|(
name|__O
argument_list|,
name|__M
argument_list|,
name|_mm256_loadu_si256
argument_list|(
name|__A
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_broadcast_i32x8
parameter_list|(
name|__mmask16
name|__M
parameter_list|,
name|__m256i
specifier|const
modifier|*
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_broadcast_i32x8
comment|// CHECK: shufflevector<8 x i32> %{{.*}},<8 x i32> %{{.*}},<16 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_maskz_broadcast_i32x8
argument_list|(
name|__M
argument_list|,
name|_mm256_loadu_si256
argument_list|(
name|__A
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_broadcast_i64x2
parameter_list|(
name|__m128i
specifier|const
modifier|*
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_broadcast_i64x2
comment|// CHECK: shufflevector<2 x i64> %{{.*}},<2 x i64> %{{.*}},<8 x i32><i32 0, i32 1, i32 0, i32 1, i32 0, i32 1, i32 0, i32 1>
return|return
name|_mm512_broadcast_i64x2
argument_list|(
name|_mm_loadu_si128
argument_list|(
name|__A
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_broadcast_i64x2
parameter_list|(
name|__m512i
name|__O
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m128i
specifier|const
modifier|*
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_broadcast_i64x2
comment|// CHECK: shufflevector<2 x i64> %{{.*}},<2 x i64> %{{.*}},<8 x i32><i32 0, i32 1, i32 0, i32 1, i32 0, i32 1, i32 0, i32 1>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_mask_broadcast_i64x2
argument_list|(
name|__O
argument_list|,
name|__M
argument_list|,
name|_mm_loadu_si128
argument_list|(
name|__A
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_broadcast_i64x2
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128i
specifier|const
modifier|*
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_broadcast_i64x2
comment|// CHECK: shufflevector<2 x i64> %{{.*}},<2 x i64> %{{.*}},<8 x i32><i32 0, i32 1, i32 0, i32 1, i32 0, i32 1, i32 0, i32 1>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_maskz_broadcast_i64x2
argument_list|(
name|__M
argument_list|,
name|_mm_loadu_si128
argument_list|(
name|__A
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm512_extractf32x8_ps
parameter_list|(
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_extractf32x8_ps
comment|// CHECK: shufflevector<16 x float> %{{.*}},<16 x float> zeroinitializer,<8 x i32><i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15>
return|return
name|_mm512_extractf32x8_ps
argument_list|(
name|__A
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm512_mask_extractf32x8_ps
parameter_list|(
name|__m256
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_extractf32x8_ps
comment|// CHECK: shufflevector<16 x float> %{{.*}},<16 x float> zeroinitializer,<8 x i32><i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x float> %{{.*}},<8 x float> %{{.*}}
return|return
name|_mm512_mask_extractf32x8_ps
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm512_maskz_extractf32x8_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_extractf32x8_ps
comment|// CHECK: shufflevector<16 x float> %{{.*}},<16 x float> zeroinitializer,<8 x i32><i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x float> %{{.*}},<8 x float> %{{.*}}
return|return
name|_mm512_maskz_extractf32x8_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm512_extractf64x2_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_extractf64x2_pd
comment|// CHECK: shufflevector<8 x double> %{{.*}},<8 x double> zeroinitializer,<2 x i32><i32 6, i32 7>
return|return
name|_mm512_extractf64x2_pd
argument_list|(
name|__A
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm512_mask_extractf64x2_pd
parameter_list|(
name|__m128d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_extractf64x2_pd
comment|// CHECK: shufflevector<8 x double> %{{.*}},<8 x double> zeroinitializer,<2 x i32><i32 6, i32 7>
comment|// CHECK: select<2 x i1> %{{.*}},<2 x double> %{{.*}},<2 x double> %{{.*}}
return|return
name|_mm512_mask_extractf64x2_pd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm512_maskz_extractf64x2_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_extractf64x2_pd
comment|// CHECK: shufflevector<8 x double> %{{.*}},<8 x double> zeroinitializer,<2 x i32><i32 6, i32 7>
comment|// CHECK: select<2 x i1> %{{.*}},<2 x double> %{{.*}},<2 x double> %{{.*}}
return|return
name|_mm512_maskz_extractf64x2_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm512_extracti32x8_epi32
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_extracti32x8_epi32
comment|// CHECK: shufflevector<16 x i32> %{{.*}},<16 x i32> %{{.*}},<8 x i32><i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15>
return|return
name|_mm512_extracti32x8_epi32
argument_list|(
name|__A
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm512_mask_extracti32x8_epi32
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_extracti32x8_epi32
comment|// CHECK: shufflevector<16 x i32> %{{.*}},<16 x i32> %{{.*}},<8 x i32><i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm512_mask_extracti32x8_epi32
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm512_maskz_extracti32x8_epi32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_extracti32x8_epi32
comment|// CHECK: shufflevector<16 x i32> %{{.*}},<16 x i32> %{{.*}},<8 x i32><i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm512_maskz_extracti32x8_epi32
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm512_extracti64x2_epi64
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_extracti64x2_epi64
comment|// CHECK: shufflevector<8 x i64> %{{.*}},<8 x i64> zeroinitializer,<2 x i32><i32 6, i32 7>
return|return
name|_mm512_extracti64x2_epi64
argument_list|(
name|__A
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm512_mask_extracti64x2_epi64
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_extracti64x2_epi64
comment|// CHECK: shufflevector<8 x i64> %{{.*}},<8 x i64> zeroinitializer,<2 x i32><i32 6, i32 7>
comment|// CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm512_mask_extracti64x2_epi64
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm512_maskz_extracti64x2_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_extracti64x2_epi64
comment|// CHECK: shufflevector<8 x i64> %{{.*}},<8 x i64> zeroinitializer,<2 x i32><i32 6, i32 7>
comment|// CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm512_maskz_extracti64x2_epi64
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_insertf32x8
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_insertf32x8
comment|// CHECK: shufflevector<16 x float> %{{.*}},<16 x float> %{{.*}},<16 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 16, i32 17, i32 18, i32 19, i32 20, i32 21, i32 22, i32 23>
return|return
name|_mm512_insertf32x8
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_insertf32x8
parameter_list|(
name|__m512
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_insertf32x8
comment|// CHECK: shufflevector<16 x float> %{{.*}},<16 x float> %{{.*}},<16 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 16, i32 17, i32 18, i32 19, i32 20, i32 21, i32 22, i32 23>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x float> %{{.*}},<16 x float> %{{.*}}
return|return
name|_mm512_mask_insertf32x8
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_maskz_insertf32x8
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_insertf32x8
comment|// CHECK: shufflevector<16 x float> %{{.*}},<16 x float> %{{.*}},<16 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 16, i32 17, i32 18, i32 19, i32 20, i32 21, i32 22, i32 23>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x float> %{{.*}},<16 x float> %{{.*}}
return|return
name|_mm512_maskz_insertf32x8
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_insertf64x2
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_insertf64x2
comment|// CHECK: shufflevector<8 x double> %{{.*}},<8 x double> %{{.*}},<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 8, i32 9>
return|return
name|_mm512_insertf64x2
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_insertf64x2
parameter_list|(
name|__m512d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_insertf64x2
comment|// CHECK: shufflevector<8 x double> %{{.*}},<8 x double> %{{.*}},<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 8, i32 9>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x double> %{{.*}},<8 x double> %{{.*}}
return|return
name|_mm512_mask_insertf64x2
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_maskz_insertf64x2
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_insertf64x2
comment|// CHECK: shufflevector<8 x double> %{{.*}},<8 x double> %{{.*}},<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 8, i32 9>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x double> %{{.*}},<8 x double> %{{.*}}
return|return
name|_mm512_maskz_insertf64x2
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_inserti32x8
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_inserti32x8
comment|// CHECK: shufflevector<16 x i32> %{{.*}},<16 x i32> %{{.*}},<16 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 16, i32 17, i32 18, i32 19, i32 20, i32 21, i32 22, i32 23>
return|return
name|_mm512_inserti32x8
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_inserti32x8
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_inserti32x8
comment|// CHECK: shufflevector<16 x i32> %{{.*}},<16 x i32> %{{.*}},<16 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 16, i32 17, i32 18, i32 19, i32 20, i32 21, i32 22, i32 23>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_mask_inserti32x8
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_inserti32x8
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_inserti32x8
comment|// CHECK: shufflevector<16 x i32> %{{.*}},<16 x i32> %{{.*}},<16 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 16, i32 17, i32 18, i32 19, i32 20, i32 21, i32 22, i32 23>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_maskz_inserti32x8
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_inserti64x2
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_inserti64x2
comment|// CHECK: shufflevector<8 x i64> %{{.*}},<8 x i64> %{{.*}},<8 x i32><i32 0, i32 1, i32 8, i32 9, i32 4, i32 5, i32 6, i32 7>
return|return
name|_mm512_inserti64x2
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_inserti64x2
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_inserti64x2
comment|// CHECK: shufflevector<8 x i64> %{{.*}},<8 x i64> %{{.*}},<8 x i32><i32 0, i32 1, i32 8, i32 9, i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_mask_inserti64x2
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_inserti64x2
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_inserti64x2
comment|// CHECK: shufflevector<8 x i64> %{{.*}},<8 x i64> %{{.*}},<8 x i32><i32 0, i32 1, i32 8, i32 9, i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_maskz_inserti64x2
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_mask_fpclass_pd_mask
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_fpclass_pd_mask
comment|// CHECK: @llvm.x86.avx512.mask.fpclass.pd.512
return|return
name|_mm512_mask_fpclass_pd_mask
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_fpclass_pd_mask
parameter_list|(
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_fpclass_pd_mask
comment|// CHECK: @llvm.x86.avx512.mask.fpclass.pd.512
return|return
name|_mm512_fpclass_pd_mask
argument_list|(
name|__A
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm512_mask_fpclass_ps_mask
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_fpclass_ps_mask
comment|// CHECK: @llvm.x86.avx512.mask.fpclass.ps.512
return|return
name|_mm512_mask_fpclass_ps_mask
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm512_fpclass_ps_mask
parameter_list|(
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_fpclass_ps_mask
comment|// CHECK: @llvm.x86.avx512.mask.fpclass.ps.512
return|return
name|_mm512_fpclass_ps_mask
argument_list|(
name|__A
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm_fpclass_sd_mask
parameter_list|(
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_fpclass_sd_mask
comment|// CHECK: @llvm.x86.avx512.mask.fpclass.sd
return|return
name|_mm_fpclass_sd_mask
argument_list|(
name|__A
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm_mask_fpclass_sd_mask
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_fpclass_sd_mask
comment|// CHECK: @llvm.x86.avx512.mask.fpclass.sd
return|return
name|_mm_mask_fpclass_sd_mask
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm_fpclass_ss_mask
parameter_list|(
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_fpclass_ss_mask
comment|// CHECK: @llvm.x86.avx512.mask.fpclass.ss
return|return
name|_mm_fpclass_ss_mask
argument_list|(
name|__A
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm_mask_fpclass_ss_mask
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_fpclass_ss_mask
comment|// CHECK: @llvm.x86.avx512.mask.fpclass.ss
return|return
name|_mm_mask_fpclass_ss_mask
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

end_unit

