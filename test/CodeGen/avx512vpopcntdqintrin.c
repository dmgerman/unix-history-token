begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ffreestanding %s -triple=x86_64-apple-darwin -target-feature +avx512vpopcntdq -emit-llvm -o - -Wall -Werror | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<immintrin.h>
end_include

begin_function
name|__m512i
name|test_mm512_popcnt_epi64
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_popcnt_epi64
comment|// CHECK: @llvm.ctpop.v8i64
return|return
name|_mm512_popcnt_epi64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_popcnt_epi64
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_popcnt_epi64
comment|// CHECK: @llvm.ctpop.v8i64
comment|// CHECK: select<8 x i1> %{{[0-9]+}},<8 x i64> %{{[0-9]+}},<8 x i64> {{.*}}
return|return
name|_mm512_mask_popcnt_epi64
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
name|test_mm512_maskz_popcnt_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_popcnt_epi64
comment|// CHECK: @llvm.ctpop.v8i64
comment|// CHECK: select<8 x i1> %{{[0-9]+}},<8 x i64> %{{[0-9]+}},<8 x i64> {{.*}}
return|return
name|_mm512_maskz_popcnt_epi64
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
name|test_mm512_popcnt_epi32
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_popcnt_epi32
comment|// CHECK: @llvm.ctpop.v16i32
return|return
name|_mm512_popcnt_epi32
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_popcnt_epi32
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_popcnt_epi32
comment|// CHECK: @llvm.ctpop.v16i32
comment|// CHECK: select<16 x i1> %{{[0-9]+}},<16 x i32> %{{[0-9]+}},<16 x i32> {{.*}}
return|return
name|_mm512_mask_popcnt_epi32
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
name|test_mm512_maskz_popcnt_epi32
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_popcnt_epi32
comment|// CHECK: @llvm.ctpop.v16i32
comment|// CHECK: select<16 x i1> %{{[0-9]+}},<16 x i32> %{{[0-9]+}},<16 x i32> {{.*}}
return|return
name|_mm512_maskz_popcnt_epi32
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

end_unit

