begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ffreestanding %s -triple=x86_64-apple-darwin -target-feature +xop -emit-llvm -o - -Wall -Werror | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -ffreestanding %s -triple=x86_64-apple-darwin -target-feature +xop -fno-signed-char -emit-llvm -o - -Wall -Werror | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<x86intrin.h>
end_include

begin_comment
comment|// _MM_PCOMCTRL_LT
end_comment

begin_function
name|__m128i
name|test_mm_comlt_epu8
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comlt_epu8
comment|// CHECK: call<16 x i8> @llvm.x86.xop.vpcomub(<16 x i8> %{{.*}},<16 x i8> %{{.*}}, i8 0)
return|return
name|_mm_comlt_epu8
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
name|test_mm_comlt_epu16
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comlt_epu16
comment|// CHECK: call<8 x i16> @llvm.x86.xop.vpcomuw(<8 x i16> %{{.*}},<8 x i16> %{{.*}}, i8 0)
return|return
name|_mm_comlt_epu16
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
name|test_mm_comlt_epu32
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comlt_epu32
comment|// CHECK: call<4 x i32> @llvm.x86.xop.vpcomud(<4 x i32> %{{.*}},<4 x i32> %{{.*}}, i8 0)
return|return
name|_mm_comlt_epu32
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
name|test_mm_comlt_epu64
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comlt_epu64
comment|// CHECK: call<2 x i64> @llvm.x86.xop.vpcomuq(<2 x i64> %{{.*}},<2 x i64> %{{.*}}, i8 0)
return|return
name|_mm_comlt_epu64
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
name|test_mm_comlt_epi8
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comlt_epi8
comment|// CHECK: call<16 x i8> @llvm.x86.xop.vpcomb(<16 x i8> %{{.*}},<16 x i8> %{{.*}}, i8 0)
return|return
name|_mm_comlt_epi8
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
name|test_mm_comlt_epi16
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comlt_epi16
comment|// CHECK: call<8 x i16> @llvm.x86.xop.vpcomw(<8 x i16> %{{.*}},<8 x i16> %{{.*}}, i8 0)
return|return
name|_mm_comlt_epi16
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
name|test_mm_comlt_epi32
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comlt_epi32
comment|// CHECK: call<4 x i32> @llvm.x86.xop.vpcomd(<4 x i32> %{{.*}},<4 x i32> %{{.*}}, i8 0)
return|return
name|_mm_comlt_epi32
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
name|test_mm_comlt_epi64
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comlt_epi64
comment|// CHECK: call<2 x i64> @llvm.x86.xop.vpcomq(<2 x i64> %{{.*}},<2 x i64> %{{.*}}, i8 0)
return|return
name|_mm_comlt_epi64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// _MM_PCOMCTRL_LE
end_comment

begin_function
name|__m128i
name|test_mm_comle_epu8
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comle_epu8
comment|// CHECK: call<16 x i8> @llvm.x86.xop.vpcomub(<16 x i8> %{{.*}},<16 x i8> %{{.*}}, i8 1)
return|return
name|_mm_comle_epu8
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
name|test_mm_comle_epu16
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comle_epu16
comment|// CHECK: call<8 x i16> @llvm.x86.xop.vpcomuw(<8 x i16> %{{.*}},<8 x i16> %{{.*}}, i8 1)
return|return
name|_mm_comle_epu16
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
name|test_mm_comle_epu32
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comle_epu32
comment|// CHECK: call<4 x i32> @llvm.x86.xop.vpcomud(<4 x i32> %{{.*}},<4 x i32> %{{.*}}, i8 1)
return|return
name|_mm_comle_epu32
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
name|test_mm_comle_epu64
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comle_epu64
comment|// CHECK: call<2 x i64> @llvm.x86.xop.vpcomuq(<2 x i64> %{{.*}},<2 x i64> %{{.*}}, i8 1)
return|return
name|_mm_comle_epu64
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
name|test_mm_comle_epi8
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comle_epi8
comment|// CHECK: call<16 x i8> @llvm.x86.xop.vpcomb(<16 x i8> %{{.*}},<16 x i8> %{{.*}}, i8 1)
return|return
name|_mm_comle_epi8
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
name|test_mm_comle_epi16
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comle_epi16
comment|// CHECK: call<8 x i16> @llvm.x86.xop.vpcomw(<8 x i16> %{{.*}},<8 x i16> %{{.*}}, i8 1)
return|return
name|_mm_comle_epi16
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
name|test_mm_comle_epi32
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comle_epi32
comment|// CHECK: call<4 x i32> @llvm.x86.xop.vpcomd(<4 x i32> %{{.*}},<4 x i32> %{{.*}}, i8 1)
return|return
name|_mm_comle_epi32
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
name|test_mm_comle_epi64
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comle_epi64
comment|// CHECK: call<2 x i64> @llvm.x86.xop.vpcomq(<2 x i64> %{{.*}},<2 x i64> %{{.*}}, i8 1)
return|return
name|_mm_comle_epi64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// _MM_PCOMCTRL_GT
end_comment

