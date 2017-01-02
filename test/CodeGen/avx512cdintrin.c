begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ffreestanding %s -triple=x86_64-apple-darwin -target-feature +avx512cd -emit-llvm -o - -Wall -Werror | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<immintrin.h>
end_include

begin_function
name|__m512i
name|test_mm512_conflict_epi64
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_conflict_epi64
comment|// CHECK: @llvm.x86.avx512.mask.conflict.q.512
return|return
name|_mm512_conflict_epi64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_conflict_epi64
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
comment|// CHECK-LABEL: @test_mm512_mask_conflict_epi64
comment|// CHECK: @llvm.x86.avx512.mask.conflict.q.512
return|return
name|_mm512_mask_conflict_epi64
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
name|test_mm512_maskz_conflict_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_conflict_epi64
comment|// CHECK: @llvm.x86.avx512.mask.conflict.q.512
return|return
name|_mm512_maskz_conflict_epi64
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
name|test_mm512_conflict_epi32
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_conflict_epi32
comment|// CHECK: @llvm.x86.avx512.mask.conflict.d.512
return|return
name|_mm512_conflict_epi32
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_conflict_epi32
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
comment|// CHECK-LABEL: @test_mm512_mask_conflict_epi32
comment|// CHECK: @llvm.x86.avx512.mask.conflict.d.512
return|return
name|_mm512_mask_conflict_epi32
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
name|test_mm512_maskz_conflict_epi32
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_conflict_epi32
comment|// CHECK: @llvm.x86.avx512.mask.conflict.d.512
return|return
name|_mm512_maskz_conflict_epi32
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
name|test_mm512_lzcnt_epi32
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_lzcnt_epi32
comment|// CHECK: call<16 x i32> @llvm.ctlz.v16i32(<16 x i32> %{{.*}}, i1 false)
return|return
name|_mm512_lzcnt_epi32
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_lzcnt_epi32
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
comment|// CHECK-LABEL: @test_mm512_mask_lzcnt_epi32
comment|// CHECK: call<16 x i32> @llvm.ctlz.v16i32(<16 x i32> %{{.*}}, i1 false)
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_mask_lzcnt_epi32
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
name|test_mm512_maskz_lzcnt_epi32
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_lzcnt_epi32
comment|// CHECK: call<16 x i32> @llvm.ctlz.v16i32(<16 x i32> %{{.*}}, i1 false)
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_maskz_lzcnt_epi32
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
name|test_mm512_lzcnt_epi64
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_lzcnt_epi64
comment|// CHECK: call<8 x i64> @llvm.ctlz.v8i64(<8 x i64> %{{.*}}, i1 false)
return|return
name|_mm512_lzcnt_epi64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_lzcnt_epi64
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
comment|// CHECK-LABEL: @test_mm512_mask_lzcnt_epi64
comment|// CHECK: call<8 x i64> @llvm.ctlz.v8i64(<8 x i64> %{{.*}}, i1 false)
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_mask_lzcnt_epi64
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
name|test_mm512_maskz_lzcnt_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_lzcnt_epi64
comment|// CHECK: call<8 x i64> @llvm.ctlz.v8i64(<8 x i64> %{{.*}}, i1 false)
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_maskz_lzcnt_epi64
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
name|test_mm512_broadcastmb_epi64
parameter_list|(
name|__mmask8
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_broadcastmb_epi64
comment|// CHECK: @llvm.x86.avx512.broadcastmb.512
return|return
name|_mm512_broadcastmb_epi64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_broadcastmw_epi32
parameter_list|(
name|__mmask16
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_broadcastmw_epi32
comment|// CHECK: @llvm.x86.avx512.broadcastmw.512
return|return
name|_mm512_broadcastmw_epi32
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

end_unit