begin_function
name|__m128i
name|test_mm_comgt_epu8
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comgt_epu8
comment|// CHECK: call<16 x i8> @llvm.x86.xop.vpcomub(<16 x i8> %{{.*}},<16 x i8> %{{.*}}, i8 2)
return|return
name|_mm_comgt_epu8
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
name|test_mm_comgt_epu16
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comgt_epu16
comment|// CHECK: call<8 x i16> @llvm.x86.xop.vpcomuw(<8 x i16> %{{.*}},<8 x i16> %{{.*}}, i8 2)
return|return
name|_mm_comgt_epu16
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
name|test_mm_comgt_epu32
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comgt_epu32
comment|// CHECK: call<4 x i32> @llvm.x86.xop.vpcomud(<4 x i32> %{{.*}},<4 x i32> %{{.*}}, i8 2)
return|return
name|_mm_comgt_epu32
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
name|test_mm_comgt_epu64
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comgt_epu64
comment|// CHECK: call<2 x i64> @llvm.x86.xop.vpcomuq(<2 x i64> %{{.*}},<2 x i64> %{{.*}}, i8 2)
return|return
name|_mm_comgt_epu64
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
name|test_mm_comgt_epi8
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comgt_epi8
comment|// CHECK: call<16 x i8> @llvm.x86.xop.vpcomb(<16 x i8> %{{.*}},<16 x i8> %{{.*}}, i8 2)
return|return
name|_mm_comgt_epi8
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
name|test_mm_comgt_epi16
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comgt_epi16
comment|// CHECK: call<8 x i16> @llvm.x86.xop.vpcomw(<8 x i16> %{{.*}},<8 x i16> %{{.*}}, i8 2)
return|return
name|_mm_comgt_epi16
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
name|test_mm_comgt_epi32
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comgt_epi32
comment|// CHECK: call<4 x i32> @llvm.x86.xop.vpcomd(<4 x i32> %{{.*}},<4 x i32> %{{.*}}, i8 2)
return|return
name|_mm_comgt_epi32
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
name|test_mm_comgt_epi64
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comgt_epi64
comment|// CHECK: call<2 x i64> @llvm.x86.xop.vpcomq(<2 x i64> %{{.*}},<2 x i64> %{{.*}}, i8 2)
return|return
name|_mm_comgt_epi64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// _MM_PCOMCTRL_GE
end_comment

begin_function
name|__m128i
name|test_mm_comge_epu8
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comge_epu8
comment|// CHECK: call<16 x i8> @llvm.x86.xop.vpcomub(<16 x i8> %{{.*}},<16 x i8> %{{.*}}, i8 3)
return|return
name|_mm_comge_epu8
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
name|test_mm_comge_epu16
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comge_epu16
comment|// CHECK: call<8 x i16> @llvm.x86.xop.vpcomuw(<8 x i16> %{{.*}},<8 x i16> %{{.*}}, i8 3)
return|return
name|_mm_comge_epu16
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
name|test_mm_comge_epu32
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comge_epu32
comment|// CHECK: call<4 x i32> @llvm.x86.xop.vpcomud(<4 x i32> %{{.*}},<4 x i32> %{{.*}}, i8 3)
return|return
name|_mm_comge_epu32
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
name|test_mm_comge_epu64
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comge_epu64
comment|// CHECK: call<2 x i64> @llvm.x86.xop.vpcomuq(<2 x i64> %{{.*}},<2 x i64> %{{.*}}, i8 3)
return|return
name|_mm_comge_epu64
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
name|test_mm_comge_epi8
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comge_epi8
comment|// CHECK: call<16 x i8> @llvm.x86.xop.vpcomb(<16 x i8> %{{.*}},<16 x i8> %{{.*}}, i8 3)
return|return
name|_mm_comge_epi8
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
name|test_mm_comge_epi16
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comge_epi16
comment|// CHECK: call<8 x i16> @llvm.x86.xop.vpcomw(<8 x i16> %{{.*}},<8 x i16> %{{.*}}, i8 3)
return|return
name|_mm_comge_epi16
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
name|test_mm_comge_epi32
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comge_epi32
comment|// CHECK: call<4 x i32> @llvm.x86.xop.vpcomd(<4 x i32> %{{.*}},<4 x i32> %{{.*}}, i8 3)
return|return
name|_mm_comge_epi32
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
name|test_mm_comge_epi64
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comge_epi64
comment|// CHECK: call<2 x i64> @llvm.x86.xop.vpcomq(<2 x i64> %{{.*}},<2 x i64> %{{.*}}, i8 3)
return|return
name|_mm_comge_epi64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// _MM_PCOMCTRL_EQ
end_comment

begin_function
name|__m128i
name|test_mm_comeq_epu8
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comeq_epu8
comment|// CHECK: call<16 x i8> @llvm.x86.xop.vpcomub(<16 x i8> %{{.*}},<16 x i8> %{{.*}}, i8 4)
return|return
name|_mm_comeq_epu8
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
name|test_mm_comeq_epu16
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comeq_epu16
comment|// CHECK: call<8 x i16> @llvm.x86.xop.vpcomuw(<8 x i16> %{{.*}},<8 x i16> %{{.*}}, i8 4)
return|return
name|_mm_comeq_epu16
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
name|test_mm_comeq_epu32
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comeq_epu32
comment|// CHECK: call<4 x i32> @llvm.x86.xop.vpcomud(<4 x i32> %{{.*}},<4 x i32> %{{.*}}, i8 4)
return|return
name|_mm_comeq_epu32
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
name|test_mm_comeq_epu64
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comeq_epu64
comment|// CHECK: call<2 x i64> @llvm.x86.xop.vpcomuq(<2 x i64> %{{.*}},<2 x i64> %{{.*}}, i8 4)
return|return
name|_mm_comeq_epu64
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
name|test_mm_comeq_epi8
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comeq_epi8
comment|// CHECK: call<16 x i8> @llvm.x86.xop.vpcomb(<16 x i8> %{{.*}},<16 x i8> %{{.*}}, i8 4)
return|return
name|_mm_comeq_epi8
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
name|test_mm_comeq_epi16
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comeq_epi16
comment|// CHECK: call<8 x i16> @llvm.x86.xop.vpcomw(<8 x i16> %{{.*}},<8 x i16> %{{.*}}, i8 4)
return|return
name|_mm_comeq_epi16
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
name|test_mm_comeq_epi32
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comeq_epi32
comment|// CHECK: call<4 x i32> @llvm.x86.xop.vpcomd(<4 x i32> %{{.*}},<4 x i32> %{{.*}}, i8 4)
return|return
name|_mm_comeq_epi32
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
name|test_mm_comeq_epi64
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comeq_epi64
comment|// CHECK: call<2 x i64> @llvm.x86.xop.vpcomq(<2 x i64> %{{.*}},<2 x i64> %{{.*}}, i8 4)
return|return
name|_mm_comeq_epi64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// _MM_PCOMCTRL_NEQ
end_comment

begin_function
name|__m128i
name|test_mm_comneq_epu8
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comneq_epu8
comment|// CHECK: call<16 x i8> @llvm.x86.xop.vpcomub(<16 x i8> %{{.*}},<16 x i8> %{{.*}}, i8 5)
return|return
name|_mm_comneq_epu8
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
name|test_mm_comneq_epu16
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comneq_epu16
comment|// CHECK: call<8 x i16> @llvm.x86.xop.vpcomuw(<8 x i16> %{{.*}},<8 x i16> %{{.*}}, i8 5)
return|return
name|_mm_comneq_epu16
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
name|test_mm_comneq_epu32
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comneq_epu32
comment|// CHECK: call<4 x i32> @llvm.x86.xop.vpcomud(<4 x i32> %{{.*}},<4 x i32> %{{.*}}, i8 5)
return|return
name|_mm_comneq_epu32
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
name|test_mm_comneq_epu64
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comneq_epu64
comment|// CHECK: call<2 x i64> @llvm.x86.xop.vpcomuq(<2 x i64> %{{.*}},<2 x i64> %{{.*}}, i8 5)
return|return
name|_mm_comneq_epu64
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
name|test_mm_comneq_epi8
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comneq_epi8
comment|// CHECK: call<16 x i8> @llvm.x86.xop.vpcomb(<16 x i8> %{{.*}},<16 x i8> %{{.*}}, i8 5)
return|return
name|_mm_comneq_epi8
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
name|test_mm_comneq_epi16
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comneq_epi16
comment|// CHECK: call<8 x i16> @llvm.x86.xop.vpcomw(<8 x i16> %{{.*}},<8 x i16> %{{.*}}, i8 5)
return|return
name|_mm_comneq_epi16
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
name|test_mm_comneq_epi32
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comneq_epi32
comment|// CHECK: call<4 x i32> @llvm.x86.xop.vpcomd(<4 x i32> %{{.*}},<4 x i32> %{{.*}}, i8 5)
return|return
name|_mm_comneq_epi32
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
name|test_mm_comneq_epi64
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comneq_epi64
comment|// CHECK: call<2 x i64> @llvm.x86.xop.vpcomq(<2 x i64> %{{.*}},<2 x i64> %{{.*}}, i8 5)
return|return
name|_mm_comneq_epi64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// _MM_PCOMCTRL_FALSE
end_comment

begin_function
name|__m128i
name|test_mm_comfalse_epu8
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comfalse_epu8
comment|// CHECK: call<16 x i8> @llvm.x86.xop.vpcomub(<16 x i8> %{{.*}},<16 x i8> %{{.*}}, i8 6)
return|return
name|_mm_comfalse_epu8
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
name|test_mm_comfalse_epu16
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comfalse_epu16
comment|// CHECK: call<8 x i16> @llvm.x86.xop.vpcomuw(<8 x i16> %{{.*}},<8 x i16> %{{.*}}, i8 6)
return|return
name|_mm_comfalse_epu16
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
name|test_mm_comfalse_epu32
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comfalse_epu32
comment|// CHECK: call<4 x i32> @llvm.x86.xop.vpcomud(<4 x i32> %{{.*}},<4 x i32> %{{.*}}, i8 6)
return|return
name|_mm_comfalse_epu32
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
name|test_mm_comfalse_epu64
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comfalse_epu64
comment|// CHECK: call<2 x i64> @llvm.x86.xop.vpcomuq(<2 x i64> %{{.*}},<2 x i64> %{{.*}}, i8 6)
return|return
name|_mm_comfalse_epu64
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
name|test_mm_comfalse_epi8
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comfalse_epi8
comment|// CHECK: call<16 x i8> @llvm.x86.xop.vpcomb(<16 x i8> %{{.*}},<16 x i8> %{{.*}}, i8 6)
return|return
name|_mm_comfalse_epi8
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
name|test_mm_comfalse_epi16
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comfalse_epi16
comment|// CHECK: call<8 x i16> @llvm.x86.xop.vpcomw(<8 x i16> %{{.*}},<8 x i16> %{{.*}}, i8 6)
return|return
name|_mm_comfalse_epi16
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
name|test_mm_comfalse_epi32
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comfalse_epi32
comment|// CHECK: call<4 x i32> @llvm.x86.xop.vpcomd(<4 x i32> %{{.*}},<4 x i32> %{{.*}}, i8 6)
return|return
name|_mm_comfalse_epi32
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
name|test_mm_comfalse_epi64
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comfalse_epi64
comment|// CHECK: call<2 x i64> @llvm.x86.xop.vpcomq(<2 x i64> %{{.*}},<2 x i64> %{{.*}}, i8 6)
return|return
name|_mm_comfalse_epi64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// _MM_PCOMCTRL_TRUE
end_comment

begin_function
name|__m128i
name|test_mm_comtrue_epu8
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comtrue_epu8
comment|// CHECK: call<16 x i8> @llvm.x86.xop.vpcomub(<16 x i8> %{{.*}},<16 x i8> %{{.*}}, i8 7)
return|return
name|_mm_comtrue_epu8
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
name|test_mm_comtrue_epu16
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comtrue_epu16
comment|// CHECK: call<8 x i16> @llvm.x86.xop.vpcomuw(<8 x i16> %{{.*}},<8 x i16> %{{.*}}, i8 7)
return|return
name|_mm_comtrue_epu16
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
name|test_mm_comtrue_epu32
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comtrue_epu32
comment|// CHECK: call<4 x i32> @llvm.x86.xop.vpcomud(<4 x i32> %{{.*}},<4 x i32> %{{.*}}, i8 7)
return|return
name|_mm_comtrue_epu32
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
name|test_mm_comtrue_epu64
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comtrue_epu64
comment|// CHECK: call<2 x i64> @llvm.x86.xop.vpcomuq(<2 x i64> %{{.*}},<2 x i64> %{{.*}}, i8 7)
return|return
name|_mm_comtrue_epu64
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
name|test_mm_comtrue_epi8
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comtrue_epi8
comment|// CHECK: call<16 x i8> @llvm.x86.xop.vpcomb(<16 x i8> %{{.*}},<16 x i8> %{{.*}}, i8 7)
return|return
name|_mm_comtrue_epi8
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
name|test_mm_comtrue_epi16
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comtrue_epi16
comment|// CHECK: call<8 x i16> @llvm.x86.xop.vpcomw(<8 x i16> %{{.*}},<8 x i16> %{{.*}}, i8 7)
return|return
name|_mm_comtrue_epi16
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
name|test_mm_comtrue_epi32
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comtrue_epi32
comment|// CHECK: call<4 x i32> @llvm.x86.xop.vpcomd(<4 x i32> %{{.*}},<4 x i32> %{{.*}}, i8 7)
return|return
name|_mm_comtrue_epi32
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
name|test_mm_comtrue_epi64
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comtrue_epi64
comment|// CHECK: call<2 x i64> @llvm.x86.xop.vpcomq(<2 x i64> %{{.*}},<2 x i64> %{{.*}}, i8 7)
return|return
name|_mm_comtrue_epi64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

end_unit

