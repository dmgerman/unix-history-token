begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ffreestanding %s -triple=x86_64-apple-darwin -target-feature +avx512f -emit-llvm -o - -Wall -Werror | FileCheck %s
end_comment

begin_comment
comment|// FIXME: It's wrong to check LLVM IR transformations from clang. This run should be removed and tests added to the appropriate LLVM pass.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -ffreestanding %s -triple=x86_64-apple-darwin -target-feature +avx512f -O2 -emit-llvm -o - -Wall -Werror | FileCheck %s -check-prefix=O2
end_comment

begin_include
include|#
directive|include
file|<immintrin.h>
end_include

begin_function
name|__m512d
name|test_mm512_sqrt_pd
parameter_list|(
name|__m512d
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_sqrt_pd
comment|// CHECK: @llvm.x86.avx512.mask.sqrt.pd.512
return|return
name|_mm512_sqrt_pd
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_sqrt_pd
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
comment|// CHECK-LABEL: @test_mm512_mask_sqrt_pd
comment|// CHECK: @llvm.x86.avx512.mask.sqrt.pd.512
return|return
name|_mm512_mask_sqrt_pd
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
name|test_mm512_maskz_sqrt_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_sqrt_pd
comment|// CHECK: @llvm.x86.avx512.mask.sqrt.pd.512
return|return
name|_mm512_maskz_sqrt_pd
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
name|test_mm512_mask_sqrt_round_pd
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
comment|// CHECK-LABEL: @test_mm512_mask_sqrt_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.sqrt.pd.512
return|return
name|_mm512_mask_sqrt_round_pd
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
name|__m512d
name|test_mm512_maskz_sqrt_round_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_sqrt_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.sqrt.pd.512
return|return
name|_mm512_maskz_sqrt_round_pd
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
name|test_mm512_sqrt_round_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_sqrt_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.sqrt.pd.512
return|return
name|_mm512_sqrt_round_pd
argument_list|(
name|__A
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_sqrt_ps
parameter_list|(
name|__m512
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_sqrt_ps
comment|// CHECK: @llvm.x86.avx512.mask.sqrt.ps.512
return|return
name|_mm512_sqrt_ps
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_sqrt_ps
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
comment|// CHECK-LABEL: @test_mm512_mask_sqrt_ps
comment|// CHECK: @llvm.x86.avx512.mask.sqrt.ps.512
return|return
name|_mm512_mask_sqrt_ps
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
name|__m512
name|test_mm512_maskz_sqrt_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_sqrt_ps
comment|// CHECK: @llvm.x86.avx512.mask.sqrt.ps.512
return|return
name|_mm512_maskz_sqrt_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_sqrt_round_ps
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
comment|// CHECK-LABEL: @test_mm512_mask_sqrt_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.sqrt.ps.512
return|return
name|_mm512_mask_sqrt_round_ps
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
name|__m512
name|test_mm512_maskz_sqrt_round_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_sqrt_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.sqrt.ps.512
return|return
name|_mm512_maskz_sqrt_round_ps
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
name|__m512
name|test_mm512_sqrt_round_ps
parameter_list|(
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_sqrt_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.sqrt.ps.512
return|return
name|_mm512_sqrt_round_ps
argument_list|(
name|__A
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_rsqrt14_pd
parameter_list|(
name|__m512d
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_rsqrt14_pd
comment|// CHECK: @llvm.x86.avx512.rsqrt14.pd.512
return|return
name|_mm512_rsqrt14_pd
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_rsqrt14_pd
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
comment|// CHECK-LABEL: @test_mm512_mask_rsqrt14_pd
comment|// CHECK: @llvm.x86.avx512.rsqrt14.pd.512
return|return
name|_mm512_mask_rsqrt14_pd
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
name|test_mm512_maskz_rsqrt14_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_rsqrt14_pd
comment|// CHECK: @llvm.x86.avx512.rsqrt14.pd.512
return|return
name|_mm512_maskz_rsqrt14_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_rsqrt14_ps
parameter_list|(
name|__m512
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_rsqrt14_ps
comment|// CHECK: @llvm.x86.avx512.rsqrt14.ps.512
return|return
name|_mm512_rsqrt14_ps
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_rsqrt14_ps
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
comment|// CHECK-LABEL: @test_mm512_mask_rsqrt14_ps
comment|// CHECK: @llvm.x86.avx512.rsqrt14.ps.512
return|return
name|_mm512_mask_rsqrt14_ps
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
name|__m512
name|test_mm512_maskz_rsqrt14_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_rsqrt14_ps
comment|// CHECK: @llvm.x86.avx512.rsqrt14.ps.512
return|return
name|_mm512_maskz_rsqrt14_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_add_ps
parameter_list|(
name|__m512
name|a
parameter_list|,
name|__m512
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_add_ps
comment|// CHECK: fadd<16 x float>
return|return
name|_mm512_add_ps
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_add_pd
parameter_list|(
name|__m512d
name|a
parameter_list|,
name|__m512d
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_add_pd
comment|// CHECK: fadd<8 x double>
return|return
name|_mm512_add_pd
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mul_ps
parameter_list|(
name|__m512
name|a
parameter_list|,
name|__m512
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mul_ps
comment|// CHECK: fmul<16 x float>
return|return
name|_mm512_mul_ps
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mul_pd
parameter_list|(
name|__m512d
name|a
parameter_list|,
name|__m512d
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mul_pd
comment|// CHECK: fmul<8 x double>
return|return
name|_mm512_mul_pd
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm512_storeu_si512
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_storeu_si512
comment|// CHECK: store<16 x i32> %{{.*}},<16 x i32>* %{{.*}}, align 1{{$}}
comment|// CHECK-NEXT: ret void
name|_mm512_storeu_si512
argument_list|(
name|__P
argument_list|,
name|__A
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_mm512_storeu_ps
parameter_list|(
name|void
modifier|*
name|p
parameter_list|,
name|__m512
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_storeu_ps
comment|// CHECK: store<16 x float> %{{.*}},<16 x float>* %{{.*}}, align 1{{$}}
comment|// CHECK-NEXT: ret void
name|_mm512_storeu_ps
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
name|test_mm512_storeu_pd
parameter_list|(
name|void
modifier|*
name|p
parameter_list|,
name|__m512d
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_storeu_pd
comment|// CHECK: store<8 x double> %{{.*}},<8 x double>* %{{.*}}, align 1{{$}}
comment|// CHECK-NEXT: ret void
name|_mm512_storeu_pd
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
name|test_mm512_mask_store_ps
parameter_list|(
name|void
modifier|*
name|p
parameter_list|,
name|__m512
name|a
parameter_list|,
name|__mmask16
name|m
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_store_ps
comment|// CHECK: @llvm.masked.store.v16f32.p0v16f32(<16 x float> %{{.*}},<16 x float>* %{{.*}}, i32 64,<16 x i1> %{{.*}})
name|_mm512_mask_store_ps
argument_list|(
name|p
argument_list|,
name|m
argument_list|,
name|a
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_mm512_store_si512
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_store_si512
comment|// CHECK: load<8 x i64>,<8 x i64>* %__A.addr.i, align 64
comment|// CHECK: [[SI512_3:%.+]] = load i8*, i8** %__P.addr.i, align 8
comment|// CHECK: bitcast i8* [[SI512_3]] to<8 x i64>*
comment|// CHECK: store<8 x i64>
name|_mm512_store_si512
argument_list|(
name|__P
argument_list|,
name|__A
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_mm512_store_epi32
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_store_epi32
comment|// CHECK: load<8 x i64>,<8 x i64>* %__A.addr.i, align 64
comment|// CHECK: [[Si32_3:%.+]] = load i8*, i8** %__P.addr.i, align 8
comment|// CHECK: bitcast i8* [[Si32_3]] to<8 x i64>*
comment|// CHECK: store<8 x i64>
name|_mm512_store_epi32
argument_list|(
name|__P
argument_list|,
name|__A
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_mm512_store_epi64
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_store_epi64
comment|// CHECK: load<8 x i64>,<8 x i64>* %__A.addr.i, align 64
comment|// CHECK: [[SI64_3:%.+]] = load i8*, i8** %__P.addr.i, align 8
comment|// CHECK: bitcast i8* [[SI64_3]] to<8 x i64>*
comment|// CHECK: store<8 x i64>
name|_mm512_store_epi64
argument_list|(
name|__P
argument_list|,
name|__A
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_mm512_store_ps
parameter_list|(
name|void
modifier|*
name|p
parameter_list|,
name|__m512
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_store_ps
comment|// CHECK: store<16 x float>
name|_mm512_store_ps
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
name|test_mm512_store_pd
parameter_list|(
name|void
modifier|*
name|p
parameter_list|,
name|__m512d
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_store_pd
comment|// CHECK: store<8 x double>
name|_mm512_store_pd
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
name|test_mm512_mask_store_pd
parameter_list|(
name|void
modifier|*
name|p
parameter_list|,
name|__m512d
name|a
parameter_list|,
name|__mmask8
name|m
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_store_pd
comment|// CHECK: @llvm.masked.store.v8f64.p0v8f64(<8 x double> %{{.*}},<8 x double>* %{{.*}}, i32 64,<8 x i1> %{{.*}})
name|_mm512_mask_store_pd
argument_list|(
name|p
argument_list|,
name|m
argument_list|,
name|a
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_mm512_mask_storeu_epi32
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_storeu_epi32
comment|// CHECK: @llvm.masked.store.v16i32.p0v16i32(<16 x i32> %{{.*}},<16 x i32>* %{{.*}}, i32 1,<16 x i1> %{{.*}})
return|return
name|_mm512_mask_storeu_epi32
argument_list|(
name|__P
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm512_mask_storeu_epi64
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_storeu_epi64
comment|// CHECK: @llvm.masked.store.v8i64.p0v8i64(<8 x i64> %{{.*}},<8 x i64>* %{{.*}}, i32 1,<8 x i1> %{{.*}})
return|return
name|_mm512_mask_storeu_epi64
argument_list|(
name|__P
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
name|test_mm512_loadu_si512
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_loadu_si512
comment|// CHECK: load<16 x i32>,<16 x i32>* %{{.*}}, align 1{{$}}
return|return
name|_mm512_loadu_si512
argument_list|(
name|__P
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_loadu_epi32
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|void
modifier|*
name|__P
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_loadu_epi32
comment|// CHECK: @llvm.masked.load.v16i32.p0v16i32(<16 x i32>* %{{.*}}, i32 1,<16 x i1> %{{.*}},<16 x i32> %{{.*}})
return|return
name|_mm512_mask_loadu_epi32
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__P
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_loadu_epi64
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|void
modifier|*
name|__P
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_loadu_epi64
comment|// CHECK: @llvm.masked.load.v8i64.p0v8i64(<8 x i64>* %{{.*}}, i32 1,<8 x i1> %{{.*}},<8 x i64> %{{.*}})
return|return
name|_mm512_mask_loadu_epi64
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__P
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_loadu_ps
parameter_list|(
name|void
modifier|*
name|p
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_loadu_ps
comment|// CHECK: load<16 x float>,<16 x float>* {{.*}}, align 1{{$}}
return|return
name|_mm512_loadu_ps
argument_list|(
name|p
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_loadu_ps
parameter_list|(
name|__m512
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|void
modifier|*
name|__P
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_loadu_ps
comment|// CHECK: @llvm.masked.load.v16f32.p0v16f32(<16 x float>* %{{.*}}, i32 1,<16 x i1> %{{.*}},<16 x float> %{{.*}})
return|return
name|_mm512_mask_loadu_ps
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__P
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_loadu_pd
parameter_list|(
name|void
modifier|*
name|p
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_loadu_pd
comment|// CHECK: load<8 x double>,<8 x double>* {{.*}}, align 1{{$}}
return|return
name|_mm512_loadu_pd
argument_list|(
name|p
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_loadu_pd
parameter_list|(
name|__m512d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|void
modifier|*
name|__P
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_loadu_pd
comment|// CHECK: @llvm.masked.load.v8f64.p0v8f64(<8 x double>* %{{.*}}, i32 1,<8 x i1> %{{.*}},<8 x double> %{{.*}})
return|return
name|_mm512_mask_loadu_pd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__P
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_load_si512
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_load_si512
comment|// CHECK: [[LI512_1:%.+]] = load i8*, i8** %__P.addr.i, align 8
comment|// CHECK: [[LI512_2:%.+]] = bitcast i8* [[LI512_1]] to<8 x i64>*
comment|// CHECK: load<8 x i64>,<8 x i64>* [[LI512_2]], align 64
return|return
name|_mm512_load_si512
argument_list|(
name|__P
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_load_epi32
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_load_epi32
comment|// CHECK: [[LI32_1:%.+]] = load i8*, i8** %__P.addr.i, align 8
comment|// CHECK: [[LI32_2:%.+]] = bitcast i8* [[LI32_1]] to<8 x i64>*
comment|// CHECK: load<8 x i64>,<8 x i64>* [[LI32_2]], align 64
return|return
name|_mm512_load_epi32
argument_list|(
name|__P
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_load_epi64
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_load_epi64
comment|// CHECK: [[LI64_1:%.+]] = load i8*, i8** %__P.addr.i, align 8
comment|// CHECK: [[LI64_2:%.+]] = bitcast i8* [[LI64_1]] to<8 x i64>*
comment|// CHECK: load<8 x i64>,<8 x i64>* [[LI64_2]], align 64
return|return
name|_mm512_load_epi64
argument_list|(
name|__P
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_load_ps
parameter_list|(
name|void
modifier|*
name|p
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_load_ps
comment|// CHECK: load<16 x float>,<16 x float>* %{{.*}}, align 64
return|return
name|_mm512_load_ps
argument_list|(
name|p
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_load_ps
parameter_list|(
name|__m512
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|void
modifier|*
name|__P
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_load_ps
comment|// CHECK: @llvm.masked.load.v16f32.p0v16f32(<16 x float>* %{{.*}}, i32 64,<16 x i1> %{{.*}},<16 x float> %{{.*}})
return|return
name|_mm512_mask_load_ps
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__P
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_maskz_load_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|void
modifier|*
name|__P
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_load_ps
comment|// CHECK: @llvm.masked.load.v16f32.p0v16f32(<16 x float>* %{{.*}}, i32 64,<16 x i1> %{{.*}},<16 x float> %{{.*}})
return|return
name|_mm512_maskz_load_ps
argument_list|(
name|__U
argument_list|,
name|__P
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_load_pd
parameter_list|(
name|void
modifier|*
name|p
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_load_pd
comment|// CHECK: load<8 x double>,<8 x double>* %{{.*}}, align 64
return|return
name|_mm512_load_pd
argument_list|(
name|p
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_load_pd
parameter_list|(
name|__m512d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|void
modifier|*
name|__P
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_load_pd
comment|// CHECK: @llvm.masked.load.v8f64.p0v8f64(<8 x double>* %{{.*}}, i32 64,<8 x i1> %{{.*}},<8 x double> %{{.*}})
return|return
name|_mm512_mask_load_pd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__P
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_maskz_load_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|void
modifier|*
name|__P
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_load_pd
comment|// CHECK: @llvm.masked.load.v8f64.p0v8f64(<8 x double>* %{{.*}}, i32 64,<8 x i1> %{{.*}},<8 x double> %{{.*}})
return|return
name|_mm512_maskz_load_pd
argument_list|(
name|__U
argument_list|,
name|__P
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_set1_pd
parameter_list|(
name|double
name|d
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_set1_pd
comment|// CHECK: insertelement<8 x double> {{.*}}, i32 0
comment|// CHECK: insertelement<8 x double> {{.*}}, i32 1
comment|// CHECK: insertelement<8 x double> {{.*}}, i32 2
comment|// CHECK: insertelement<8 x double> {{.*}}, i32 3
comment|// CHECK: insertelement<8 x double> {{.*}}, i32 4
comment|// CHECK: insertelement<8 x double> {{.*}}, i32 5
comment|// CHECK: insertelement<8 x double> {{.*}}, i32 6
comment|// CHECK: insertelement<8 x double> {{.*}}, i32 7
return|return
name|_mm512_set1_pd
argument_list|(
name|d
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm512_knot
parameter_list|(
name|__mmask16
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_knot
comment|// CHECK: @llvm.x86.avx512.knot.w
return|return
name|_mm512_knot
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_alignr_epi32
parameter_list|(
name|__m512i
name|a
parameter_list|,
name|__m512i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_alignr_epi32
comment|// CHECK: shufflevector<16 x i32> %{{.*}},<16 x i32> %{{.*}},<16 x i32><i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15, i32 16, i32 17>
return|return
name|_mm512_alignr_epi32
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
name|__m512i
name|test_mm512_mask_alignr_epi32
parameter_list|(
name|__m512i
name|w
parameter_list|,
name|__mmask16
name|u
parameter_list|,
name|__m512i
name|a
parameter_list|,
name|__m512i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_alignr_epi32
comment|// CHECK: shufflevector<16 x i32> %{{.*}},<16 x i32> %{{.*}},<16 x i32><i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15, i32 16, i32 17>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i32> %{{.*}},<16 x i32> {{.*}}
return|return
name|_mm512_mask_alignr_epi32
argument_list|(
name|w
argument_list|,
name|u
argument_list|,
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
name|__m512i
name|test_mm512_maskz_alignr_epi32
parameter_list|(
name|__mmask16
name|u
parameter_list|,
name|__m512i
name|a
parameter_list|,
name|__m512i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_alignr_epi32
comment|// CHECK: shufflevector<16 x i32> %{{.*}},<16 x i32> %{{.*}},<16 x i32><i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15, i32 16, i32 17>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i32> %{{.*}},<16 x i32> {{.*}}
return|return
name|_mm512_maskz_alignr_epi32
argument_list|(
name|u
argument_list|,
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
name|__m512i
name|test_mm512_alignr_epi64
parameter_list|(
name|__m512i
name|a
parameter_list|,
name|__m512i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_alignr_epi64
comment|// CHECK: shufflevector<8 x i64> %{{.*}},<8 x i64> %{{.*}},<8 x i32><i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 8, i32 9>
return|return
name|_mm512_alignr_epi64
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
name|__m512i
name|test_mm512_mask_alignr_epi64
parameter_list|(
name|__m512i
name|w
parameter_list|,
name|__mmask8
name|u
parameter_list|,
name|__m512i
name|a
parameter_list|,
name|__m512i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_alignr_epi64
comment|// CHECK: shufflevector<8 x i64> %{{.*}},<8 x i64> %{{.*}},<8 x i32><i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 8, i32 9>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> {{.*}}
return|return
name|_mm512_mask_alignr_epi64
argument_list|(
name|w
argument_list|,
name|u
argument_list|,
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
name|__m512i
name|test_mm512_maskz_alignr_epi64
parameter_list|(
name|__mmask8
name|u
parameter_list|,
name|__m512i
name|a
parameter_list|,
name|__m512i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_alignr_epi64
comment|// CHECK: shufflevector<8 x i64> %{{.*}},<8 x i64> %{{.*}},<8 x i32><i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 8, i32 9>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> {{.*}}
return|return
name|_mm512_maskz_alignr_epi64
argument_list|(
name|u
argument_list|,
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
name|__m512d
name|test_mm512_fmadd_round_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|,
name|__m512d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_fmadd_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.vfmadd.pd.512
return|return
name|_mm512_fmadd_round_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
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
name|test_mm512_mask_fmadd_round_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__B
parameter_list|,
name|__m512d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_fmadd_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.vfmadd.pd.512
return|return
name|_mm512_mask_fmadd_round_pd
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
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
name|test_mm512_mask3_fmadd_round_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|,
name|__m512d
name|__C
parameter_list|,
name|__mmask8
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask3_fmadd_round_pd
comment|// CHECK: @llvm.x86.avx512.mask3.vfmadd.pd.512
return|return
name|_mm512_mask3_fmadd_round_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__U
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
name|test_mm512_maskz_fmadd_round_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|,
name|__m512d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_fmadd_round_pd
comment|// CHECK: @llvm.x86.avx512.maskz.vfmadd.pd.512
return|return
name|_mm512_maskz_fmadd_round_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
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
name|test_mm512_fmsub_round_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|,
name|__m512d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_fmsub_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.vfmadd.pd.512
return|return
name|_mm512_fmsub_round_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
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
name|test_mm512_mask_fmsub_round_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__B
parameter_list|,
name|__m512d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_fmsub_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.vfmadd.pd.512
return|return
name|_mm512_mask_fmsub_round_pd
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
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
name|test_mm512_maskz_fmsub_round_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|,
name|__m512d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_fmsub_round_pd
comment|// CHECK: @llvm.x86.avx512.maskz.vfmadd.pd.512
return|return
name|_mm512_maskz_fmsub_round_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
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
name|test_mm512_fnmadd_round_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|,
name|__m512d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_fnmadd_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.vfmadd.pd.512
return|return
name|_mm512_fnmadd_round_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
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
name|test_mm512_mask3_fnmadd_round_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|,
name|__m512d
name|__C
parameter_list|,
name|__mmask8
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask3_fnmadd_round_pd
comment|// CHECK: @llvm.x86.avx512.mask3.vfmadd.pd.512
return|return
name|_mm512_mask3_fnmadd_round_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__U
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
name|test_mm512_maskz_fnmadd_round_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|,
name|__m512d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_fnmadd_round_pd
comment|// CHECK: @llvm.x86.avx512.maskz.vfmadd.pd.512
return|return
name|_mm512_maskz_fnmadd_round_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
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
name|test_mm512_fnmsub_round_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|,
name|__m512d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_fnmsub_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.vfmadd.pd.512
return|return
name|_mm512_fnmsub_round_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
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
name|test_mm512_maskz_fnmsub_round_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|,
name|__m512d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_fnmsub_round_pd
comment|// CHECK: @llvm.x86.avx512.maskz.vfmadd.pd.512
return|return
name|_mm512_maskz_fnmsub_round_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
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
name|test_mm512_fmadd_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|,
name|__m512d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_fmadd_pd
comment|// CHECK: @llvm.x86.avx512.mask.vfmadd.pd.512
return|return
name|_mm512_fmadd_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_fmadd_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__B
parameter_list|,
name|__m512d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_fmadd_pd
comment|// CHECK: @llvm.x86.avx512.mask.vfmadd.pd.512
return|return
name|_mm512_mask_fmadd_pd
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask3_fmadd_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|,
name|__m512d
name|__C
parameter_list|,
name|__mmask8
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask3_fmadd_pd
comment|// CHECK: @llvm.x86.avx512.mask3.vfmadd.pd.512
return|return
name|_mm512_mask3_fmadd_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__U
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_maskz_fmadd_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|,
name|__m512d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_fmadd_pd
comment|// CHECK: @llvm.x86.avx512.maskz.vfmadd.pd.512
return|return
name|_mm512_maskz_fmadd_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_fmsub_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|,
name|__m512d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_fmsub_pd
comment|// CHECK: @llvm.x86.avx512.mask.vfmadd.pd.512
return|return
name|_mm512_fmsub_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_fmsub_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__B
parameter_list|,
name|__m512d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_fmsub_pd
comment|// CHECK: @llvm.x86.avx512.mask.vfmadd.pd.512
return|return
name|_mm512_mask_fmsub_pd
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_maskz_fmsub_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|,
name|__m512d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_fmsub_pd
comment|// CHECK: @llvm.x86.avx512.maskz.vfmadd.pd.512
return|return
name|_mm512_maskz_fmsub_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_fnmadd_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|,
name|__m512d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_fnmadd_pd
comment|// CHECK: @llvm.x86.avx512.mask.vfmadd.pd.512
return|return
name|_mm512_fnmadd_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask3_fnmadd_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|,
name|__m512d
name|__C
parameter_list|,
name|__mmask8
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask3_fnmadd_pd
comment|// CHECK: @llvm.x86.avx512.mask3.vfmadd.pd.512
return|return
name|_mm512_mask3_fnmadd_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__U
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_maskz_fnmadd_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|,
name|__m512d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_fnmadd_pd
comment|// CHECK: @llvm.x86.avx512.maskz.vfmadd.pd.512
return|return
name|_mm512_maskz_fnmadd_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_fnmsub_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|,
name|__m512d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_fnmsub_pd
comment|// CHECK: @llvm.x86.avx512.mask.vfmadd.pd.512
return|return
name|_mm512_fnmsub_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_maskz_fnmsub_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|,
name|__m512d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_fnmsub_pd
comment|// CHECK: @llvm.x86.avx512.maskz.vfmadd.pd.512
return|return
name|_mm512_maskz_fnmsub_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_fmadd_round_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|,
name|__m512
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_fmadd_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.vfmadd.ps.512
return|return
name|_mm512_fmadd_round_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_fmadd_round_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__B
parameter_list|,
name|__m512
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_fmadd_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.vfmadd.ps.512
return|return
name|_mm512_mask_fmadd_round_ps
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask3_fmadd_round_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|,
name|__m512
name|__C
parameter_list|,
name|__mmask16
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask3_fmadd_round_ps
comment|// CHECK: @llvm.x86.avx512.mask3.vfmadd.ps.512
return|return
name|_mm512_mask3_fmadd_round_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__U
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_maskz_fmadd_round_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|,
name|__m512
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_fmadd_round_ps
comment|// CHECK: @llvm.x86.avx512.maskz.vfmadd.ps.512
return|return
name|_mm512_maskz_fmadd_round_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_fmsub_round_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|,
name|__m512
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_fmsub_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.vfmadd.ps.512
return|return
name|_mm512_fmsub_round_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_fmsub_round_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__B
parameter_list|,
name|__m512
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_fmsub_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.vfmadd.ps.512
return|return
name|_mm512_mask_fmsub_round_ps
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_maskz_fmsub_round_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|,
name|__m512
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_fmsub_round_ps
comment|// CHECK: @llvm.x86.avx512.maskz.vfmadd.ps.512
return|return
name|_mm512_maskz_fmsub_round_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_fnmadd_round_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|,
name|__m512
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_fnmadd_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.vfmadd.ps.512
return|return
name|_mm512_fnmadd_round_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask3_fnmadd_round_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|,
name|__m512
name|__C
parameter_list|,
name|__mmask16
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask3_fnmadd_round_ps
comment|// CHECK: @llvm.x86.avx512.mask3.vfmadd.ps.512
return|return
name|_mm512_mask3_fnmadd_round_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__U
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_maskz_fnmadd_round_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|,
name|__m512
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_fnmadd_round_ps
comment|// CHECK: @llvm.x86.avx512.maskz.vfmadd.ps.512
return|return
name|_mm512_maskz_fnmadd_round_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_fnmsub_round_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|,
name|__m512
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_fnmsub_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.vfmadd.ps.512
return|return
name|_mm512_fnmsub_round_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_maskz_fnmsub_round_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|,
name|__m512
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_fnmsub_round_ps
comment|// CHECK: @llvm.x86.avx512.maskz.vfmadd.ps.512
return|return
name|_mm512_maskz_fnmsub_round_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_fmadd_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|,
name|__m512
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_fmadd_ps
comment|// CHECK: @llvm.x86.avx512.mask.vfmadd.ps.512
return|return
name|_mm512_fmadd_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_fmadd_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__B
parameter_list|,
name|__m512
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_fmadd_ps
comment|// CHECK: @llvm.x86.avx512.mask.vfmadd.ps.512
return|return
name|_mm512_mask_fmadd_ps
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask3_fmadd_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|,
name|__m512
name|__C
parameter_list|,
name|__mmask16
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask3_fmadd_ps
comment|// CHECK: @llvm.x86.avx512.mask3.vfmadd.ps.512
return|return
name|_mm512_mask3_fmadd_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__U
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_maskz_fmadd_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|,
name|__m512
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_fmadd_ps
comment|// CHECK: @llvm.x86.avx512.maskz.vfmadd.ps.512
return|return
name|_mm512_maskz_fmadd_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_fmsub_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|,
name|__m512
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_fmsub_ps
comment|// CHECK: @llvm.x86.avx512.mask.vfmadd.ps.512
return|return
name|_mm512_fmsub_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_fmsub_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__B
parameter_list|,
name|__m512
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_fmsub_ps
comment|// CHECK: @llvm.x86.avx512.mask.vfmadd.ps.512
return|return
name|_mm512_mask_fmsub_ps
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_maskz_fmsub_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|,
name|__m512
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_fmsub_ps
comment|// CHECK: @llvm.x86.avx512.maskz.vfmadd.ps.512
return|return
name|_mm512_maskz_fmsub_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_fnmadd_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|,
name|__m512
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_fnmadd_ps
comment|// CHECK: @llvm.x86.avx512.mask.vfmadd.ps.512
return|return
name|_mm512_fnmadd_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask3_fnmadd_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|,
name|__m512
name|__C
parameter_list|,
name|__mmask16
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask3_fnmadd_ps
comment|// CHECK: @llvm.x86.avx512.mask3.vfmadd.ps.512
return|return
name|_mm512_mask3_fnmadd_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__U
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_maskz_fnmadd_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|,
name|__m512
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_fnmadd_ps
comment|// CHECK: @llvm.x86.avx512.maskz.vfmadd.ps.512
return|return
name|_mm512_maskz_fnmadd_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_fnmsub_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|,
name|__m512
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_fnmsub_ps
comment|// CHECK: @llvm.x86.avx512.mask.vfmadd.ps.512
return|return
name|_mm512_fnmsub_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_maskz_fnmsub_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|,
name|__m512
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_fnmsub_ps
comment|// CHECK: @llvm.x86.avx512.maskz.vfmadd.ps.512
return|return
name|_mm512_maskz_fnmsub_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_fmaddsub_round_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|,
name|__m512d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_fmaddsub_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.vfmaddsub.pd.512
return|return
name|_mm512_fmaddsub_round_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
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
name|test_mm512_mask_fmaddsub_round_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__B
parameter_list|,
name|__m512d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_fmaddsub_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.vfmaddsub.pd.512
return|return
name|_mm512_mask_fmaddsub_round_pd
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
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
name|test_mm512_mask3_fmaddsub_round_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|,
name|__m512d
name|__C
parameter_list|,
name|__mmask8
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask3_fmaddsub_round_pd
comment|// CHECK: @llvm.x86.avx512.mask3.vfmaddsub.pd.512
return|return
name|_mm512_mask3_fmaddsub_round_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__U
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
name|test_mm512_maskz_fmaddsub_round_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|,
name|__m512d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_fmaddsub_round_pd
comment|// CHECK: @llvm.x86.avx512.maskz.vfmaddsub.pd.512
return|return
name|_mm512_maskz_fmaddsub_round_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
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
name|test_mm512_fmsubadd_round_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|,
name|__m512d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_fmsubadd_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.vfmaddsub.pd.512
return|return
name|_mm512_fmsubadd_round_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
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
name|test_mm512_mask_fmsubadd_round_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__B
parameter_list|,
name|__m512d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_fmsubadd_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.vfmaddsub.pd.512
return|return
name|_mm512_mask_fmsubadd_round_pd
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
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
name|test_mm512_maskz_fmsubadd_round_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|,
name|__m512d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_fmsubadd_round_pd
comment|// CHECK: @llvm.x86.avx512.maskz.vfmaddsub.pd.512
return|return
name|_mm512_maskz_fmsubadd_round_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
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
name|test_mm512_fmaddsub_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|,
name|__m512d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_fmaddsub_pd
comment|// CHECK: @llvm.x86.avx512.mask.vfmaddsub.pd.512
return|return
name|_mm512_fmaddsub_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_fmaddsub_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__B
parameter_list|,
name|__m512d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_fmaddsub_pd
comment|// CHECK: @llvm.x86.avx512.mask.vfmaddsub.pd.512
return|return
name|_mm512_mask_fmaddsub_pd
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask3_fmaddsub_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|,
name|__m512d
name|__C
parameter_list|,
name|__mmask8
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask3_fmaddsub_pd
comment|// CHECK: @llvm.x86.avx512.mask3.vfmaddsub.pd.512
return|return
name|_mm512_mask3_fmaddsub_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__U
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_maskz_fmaddsub_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|,
name|__m512d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_fmaddsub_pd
comment|// CHECK: @llvm.x86.avx512.maskz.vfmaddsub.pd.512
return|return
name|_mm512_maskz_fmaddsub_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_fmsubadd_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|,
name|__m512d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_fmsubadd_pd
comment|// CHECK: @llvm.x86.avx512.mask.vfmaddsub.pd.512
return|return
name|_mm512_fmsubadd_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_fmsubadd_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__B
parameter_list|,
name|__m512d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_fmsubadd_pd
comment|// CHECK: @llvm.x86.avx512.mask.vfmaddsub.pd.512
return|return
name|_mm512_mask_fmsubadd_pd
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_maskz_fmsubadd_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|,
name|__m512d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_fmsubadd_pd
comment|// CHECK: @llvm.x86.avx512.maskz.vfmaddsub.pd.512
return|return
name|_mm512_maskz_fmsubadd_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_fmaddsub_round_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|,
name|__m512
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_fmaddsub_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.vfmaddsub.ps.512
return|return
name|_mm512_fmaddsub_round_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_fmaddsub_round_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__B
parameter_list|,
name|__m512
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_fmaddsub_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.vfmaddsub.ps.512
return|return
name|_mm512_mask_fmaddsub_round_ps
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask3_fmaddsub_round_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|,
name|__m512
name|__C
parameter_list|,
name|__mmask16
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask3_fmaddsub_round_ps
comment|// CHECK: @llvm.x86.avx512.mask3.vfmaddsub.ps.512
return|return
name|_mm512_mask3_fmaddsub_round_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__U
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_maskz_fmaddsub_round_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|,
name|__m512
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_fmaddsub_round_ps
comment|// CHECK: @llvm.x86.avx512.maskz.vfmaddsub.ps.512
return|return
name|_mm512_maskz_fmaddsub_round_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_fmsubadd_round_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|,
name|__m512
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_fmsubadd_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.vfmaddsub.ps.512
return|return
name|_mm512_fmsubadd_round_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_fmsubadd_round_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__B
parameter_list|,
name|__m512
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_fmsubadd_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.vfmaddsub.ps.512
return|return
name|_mm512_mask_fmsubadd_round_ps
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_maskz_fmsubadd_round_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|,
name|__m512
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_fmsubadd_round_ps
comment|// CHECK: @llvm.x86.avx512.maskz.vfmaddsub.ps.512
return|return
name|_mm512_maskz_fmsubadd_round_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_fmaddsub_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|,
name|__m512
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_fmaddsub_ps
comment|// CHECK: @llvm.x86.avx512.mask.vfmaddsub.ps.512
return|return
name|_mm512_fmaddsub_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_fmaddsub_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__B
parameter_list|,
name|__m512
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_fmaddsub_ps
comment|// CHECK: @llvm.x86.avx512.mask.vfmaddsub.ps.512
return|return
name|_mm512_mask_fmaddsub_ps
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask3_fmaddsub_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|,
name|__m512
name|__C
parameter_list|,
name|__mmask16
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask3_fmaddsub_ps
comment|// CHECK: @llvm.x86.avx512.mask3.vfmaddsub.ps.512
return|return
name|_mm512_mask3_fmaddsub_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__U
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_maskz_fmaddsub_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|,
name|__m512
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_fmaddsub_ps
comment|// CHECK: @llvm.x86.avx512.maskz.vfmaddsub.ps.512
return|return
name|_mm512_maskz_fmaddsub_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_fmsubadd_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|,
name|__m512
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_fmsubadd_ps
comment|// CHECK: @llvm.x86.avx512.mask.vfmaddsub.ps.512
return|return
name|_mm512_fmsubadd_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_fmsubadd_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__B
parameter_list|,
name|__m512
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_fmsubadd_ps
comment|// CHECK: @llvm.x86.avx512.mask.vfmaddsub.ps.512
return|return
name|_mm512_mask_fmsubadd_ps
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_maskz_fmsubadd_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|,
name|__m512
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_fmsubadd_ps
comment|// CHECK: @llvm.x86.avx512.maskz.vfmaddsub.ps.512
return|return
name|_mm512_maskz_fmsubadd_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask3_fmsub_round_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|,
name|__m512d
name|__C
parameter_list|,
name|__mmask8
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask3_fmsub_round_pd
comment|// CHECK: @llvm.x86.avx512.mask3.vfmsub.pd.512
return|return
name|_mm512_mask3_fmsub_round_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__U
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
name|test_mm512_mask3_fmsub_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|,
name|__m512d
name|__C
parameter_list|,
name|__mmask8
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask3_fmsub_pd
comment|// CHECK: @llvm.x86.avx512.mask3.vfmsub.pd.512
return|return
name|_mm512_mask3_fmsub_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__U
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask3_fmsub_round_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|,
name|__m512
name|__C
parameter_list|,
name|__mmask16
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask3_fmsub_round_ps
comment|// CHECK: @llvm.x86.avx512.mask3.vfmsub.ps.512
return|return
name|_mm512_mask3_fmsub_round_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__U
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask3_fmsub_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|,
name|__m512
name|__C
parameter_list|,
name|__mmask16
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask3_fmsub_ps
comment|// CHECK: @llvm.x86.avx512.mask3.vfmsub.ps.512
return|return
name|_mm512_mask3_fmsub_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__U
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask3_fmsubadd_round_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|,
name|__m512d
name|__C
parameter_list|,
name|__mmask8
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask3_fmsubadd_round_pd
comment|// CHECK: @llvm.x86.avx512.mask3.vfmsubadd.pd.512
return|return
name|_mm512_mask3_fmsubadd_round_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__U
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
name|test_mm512_mask3_fmsubadd_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|,
name|__m512d
name|__C
parameter_list|,
name|__mmask8
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask3_fmsubadd_pd
comment|// CHECK: @llvm.x86.avx512.mask3.vfmsubadd.pd.512
return|return
name|_mm512_mask3_fmsubadd_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__U
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask3_fmsubadd_round_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|,
name|__m512
name|__C
parameter_list|,
name|__mmask16
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask3_fmsubadd_round_ps
comment|// CHECK: @llvm.x86.avx512.mask3.vfmsubadd.ps.512
return|return
name|_mm512_mask3_fmsubadd_round_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__U
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask3_fmsubadd_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|,
name|__m512
name|__C
parameter_list|,
name|__mmask16
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask3_fmsubadd_ps
comment|// CHECK: @llvm.x86.avx512.mask3.vfmsubadd.ps.512
return|return
name|_mm512_mask3_fmsubadd_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__U
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_fnmadd_round_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__B
parameter_list|,
name|__m512d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_fnmadd_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.vfnmadd.pd.512
return|return
name|_mm512_mask_fnmadd_round_pd
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
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
name|test_mm512_mask_fnmadd_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__B
parameter_list|,
name|__m512d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_fnmadd_pd
comment|// CHECK: @llvm.x86.avx512.mask.vfnmadd.pd.512
return|return
name|_mm512_mask_fnmadd_pd
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_fnmadd_round_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__B
parameter_list|,
name|__m512
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_fnmadd_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.vfnmadd.ps.512
return|return
name|_mm512_mask_fnmadd_round_ps
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_fnmadd_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__B
parameter_list|,
name|__m512
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_fnmadd_ps
comment|// CHECK: @llvm.x86.avx512.mask.vfnmadd.ps.512
return|return
name|_mm512_mask_fnmadd_ps
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_fnmsub_round_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__B
parameter_list|,
name|__m512d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_fnmsub_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.vfnmsub.pd.512
return|return
name|_mm512_mask_fnmsub_round_pd
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
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
name|test_mm512_mask3_fnmsub_round_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|,
name|__m512d
name|__C
parameter_list|,
name|__mmask8
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask3_fnmsub_round_pd
comment|// CHECK: @llvm.x86.avx512.mask3.vfnmsub.pd.512
return|return
name|_mm512_mask3_fnmsub_round_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__U
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
name|test_mm512_mask_fnmsub_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__B
parameter_list|,
name|__m512d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_fnmsub_pd
comment|// CHECK: @llvm.x86.avx512.mask.vfnmsub.pd.512
return|return
name|_mm512_mask_fnmsub_pd
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask3_fnmsub_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|,
name|__m512d
name|__C
parameter_list|,
name|__mmask8
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask3_fnmsub_pd
comment|// CHECK: @llvm.x86.avx512.mask3.vfnmsub.pd.512
return|return
name|_mm512_mask3_fnmsub_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__U
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_fnmsub_round_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__B
parameter_list|,
name|__m512
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_fnmsub_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.vfnmsub.ps.512
return|return
name|_mm512_mask_fnmsub_round_ps
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask3_fnmsub_round_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|,
name|__m512
name|__C
parameter_list|,
name|__mmask16
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask3_fnmsub_round_ps
comment|// CHECK: @llvm.x86.avx512.mask3.vfnmsub.ps.512
return|return
name|_mm512_mask3_fnmsub_round_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__U
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_fnmsub_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__B
parameter_list|,
name|__m512
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_fnmsub_ps
comment|// CHECK: @llvm.x86.avx512.mask.vfnmsub.ps.512
return|return
name|_mm512_mask_fnmsub_ps
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask3_fnmsub_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|,
name|__m512
name|__C
parameter_list|,
name|__mmask16
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask3_fnmsub_ps
comment|// CHECK: @llvm.x86.avx512.mask3.vfnmsub.ps.512
return|return
name|_mm512_mask3_fnmsub_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__U
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm512_cmpeq_epi32_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpeq_epi32_mask
comment|// CHECK: icmp eq<16 x i32> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm512_cmpeq_epi32_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm512_mask_cmpeq_epi32_mask
parameter_list|(
name|__mmask16
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpeq_epi32_mask
comment|// CHECK: icmp eq<16 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: and<16 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm512_mask_cmpeq_epi32_mask
argument_list|(
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_mask_cmpeq_epi64_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpeq_epi64_mask
comment|// CHECK: icmp eq<8 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: and<8 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm512_mask_cmpeq_epi64_mask
argument_list|(
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_cmpeq_epi64_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpeq_epi64_mask
comment|// CHECK: icmp eq<8 x i64> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm512_cmpeq_epi64_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm512_cmpgt_epi32_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpgt_epi32_mask
comment|// CHECK: icmp sgt<16 x i32> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm512_cmpgt_epi32_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm512_mask_cmpgt_epi32_mask
parameter_list|(
name|__mmask16
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpgt_epi32_mask
comment|// CHECK: icmp sgt<16 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: and<16 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm512_mask_cmpgt_epi32_mask
argument_list|(
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_mask_cmpgt_epi64_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpgt_epi64_mask
comment|// CHECK: icmp sgt<8 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: and<8 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm512_mask_cmpgt_epi64_mask
argument_list|(
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_cmpgt_epi64_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpgt_epi64_mask
comment|// CHECK: icmp sgt<8 x i64> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm512_cmpgt_epi64_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_unpackhi_pd
parameter_list|(
name|__m512d
name|a
parameter_list|,
name|__m512d
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_unpackhi_pd
comment|// CHECK: shufflevector<8 x double> {{.*}}<i32 1, i32 9, i32 3, i32 11, i32 5, i32 13, i32 7, i32 15>
return|return
name|_mm512_unpackhi_pd
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_unpacklo_pd
parameter_list|(
name|__m512d
name|a
parameter_list|,
name|__m512d
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_unpacklo_pd
comment|// CHECK: shufflevector<8 x double> {{.*}}<i32 0, i32 8, i32 2, i32 10, i32 4, i32 12, i32 6, i32 14>
return|return
name|_mm512_unpacklo_pd
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_unpackhi_ps
parameter_list|(
name|__m512
name|a
parameter_list|,
name|__m512
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_unpackhi_ps
comment|// CHECK: shufflevector<16 x float> {{.*}}<i32 2, i32 18, i32 3, i32 19, i32 6, i32 22, i32 7, i32 23, i32 10, i32 26, i32 11, i32 27, i32 14, i32 30, i32 15, i32 31>
return|return
name|_mm512_unpackhi_ps
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_unpacklo_ps
parameter_list|(
name|__m512
name|a
parameter_list|,
name|__m512
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_unpacklo_ps
comment|// CHECK: shufflevector<16 x float> {{.*}}<i32 0, i32 16, i32 1, i32 17, i32 4, i32 20, i32 5, i32 21, i32 8, i32 24, i32 9, i32 25, i32 12, i32 28, i32 13, i32 29>
return|return
name|_mm512_unpacklo_ps
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm512_cmp_round_ps_mask
parameter_list|(
name|__m512
name|a
parameter_list|,
name|__m512
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmp_round_ps_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.ps.512
return|return
name|_mm512_cmp_round_ps_mask
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm512_mask_cmp_round_ps_mask
parameter_list|(
name|__mmask16
name|m
parameter_list|,
name|__m512
name|a
parameter_list|,
name|__m512
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmp_round_ps_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.ps.512
return|return
name|_mm512_mask_cmp_round_ps_mask
argument_list|(
name|m
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm512_cmp_ps_mask
parameter_list|(
name|__m512
name|a
parameter_list|,
name|__m512
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmp_ps_mask
comment|// CHECKn: @llvm.x86.avx512.mask.cmp.ps.512
return|return
name|_mm512_cmp_ps_mask
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm512_mask_cmp_ps_mask
parameter_list|(
name|__mmask16
name|m
parameter_list|,
name|__m512
name|a
parameter_list|,
name|__m512
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmp_ps_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.ps.512
return|return
name|_mm512_mask_cmp_ps_mask
argument_list|(
name|m
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_cmp_round_pd_mask
parameter_list|(
name|__m512d
name|a
parameter_list|,
name|__m512d
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmp_round_pd_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.pd.512
return|return
name|_mm512_cmp_round_pd_mask
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_mask_cmp_round_pd_mask
parameter_list|(
name|__mmask8
name|m
parameter_list|,
name|__m512d
name|a
parameter_list|,
name|__m512d
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmp_round_pd_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.pd.512
return|return
name|_mm512_mask_cmp_round_pd_mask
argument_list|(
name|m
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_cmp_pd_mask
parameter_list|(
name|__m512d
name|a
parameter_list|,
name|__m512d
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmp_pd_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.pd.512
return|return
name|_mm512_cmp_pd_mask
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_mask_cmp_pd_mask
parameter_list|(
name|__mmask8
name|m
parameter_list|,
name|__m512d
name|a
parameter_list|,
name|__m512d
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmp_pd_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.pd.512
return|return
name|_mm512_mask_cmp_pd_mask
argument_list|(
name|m
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_cmpeq_pd_mask
parameter_list|(
name|__m512d
name|a
parameter_list|,
name|__m512d
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpeq_pd_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.pd.512
return|return
name|_mm512_cmpeq_pd_mask
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_cmpeq_ps_mask
parameter_list|(
name|__m512
name|a
parameter_list|,
name|__m512
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpeq_ps_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.ps.512
return|return
name|_mm512_cmpeq_ps_mask
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_mask_cmpeq_pd_mask
parameter_list|(
name|__mmask8
name|k
parameter_list|,
name|__m512d
name|a
parameter_list|,
name|__m512d
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpeq_pd_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.pd.512
return|return
name|_mm512_mask_cmpeq_pd_mask
argument_list|(
name|k
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_mask_cmpeq_ps_mask
parameter_list|(
name|__mmask8
name|k
parameter_list|,
name|__m512
name|a
parameter_list|,
name|__m512
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpeq_ps_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.ps.512
return|return
name|_mm512_mask_cmpeq_ps_mask
argument_list|(
name|k
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_cmple_pd_mask
parameter_list|(
name|__m512d
name|a
parameter_list|,
name|__m512d
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmple_pd_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.pd.512
return|return
name|_mm512_cmpeq_pd_mask
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_cmple_ps_mask
parameter_list|(
name|__m512
name|a
parameter_list|,
name|__m512
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmple_ps_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.ps.512
return|return
name|_mm512_cmpeq_ps_mask
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_mask_cmple_pd_mask
parameter_list|(
name|__mmask8
name|k
parameter_list|,
name|__m512d
name|a
parameter_list|,
name|__m512d
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmple_pd_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.pd.512
return|return
name|_mm512_mask_cmple_pd_mask
argument_list|(
name|k
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_mask_cmple_ps_mask
parameter_list|(
name|__mmask8
name|k
parameter_list|,
name|__m512
name|a
parameter_list|,
name|__m512
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmple_ps_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.ps.512
return|return
name|_mm512_mask_cmple_ps_mask
argument_list|(
name|k
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_cmplt_pd_mask
parameter_list|(
name|__m512d
name|a
parameter_list|,
name|__m512d
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmplt_pd_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.pd.512
return|return
name|_mm512_cmplt_pd_mask
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_cmplt_ps_mask
parameter_list|(
name|__m512
name|a
parameter_list|,
name|__m512
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmplt_ps_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.ps.512
return|return
name|_mm512_cmplt_ps_mask
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_mask_cmplt_pd_mask
parameter_list|(
name|__mmask8
name|k
parameter_list|,
name|__m512d
name|a
parameter_list|,
name|__m512d
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmplt_pd_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.pd.512
return|return
name|_mm512_mask_cmplt_pd_mask
argument_list|(
name|k
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_mask_cmplt_ps_mask
parameter_list|(
name|__mmask8
name|k
parameter_list|,
name|__m512
name|a
parameter_list|,
name|__m512
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmplt_ps_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.ps.512
return|return
name|_mm512_mask_cmplt_ps_mask
argument_list|(
name|k
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_cmpneq_pd_mask
parameter_list|(
name|__m512d
name|a
parameter_list|,
name|__m512d
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpneq_pd_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.pd.512
return|return
name|_mm512_cmpneq_pd_mask
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_cmpneq_ps_mask
parameter_list|(
name|__m512
name|a
parameter_list|,
name|__m512
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpneq_ps_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.ps.512
return|return
name|_mm512_cmpneq_ps_mask
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_mask_cmpneq_pd_mask
parameter_list|(
name|__mmask8
name|k
parameter_list|,
name|__m512d
name|a
parameter_list|,
name|__m512d
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpneq_pd_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.pd.512
return|return
name|_mm512_mask_cmpneq_pd_mask
argument_list|(
name|k
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_mask_cmpneq_ps_mask
parameter_list|(
name|__mmask8
name|k
parameter_list|,
name|__m512
name|a
parameter_list|,
name|__m512
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpneq_ps_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.ps.512
return|return
name|_mm512_mask_cmpneq_ps_mask
argument_list|(
name|k
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_cmpnle_pd_mask
parameter_list|(
name|__m512d
name|a
parameter_list|,
name|__m512d
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpnle_pd_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.pd.512
return|return
name|_mm512_cmpnle_pd_mask
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_cmpnle_ps_mask
parameter_list|(
name|__m512
name|a
parameter_list|,
name|__m512
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpnle_ps_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.ps.512
return|return
name|_mm512_cmpnle_ps_mask
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_mask_cmpnle_pd_mask
parameter_list|(
name|__mmask8
name|k
parameter_list|,
name|__m512d
name|a
parameter_list|,
name|__m512d
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpnle_pd_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.pd.512
return|return
name|_mm512_mask_cmpnle_pd_mask
argument_list|(
name|k
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_mask_cmpnle_ps_mask
parameter_list|(
name|__mmask8
name|k
parameter_list|,
name|__m512
name|a
parameter_list|,
name|__m512
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpnle_ps_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.ps.512
return|return
name|_mm512_mask_cmpnle_ps_mask
argument_list|(
name|k
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_cmpnlt_pd_mask
parameter_list|(
name|__m512d
name|a
parameter_list|,
name|__m512d
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpnlt_pd_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.pd.512
return|return
name|_mm512_cmpnlt_pd_mask
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_cmpnlt_ps_mask
parameter_list|(
name|__m512
name|a
parameter_list|,
name|__m512
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpnlt_ps_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.ps.512
return|return
name|_mm512_cmpnlt_ps_mask
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_mask_cmpnlt_pd_mask
parameter_list|(
name|__mmask8
name|k
parameter_list|,
name|__m512d
name|a
parameter_list|,
name|__m512d
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpnlt_pd_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.pd.512
return|return
name|_mm512_mask_cmpnlt_pd_mask
argument_list|(
name|k
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_mask_cmpnlt_ps_mask
parameter_list|(
name|__mmask8
name|k
parameter_list|,
name|__m512
name|a
parameter_list|,
name|__m512
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpnlt_ps_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.ps.512
return|return
name|_mm512_mask_cmpnlt_ps_mask
argument_list|(
name|k
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_cmpord_pd_mask
parameter_list|(
name|__m512d
name|a
parameter_list|,
name|__m512d
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpord_pd_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.pd.512
return|return
name|_mm512_cmpord_pd_mask
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_cmpord_ps_mask
parameter_list|(
name|__m512
name|a
parameter_list|,
name|__m512
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpord_ps_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.ps.512
return|return
name|_mm512_cmpord_ps_mask
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_mask_cmpord_pd_mask
parameter_list|(
name|__mmask8
name|k
parameter_list|,
name|__m512d
name|a
parameter_list|,
name|__m512d
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpord_pd_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.pd.512
return|return
name|_mm512_mask_cmpord_pd_mask
argument_list|(
name|k
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_mask_cmpord_ps_mask
parameter_list|(
name|__mmask8
name|k
parameter_list|,
name|__m512
name|a
parameter_list|,
name|__m512
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpord_ps_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.ps.512
return|return
name|_mm512_mask_cmpord_ps_mask
argument_list|(
name|k
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_cmpunord_pd_mask
parameter_list|(
name|__m512d
name|a
parameter_list|,
name|__m512d
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpunord_pd_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.pd.512
return|return
name|_mm512_cmpunord_pd_mask
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_cmpunord_ps_mask
parameter_list|(
name|__m512
name|a
parameter_list|,
name|__m512
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpunord_ps_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.ps.512
return|return
name|_mm512_cmpunord_ps_mask
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_mask_cmpunord_pd_mask
parameter_list|(
name|__mmask8
name|k
parameter_list|,
name|__m512d
name|a
parameter_list|,
name|__m512d
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpunord_pd_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.pd.512
return|return
name|_mm512_mask_cmpunord_pd_mask
argument_list|(
name|k
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_mask_cmpunord_ps_mask
parameter_list|(
name|__mmask8
name|k
parameter_list|,
name|__m512
name|a
parameter_list|,
name|__m512
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpunord_ps_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.ps.512
return|return
name|_mm512_mask_cmpunord_ps_mask
argument_list|(
name|k
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm512_extractf64x4_pd
parameter_list|(
name|__m512d
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_extractf64x4_pd
comment|// CHECK: shufflevector<8 x double> %{{.*}},<8 x double> zeroinitializer,<4 x i32><i32 4, i32 5, i32 6, i32 7>
return|return
name|_mm512_extractf64x4_pd
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm512_mask_extractf64x4_pd
parameter_list|(
name|__m256d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL:@test_mm512_mask_extractf64x4_pd
comment|// CHECK: shufflevector<8 x double> %{{.*}},<8 x double> zeroinitializer,<4 x i32><i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x double> %{{.*}},<4 x double> %{{.*}}
return|return
name|_mm512_mask_extractf64x4_pd
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
name|__m256d
name|test_mm512_maskz_extractf64x4_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL:@test_mm512_maskz_extractf64x4_pd
comment|// CHECK: shufflevector<8 x double> %{{.*}},<8 x double> zeroinitializer,<4 x i32><i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x double> %{{.*}},<4 x double> %{{.*}}
return|return
name|_mm512_maskz_extractf64x4_pd
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
name|__m128
name|test_mm512_extractf32x4_ps
parameter_list|(
name|__m512
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_extractf32x4_ps
comment|// CHECK: shufflevector<16 x float> %{{.*}},<16 x float> zeroinitializer,<4 x i32><i32 4, i32 5, i32 6, i32 7>
return|return
name|_mm512_extractf32x4_ps
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm512_mask_extractf32x4_ps
parameter_list|(
name|__m128
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL:@test_mm512_mask_extractf32x4_ps
comment|// CHECK: shufflevector<16 x float> %{{.*}},<16 x float> zeroinitializer,<4 x i32><i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x float> %{{.*}},<4 x float> %{{.*}}
return|return
name|_mm512_mask_extractf32x4_ps
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
name|__m128
name|test_mm512_maskz_extractf32x4_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL:@test_mm512_maskz_extractf32x4_ps
comment|// CHECK: shufflevector<16 x float> %{{.*}},<16 x float> zeroinitializer,<4 x i32><i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x float> %{{.*}},<4 x float> %{{.*}}
return|return
name|_mm512_maskz_extractf32x4_ps
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
name|__mmask16
name|test_mm512_cmpeq_epu32_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpeq_epu32_mask
comment|// CHECK: icmp eq<16 x i32> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm512_cmpeq_epu32_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm512_mask_cmpeq_epu32_mask
parameter_list|(
name|__mmask16
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpeq_epu32_mask
comment|// CHECK: icmp eq<16 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: and<16 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm512_mask_cmpeq_epu32_mask
argument_list|(
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_cmpeq_epu64_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpeq_epu64_mask
comment|// CHECK: icmp eq<8 x i64> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm512_cmpeq_epu64_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_mask_cmpeq_epu64_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpeq_epu64_mask
comment|// CHECK: icmp eq<8 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: and<8 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm512_mask_cmpeq_epu64_mask
argument_list|(
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm512_cmpge_epi32_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpge_epi32_mask
comment|// CHECK: icmp sge<16 x i32> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm512_cmpge_epi32_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm512_mask_cmpge_epi32_mask
parameter_list|(
name|__mmask16
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpge_epi32_mask
comment|// CHECK: icmp sge<16 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: and<16 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm512_mask_cmpge_epi32_mask
argument_list|(
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_cmpge_epi64_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpge_epi64_mask
comment|// CHECK: icmp sge<8 x i64> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm512_cmpge_epi64_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_mask_cmpge_epi64_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpge_epi64_mask
comment|// CHECK: icmp sge<8 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: and<8 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm512_mask_cmpge_epi64_mask
argument_list|(
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm512_cmpge_epu32_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpge_epu32_mask
comment|// CHECK: icmp uge<16 x i32> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm512_cmpge_epu32_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm512_mask_cmpge_epu32_mask
parameter_list|(
name|__mmask16
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpge_epu32_mask
comment|// CHECK: icmp uge<16 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: and<16 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm512_mask_cmpge_epu32_mask
argument_list|(
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_cmpge_epu64_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpge_epu64_mask
comment|// CHECK: icmp uge<8 x i64> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm512_cmpge_epu64_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_mask_cmpge_epu64_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpge_epu64_mask
comment|// CHECK: icmp uge<8 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: and<8 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm512_mask_cmpge_epu64_mask
argument_list|(
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm512_cmpgt_epu32_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpgt_epu32_mask
comment|// CHECK: icmp ugt<16 x i32> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm512_cmpgt_epu32_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm512_mask_cmpgt_epu32_mask
parameter_list|(
name|__mmask16
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpgt_epu32_mask
comment|// CHECK: icmp ugt<16 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: and<16 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm512_mask_cmpgt_epu32_mask
argument_list|(
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_cmpgt_epu64_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpgt_epu64_mask
comment|// CHECK: icmp ugt<8 x i64> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm512_cmpgt_epu64_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_mask_cmpgt_epu64_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpgt_epu64_mask
comment|// CHECK: icmp ugt<8 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: and<8 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm512_mask_cmpgt_epu64_mask
argument_list|(
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm512_cmple_epi32_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmple_epi32_mask
comment|// CHECK: icmp sle<16 x i32> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm512_cmple_epi32_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm512_mask_cmple_epi32_mask
parameter_list|(
name|__mmask16
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmple_epi32_mask
comment|// CHECK: icmp sle<16 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: and<16 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm512_mask_cmple_epi32_mask
argument_list|(
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_cmple_epi64_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmple_epi64_mask
comment|// CHECK: icmp sle<8 x i64> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm512_cmple_epi64_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_mask_cmple_epi64_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmple_epi64_mask
comment|// CHECK: icmp sle<8 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: and<8 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm512_mask_cmple_epi64_mask
argument_list|(
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm512_cmple_epu32_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmple_epu32_mask
comment|// CHECK: icmp ule<16 x i32> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm512_cmple_epu32_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm512_mask_cmple_epu32_mask
parameter_list|(
name|__mmask16
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmple_epu32_mask
comment|// CHECK: icmp ule<16 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: and<16 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm512_mask_cmple_epu32_mask
argument_list|(
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_cmple_epu64_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmple_epu64_mask
comment|// CHECK: icmp ule<8 x i64> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm512_cmple_epu64_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_mask_cmple_epu64_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmple_epu64_mask
comment|// CHECK: icmp ule<8 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: and<8 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm512_mask_cmple_epu64_mask
argument_list|(
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm512_cmplt_epi32_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmplt_epi32_mask
comment|// CHECK: icmp slt<16 x i32> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm512_cmplt_epi32_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm512_mask_cmplt_epi32_mask
parameter_list|(
name|__mmask16
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmplt_epi32_mask
comment|// CHECK: icmp slt<16 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: and<16 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm512_mask_cmplt_epi32_mask
argument_list|(
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_cmplt_epi64_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmplt_epi64_mask
comment|// CHECK: icmp slt<8 x i64> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm512_cmplt_epi64_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_mask_cmplt_epi64_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmplt_epi64_mask
comment|// CHECK: icmp slt<8 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: and<8 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm512_mask_cmplt_epi64_mask
argument_list|(
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm512_cmplt_epu32_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmplt_epu32_mask
comment|// CHECK: icmp ult<16 x i32> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm512_cmplt_epu32_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm512_mask_cmplt_epu32_mask
parameter_list|(
name|__mmask16
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmplt_epu32_mask
comment|// CHECK: icmp ult<16 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: and<16 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm512_mask_cmplt_epu32_mask
argument_list|(
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_cmplt_epu64_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmplt_epu64_mask
comment|// CHECK: icmp ult<8 x i64> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm512_cmplt_epu64_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_mask_cmplt_epu64_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmplt_epu64_mask
comment|// CHECK: icmp ult<8 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: and<8 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm512_mask_cmplt_epu64_mask
argument_list|(
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm512_cmpneq_epi32_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpneq_epi32_mask
comment|// CHECK: icmp ne<16 x i32> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm512_cmpneq_epi32_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm512_mask_cmpneq_epi32_mask
parameter_list|(
name|__mmask16
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpneq_epi32_mask
comment|// CHECK: icmp ne<16 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: and<16 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm512_mask_cmpneq_epi32_mask
argument_list|(
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_cmpneq_epi64_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpneq_epi64_mask
comment|// CHECK: icmp ne<8 x i64> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm512_cmpneq_epi64_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_mask_cmpneq_epi64_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpneq_epi64_mask
comment|// CHECK: icmp ne<8 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: and<8 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm512_mask_cmpneq_epi64_mask
argument_list|(
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm512_cmpneq_epu32_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpneq_epu32_mask
comment|// CHECK: icmp ne<16 x i32> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm512_cmpneq_epu32_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm512_mask_cmpneq_epu32_mask
parameter_list|(
name|__mmask16
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpneq_epu32_mask
comment|// CHECK: icmp ne<16 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: and<16 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm512_mask_cmpneq_epu32_mask
argument_list|(
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_cmpneq_epu64_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpneq_epu64_mask
comment|// CHECK: icmp ne<8 x i64> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm512_cmpneq_epu64_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_mask_cmpneq_epu64_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpneq_epu64_mask
comment|// CHECK: icmp ne<8 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: and<8 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm512_mask_cmpneq_epu64_mask
argument_list|(
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm512_cmp_eq_epi32_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmp_eq_epi32_mask
comment|// CHECK: icmp eq<16 x i32> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm512_cmp_epi32_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|,
name|_MM_CMPINT_EQ
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm512_mask_cmp_eq_epi32_mask
parameter_list|(
name|__mmask16
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmp_eq_epi32_mask
comment|// CHECK: icmp eq<16 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: and<16 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm512_mask_cmp_epi32_mask
argument_list|(
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|,
name|_MM_CMPINT_EQ
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_cmp_eq_epi64_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmp_eq_epi64_mask
comment|// CHECK: icmp eq<8 x i64> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm512_cmp_epi64_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|,
name|_MM_CMPINT_EQ
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_mask_cmp_eq_epi64_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmp_eq_epi64_mask
comment|// CHECK: icmp eq<8 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: and<8 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm512_mask_cmp_epi64_mask
argument_list|(
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|,
name|_MM_CMPINT_EQ
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm512_cmp_epu32_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmp_epu32_mask
comment|// CHECK: icmp eq<16 x i32> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm512_cmp_epu32_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm512_mask_cmp_epu32_mask
parameter_list|(
name|__mmask16
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmp_epu32_mask
comment|// CHECK: icmp eq<16 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: and<16 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm512_mask_cmp_epu32_mask
argument_list|(
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_cmp_epu64_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmp_epu64_mask
comment|// CHECK: icmp eq<8 x i64> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm512_cmp_epu64_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_mask_cmp_epu64_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmp_epu64_mask
comment|// CHECK: icmp eq<8 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: and<8 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm512_mask_cmp_epu64_mask
argument_list|(
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_and_epi32
parameter_list|(
name|__m512i
name|__src
parameter_list|,
name|__mmask16
name|__k
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_and_epi32
comment|// CHECK: and<16 x i32>
comment|// CHECK: %[[MASK:.*]] = bitcast i16 %{{.*}} to<16 x i1>
comment|// CHECK: select<16 x i1> %[[MASK]],<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_mask_and_epi32
argument_list|(
name|__src
argument_list|,
name|__k
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_and_epi32
parameter_list|(
name|__mmask16
name|__k
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_and_epi32
comment|// CHECK: and<16 x i32>
comment|// CHECK: %[[MASK:.*]] = bitcast i16 %{{.*}} to<16 x i1>
comment|// CHECK: select<16 x i1> %[[MASK]],<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_maskz_and_epi32
argument_list|(
name|__k
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_and_epi64
parameter_list|(
name|__m512i
name|__src
parameter_list|,
name|__mmask8
name|__k
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_and_epi64
comment|// CHECK: %[[AND_RES:.*]] = and<8 x i64>
comment|// CHECK: %[[MASK:.*]] = bitcast i8 %{{.*}} to<8 x i1>
comment|// CHECK: select<8 x i1> %[[MASK]],<8 x i64> %[[AND_RES]],<8 x i64> %{{.*}}
return|return
name|_mm512_mask_and_epi64
argument_list|(
name|__src
argument_list|,
name|__k
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_and_epi64
parameter_list|(
name|__mmask8
name|__k
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_and_epi64
comment|// CHECK: %[[AND_RES:.*]] = and<8 x i64>
comment|// CHECK: %[[MASK:.*]] = bitcast i8 %{{.*}} to<8 x i1>
comment|// CHECK: select<8 x i1> %[[MASK]],<8 x i64> %[[AND_RES]],<8 x i64> %{{.*}}
return|return
name|_mm512_maskz_and_epi64
argument_list|(
name|__k
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_or_epi32
parameter_list|(
name|__m512i
name|__src
parameter_list|,
name|__mmask16
name|__k
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_or_epi32
comment|// CHECK: or<16 x i32>
comment|// CHECK: %[[MASK:.*]] = bitcast i16 %{{.*}} to<16 x i1>
comment|// CHECK: select<16 x i1> %[[MASK]],<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_mask_or_epi32
argument_list|(
name|__src
argument_list|,
name|__k
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_or_epi32
parameter_list|(
name|__mmask16
name|__k
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_or_epi32
comment|// CHECK: or<16 x i32>
comment|// CHECK: %[[MASK:.*]] = bitcast i16 %{{.*}} to<16 x i1>
comment|// CHECK: select<16 x i1> %[[MASK]],<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_maskz_or_epi32
argument_list|(
name|__k
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_or_epi64
parameter_list|(
name|__m512i
name|__src
parameter_list|,
name|__mmask8
name|__k
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_or_epi64
comment|// CHECK: %[[OR_RES:.*]] = or<8 x i64>
comment|// CHECK: %[[MASK:.*]] = bitcast i8 %{{.*}} to<8 x i1>
comment|// CHECK: select<8 x i1> %[[MASK]],<8 x i64> %[[OR_RES]],<8 x i64> %{{.*}}
return|return
name|_mm512_mask_or_epi64
argument_list|(
name|__src
argument_list|,
name|__k
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_or_epi64
parameter_list|(
name|__mmask8
name|__k
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_or_epi64
comment|// CHECK: %[[OR_RES:.*]] = or<8 x i64>
comment|// CHECK: %[[MASK:.*]] = bitcast i8 %{{.*}} to<8 x i1>
comment|// CHECK: select<8 x i1> %[[MASK]],<8 x i64> %[[OR_RES]],<8 x i64> %{{.*}}
return|return
name|_mm512_maskz_or_epi64
argument_list|(
name|__k
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_xor_epi32
parameter_list|(
name|__m512i
name|__src
parameter_list|,
name|__mmask16
name|__k
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_xor_epi32
comment|// CHECK: xor<16 x i32>
comment|// CHECK: %[[MASK:.*]] = bitcast i16 %{{.*}} to<16 x i1>
comment|// CHECK: select<16 x i1> %[[MASK]],<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_mask_xor_epi32
argument_list|(
name|__src
argument_list|,
name|__k
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_xor_epi32
parameter_list|(
name|__mmask16
name|__k
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_xor_epi32
comment|// CHECK: xor<16 x i32>
comment|// CHECK: %[[MASK:.*]] = bitcast i16 %{{.*}} to<16 x i1>
comment|// CHECK: select<16 x i1> %[[MASK]],<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_maskz_xor_epi32
argument_list|(
name|__k
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_xor_epi64
parameter_list|(
name|__m512i
name|__src
parameter_list|,
name|__mmask8
name|__k
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_xor_epi64
comment|// CHECK: %[[XOR_RES:.*]] = xor<8 x i64>
comment|// CHECK: %[[MASK:.*]] = bitcast i8 %{{.*}} to<8 x i1>
comment|// CHECK: select<8 x i1> %[[MASK]],<8 x i64> %[[XOR_RES]],<8 x i64> %{{.*}}
return|return
name|_mm512_mask_xor_epi64
argument_list|(
name|__src
argument_list|,
name|__k
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_xor_epi64
parameter_list|(
name|__mmask8
name|__k
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_xor_epi64
comment|// CHECK: %[[XOR_RES:.*]] = xor<8 x i64>
comment|// CHECK: %[[MASK:.*]] = bitcast i8 %{{.*}} to<8 x i1>
comment|// CHECK: select<8 x i1> %[[MASK]],<8 x i64> %[[XOR_RES]],<8 x i64> %{{.*}}
return|return
name|_mm512_maskz_xor_epi64
argument_list|(
name|__k
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_and_epi32
parameter_list|(
name|__m512i
name|__src
parameter_list|,
name|__mmask16
name|__k
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_and_epi32
comment|// CHECK: and<16 x i32>
return|return
name|_mm512_and_epi32
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_and_epi64
parameter_list|(
name|__m512i
name|__src
parameter_list|,
name|__mmask8
name|__k
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_and_epi64
comment|// CHECK: and<8 x i64>
return|return
name|_mm512_and_epi64
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_or_epi32
parameter_list|(
name|__m512i
name|__src
parameter_list|,
name|__mmask16
name|__k
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_or_epi32
comment|// CHECK: or<16 x i32>
return|return
name|_mm512_or_epi32
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_or_epi64
parameter_list|(
name|__m512i
name|__src
parameter_list|,
name|__mmask8
name|__k
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_or_epi64
comment|// CHECK: or<8 x i64>
return|return
name|_mm512_or_epi64
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_xor_epi32
parameter_list|(
name|__m512i
name|__src
parameter_list|,
name|__mmask16
name|__k
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_xor_epi32
comment|// CHECK: xor<16 x i32>
return|return
name|_mm512_xor_epi32
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_xor_epi64
parameter_list|(
name|__m512i
name|__src
parameter_list|,
name|__mmask8
name|__k
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_xor_epi64
comment|// CHECK: xor<8 x i64>
return|return
name|_mm512_xor_epi64
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_andnot_epi32
parameter_list|(
name|__mmask16
name|__k
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_andnot_epi32
comment|// CHECK: xor<16 x i32> %{{.*}},<i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1>
comment|// CHECK: and<16 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_maskz_andnot_epi32
argument_list|(
name|__k
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
name|test_mm512_mask_andnot_epi32
parameter_list|(
name|__mmask16
name|__k
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|,
name|__m512i
name|__src
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_andnot_epi32
comment|// CHECK: xor<16 x i32> %{{.*}},<i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1>
comment|// CHECK: and<16 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_mask_andnot_epi32
argument_list|(
name|__src
argument_list|,
name|__k
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
name|test_mm512_andnot_si512
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_andnot_si512
comment|//CHECK: load {{.*}}%__A.addr.i, align 64
comment|//CHECK: %neg.i = xor{{.*}},<i64 -1, i64 -1, i64 -1, i64 -1, i64 -1, i64 -1, i64 -1, i64 -1>
comment|//CHECK: load {{.*}}%__B.addr.i, align 64
comment|//CHECK: and<8 x i64> %neg.i,{{.*}}
return|return
name|_mm512_andnot_si512
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_andnot_epi32
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_andnot_epi32
comment|// CHECK: xor<16 x i32> %{{.*}},<i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1>
comment|// CHECK: and<16 x i32> %{{.*}}, %{{.*}}
return|return
name|_mm512_andnot_epi32
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_andnot_epi64
parameter_list|(
name|__mmask8
name|__k
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_andnot_epi64
comment|// CHECK: xor<8 x i64> %{{.*}},<i64 -1, i64 -1, i64 -1, i64 -1, i64 -1, i64 -1, i64 -1, i64 -1>
comment|// CHECK: and<8 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_maskz_andnot_epi64
argument_list|(
name|__k
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
name|test_mm512_mask_andnot_epi64
parameter_list|(
name|__mmask8
name|__k
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|,
name|__m512i
name|__src
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_mask_andnot_epi64
comment|// CHECK: xor<8 x i64> %{{.*}},<i64 -1, i64 -1, i64 -1, i64 -1, i64 -1, i64 -1, i64 -1, i64 -1>
comment|// CHECK: and<8 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_mask_andnot_epi64
argument_list|(
name|__src
argument_list|,
name|__k
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
name|test_mm512_andnot_epi64
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_andnot_epi64
comment|// CHECK: xor<8 x i64> %{{.*}},<i64 -1, i64 -1, i64 -1, i64 -1, i64 -1, i64 -1, i64 -1, i64 -1>
comment|// CHECK: and<8 x i64> %{{.*}}, %{{.*}}
return|return
name|_mm512_andnot_epi64
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_sub_epi32
parameter_list|(
name|__mmask16
name|__k
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_maskz_sub_epi32
comment|//CHECK: sub<16 x i32> %{{.*}}, %{{.*}}
comment|//CHECK: select<16 x i1> %{{.*}},<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_maskz_sub_epi32
argument_list|(
name|__k
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
name|test_mm512_mask_sub_epi32
parameter_list|(
name|__mmask16
name|__k
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|,
name|__m512i
name|__src
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_mask_sub_epi32
comment|//CHECK: sub<16 x i32> %{{.*}}, %{{.*}}
comment|//CHECK: select<16 x i1> %{{.*}},<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_mask_sub_epi32
argument_list|(
name|__src
argument_list|,
name|__k
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
name|test_mm512_sub_epi32
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_sub_epi32
comment|//CHECK: sub<16 x i32>
return|return
name|_mm512_sub_epi32
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_sub_epi64
parameter_list|(
name|__mmask8
name|__k
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_maskz_sub_epi64
comment|//CHECK: sub<8 x i64> %{{.*}}, %{{.*}}
comment|//CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_maskz_sub_epi64
argument_list|(
name|__k
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
name|test_mm512_mask_sub_epi64
parameter_list|(
name|__mmask8
name|__k
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|,
name|__m512i
name|__src
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_mask_sub_epi64
comment|//CHECK: sub<8 x i64> %{{.*}}, %{{.*}}
comment|//CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_mask_sub_epi64
argument_list|(
name|__src
argument_list|,
name|__k
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
name|test_mm512_sub_epi64
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_sub_epi64
comment|//CHECK: sub<8 x i64>
return|return
name|_mm512_sub_epi64
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_add_epi32
parameter_list|(
name|__mmask16
name|__k
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_maskz_add_epi32
comment|//CHECK: add<16 x i32> %{{.*}}, %{{.*}}
comment|//CHECK: select<16 x i1> %{{.*}},<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_maskz_add_epi32
argument_list|(
name|__k
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
name|test_mm512_mask_add_epi32
parameter_list|(
name|__mmask16
name|__k
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|,
name|__m512i
name|__src
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_mask_add_epi32
comment|//CHECK: add<16 x i32> %{{.*}}, %{{.*}}
comment|//CHECK: select<16 x i1> %{{.*}},<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_mask_add_epi32
argument_list|(
name|__src
argument_list|,
name|__k
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
name|test_mm512_add_epi32
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_add_epi32
comment|//CHECK: add<16 x i32>
return|return
name|_mm512_add_epi32
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_add_epi64
parameter_list|(
name|__mmask8
name|__k
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_maskz_add_epi64
comment|//CHECK: add<8 x i64> %{{.*}}, %{{.*}}
comment|//CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_maskz_add_epi64
argument_list|(
name|__k
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
name|test_mm512_mask_add_epi64
parameter_list|(
name|__mmask8
name|__k
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|,
name|__m512i
name|__src
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_mask_add_epi64
comment|//CHECK: add<8 x i64> %{{.*}}, %{{.*}}
comment|//CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_mask_add_epi64
argument_list|(
name|__src
argument_list|,
name|__k
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
name|test_mm512_add_epi64
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_add_epi64
comment|//CHECK: add<8 x i64>
return|return
name|_mm512_add_epi64
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mul_epi32
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_mul_epi32
comment|//CHECK: @llvm.x86.avx512.pmul.dq.512
return|return
name|_mm512_mul_epi32
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_mul_epi32
parameter_list|(
name|__mmask16
name|__k
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_maskz_mul_epi32
comment|//CHECK: @llvm.x86.avx512.pmul.dq.512
comment|//CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_maskz_mul_epi32
argument_list|(
name|__k
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
name|test_mm512_mask_mul_epi32
parameter_list|(
name|__mmask16
name|__k
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|,
name|__m512i
name|__src
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_mask_mul_epi32
comment|//CHECK: @llvm.x86.avx512.pmul.dq.512
comment|//CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_mask_mul_epi32
argument_list|(
name|__src
argument_list|,
name|__k
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
name|test_mm512_mul_epu32
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_mul_epu32
comment|//CHECK: @llvm.x86.avx512.pmulu.dq.512
return|return
name|_mm512_mul_epu32
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_mul_epu32
parameter_list|(
name|__mmask16
name|__k
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_maskz_mul_epu32
comment|//CHECK: @llvm.x86.avx512.pmulu.dq.512
comment|//CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_maskz_mul_epu32
argument_list|(
name|__k
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
name|test_mm512_mask_mul_epu32
parameter_list|(
name|__mmask16
name|__k
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|,
name|__m512i
name|__src
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_mask_mul_epu32
comment|//CHECK: @llvm.x86.avx512.pmulu.dq.512
comment|//CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_mask_mul_epu32
argument_list|(
name|__src
argument_list|,
name|__k
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
name|test_mm512_maskz_mullo_epi32
parameter_list|(
name|__mmask16
name|__k
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_maskz_mullo_epi32
comment|//CHECK: mul<16 x i32> %{{.*}}, %{{.*}}
comment|//CHECK: select<16 x i1> %{{.*}},<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_maskz_mullo_epi32
argument_list|(
name|__k
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
name|test_mm512_mask_mullo_epi32
parameter_list|(
name|__mmask16
name|__k
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|,
name|__m512i
name|__src
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_mask_mullo_epi32
comment|//CHECK: mul<16 x i32> %{{.*}}, %{{.*}}
comment|//CHECK: select<16 x i1> %{{.*}},<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_mask_mullo_epi32
argument_list|(
name|__src
argument_list|,
name|__k
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
name|test_mm512_mullo_epi32
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_mullo_epi32
comment|//CHECK: mul<16 x i32>
return|return
name|_mm512_mullo_epi32
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
name|test_mm512_add_round_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_add_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.add.pd.512
return|return
name|_mm512_add_round_pd
argument_list|(
name|__A
argument_list|,
name|__B
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
name|test_mm512_mask_add_round_pd
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
comment|// CHECK-LABEL: @test_mm512_mask_add_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.add.pd.512
return|return
name|_mm512_mask_add_round_pd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
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
name|test_mm512_maskz_add_round_pd
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
comment|// CHECK-LABEL: @test_mm512_maskz_add_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.add.pd.512
return|return
name|_mm512_maskz_add_round_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
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
name|test_mm512_mask_add_pd
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
comment|// CHECK-LABEL: @test_mm512_mask_add_pd
comment|// CHECK: fadd<8 x double> %{{.*}}, %{{.*}}
comment|// CHECK: select<8 x i1> %{{.*}},<8 x double> %{{.*}},<8 x double> %{{.*}}
return|return
name|_mm512_mask_add_pd
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
name|test_mm512_maskz_add_pd
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
comment|// CHECK-LABEL: @test_mm512_maskz_add_pd
comment|// CHECK: fadd<8 x double> %{{.*}}, %{{.*}}
comment|// CHECK: select<8 x i1> %{{.*}},<8 x double> %{{.*}},<8 x double> %{{.*}}
return|return
name|_mm512_maskz_add_pd
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
name|test_mm512_add_round_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_add_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.add.ps.512
return|return
name|_mm512_add_round_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_add_round_ps
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
comment|// CHECK-LABEL: @test_mm512_mask_add_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.add.ps.512
return|return
name|_mm512_mask_add_round_ps
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_maskz_add_round_ps
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
comment|// CHECK-LABEL: @test_mm512_maskz_add_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.add.ps.512
return|return
name|_mm512_maskz_add_round_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_add_ps
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
comment|// CHECK-LABEL: @test_mm512_mask_add_ps
comment|// CHECK: fadd<16 x float> %{{.*}}, %{{.*}}
comment|// CHECK: select<16 x i1> %{{.*}},<16 x float> %{{.*}},<16 x float> %{{.*}}
return|return
name|_mm512_mask_add_ps
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
name|test_mm512_maskz_add_ps
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
comment|// CHECK-LABEL: @test_mm512_maskz_add_ps
comment|// CHECK: fadd<16 x float> %{{.*}}, %{{.*}}
comment|// CHECK: select<16 x i1> %{{.*}},<16 x float> %{{.*}},<16 x float> %{{.*}}
return|return
name|_mm512_maskz_add_ps
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
name|__m128
name|test_mm_add_round_ss
parameter_list|(
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_add_round_ss
comment|// CHECK: @llvm.x86.avx512.mask.add.ss.round
return|return
name|_mm_add_round_ss
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_add_round_ss
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
comment|// CHECK-LABEL: @test_mm_mask_add_round_ss
comment|// CHECK: @llvm.x86.avx512.mask.add.ss.round
return|return
name|_mm_mask_add_round_ss
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_maskz_add_round_ss
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
comment|// CHECK-LABEL: @test_mm_maskz_add_round_ss
comment|// CHECK: @llvm.x86.avx512.mask.add.ss.round
return|return
name|_mm_maskz_add_round_ss
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_add_ss
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
comment|// CHECK-LABEL: @test_mm_mask_add_ss
comment|// CHECK: @llvm.x86.avx512.mask.add.ss.round
return|return
name|_mm_mask_add_ss
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
name|__m128
name|test_mm_maskz_add_ss
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
comment|// CHECK-LABEL: @test_mm_maskz_add_ss
comment|// CHECK: @llvm.x86.avx512.mask.add.ss.round
return|return
name|_mm_maskz_add_ss
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
name|__m128d
name|test_mm_add_round_sd
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_add_round_sd
comment|// CHECK: @llvm.x86.avx512.mask.add.sd.round
return|return
name|_mm_add_round_sd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_add_round_sd
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
comment|// CHECK-LABEL: @test_mm_mask_add_round_sd
comment|// CHECK: @llvm.x86.avx512.mask.add.sd.round
return|return
name|_mm_mask_add_round_sd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_maskz_add_round_sd
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
comment|// CHECK-LABEL: @test_mm_maskz_add_round_sd
comment|// CHECK: @llvm.x86.avx512.mask.add.sd.round
return|return
name|_mm_maskz_add_round_sd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_add_sd
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
comment|// CHECK-LABEL: @test_mm_mask_add_sd
comment|// CHECK: @llvm.x86.avx512.mask.add.sd.round
return|return
name|_mm_mask_add_sd
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
name|__m128d
name|test_mm_maskz_add_sd
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
comment|// CHECK-LABEL: @test_mm_maskz_add_sd
comment|// CHECK: @llvm.x86.avx512.mask.add.sd.round
return|return
name|_mm_maskz_add_sd
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
name|test_mm512_sub_round_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_sub_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.sub.pd.512
return|return
name|_mm512_sub_round_pd
argument_list|(
name|__A
argument_list|,
name|__B
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
name|test_mm512_mask_sub_round_pd
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
comment|// CHECK-LABEL: @test_mm512_mask_sub_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.sub.pd.512
return|return
name|_mm512_mask_sub_round_pd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
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
name|test_mm512_maskz_sub_round_pd
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
comment|// CHECK-LABEL: @test_mm512_maskz_sub_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.sub.pd.512
return|return
name|_mm512_maskz_sub_round_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
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
name|test_mm512_mask_sub_pd
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
comment|// CHECK-LABEL: @test_mm512_mask_sub_pd
comment|// CHECK: fsub<8 x double> %{{.*}}, %{{.*}}
comment|// CHECK: select<8 x i1> %{{.*}},<8 x double> %{{.*}},<8 x double> %{{.*}}
return|return
name|_mm512_mask_sub_pd
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
name|test_mm512_maskz_sub_pd
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
comment|// CHECK-LABEL: @test_mm512_maskz_sub_pd
comment|// CHECK: fsub<8 x double> %{{.*}}, %{{.*}}
comment|// CHECK: select<8 x i1> %{{.*}},<8 x double> %{{.*}},<8 x double> %{{.*}}
return|return
name|_mm512_maskz_sub_pd
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
name|test_mm512_sub_round_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_sub_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.sub.ps.512
return|return
name|_mm512_sub_round_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_sub_round_ps
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
comment|// CHECK-LABEL: @test_mm512_mask_sub_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.sub.ps.512
return|return
name|_mm512_mask_sub_round_ps
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_maskz_sub_round_ps
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
comment|// CHECK-LABEL: @test_mm512_maskz_sub_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.sub.ps.512
return|return
name|_mm512_maskz_sub_round_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_sub_ps
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
comment|// CHECK-LABEL: @test_mm512_mask_sub_ps
comment|// CHECK: fsub<16 x float> %{{.*}}, %{{.*}}
comment|// CHECK: select<16 x i1> %{{.*}},<16 x float> %{{.*}},<16 x float> %{{.*}}
return|return
name|_mm512_mask_sub_ps
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
name|test_mm512_maskz_sub_ps
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
comment|// CHECK-LABEL: @test_mm512_maskz_sub_ps
comment|// CHECK: fsub<16 x float> %{{.*}}, %{{.*}}
comment|// CHECK: select<16 x i1> %{{.*}},<16 x float> %{{.*}},<16 x float> %{{.*}}
return|return
name|_mm512_maskz_sub_ps
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
name|__m128
name|test_mm_sub_round_ss
parameter_list|(
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_sub_round_ss
comment|// CHECK: @llvm.x86.avx512.mask.sub.ss.round
return|return
name|_mm_sub_round_ss
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_sub_round_ss
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
comment|// CHECK-LABEL: @test_mm_mask_sub_round_ss
comment|// CHECK: @llvm.x86.avx512.mask.sub.ss.round
return|return
name|_mm_mask_sub_round_ss
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_maskz_sub_round_ss
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
comment|// CHECK-LABEL: @test_mm_maskz_sub_round_ss
comment|// CHECK: @llvm.x86.avx512.mask.sub.ss.round
return|return
name|_mm_maskz_sub_round_ss
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_sub_ss
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
comment|// CHECK-LABEL: @test_mm_mask_sub_ss
comment|// CHECK: @llvm.x86.avx512.mask.sub.ss.round
return|return
name|_mm_mask_sub_ss
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
name|__m128
name|test_mm_maskz_sub_ss
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
comment|// CHECK-LABEL: @test_mm_maskz_sub_ss
comment|// CHECK: @llvm.x86.avx512.mask.sub.ss.round
return|return
name|_mm_maskz_sub_ss
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
name|__m128d
name|test_mm_sub_round_sd
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_sub_round_sd
comment|// CHECK: @llvm.x86.avx512.mask.sub.sd.round
return|return
name|_mm_sub_round_sd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_sub_round_sd
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
comment|// CHECK-LABEL: @test_mm_mask_sub_round_sd
comment|// CHECK: @llvm.x86.avx512.mask.sub.sd.round
return|return
name|_mm_mask_sub_round_sd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_maskz_sub_round_sd
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
comment|// CHECK-LABEL: @test_mm_maskz_sub_round_sd
comment|// CHECK: @llvm.x86.avx512.mask.sub.sd.round
return|return
name|_mm_maskz_sub_round_sd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_sub_sd
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
comment|// CHECK-LABEL: @test_mm_mask_sub_sd
comment|// CHECK: @llvm.x86.avx512.mask.sub.sd.round
return|return
name|_mm_mask_sub_sd
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
name|__m128d
name|test_mm_maskz_sub_sd
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
comment|// CHECK-LABEL: @test_mm_maskz_sub_sd
comment|// CHECK: @llvm.x86.avx512.mask.sub.sd.round
return|return
name|_mm_maskz_sub_sd
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
name|test_mm512_mul_round_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mul_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.mul.pd.512
return|return
name|_mm512_mul_round_pd
argument_list|(
name|__A
argument_list|,
name|__B
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
name|test_mm512_mask_mul_round_pd
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
comment|// CHECK-LABEL: @test_mm512_mask_mul_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.mul.pd.512
return|return
name|_mm512_mask_mul_round_pd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
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
name|test_mm512_maskz_mul_round_pd
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
comment|// CHECK-LABEL: @test_mm512_maskz_mul_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.mul.pd.512
return|return
name|_mm512_maskz_mul_round_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
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
name|test_mm512_mask_mul_pd
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
comment|// CHECK-LABEL: @test_mm512_mask_mul_pd
comment|// CHECK: fmul<8 x double> %{{.*}}, %{{.*}}
comment|// CHECK: select<8 x i1> %{{.*}},<8 x double> %{{.*}},<8 x double> %{{.*}}
return|return
name|_mm512_mask_mul_pd
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
name|test_mm512_maskz_mul_pd
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
comment|// CHECK-LABEL: @test_mm512_maskz_mul_pd
comment|// CHECK: fmul<8 x double> %{{.*}}, %{{.*}}
comment|// CHECK: select<8 x i1> %{{.*}},<8 x double> %{{.*}},<8 x double> %{{.*}}
return|return
name|_mm512_maskz_mul_pd
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
name|test_mm512_mul_round_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mul_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.mul.ps.512
return|return
name|_mm512_mul_round_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_mul_round_ps
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
comment|// CHECK-LABEL: @test_mm512_mask_mul_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.mul.ps.512
return|return
name|_mm512_mask_mul_round_ps
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_maskz_mul_round_ps
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
comment|// CHECK-LABEL: @test_mm512_maskz_mul_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.mul.ps.512
return|return
name|_mm512_maskz_mul_round_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_mul_ps
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
comment|// CHECK-LABEL: @test_mm512_mask_mul_ps
comment|// CHECK: fmul<16 x float> %{{.*}}, %{{.*}}
comment|// CHECK: select<16 x i1> %{{.*}},<16 x float> %{{.*}},<16 x float> %{{.*}}
return|return
name|_mm512_mask_mul_ps
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
name|test_mm512_maskz_mul_ps
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
comment|// CHECK-LABEL: @test_mm512_maskz_mul_ps
comment|// CHECK: fmul<16 x float> %{{.*}}, %{{.*}}
comment|// CHECK: select<16 x i1> %{{.*}},<16 x float> %{{.*}},<16 x float> %{{.*}}
return|return
name|_mm512_maskz_mul_ps
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
name|__m128
name|test_mm_mul_round_ss
parameter_list|(
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mul_round_ss
comment|// CHECK: @llvm.x86.avx512.mask.mul.ss.round
return|return
name|_mm_mul_round_ss
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_mul_round_ss
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
comment|// CHECK-LABEL: @test_mm_mask_mul_round_ss
comment|// CHECK: @llvm.x86.avx512.mask.mul.ss.round
return|return
name|_mm_mask_mul_round_ss
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_maskz_mul_round_ss
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
comment|// CHECK-LABEL: @test_mm_maskz_mul_round_ss
comment|// CHECK: @llvm.x86.avx512.mask.mul.ss.round
return|return
name|_mm_maskz_mul_round_ss
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_mul_ss
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
comment|// CHECK-LABEL: @test_mm_mask_mul_ss
comment|// CHECK: @llvm.x86.avx512.mask.mul.ss.round
return|return
name|_mm_mask_mul_ss
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
name|__m128
name|test_mm_maskz_mul_ss
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
comment|// CHECK-LABEL: @test_mm_maskz_mul_ss
comment|// CHECK: @llvm.x86.avx512.mask.mul.ss.round
return|return
name|_mm_maskz_mul_ss
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
name|__m128d
name|test_mm_mul_round_sd
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mul_round_sd
comment|// CHECK: @llvm.x86.avx512.mask.mul.sd.round
return|return
name|_mm_mul_round_sd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_mul_round_sd
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
comment|// CHECK-LABEL: @test_mm_mask_mul_round_sd
comment|// CHECK: @llvm.x86.avx512.mask.mul.sd.round
return|return
name|_mm_mask_mul_round_sd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_maskz_mul_round_sd
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
comment|// CHECK-LABEL: @test_mm_maskz_mul_round_sd
comment|// CHECK: @llvm.x86.avx512.mask.mul.sd.round
return|return
name|_mm_maskz_mul_round_sd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_mul_sd
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
comment|// CHECK-LABEL: @test_mm_mask_mul_sd
comment|// CHECK: @llvm.x86.avx512.mask.mul.sd.round
return|return
name|_mm_mask_mul_sd
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
name|__m128d
name|test_mm_maskz_mul_sd
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
comment|// CHECK-LABEL: @test_mm_maskz_mul_sd
comment|// CHECK: @llvm.x86.avx512.mask.mul.sd.round
return|return
name|_mm_maskz_mul_sd
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
name|test_mm512_div_round_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_div_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.div.pd.512
return|return
name|_mm512_div_round_pd
argument_list|(
name|__A
argument_list|,
name|__B
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
name|test_mm512_mask_div_round_pd
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
comment|// CHECK-LABEL: @test_mm512_mask_div_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.div.pd.512
return|return
name|_mm512_mask_div_round_pd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
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
name|test_mm512_maskz_div_round_pd
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
comment|// CHECK-LABEL: @test_mm512_maskz_div_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.div.pd.512
return|return
name|_mm512_maskz_div_round_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
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
name|test_mm512_div_pd
parameter_list|(
name|__m512d
name|__a
parameter_list|,
name|__m512d
name|__b
parameter_list|)
block|{
comment|// CHECK-LABLE: @test_mm512_div_pd
comment|// CHECK: fdiv<8 x double>
return|return
name|_mm512_div_pd
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_div_pd
parameter_list|(
name|__m512d
name|__w
parameter_list|,
name|__mmask8
name|__u
parameter_list|,
name|__m512d
name|__a
parameter_list|,
name|__m512d
name|__b
parameter_list|)
block|{
comment|// CHECK-LABLE: @test_mm512_mask_div_pd
comment|// CHECK: fdiv<8 x double> %{{.*}}, %{{.*}}
comment|// CHECK: select<8 x i1> %{{.*}},<8 x double> %{{.*}},<8 x double> %{{.*}}
return|return
name|_mm512_mask_div_pd
argument_list|(
name|__w
argument_list|,
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_maskz_div_pd
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
comment|// CHECK-LABEL: @test_mm512_maskz_div_pd
comment|// CHECK: fdiv<8 x double> %{{.*}}, %{{.*}}
comment|// CHECK: select<8 x i1> %{{.*}},<8 x double> %{{.*}},<8 x double> %{{.*}}
return|return
name|_mm512_maskz_div_pd
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
name|test_mm512_div_round_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_div_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.div.ps.512
return|return
name|_mm512_div_round_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_div_round_ps
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
comment|// CHECK-LABEL: @test_mm512_mask_div_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.div.ps.512
return|return
name|_mm512_mask_div_round_ps
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_maskz_div_round_ps
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
comment|// CHECK-LABEL: @test_mm512_maskz_div_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.div.ps.512
return|return
name|_mm512_maskz_div_round_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_div_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_div_ps
comment|// CHECK: fdiv<16 x float>
return|return
name|_mm512_div_ps
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
name|test_mm512_mask_div_ps
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
comment|// CHECK-LABEL: @test_mm512_mask_div_ps
comment|// CHECK: fdiv<16 x float> %{{.*}}, %{{.*}}
comment|// CHECK: select<16 x i1> %{{.*}},<16 x float> %{{.*}},<16 x float> %{{.*}}
return|return
name|_mm512_mask_div_ps
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
name|test_mm512_maskz_div_ps
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
comment|// CHECK-LABEL: @test_mm512_maskz_div_ps
comment|// CHECK: fdiv<16 x float> %{{.*}}, %{{.*}}
comment|// CHECK: select<16 x i1> %{{.*}},<16 x float> %{{.*}},<16 x float> %{{.*}}
return|return
name|_mm512_maskz_div_ps
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
name|__m128
name|test_mm_div_round_ss
parameter_list|(
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_div_round_ss
comment|// CHECK: @llvm.x86.avx512.mask.div.ss.round
return|return
name|_mm_div_round_ss
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_div_round_ss
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
comment|// CHECK-LABEL: @test_mm_mask_div_round_ss
comment|// CHECK: @llvm.x86.avx512.mask.div.ss.round
return|return
name|_mm_mask_div_round_ss
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_maskz_div_round_ss
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
comment|// CHECK-LABEL: @test_mm_maskz_div_round_ss
comment|// CHECK: @llvm.x86.avx512.mask.div.ss.round
return|return
name|_mm_maskz_div_round_ss
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_div_ss
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
comment|// CHECK-LABEL: @test_mm_mask_div_ss
comment|// CHECK: @llvm.x86.avx512.mask.div.ss.round
return|return
name|_mm_mask_div_ss
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
name|__m128
name|test_mm_maskz_div_ss
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
comment|// CHECK-LABEL: @test_mm_maskz_div_ss
comment|// CHECK: @llvm.x86.avx512.mask.div.ss.round
return|return
name|_mm_maskz_div_ss
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
name|__m128d
name|test_mm_div_round_sd
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_div_round_sd
comment|// CHECK: @llvm.x86.avx512.mask.div.sd.round
return|return
name|_mm_div_round_sd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_div_round_sd
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
comment|// CHECK-LABEL: @test_mm_mask_div_round_sd
comment|// CHECK: @llvm.x86.avx512.mask.div.sd.round
return|return
name|_mm_mask_div_round_sd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_maskz_div_round_sd
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
comment|// CHECK-LABEL: @test_mm_maskz_div_round_sd
comment|// CHECK: @llvm.x86.avx512.mask.div.sd.round
return|return
name|_mm_maskz_div_round_sd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
operator||
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_div_sd
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
comment|// CHECK-LABEL: @test_mm_mask_div_sd
comment|// CHECK: @llvm.x86.avx512.mask.div.sd.round
return|return
name|_mm_mask_div_sd
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
name|__m128d
name|test_mm_maskz_div_sd
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
comment|// CHECK-LABEL: @test_mm_maskz_div_sd
comment|// CHECK: @llvm.x86.avx512.mask.div.sd.round
return|return
name|_mm_maskz_div_sd
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
name|__m128
name|test_mm_max_round_ss
parameter_list|(
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_max_round_ss
comment|// CHECK: @llvm.x86.avx512.mask.max.ss.round
return|return
name|_mm_max_round_ss
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
literal|0x08
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_max_round_ss
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
comment|// CHECK-LABEL: @test_mm_mask_max_round_ss
comment|// CHECK: @llvm.x86.avx512.mask.max.ss.round
return|return
name|_mm_mask_max_round_ss
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|0x08
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_maskz_max_round_ss
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
comment|// CHECK-LABEL: @test_mm_maskz_max_round_ss
comment|// CHECK: @llvm.x86.avx512.mask.max.ss.round
return|return
name|_mm_maskz_max_round_ss
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|0x08
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_max_ss
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
comment|// CHECK-LABEL: @test_mm_mask_max_ss
comment|// CHECK: @llvm.x86.avx512.mask.max.ss.round
return|return
name|_mm_mask_max_ss
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
name|__m128
name|test_mm_maskz_max_ss
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
comment|// CHECK-LABEL: @test_mm_maskz_max_ss
comment|// CHECK: @llvm.x86.avx512.mask.max.ss.round
return|return
name|_mm_maskz_max_ss
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
name|__m128d
name|test_mm_max_round_sd
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_max_round_sd
comment|// CHECK: @llvm.x86.avx512.mask.max.sd.round
return|return
name|_mm_max_round_sd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
literal|0x08
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_max_round_sd
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
comment|// CHECK-LABEL: @test_mm_mask_max_round_sd
comment|// CHECK: @llvm.x86.avx512.mask.max.sd.round
return|return
name|_mm_mask_max_round_sd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|0x08
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_maskz_max_round_sd
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
comment|// CHECK-LABEL: @test_mm_maskz_max_round_sd
comment|// CHECK: @llvm.x86.avx512.mask.max.sd.round
return|return
name|_mm_maskz_max_round_sd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|0x08
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_max_sd
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
comment|// CHECK-LABEL: @test_mm_mask_max_sd
comment|// CHECK: @llvm.x86.avx512.mask.max.sd.round
return|return
name|_mm_mask_max_sd
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
name|__m128d
name|test_mm_maskz_max_sd
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
comment|// CHECK-LABEL: @test_mm_maskz_max_sd
comment|// CHECK: @llvm.x86.avx512.mask.max.sd.round
return|return
name|_mm_maskz_max_sd
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
name|__m128
name|test_mm_min_round_ss
parameter_list|(
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_min_round_ss
comment|// CHECK: @llvm.x86.avx512.mask.min.ss.round
return|return
name|_mm_min_round_ss
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
literal|0x08
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_min_round_ss
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
comment|// CHECK-LABEL: @test_mm_mask_min_round_ss
comment|// CHECK: @llvm.x86.avx512.mask.min.ss.round
return|return
name|_mm_mask_min_round_ss
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|0x08
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_maskz_min_round_ss
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
comment|// CHECK-LABEL: @test_mm_maskz_min_round_ss
comment|// CHECK: @llvm.x86.avx512.mask.min.ss.round
return|return
name|_mm_maskz_min_round_ss
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|0x08
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_min_ss
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
comment|// CHECK-LABEL: @test_mm_mask_min_ss
comment|// CHECK: @llvm.x86.avx512.mask.min.ss.round
return|return
name|_mm_mask_min_ss
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
name|__m128
name|test_mm_maskz_min_ss
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
comment|// CHECK-LABEL: @test_mm_maskz_min_ss
comment|// CHECK: @llvm.x86.avx512.mask.min.ss.round
return|return
name|_mm_maskz_min_ss
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
name|__m128d
name|test_mm_min_round_sd
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_min_round_sd
comment|// CHECK: @llvm.x86.avx512.mask.min.sd.round
return|return
name|_mm_min_round_sd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
literal|0x08
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_min_round_sd
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
comment|// CHECK-LABEL: @test_mm_mask_min_round_sd
comment|// CHECK: @llvm.x86.avx512.mask.min.sd.round
return|return
name|_mm_mask_min_round_sd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|0x08
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_maskz_min_round_sd
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
comment|// CHECK-LABEL: @test_mm_maskz_min_round_sd
comment|// CHECK: @llvm.x86.avx512.mask.min.sd.round
return|return
name|_mm_maskz_min_round_sd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|0x08
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_min_sd
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
comment|// CHECK-LABEL: @test_mm_mask_min_sd
comment|// CHECK: @llvm.x86.avx512.mask.min.sd.round
return|return
name|_mm_mask_min_sd
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
name|__m128d
name|test_mm_maskz_min_sd
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
comment|// CHECK-LABEL: @test_mm_maskz_min_sd
comment|// CHECK: @llvm.x86.avx512.mask.min.sd.round
return|return
name|_mm_maskz_min_sd
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
name|test_mm512_undefined
parameter_list|()
block|{
comment|// CHECK-LABEL: @test_mm512_undefined
comment|// CHECK: ret<16 x float> zeroinitializer
return|return
name|_mm512_undefined
argument_list|()
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_undefined_ps
parameter_list|()
block|{
comment|// CHECK-LABEL: @test_mm512_undefined_ps
comment|// CHECK: ret<16 x float> zeroinitializer
return|return
name|_mm512_undefined_ps
argument_list|()
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_undefined_pd
parameter_list|()
block|{
comment|// CHECK-LABEL: @test_mm512_undefined_pd
comment|// CHECK: ret<8 x double> zeroinitializer
return|return
name|_mm512_undefined_pd
argument_list|()
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_undefined_epi32
parameter_list|()
block|{
comment|// CHECK-LABEL: @test_mm512_undefined_epi32
comment|// CHECK: ret<8 x i64> zeroinitializer
return|return
name|_mm512_undefined_epi32
argument_list|()
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_cvtepi8_epi32
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtepi8_epi32
comment|// CHECK: sext<16 x i8> %{{.*}} to<16 x i32>
return|return
name|_mm512_cvtepi8_epi32
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_cvtepi8_epi32
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtepi8_epi32
comment|// CHECK: sext<16 x i8> %{{.*}} to<16 x i32>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_mask_cvtepi8_epi32
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
name|test_mm512_maskz_cvtepi8_epi32
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtepi8_epi32
comment|// CHECK: sext<16 x i8> %{{.*}} to<16 x i32>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_maskz_cvtepi8_epi32
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
name|test_mm512_cvtepi8_epi64
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtepi8_epi64
comment|// CHECK: sext<8 x i8> %{{.*}} to<8 x i64>
return|return
name|_mm512_cvtepi8_epi64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_cvtepi8_epi64
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtepi8_epi64
comment|// CHECK: sext<8 x i8> %{{.*}} to<8 x i64>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_mask_cvtepi8_epi64
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
name|test_mm512_maskz_cvtepi8_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtepi8_epi64
comment|// CHECK: sext<8 x i8> %{{.*}} to<8 x i64>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_maskz_cvtepi8_epi64
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
name|test_mm512_cvtepi32_epi64
parameter_list|(
name|__m256i
name|__X
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtepi32_epi64
comment|// CHECK: sext<8 x i32> %{{.*}} to<8 x i64>
return|return
name|_mm512_cvtepi32_epi64
argument_list|(
name|__X
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_cvtepi32_epi64
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__X
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtepi32_epi64
comment|// CHECK: sext<8 x i32> %{{.*}} to<8 x i64>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_mask_cvtepi32_epi64
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__X
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_cvtepi32_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__X
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtepi32_epi64
comment|// CHECK: sext<8 x i32> %{{.*}} to<8 x i64>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_maskz_cvtepi32_epi64
argument_list|(
name|__U
argument_list|,
name|__X
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_cvtepi16_epi32
parameter_list|(
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtepi16_epi32
comment|// CHECK: sext<16 x i16> %{{.*}} to<16 x i32>
return|return
name|_mm512_cvtepi16_epi32
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_cvtepi16_epi32
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtepi16_epi32
comment|// CHECK: sext<16 x i16> %{{.*}} to<16 x i32>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_mask_cvtepi16_epi32
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
name|test_mm512_maskz_cvtepi16_epi32
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtepi16_epi32
comment|// CHECK: sext<16 x i16> %{{.*}} to<16 x i32>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_maskz_cvtepi16_epi32
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
name|test_mm512_cvtepi16_epi64
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtepi16_epi64
comment|// CHECK: sext<8 x i16> %{{.*}} to<8 x i64>
return|return
name|_mm512_cvtepi16_epi64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_cvtepi16_epi64
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtepi16_epi64
comment|// CHECK: sext<8 x i16> %{{.*}} to<8 x i64>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_mask_cvtepi16_epi64
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
name|test_mm512_maskz_cvtepi16_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtepi16_epi64
comment|// CHECK: sext<8 x i16> %{{.*}} to<8 x i64>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_maskz_cvtepi16_epi64
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
name|test_mm512_cvtepu8_epi32
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtepu8_epi32
comment|// CHECK: zext<16 x i8> %{{.*}} to<16 x i32>
return|return
name|_mm512_cvtepu8_epi32
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_cvtepu8_epi32
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtepu8_epi32
comment|// CHECK: zext<16 x i8> %{{.*}} to<16 x i32>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_mask_cvtepu8_epi32
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
name|test_mm512_maskz_cvtepu8_epi32
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtepu8_epi32
comment|// CHECK: zext<16 x i8> %{{.*}} to<16 x i32>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_maskz_cvtepu8_epi32
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
name|test_mm512_cvtepu8_epi64
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtepu8_epi64
comment|// CHECK: zext<8 x i8> %{{.*}} to<8 x i64>
return|return
name|_mm512_cvtepu8_epi64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_cvtepu8_epi64
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtepu8_epi64
comment|// CHECK: zext<8 x i8> %{{.*}} to<8 x i64>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_mask_cvtepu8_epi64
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
name|test_mm512_maskz_cvtepu8_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtepu8_epi64
comment|// CHECK: zext<8 x i8> %{{.*}} to<8 x i64>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_maskz_cvtepu8_epi64
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
name|test_mm512_cvtepu32_epi64
parameter_list|(
name|__m256i
name|__X
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtepu32_epi64
comment|// CHECK: zext<8 x i32> %{{.*}} to<8 x i64>
return|return
name|_mm512_cvtepu32_epi64
argument_list|(
name|__X
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_cvtepu32_epi64
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__X
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtepu32_epi64
comment|// CHECK: zext<8 x i32> %{{.*}} to<8 x i64>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_mask_cvtepu32_epi64
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__X
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_cvtepu32_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__X
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtepu32_epi64
comment|// CHECK: zext<8 x i32> %{{.*}} to<8 x i64>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_maskz_cvtepu32_epi64
argument_list|(
name|__U
argument_list|,
name|__X
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_cvtepu16_epi32
parameter_list|(
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtepu16_epi32
comment|// CHECK: zext<16 x i16> %{{.*}} to<16 x i32>
return|return
name|_mm512_cvtepu16_epi32
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_cvtepu16_epi32
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtepu16_epi32
comment|// CHECK: zext<16 x i16> %{{.*}} to<16 x i32>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_mask_cvtepu16_epi32
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
name|test_mm512_maskz_cvtepu16_epi32
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtepu16_epi32
comment|// CHECK: zext<16 x i16> %{{.*}} to<16 x i32>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_maskz_cvtepu16_epi32
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
name|test_mm512_cvtepu16_epi64
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtepu16_epi64
comment|// CHECK: zext<8 x i16> %{{.*}} to<8 x i64>
return|return
name|_mm512_cvtepu16_epi64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_cvtepu16_epi64
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtepu16_epi64
comment|// CHECK: zext<8 x i16> %{{.*}} to<8 x i64>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_mask_cvtepu16_epi64
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
name|test_mm512_maskz_cvtepu16_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtepu16_epi64
comment|// CHECK: zext<8 x i16> %{{.*}} to<8 x i64>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_maskz_cvtepu16_epi64
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
name|test_mm512_rol_epi32
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_rol_epi32
comment|// CHECK: @llvm.x86.avx512.mask.prol.d.512
return|return
name|_mm512_rol_epi32
argument_list|(
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_rol_epi32
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
comment|// CHECK-LABEL: @test_mm512_mask_rol_epi32
comment|// CHECK: @llvm.x86.avx512.mask.prol.d.512
return|return
name|_mm512_mask_rol_epi32
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_rol_epi32
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_rol_epi32
comment|// CHECK: @llvm.x86.avx512.mask.prol.d.512
return|return
name|_mm512_maskz_rol_epi32
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_rol_epi64
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_rol_epi64
comment|// CHECK: @llvm.x86.avx512.mask.prol.q.512
return|return
name|_mm512_rol_epi64
argument_list|(
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_rol_epi64
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
comment|// CHECK-LABEL: @test_mm512_mask_rol_epi64
comment|// CHECK: @llvm.x86.avx512.mask.prol.q.512
return|return
name|_mm512_mask_rol_epi64
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_rol_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_rol_epi64
comment|// CHECK: @llvm.x86.avx512.mask.prol.q.512
return|return
name|_mm512_maskz_rol_epi64
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_rolv_epi32
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_rolv_epi32
comment|// CHECK: @llvm.x86.avx512.mask.prolv.d.512
return|return
name|_mm512_rolv_epi32
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_rolv_epi32
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
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_rolv_epi32
comment|// CHECK: @llvm.x86.avx512.mask.prolv.d.512
return|return
name|_mm512_mask_rolv_epi32
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
name|test_mm512_maskz_rolv_epi32
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_rolv_epi32
comment|// CHECK: @llvm.x86.avx512.mask.prolv.d.512
return|return
name|_mm512_maskz_rolv_epi32
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
name|test_mm512_rolv_epi64
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_rolv_epi64
comment|// CHECK: @llvm.x86.avx512.mask.prolv.q.512
return|return
name|_mm512_rolv_epi64
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_rolv_epi64
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
comment|// CHECK-LABEL: @test_mm512_mask_rolv_epi64
comment|// CHECK: @llvm.x86.avx512.mask.prolv.q.512
return|return
name|_mm512_mask_rolv_epi64
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
name|test_mm512_maskz_rolv_epi64
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
comment|// CHECK-LABEL: @test_mm512_maskz_rolv_epi64
comment|// CHECK: @llvm.x86.avx512.mask.prolv.q.512
return|return
name|_mm512_maskz_rolv_epi64
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
name|test_mm512_ror_epi32
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_ror_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pror.d.512
return|return
name|_mm512_ror_epi32
argument_list|(
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_ror_epi32
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
comment|// CHECK-LABEL: @test_mm512_mask_ror_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pror.d.512
return|return
name|_mm512_mask_ror_epi32
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_ror_epi32
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_ror_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pror.d.512
return|return
name|_mm512_maskz_ror_epi32
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_ror_epi64
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_ror_epi64
comment|// CHECK: @llvm.x86.avx512.mask.pror.q.512
return|return
name|_mm512_ror_epi64
argument_list|(
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_ror_epi64
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
comment|// CHECK-LABEL: @test_mm512_mask_ror_epi64
comment|// CHECK: @llvm.x86.avx512.mask.pror.q.512
return|return
name|_mm512_mask_ror_epi64
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_ror_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_ror_epi64
comment|// CHECK: @llvm.x86.avx512.mask.pror.q.512
return|return
name|_mm512_maskz_ror_epi64
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_rorv_epi32
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_rorv_epi32
comment|// CHECK: @llvm.x86.avx512.mask.prorv.d.512
return|return
name|_mm512_rorv_epi32
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_rorv_epi32
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
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_rorv_epi32
comment|// CHECK: @llvm.x86.avx512.mask.prorv.d.512
return|return
name|_mm512_mask_rorv_epi32
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
name|test_mm512_maskz_rorv_epi32
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_rorv_epi32
comment|// CHECK: @llvm.x86.avx512.mask.prorv.d.512
return|return
name|_mm512_maskz_rorv_epi32
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
name|test_mm512_rorv_epi64
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_rorv_epi64
comment|// CHECK: @llvm.x86.avx512.mask.prorv.q.512
return|return
name|_mm512_rorv_epi64
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_rorv_epi64
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
comment|// CHECK-LABEL: @test_mm512_mask_rorv_epi64
comment|// CHECK: @llvm.x86.avx512.mask.prorv.q.512
return|return
name|_mm512_mask_rorv_epi64
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
name|test_mm512_maskz_rorv_epi64
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
comment|// CHECK-LABEL: @test_mm512_maskz_rorv_epi64
comment|// CHECK: @llvm.x86.avx512.mask.prorv.q.512
return|return
name|_mm512_maskz_rorv_epi64
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
name|test_mm512_slli_epi32
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_slli_epi32
comment|// CHECK: @llvm.x86.avx512.pslli.d.512
return|return
name|_mm512_slli_epi32
argument_list|(
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_slli_epi32
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
comment|// CHECK-LABEL: @test_mm512_mask_slli_epi32
comment|// CHECK: @llvm.x86.avx512.pslli.d.512
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_mask_slli_epi32
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_slli_epi32
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_slli_epi32
comment|// CHECK: @llvm.x86.avx512.pslli.d.512
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_maskz_slli_epi32
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_slli_epi64
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_slli_epi64
comment|// CHECK: @llvm.x86.avx512.pslli.q.512
return|return
name|_mm512_slli_epi64
argument_list|(
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_slli_epi64
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
comment|// CHECK-LABEL: @test_mm512_mask_slli_epi64
comment|// CHECK: @llvm.x86.avx512.pslli.q.512
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_mask_slli_epi64
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_slli_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_slli_epi64
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_maskz_slli_epi64
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_srli_epi32
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_srli_epi32
comment|// CHECK: @llvm.x86.avx512.psrli.d.512
return|return
name|_mm512_srli_epi32
argument_list|(
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_srli_epi32
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
comment|// CHECK-LABEL: @test_mm512_mask_srli_epi32
comment|// CHECK: @llvm.x86.avx512.psrli.d.512
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_mask_srli_epi32
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_srli_epi32
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_srli_epi32
comment|// CHECK: @llvm.x86.avx512.psrli.d.512
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_maskz_srli_epi32
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_srli_epi64
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_srli_epi64
comment|// CHECK: @llvm.x86.avx512.psrli.q.512
return|return
name|_mm512_srli_epi64
argument_list|(
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_srli_epi64
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
comment|// CHECK-LABEL: @test_mm512_mask_srli_epi64
comment|// CHECK: @llvm.x86.avx512.psrli.q.512
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_mask_srli_epi64
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_srli_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_srli_epi64
comment|// CHECK: @llvm.x86.avx512.psrli.q.512
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_maskz_srli_epi64
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_load_epi32
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|void
specifier|const
modifier|*
name|__P
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_load_epi32
comment|// CHECK: @llvm.masked.load.v16i32.p0v16i32(<16 x i32>* %{{.*}}, i32 64,<16 x i1> %{{.*}},<16 x i32> %{{.*}})
return|return
name|_mm512_mask_load_epi32
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__P
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_load_epi32
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|void
specifier|const
modifier|*
name|__P
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_load_epi32
comment|// CHECK: @llvm.masked.load.v16i32.p0v16i32(<16 x i32>* %{{.*}}, i32 64,<16 x i1> %{{.*}},<16 x i32> %{{.*}})
return|return
name|_mm512_maskz_load_epi32
argument_list|(
name|__U
argument_list|,
name|__P
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_mov_epi32
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
comment|// CHECK-LABEL: @test_mm512_mask_mov_epi32
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_mask_mov_epi32
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
name|test_mm512_maskz_mov_epi32
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_mov_epi32
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_maskz_mov_epi32
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
name|test_mm512_mask_mov_epi64
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
comment|// CHECK-LABEL: @test_mm512_mask_mov_epi64
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_mask_mov_epi64
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
name|test_mm512_maskz_mov_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_mov_epi64
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_maskz_mov_epi64
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
name|test_mm512_mask_load_epi64
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|void
specifier|const
modifier|*
name|__P
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_load_epi64
comment|// CHECK: @llvm.masked.load.v8i64.p0v8i64(<8 x i64>* %{{.*}}, i32 64,<8 x i1> %{{.*}},<8 x i64> %{{.*}})
return|return
name|_mm512_mask_load_epi64
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__P
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_load_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|void
specifier|const
modifier|*
name|__P
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_load_epi64
comment|// CHECK: @llvm.masked.load.v8i64.p0v8i64(<8 x i64>* %{{.*}}, i32 64,<8 x i1> %{{.*}},<8 x i64> %{{.*}})
return|return
name|_mm512_maskz_load_epi64
argument_list|(
name|__U
argument_list|,
name|__P
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm512_mask_store_epi32
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_store_epi32
comment|// CHECK: @llvm.masked.store.v16i32.p0v16i32(<16 x i32> %{{.*}},<16 x i32>* %{{.*}}, i32 64,<16 x i1> %{{.*}})
return|return
name|_mm512_mask_store_epi32
argument_list|(
name|__P
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm512_mask_store_epi64
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_store_epi64
comment|// CHECK: @llvm.masked.store.v8i64.p0v8i64(<8 x i64> %{{.*}},<8 x i64>* %{{.*}}, i32 64,<8 x i1> %{{.*}})
return|return
name|_mm512_mask_store_epi64
argument_list|(
name|__P
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
name|test_mm512_movedup_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_movedup_pd
comment|// CHECK: shufflevector<8 x double> %{{.*}},<8 x double> %{{.*}},<8 x i32><i32 0, i32 0, i32 2, i32 2, i32 4, i32 4, i32 6, i32 6>
return|return
name|_mm512_movedup_pd
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_movedup_pd
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
comment|// CHECK-LABEL: @test_mm512_mask_movedup_pd
comment|// CHECK: shufflevector<8 x double> %{{.*}},<8 x double> %{{.*}},<8 x i32><i32 0, i32 0, i32 2, i32 2, i32 4, i32 4, i32 6, i32 6>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x double> %{{.*}},<8 x double> %{{.*}}
return|return
name|_mm512_mask_movedup_pd
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
name|test_mm512_maskz_movedup_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_movedup_pd
comment|// CHECK: shufflevector<8 x double> %{{.*}},<8 x double> %{{.*}},<8 x i32><i32 0, i32 0, i32 2, i32 2, i32 4, i32 4, i32 6, i32 6>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x double> %{{.*}},<8 x double> %{{.*}}
return|return
name|_mm512_maskz_movedup_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm_comi_round_sd
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_comi_round_sd
comment|// CHECK: @llvm.x86.avx512.vcomi.sd
return|return
name|_mm_comi_round_sd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
literal|5
argument_list|,
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm_comi_round_ss
parameter_list|(
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_comi_round_ss
comment|// CHECK: @llvm.x86.avx512.vcomi.ss
return|return
name|_mm_comi_round_ss
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
literal|5
argument_list|,
name|_MM_FROUND_NO_EXC
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_fixupimm_round_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|,
name|__m512i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_fixupimm_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.fixupimm.pd.512
return|return
name|_mm512_fixupimm_round_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
literal|5
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_fixupimm_round_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__B
parameter_list|,
name|__m512i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_fixupimm_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.fixupimm.pd.512
return|return
name|_mm512_mask_fixupimm_round_pd
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
literal|5
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_fixupimm_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|,
name|__m512i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_fixupimm_pd
comment|// CHECK: @llvm.x86.avx512.mask.fixupimm.pd.512
return|return
name|_mm512_fixupimm_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_fixupimm_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__B
parameter_list|,
name|__m512i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_fixupimm_pd
comment|// CHECK: @llvm.x86.avx512.mask.fixupimm.pd.512
return|return
name|_mm512_mask_fixupimm_pd
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_maskz_fixupimm_round_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|,
name|__m512i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_fixupimm_round_pd
comment|// CHECK: @llvm.x86.avx512.maskz.fixupimm.pd.512
return|return
name|_mm512_maskz_fixupimm_round_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
literal|5
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_maskz_fixupimm_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|,
name|__m512i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_fixupimm_pd
comment|// CHECK: @llvm.x86.avx512.maskz.fixupimm.pd.512
return|return
name|_mm512_maskz_fixupimm_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_fixupimm_round_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|,
name|__m512i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_fixupimm_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.fixupimm.ps.512
return|return
name|_mm512_fixupimm_round_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
literal|5
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_fixupimm_round_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__B
parameter_list|,
name|__m512i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_fixupimm_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.fixupimm.ps.512
return|return
name|_mm512_mask_fixupimm_round_ps
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
literal|5
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_fixupimm_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|,
name|__m512i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_fixupimm_ps
comment|// CHECK: @llvm.x86.avx512.mask.fixupimm.ps.512
return|return
name|_mm512_fixupimm_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_fixupimm_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__B
parameter_list|,
name|__m512i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_fixupimm_ps
comment|// CHECK: @llvm.x86.avx512.mask.fixupimm.ps.512
return|return
name|_mm512_mask_fixupimm_ps
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_maskz_fixupimm_round_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|,
name|__m512i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_fixupimm_round_ps
comment|// CHECK: @llvm.x86.avx512.maskz.fixupimm.ps.512
return|return
name|_mm512_maskz_fixupimm_round_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
literal|5
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_maskz_fixupimm_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|,
name|__m512i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_fixupimm_ps
comment|// CHECK: @llvm.x86.avx512.maskz.fixupimm.ps.512
return|return
name|_mm512_maskz_fixupimm_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_fixupimm_round_sd
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|,
name|__m128i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_fixupimm_round_sd
comment|// CHECK: @llvm.x86.avx512.mask.fixupimm
return|return
name|_mm_fixupimm_round_sd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
literal|5
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_fixupimm_round_sd
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__B
parameter_list|,
name|__m128i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_fixupimm_round_sd
comment|// CHECK: @llvm.x86.avx512.mask.fixupimm
return|return
name|_mm_mask_fixupimm_round_sd
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
literal|5
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_fixupimm_sd
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|,
name|__m128i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_fixupimm_sd
comment|// CHECK: @llvm.x86.avx512.mask.fixupimm
return|return
name|_mm_fixupimm_sd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_fixupimm_sd
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__B
parameter_list|,
name|__m128i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_fixupimm_sd
comment|// CHECK: @llvm.x86.avx512.mask.fixupimm
return|return
name|_mm_mask_fixupimm_sd
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_maskz_fixupimm_round_sd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|,
name|__m128i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_fixupimm_round_sd
comment|// CHECK: @llvm.x86.avx512.maskz.fixupimm
return|return
name|_mm_maskz_fixupimm_round_sd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
literal|5
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_maskz_fixupimm_sd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|,
name|__m128i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_fixupimm_sd
comment|// CHECK: @llvm.x86.avx512.maskz.fixupimm
return|return
name|_mm_maskz_fixupimm_sd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_fixupimm_round_ss
parameter_list|(
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|,
name|__m128i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_fixupimm_round_ss
comment|// CHECK: @llvm.x86.avx512.mask.fixupimm
return|return
name|_mm_fixupimm_round_ss
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
literal|5
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_fixupimm_round_ss
parameter_list|(
name|__m128
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__B
parameter_list|,
name|__m128i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_fixupimm_round_ss
comment|// CHECK: @llvm.x86.avx512.mask.fixupimm
return|return
name|_mm_mask_fixupimm_round_ss
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
literal|5
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_fixupimm_ss
parameter_list|(
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|,
name|__m128i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_fixupimm_ss
comment|// CHECK: @llvm.x86.avx512.mask.fixupimm
return|return
name|_mm_fixupimm_ss
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_fixupimm_ss
parameter_list|(
name|__m128
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__B
parameter_list|,
name|__m128i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_fixupimm_ss
comment|// CHECK: @llvm.x86.avx512.mask.fixupimm
return|return
name|_mm_mask_fixupimm_ss
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_maskz_fixupimm_round_ss
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|,
name|__m128i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_fixupimm_round_ss
comment|// CHECK: @llvm.x86.avx512.maskz.fixupimm
return|return
name|_mm_maskz_fixupimm_round_ss
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
literal|5
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_maskz_fixupimm_ss
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|,
name|__m128i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_fixupimm_ss
comment|// CHECK: @llvm.x86.avx512.maskz.fixupimm
return|return
name|_mm_maskz_fixupimm_ss
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_getexp_round_sd
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_getexp_round_sd
comment|// CHECK: @llvm.x86.avx512.mask.getexp.sd
return|return
name|_mm_getexp_round_sd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_getexp_sd
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_getexp_sd
comment|// CHECK: @llvm.x86.avx512.mask.getexp.sd
return|return
name|_mm_getexp_sd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_getexp_round_ss
parameter_list|(
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_getexp_round_ss
comment|// CHECK: @llvm.x86.avx512.mask.getexp.ss
return|return
name|_mm_getexp_round_ss
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_getexp_ss
parameter_list|(
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_getexp_ss
comment|// CHECK: @llvm.x86.avx512.mask.getexp.ss
return|return
name|_mm_getexp_ss
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_getmant_round_sd
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_getmant_round_sd
comment|// CHECK: @llvm.x86.avx512.mask.getmant.sd
return|return
name|_mm_getmant_round_sd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_MANT_NORM_1_2
argument_list|,
name|_MM_MANT_SIGN_src
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_getmant_sd
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_getmant_sd
comment|// CHECK: @llvm.x86.avx512.mask.getmant.sd
return|return
name|_mm_getmant_sd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_MANT_NORM_1_2
argument_list|,
name|_MM_MANT_SIGN_src
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_getmant_round_ss
parameter_list|(
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_getmant_round_ss
comment|// CHECK: @llvm.x86.avx512.mask.getmant.ss
return|return
name|_mm_getmant_round_ss
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_MANT_NORM_1_2
argument_list|,
name|_MM_MANT_SIGN_src
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_getmant_ss
parameter_list|(
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_getmant_ss
comment|// CHECK: @llvm.x86.avx512.mask.getmant.ss
return|return
name|_mm_getmant_ss
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_MANT_NORM_1_2
argument_list|,
name|_MM_MANT_SIGN_src
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm512_kmov
parameter_list|(
name|__mmask16
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_kmov
comment|// CHECK: load i16, i16* %__A.addr.i, align 2
return|return
name|_mm512_kmov
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_unpackhi_pd
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
comment|// CHECK-LABEL: @test_mm512_mask_unpackhi_pd
comment|// CHECK: shufflevector<8 x double> %{{.*}},<8 x double> %{{.*}},<8 x i32><i32 1, i32 9, i32 3, i32 11, i32 5, i32 13, i32 7, i32 15>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x double> %{{.*}},<8 x double> %{{.*}}
return|return
name|_mm512_mask_unpackhi_pd
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

begin_if
if|#
directive|if
name|__x86_64__
end_if

begin_function
name|unsigned
name|long
name|long
name|test_mm_cvt_roundsd_si64
parameter_list|(
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvt_roundsd_si64
comment|// CHECK: @llvm.x86.avx512.vcvtsd2si64
return|return
name|_mm_cvt_roundsd_si64
argument_list|(
name|__A
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|__m512i
name|test_mm512_mask2_permutex2var_epi32
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__I
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask2_permutex2var_epi32
comment|// CHECK: @llvm.x86.avx512.mask.vpermi2var.d.512
return|return
name|_mm512_mask2_permutex2var_epi32
argument_list|(
name|__A
argument_list|,
name|__I
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_unpackhi_epi32
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_unpackhi_epi32
comment|// CHECK: shufflevector<16 x i32> %{{.*}},<16 x i32> %{{.*}},<16 x i32><i32 2, i32 18, i32 3, i32 19, i32 6, i32 22, i32 7, i32 23, i32 10, i32 26, i32 11, i32 27, i32 14, i32 30, i32 15, i32 31>
return|return
name|_mm512_unpackhi_epi32
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
name|test_mm512_maskz_unpackhi_pd
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
comment|// CHECK-LABEL: @test_mm512_maskz_unpackhi_pd
comment|// CHECK: shufflevector<8 x double> %{{.*}},<8 x double> %{{.*}},<8 x i32><i32 1, i32 9, i32 3, i32 11, i32 5, i32 13, i32 7, i32 15>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x double> %{{.*}},<8 x double> %{{.*}}
return|return
name|_mm512_maskz_unpackhi_pd
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

begin_if
if|#
directive|if
name|__x86_64__
end_if

begin_function
name|long
name|long
name|test_mm_cvt_roundsd_i64
parameter_list|(
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvt_roundsd_i64
comment|// CHECK: @llvm.x86.avx512.vcvtsd2si64
return|return
name|_mm_cvt_roundsd_i64
argument_list|(
name|__A
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|__m512d
name|test_mm512_mask2_permutex2var_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__m512i
name|__I
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask2_permutex2var_pd
comment|// CHECK: @llvm.x86.avx512.mask.vpermi2var.pd.512
return|return
name|_mm512_mask2_permutex2var_pd
argument_list|(
name|__A
argument_list|,
name|__I
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_unpackhi_epi32
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
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_unpackhi_epi32
comment|// CHECK: shufflevector<16 x i32> %{{.*}},<16 x i32> %{{.*}},<16 x i32><i32 2, i32 18, i32 3, i32 19, i32 6, i32 22, i32 7, i32 23, i32 10, i32 26, i32 11, i32 27, i32 14, i32 30, i32 15, i32 31>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_mask_unpackhi_epi32
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
name|test_mm512_mask_unpackhi_ps
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
comment|// CHECK-LABEL: @test_mm512_mask_unpackhi_ps
comment|// CHECK: shufflevector<16 x float> %{{.*}},<16 x float> %{{.*}},<16 x i32><i32 2, i32 18, i32 3, i32 19, i32 6, i32 22, i32 7, i32 23, i32 10, i32 26, i32 11, i32 27, i32 14, i32 30, i32 15, i32 31>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x float> %{{.*}},<16 x float> %{{.*}}
return|return
name|_mm512_mask_unpackhi_ps
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
name|test_mm512_maskz_unpackhi_ps
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
comment|// CHECK-LABEL: @test_mm512_maskz_unpackhi_ps
comment|// CHECK: shufflevector<16 x float> %{{.*}},<16 x float> %{{.*}},<16 x i32><i32 2, i32 18, i32 3, i32 19, i32 6, i32 22, i32 7, i32 23, i32 10, i32 26, i32 11, i32 27, i32 14, i32 30, i32 15, i32 31>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x float> %{{.*}},<16 x float> %{{.*}}
return|return
name|_mm512_maskz_unpackhi_ps
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
name|test_mm512_mask_unpacklo_pd
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
comment|// CHECK-LABEL: @test_mm512_mask_unpacklo_pd
comment|// CHECK: shufflevector<8 x double> %{{.*}},<8 x double> %{{.*}},<8 x i32><i32 0, i32 8, i32 2, i32 10, i32 4, i32 12, i32 6, i32 14>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x double> %{{.*}},<8 x double> %{{.*}}
return|return
name|_mm512_mask_unpacklo_pd
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
name|test_mm512_maskz_unpacklo_pd
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
comment|// CHECK-LABEL: @test_mm512_maskz_unpacklo_pd
comment|// CHECK: shufflevector<8 x double> %{{.*}},<8 x double> %{{.*}},<8 x i32><i32 0, i32 8, i32 2, i32 10, i32 4, i32 12, i32 6, i32 14>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x double> %{{.*}},<8 x double> %{{.*}}
return|return
name|_mm512_maskz_unpacklo_pd
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
name|test_mm512_mask_unpacklo_ps
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
comment|// CHECK-LABEL: @test_mm512_mask_unpacklo_ps
comment|// CHECK: shufflevector<16 x float> %{{.*}},<16 x float> %{{.*}},<16 x i32><i32 0, i32 16, i32 1, i32 17, i32 4, i32 20, i32 5, i32 21, i32 8, i32 24, i32 9, i32 25, i32 12, i32 28, i32 13, i32 29>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x float> %{{.*}},<16 x float> %{{.*}}
return|return
name|_mm512_mask_unpacklo_ps
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
name|test_mm512_maskz_unpacklo_ps
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
comment|// CHECK-LABEL: @test_mm512_maskz_unpacklo_ps
comment|// CHECK: shufflevector<16 x float> %{{.*}},<16 x float> %{{.*}},<16 x i32><i32 0, i32 16, i32 1, i32 17, i32 4, i32 20, i32 5, i32 21, i32 8, i32 24, i32 9, i32 25, i32 12, i32 28, i32 13, i32 29>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x float> %{{.*}},<16 x float> %{{.*}}
return|return
name|_mm512_maskz_unpacklo_ps
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
name|int
name|test_mm_cvt_roundsd_si32
parameter_list|(
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvt_roundsd_si32
comment|// CHECK: @llvm.x86.avx512.vcvtsd2si32
return|return
name|_mm_cvt_roundsd_si32
argument_list|(
name|__A
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm_cvt_roundsd_i32
parameter_list|(
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvt_roundsd_i32
comment|// CHECK: @llvm.x86.avx512.vcvtsd2si32
return|return
name|_mm_cvt_roundsd_i32
argument_list|(
name|__A
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|test_mm_cvt_roundsd_u32
parameter_list|(
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvt_roundsd_u32
comment|// CHECK: @llvm.x86.avx512.vcvtsd2usi32
return|return
name|_mm_cvt_roundsd_u32
argument_list|(
name|__A
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|test_mm_cvtsd_u32
parameter_list|(
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtsd_u32
comment|// CHECK: @llvm.x86.avx512.vcvtsd2usi32
return|return
name|_mm_cvtsd_u32
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|__x86_64__
end_ifdef

begin_function
name|unsigned
name|long
name|long
name|test_mm_cvt_roundsd_u64
parameter_list|(
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvt_roundsd_u64
comment|// CHECK: @llvm.x86.avx512.vcvtsd2usi64
return|return
name|_mm_cvt_roundsd_u64
argument_list|(
name|__A
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|long
name|long
name|test_mm_cvtsd_u64
parameter_list|(
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtsd_u64
comment|// CHECK: @llvm.x86.avx512.vcvtsd2usi64
return|return
name|_mm_cvtsd_u64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|int
name|test_mm_cvt_roundss_si32
parameter_list|(
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvt_roundss_si32
comment|// CHECK: @llvm.x86.avx512.vcvtss2si32
return|return
name|_mm_cvt_roundss_si32
argument_list|(
name|__A
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm_cvt_roundss_i32
parameter_list|(
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvt_roundss_i32
comment|// CHECK: @llvm.x86.avx512.vcvtss2si32
return|return
name|_mm_cvt_roundss_i32
argument_list|(
name|__A
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|__x86_64__
end_ifdef

begin_function
name|int
name|test_mm_cvt_roundss_si64
parameter_list|(
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvt_roundss_si64
comment|// CHECK: @llvm.x86.avx512.vcvtss2si64
return|return
name|_mm_cvt_roundss_si64
argument_list|(
name|__A
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|long
name|long
name|test_mm_cvt_roundss_i64
parameter_list|(
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvt_roundss_i64
comment|// CHECK: @llvm.x86.avx512.vcvtss2si64
return|return
name|_mm_cvt_roundss_i64
argument_list|(
name|__A
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|unsigned
name|test_mm_cvt_roundss_u32
parameter_list|(
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvt_roundss_u32
comment|// CHECK: @llvm.x86.avx512.vcvtss2usi32
return|return
name|_mm_cvt_roundss_u32
argument_list|(
name|__A
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|test_mm_cvtss_u32
parameter_list|(
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtss_u32
comment|// CHECK: @llvm.x86.avx512.vcvtss2usi32
return|return
name|_mm_cvtss_u32
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|__x86_64__
end_ifdef

begin_function
name|unsigned
name|long
name|long
name|test_mm_cvt_roundss_u64
parameter_list|(
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvt_roundss_u64
comment|// CHECK: @llvm.x86.avx512.vcvtss2usi64
return|return
name|_mm_cvt_roundss_u64
argument_list|(
name|__A
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|long
name|long
name|test_mm_cvtss_u64
parameter_list|(
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtss_u64
comment|// CHECK: @llvm.x86.avx512.vcvtss2usi64
return|return
name|_mm_cvtss_u64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|int
name|test_mm_cvtt_roundsd_i32
parameter_list|(
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtt_roundsd_i32
comment|// CHECK: @llvm.x86.avx512.cvttsd2si
return|return
name|_mm_cvtt_roundsd_i32
argument_list|(
name|__A
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm_cvtt_roundsd_si32
parameter_list|(
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtt_roundsd_si32
comment|// CHECK: @llvm.x86.avx512.cvttsd2si
return|return
name|_mm_cvtt_roundsd_si32
argument_list|(
name|__A
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm_cvttsd_i32
parameter_list|(
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvttsd_i32
comment|// CHECK: @llvm.x86.avx512.cvttsd2si
return|return
name|_mm_cvttsd_i32
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|__x86_64__
end_ifdef

begin_function
name|unsigned
name|long
name|long
name|test_mm_cvtt_roundsd_si64
parameter_list|(
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtt_roundsd_si64
comment|// CHECK: @llvm.x86.avx512.cvttsd2si64
return|return
name|_mm_cvtt_roundsd_si64
argument_list|(
name|__A
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|long
name|long
name|test_mm_cvtt_roundsd_i64
parameter_list|(
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtt_roundsd_i64
comment|// CHECK: @llvm.x86.avx512.cvttsd2si64
return|return
name|_mm_cvtt_roundsd_i64
argument_list|(
name|__A
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|long
name|long
name|test_mm_cvttsd_i64
parameter_list|(
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvttsd_i64
comment|// CHECK: @llvm.x86.avx512.cvttsd2si64
return|return
name|_mm_cvttsd_i64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|unsigned
name|test_mm_cvtt_roundsd_u32
parameter_list|(
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtt_roundsd_u32
comment|// CHECK: @llvm.x86.avx512.cvttsd2usi
return|return
name|_mm_cvtt_roundsd_u32
argument_list|(
name|__A
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|test_mm_cvttsd_u32
parameter_list|(
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvttsd_u32
comment|// CHECK: @llvm.x86.avx512.cvttsd2usi
return|return
name|_mm_cvttsd_u32
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|__x86_64__
end_ifdef

begin_function
name|unsigned
name|long
name|long
name|test_mm_cvtt_roundsd_u64
parameter_list|(
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtt_roundsd_u64
comment|// CHECK: @llvm.x86.avx512.cvttsd2usi64
return|return
name|_mm_cvtt_roundsd_u64
argument_list|(
name|__A
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|long
name|long
name|test_mm_cvttsd_u64
parameter_list|(
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvttsd_u64
comment|// CHECK: @llvm.x86.avx512.cvttsd2usi64
return|return
name|_mm_cvttsd_u64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|int
name|test_mm_cvtt_roundss_i32
parameter_list|(
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtt_roundss_i32
comment|// CHECK: @llvm.x86.avx512.cvttss2si
return|return
name|_mm_cvtt_roundss_i32
argument_list|(
name|__A
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm_cvtt_roundss_si32
parameter_list|(
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtt_roundss_si32
comment|// CHECK: @llvm.x86.avx512.cvttss2si
return|return
name|_mm_cvtt_roundss_si32
argument_list|(
name|__A
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm_cvttss_i32
parameter_list|(
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvttss_i32
comment|// CHECK: @llvm.x86.avx512.cvttss2si
return|return
name|_mm_cvttss_i32
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|__x86_64__
end_ifdef

begin_function
name|float
name|test_mm_cvtt_roundss_i64
parameter_list|(
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtt_roundss_i64
comment|// CHECK: @llvm.x86.avx512.cvttss2si64
return|return
name|_mm_cvtt_roundss_i64
argument_list|(
name|__A
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|long
name|long
name|test_mm_cvtt_roundss_si64
parameter_list|(
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtt_roundss_si64
comment|// CHECK: @llvm.x86.avx512.cvttss2si64
return|return
name|_mm_cvtt_roundss_si64
argument_list|(
name|__A
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|long
name|long
name|test_mm_cvttss_i64
parameter_list|(
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvttss_i64
comment|// CHECK: @llvm.x86.avx512.cvttss2si64
return|return
name|_mm_cvttss_i64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|unsigned
name|test_mm_cvtt_roundss_u32
parameter_list|(
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtt_roundss_u32
comment|// CHECK: @llvm.x86.avx512.cvttss2usi
return|return
name|_mm_cvtt_roundss_u32
argument_list|(
name|__A
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|test_mm_cvttss_u32
parameter_list|(
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvttss_u32
comment|// CHECK: @llvm.x86.avx512.cvttss2usi
return|return
name|_mm_cvttss_u32
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|__x86_64__
end_ifdef

begin_function
name|unsigned
name|long
name|long
name|test_mm_cvtt_roundss_u64
parameter_list|(
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtt_roundss_u64
comment|// CHECK: @llvm.x86.avx512.cvttss2usi64
return|return
name|_mm_cvtt_roundss_u64
argument_list|(
name|__A
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|long
name|long
name|test_mm_cvttss_u64
parameter_list|(
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvttss_u64
comment|// CHECK: @llvm.x86.avx512.cvttss2usi64
return|return
name|_mm_cvttss_u64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|__m512i
name|test_mm512_cvtt_roundps_epu32
parameter_list|(
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtt_roundps_epu32
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2udq.512
return|return
name|_mm512_cvtt_roundps_epu32
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
name|test_mm512_mask_cvtt_roundps_epu32
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtt_roundps_epu32
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2udq.512
return|return
name|_mm512_mask_cvtt_roundps_epu32
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
name|test_mm512_maskz_cvtt_roundps_epu32
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtt_roundps_epu32
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2udq.512
return|return
name|_mm512_maskz_cvtt_roundps_epu32
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
name|__m256i
name|test_mm512_cvt_roundps_ph
parameter_list|(
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvt_roundps_ph
comment|// CHECK: @llvm.x86.avx512.mask.vcvtps2ph.512
return|return
name|_mm512_cvt_roundps_ph
argument_list|(
name|__A
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm512_mask_cvt_roundps_ph
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvt_roundps_ph
comment|// CHECK: @llvm.x86.avx512.mask.vcvtps2ph.512
return|return
name|_mm512_mask_cvt_roundps_ph
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
name|__m256i
name|test_mm512_maskz_cvt_roundps_ph
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvt_roundps_ph
comment|// CHECK: @llvm.x86.avx512.mask.vcvtps2ph.512
return|return
name|_mm512_maskz_cvt_roundps_ph
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
name|__m512
name|test_mm512_cvt_roundph_ps
parameter_list|(
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvt_roundph_ps
comment|// CHECK: @llvm.x86.avx512.mask.vcvtph2ps.512
return|return
name|_mm512_cvt_roundph_ps
argument_list|(
name|__A
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_cvt_roundph_ps
parameter_list|(
name|__m512
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvt_roundph_ps
comment|// CHECK: @llvm.x86.avx512.mask.vcvtph2ps.512
return|return
name|_mm512_mask_cvt_roundph_ps
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
name|__m512
name|test_mm512_maskz_cvt_roundph_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvt_roundph_ps
comment|// CHECK: @llvm.x86.avx512.mask.vcvtph2ps.512
return|return
name|_mm512_maskz_cvt_roundph_ps
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
name|__m512
name|test_mm512_mask_cvt_roundepi32_ps
parameter_list|(
name|__m512
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvt_roundepi32_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtdq2ps.512
return|return
name|_mm512_mask_cvt_roundepi32_ps
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
name|test_mm512_maskz_cvt_roundepi32_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvt_roundepi32_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtdq2ps.512
return|return
name|_mm512_maskz_cvt_roundepi32_ps
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
name|test_mm512_mask_cvt_roundepu32_ps
parameter_list|(
name|__m512
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvt_roundepu32_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtudq2ps.512
return|return
name|_mm512_mask_cvt_roundepu32_ps
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
name|test_mm512_maskz_cvt_roundepu32_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvt_roundepu32_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtudq2ps.512
return|return
name|_mm512_maskz_cvt_roundepu32_ps
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
name|__m256
name|test_mm512_mask_cvt_roundpd_ps
parameter_list|(
name|__m256
name|W
parameter_list|,
name|__mmask8
name|U
parameter_list|,
name|__m512d
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvt_roundpd_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2ps.512
return|return
name|_mm512_mask_cvt_roundpd_ps
argument_list|(
name|W
argument_list|,
name|U
argument_list|,
name|A
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm512_maskz_cvt_roundpd_ps
parameter_list|(
name|__mmask8
name|U
parameter_list|,
name|__m512d
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvt_roundpd_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2ps.512
return|return
name|_mm512_maskz_cvt_roundpd_ps
argument_list|(
name|U
argument_list|,
name|A
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm512_cvtt_roundpd_epi32
parameter_list|(
name|__m512d
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtt_roundpd_epi32
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2dq.512
return|return
name|_mm512_cvtt_roundpd_epi32
argument_list|(
name|A
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm512_mask_cvtt_roundpd_epi32
parameter_list|(
name|__m256i
name|W
parameter_list|,
name|__mmask8
name|U
parameter_list|,
name|__m512d
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtt_roundpd_epi32
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2dq.512
return|return
name|_mm512_mask_cvtt_roundpd_epi32
argument_list|(
name|W
argument_list|,
name|U
argument_list|,
name|A
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm512_maskz_cvtt_roundpd_epi32
parameter_list|(
name|__mmask8
name|U
parameter_list|,
name|__m512d
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtt_roundpd_epi32
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2dq.512
return|return
name|_mm512_maskz_cvtt_roundpd_epi32
argument_list|(
name|U
argument_list|,
name|A
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_cvtt_roundps_epi32
parameter_list|(
name|__m512i
name|W
parameter_list|,
name|__mmask16
name|U
parameter_list|,
name|__m512
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtt_roundps_epi32
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2dq.512
return|return
name|_mm512_mask_cvtt_roundps_epi32
argument_list|(
name|W
argument_list|,
name|U
argument_list|,
name|A
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_cvtt_roundps_epi32
parameter_list|(
name|__mmask16
name|U
parameter_list|,
name|__m512
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtt_roundps_epi32
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2dq.512
return|return
name|_mm512_maskz_cvtt_roundps_epi32
argument_list|(
name|U
argument_list|,
name|A
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_cvt_roundps_epi32
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvt_roundps_epi32
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2dq.512
return|return
name|_mm512_mask_cvt_roundps_epi32
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
name|__m512i
name|test_mm512_maskz_cvt_roundps_epi32
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvt_roundps_epi32
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2dq.512
return|return
name|_mm512_maskz_cvt_roundps_epi32
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
name|__m256i
name|test_mm512_mask_cvt_roundpd_epi32
parameter_list|(
name|__m256i
name|W
parameter_list|,
name|__mmask8
name|U
parameter_list|,
name|__m512d
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvt_roundpd_epi32
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2dq.512
return|return
name|_mm512_mask_cvt_roundpd_epi32
argument_list|(
name|W
argument_list|,
name|U
argument_list|,
name|A
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm512_maskz_cvt_roundpd_epi32
parameter_list|(
name|__mmask8
name|U
parameter_list|,
name|__m512d
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvt_roundpd_epi32
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2dq.512
return|return
name|_mm512_maskz_cvt_roundpd_epi32
argument_list|(
name|U
argument_list|,
name|A
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_cvt_roundps_epu32
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvt_roundps_epu32
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2udq.512
return|return
name|_mm512_mask_cvt_roundps_epu32
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
name|__m512i
name|test_mm512_maskz_cvt_roundps_epu32
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvt_roundps_epu32
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2udq.512
return|return
name|_mm512_maskz_cvt_roundps_epu32
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
name|__m256i
name|test_mm512_mask_cvt_roundpd_epu32
parameter_list|(
name|__m256i
name|W
parameter_list|,
name|__mmask8
name|U
parameter_list|,
name|__m512d
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvt_roundpd_epu32
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2udq.512
return|return
name|_mm512_mask_cvt_roundpd_epu32
argument_list|(
name|W
argument_list|,
name|U
argument_list|,
name|A
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm512_maskz_cvt_roundpd_epu32
parameter_list|(
name|__mmask8
name|U
parameter_list|,
name|__m512d
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvt_roundpd_epu32
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2udq.512
return|return
name|_mm512_maskz_cvt_roundpd_epu32
argument_list|(
name|U
argument_list|,
name|A
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask2_permutex2var_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__m512i
name|__I
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask2_permutex2var_ps
comment|// CHECK: @llvm.x86.avx512.mask.vpermi2var.ps.512
return|return
name|_mm512_mask2_permutex2var_ps
argument_list|(
name|__A
argument_list|,
name|__I
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask2_permutex2var_epi64
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__I
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask2_permutex2var_epi64
comment|// CHECK: @llvm.x86.avx512.mask.vpermi2var.q.512
return|return
name|_mm512_mask2_permutex2var_epi64
argument_list|(
name|__A
argument_list|,
name|__I
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_permute_pd
parameter_list|(
name|__m512d
name|__X
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_permute_pd
comment|// CHECK: shufflevector<8 x double> %{{.*}},<8 x double> zeroinitializer,<8 x i32><i32 0, i32 1, i32 2, i32 2, i32 4, i32 4, i32 6, i32 6>
return|return
name|_mm512_permute_pd
argument_list|(
name|__X
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_permute_pd
parameter_list|(
name|__m512d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__X
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_permute_pd
comment|// CHECK: shufflevector<8 x double> %{{.*}},<8 x double> zeroinitializer,<8 x i32><i32 0, i32 1, i32 2, i32 2, i32 4, i32 4, i32 6, i32 6>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x double> %{{.*}},<8 x double> %{{.*}}
return|return
name|_mm512_mask_permute_pd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__X
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_maskz_permute_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__X
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_permute_pd
comment|// CHECK: shufflevector<8 x double> %{{.*}},<8 x double> zeroinitializer,<8 x i32><i32 0, i32 1, i32 2, i32 2, i32 4, i32 4, i32 6, i32 6>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x double> %{{.*}},<8 x double> %{{.*}}
return|return
name|_mm512_maskz_permute_pd
argument_list|(
name|__U
argument_list|,
name|__X
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_permute_ps
parameter_list|(
name|__m512
name|__X
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_permute_ps
comment|// CHECK: shufflevector<16 x float> %{{.*}},<16 x float> zeroinitializer,<16 x i32><i32 2, i32 0, i32 0, i32 0, i32 6, i32 4, i32 4, i32 4, i32 10, i32 8, i32 8, i32 8, i32 14, i32 12, i32 12, i32 12>
return|return
name|_mm512_permute_ps
argument_list|(
name|__X
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_permute_ps
parameter_list|(
name|__m512
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__X
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_permute_ps
comment|// CHECK: shufflevector<16 x float> %{{.*}},<16 x float> zeroinitializer,<16 x i32><i32 2, i32 0, i32 0, i32 0, i32 6, i32 4, i32 4, i32 4, i32 10, i32 8, i32 8, i32 8, i32 14, i32 12, i32 12, i32 12>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x float> %{{.*}},<16 x float> %{{.*}}
return|return
name|_mm512_mask_permute_ps
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__X
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_maskz_permute_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__X
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_permute_ps
comment|// CHECK: shufflevector<16 x float> %{{.*}},<16 x float> zeroinitializer,<16 x i32><i32 2, i32 0, i32 0, i32 0, i32 6, i32 4, i32 4, i32 4, i32 10, i32 8, i32 8, i32 8, i32 14, i32 12, i32 12, i32 12>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x float> %{{.*}},<16 x float> %{{.*}}
return|return
name|_mm512_maskz_permute_ps
argument_list|(
name|__U
argument_list|,
name|__X
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_permutevar_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__m512i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_permutevar_pd
comment|// CHECK: @llvm.x86.avx512.vpermilvar.pd.512
return|return
name|_mm512_permutevar_pd
argument_list|(
name|__A
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_permutevar_pd
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
name|__m512i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_permutevar_pd
comment|// CHECK: @llvm.x86.avx512.vpermilvar.pd.512
comment|// CHECK: select<8 x i1> %{{.*}},<8 x double> %{{.*}},<8 x double> %{{.*}}
return|return
name|_mm512_mask_permutevar_pd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_maskz_permutevar_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|,
name|__m512i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_permutevar_pd
comment|// CHECK: @llvm.x86.avx512.vpermilvar.pd.512
comment|// CHECK: select<8 x i1> %{{.*}},<8 x double> %{{.*}},<8 x double> %{{.*}}
return|return
name|_mm512_maskz_permutevar_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_permutevar_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__m512i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_permutevar_ps
comment|// CHECK: @llvm.x86.avx512.vpermilvar.ps.512
return|return
name|_mm512_permutevar_ps
argument_list|(
name|__A
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_permutevar_ps
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
name|__m512i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_permutevar_ps
comment|// CHECK: @llvm.x86.avx512.vpermilvar.ps.512
comment|// CHECK: select<16 x i1> %{{.*}},<16 x float> %{{.*}},<16 x float> %{{.*}}
return|return
name|_mm512_mask_permutevar_ps
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_maskz_permutevar_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|,
name|__m512i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_permutevar_ps
comment|// CHECK: @llvm.x86.avx512.vpermilvar.ps.512
comment|// CHECK: select<16 x i1> %{{.*}},<16 x float> %{{.*}},<16 x float> %{{.*}}
return|return
name|_mm512_maskz_permutevar_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_permutex2var_epi32
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__I
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_permutex2var_epi32
comment|// CHECK: @llvm.x86.avx512.maskz.vpermt2var.d.512
return|return
name|_mm512_maskz_permutex2var_epi32
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__I
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_permutex2var_epi32
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512i
name|__I
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_permutex2var_epi32
comment|// CHECK: @llvm.x86.avx512.mask.vpermt2var.d.512
return|return
name|_mm512_mask_permutex2var_epi32
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__I
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_permutex2var_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__m512i
name|__I
parameter_list|,
name|__m512d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_permutex2var_pd
comment|// CHECK: @llvm.x86.avx512.mask.vpermt2var.pd.512
return|return
name|_mm512_permutex2var_pd
argument_list|(
name|__A
argument_list|,
name|__I
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_permutex2var_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__I
parameter_list|,
name|__m512d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_permutex2var_pd
comment|// CHECK: @llvm.x86.avx512.mask.vpermt2var.pd.512
return|return
name|_mm512_mask_permutex2var_pd
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__I
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_maskz_permutex2var_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|,
name|__m512i
name|__I
parameter_list|,
name|__m512d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_permutex2var_pd
comment|// CHECK: @llvm.x86.avx512.maskz.vpermt2var.pd.512
return|return
name|_mm512_maskz_permutex2var_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__I
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_permutex2var_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__m512i
name|__I
parameter_list|,
name|__m512
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_permutex2var_ps
comment|// CHECK: @llvm.x86.avx512.mask.vpermt2var.ps.512
return|return
name|_mm512_permutex2var_ps
argument_list|(
name|__A
argument_list|,
name|__I
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_permutex2var_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512i
name|__I
parameter_list|,
name|__m512
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_permutex2var_ps
comment|// CHECK: @llvm.x86.avx512.mask.vpermt2var.ps.512
return|return
name|_mm512_mask_permutex2var_ps
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__I
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_maskz_permutex2var_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|,
name|__m512i
name|__I
parameter_list|,
name|__m512
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_permutex2var_ps
comment|// CHECK: @llvm.x86.avx512.maskz.vpermt2var.ps.512
return|return
name|_mm512_maskz_permutex2var_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__I
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_permutex2var_epi64
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__I
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_permutex2var_epi64
comment|// CHECK: @llvm.x86.avx512.mask.vpermt2var.q.512
return|return
name|_mm512_mask_permutex2var_epi64
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__I
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_permutex2var_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__I
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_permutex2var_epi64
comment|// CHECK: @llvm.x86.avx512.maskz.vpermt2var.q.512
return|return
name|_mm512_maskz_permutex2var_epi64
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__I
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm512_testn_epi32_mask
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_testn_epi32_mask
comment|// CHECK: @llvm.x86.avx512.ptestnm.d.512
return|return
name|_mm512_testn_epi32_mask
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm512_mask_testn_epi32_mask
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_testn_epi32_mask
comment|// CHECK: @llvm.x86.avx512.ptestnm.d.512
return|return
name|_mm512_mask_testn_epi32_mask
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
name|__mmask8
name|test_mm512_testn_epi64_mask
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_testn_epi64_mask
comment|// CHECK: @llvm.x86.avx512.ptestnm.q.512
return|return
name|_mm512_testn_epi64_mask
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_mask_testn_epi64_mask
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
comment|// CHECK-LABEL: @test_mm512_mask_testn_epi64_mask
comment|// CHECK: @llvm.x86.avx512.ptestnm.q.512
return|return
name|_mm512_mask_testn_epi64_mask
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
name|__mmask16
name|test_mm512_mask_test_epi32_mask
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_test_epi32_mask
comment|// CHECK: @llvm.x86.avx512.ptestm.d.512
return|return
name|_mm512_mask_test_epi32_mask
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
name|__mmask8
name|test_mm512_mask_test_epi64_mask
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
comment|// CHECK-LABEL: @test_mm512_mask_test_epi64_mask
comment|// CHECK: @llvm.x86.avx512.ptestm.q.512
return|return
name|_mm512_mask_test_epi64_mask
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
name|test_mm512_maskz_unpackhi_epi32
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_unpackhi_epi32
comment|// CHECK: shufflevector<16 x i32> %{{.*}},<16 x i32> %{{.*}},<16 x i32><i32 2, i32 18, i32 3, i32 19, i32 6, i32 22, i32 7, i32 23, i32 10, i32 26, i32 11, i32 27, i32 14, i32 30, i32 15, i32 31>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_maskz_unpackhi_epi32
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
name|test_mm512_unpackhi_epi64
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_unpackhi_epi64
comment|// CHECK: shufflevector<8 x i64> %{{.*}},<8 x i64> %{{.*}},<8 x i32><i32 1, i32 9, i32 3, i32 11, i32 5, i32 13, i32 7, i32 15>
return|return
name|_mm512_unpackhi_epi64
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_unpackhi_epi64
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
comment|// CHECK-LABEL: @test_mm512_mask_unpackhi_epi64
comment|// CHECK: shufflevector<8 x i64> %{{.*}},<8 x i64> %{{.*}},<8 x i32><i32 1, i32 9, i32 3, i32 11, i32 5, i32 13, i32 7, i32 15>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_mask_unpackhi_epi64
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
name|test_mm512_maskz_unpackhi_epi64
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
comment|// CHECK-LABEL: @test_mm512_maskz_unpackhi_epi64
comment|// CHECK: shufflevector<8 x i64> %{{.*}},<8 x i64> %{{.*}},<8 x i32><i32 1, i32 9, i32 3, i32 11, i32 5, i32 13, i32 7, i32 15>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_maskz_unpackhi_epi64
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
name|test_mm512_unpacklo_epi32
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_unpacklo_epi32
comment|// CHECK: shufflevector<16 x i32> %{{.*}},<16 x i32> %{{.*}},<16 x i32><i32 0, i32 16, i32 1, i32 17, i32 4, i32 20, i32 5, i32 21, i32 8, i32 24, i32 9, i32 25, i32 12, i32 28, i32 13, i32 29>
return|return
name|_mm512_unpacklo_epi32
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_unpacklo_epi32
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
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_unpacklo_epi32
comment|// CHECK: shufflevector<16 x i32> %{{.*}},<16 x i32> %{{.*}},<16 x i32><i32 0, i32 16, i32 1, i32 17, i32 4, i32 20, i32 5, i32 21, i32 8, i32 24, i32 9, i32 25, i32 12, i32 28, i32 13, i32 29>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_mask_unpacklo_epi32
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
name|test_mm512_maskz_unpacklo_epi32
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_unpacklo_epi32
comment|// CHECK: shufflevector<16 x i32> %{{.*}},<16 x i32> %{{.*}},<16 x i32><i32 0, i32 16, i32 1, i32 17, i32 4, i32 20, i32 5, i32 21, i32 8, i32 24, i32 9, i32 25, i32 12, i32 28, i32 13, i32 29>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_maskz_unpacklo_epi32
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
name|test_mm512_unpacklo_epi64
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_unpacklo_epi64
comment|// CHECK: shufflevector<8 x i64> %{{.*}},<8 x i64> %{{.*}},<8 x i32><i32 0, i32 8, i32 2, i32 10, i32 4, i32 12, i32 6, i32 14>
return|return
name|_mm512_unpacklo_epi64
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_unpacklo_epi64
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
comment|// CHECK-LABEL: @test_mm512_mask_unpacklo_epi64
comment|// CHECK: shufflevector<8 x i64> %{{.*}},<8 x i64> %{{.*}},<8 x i32><i32 0, i32 8, i32 2, i32 10, i32 4, i32 12, i32 6, i32 14>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_mask_unpacklo_epi64
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
name|test_mm512_maskz_unpacklo_epi64
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
comment|// CHECK-LABEL: @test_mm512_maskz_unpacklo_epi64
comment|// CHECK: shufflevector<8 x i64> %{{.*}},<8 x i64> %{{.*}},<8 x i32><i32 0, i32 8, i32 2, i32 10, i32 4, i32 12, i32 6, i32 14>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_maskz_unpacklo_epi64
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
name|__m128d
name|test_mm_roundscale_round_sd
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_roundscale_round_sd
comment|// CHECK: @llvm.x86.avx512.mask.rndscale.sd
return|return
name|_mm_roundscale_round_sd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
literal|3
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_roundscale_sd
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_roundscale_sd
comment|// CHECK: @llvm.x86.avx512.mask.rndscale.sd
return|return
name|_mm_roundscale_sd
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
name|__m128d
name|test_mm_mask_roundscale_sd
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
comment|// CHECK: @llvm.x86.avx512.mask.rndscale.sd
return|return
name|_mm_mask_roundscale_sd
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
name|__m128d
name|test_mm_mask_roundscale_round_sd
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
comment|// CHECK: @llvm.x86.avx512.mask.rndscale.sd
return|return
name|_mm_mask_roundscale_round_sd
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
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_maskz_roundscale_sd
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
comment|// CHECK: @llvm.x86.avx512.mask.rndscale.sd
return|return
name|_mm_maskz_roundscale_sd
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
name|__m128d
name|test_mm_maskz_roundscale_round_sd
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
comment|// CHECK: @llvm.x86.avx512.mask.rndscale.sd
return|return
name|_mm_maskz_roundscale_round_sd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|3
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_roundscale_round_ss
parameter_list|(
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_roundscale_round_ss
comment|// CHECK: @llvm.x86.avx512.mask.rndscale.ss
return|return
name|_mm_roundscale_round_ss
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
literal|3
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_roundscale_ss
parameter_list|(
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_roundscale_ss
comment|// CHECK: @llvm.x86.avx512.mask.rndscale.ss
return|return
name|_mm_roundscale_ss
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
name|__m128
name|test_mm_mask_roundscale_ss
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
comment|// CHECK-LABEL: @test_mm_mask_roundscale_ss
comment|// CHECK: @llvm.x86.avx512.mask.rndscale.ss
return|return
name|_mm_mask_roundscale_ss
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
name|__m128
name|test_mm_maskz_roundscale_round_ss
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
comment|// CHECK-LABEL: @test_mm_maskz_roundscale_round_ss
comment|// CHECK: @llvm.x86.avx512.mask.rndscale.ss
return|return
name|_mm_maskz_roundscale_round_ss
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|3
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_maskz_roundscale_ss
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
comment|// CHECK-LABEL: @test_mm_maskz_roundscale_ss
comment|// CHECK: @llvm.x86.avx512.mask.rndscale.ss
return|return
name|_mm_maskz_roundscale_ss
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
name|__m512d
name|test_mm512_scalef_round_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_scalef_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.scalef.pd.512
return|return
name|_mm512_scalef_round_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_scalef_round_pd
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
comment|// CHECK-LABEL: @test_mm512_mask_scalef_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.scalef.pd.512
return|return
name|_mm512_mask_scalef_round_pd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_maskz_scalef_round_pd
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
comment|// CHECK-LABEL: @test_mm512_maskz_scalef_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.scalef.pd.512
return|return
name|_mm512_maskz_scalef_round_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_scalef_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_scalef_pd
comment|// CHECK: @llvm.x86.avx512.mask.scalef.pd.512
return|return
name|_mm512_scalef_pd
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
name|test_mm512_mask_scalef_pd
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
comment|// CHECK-LABEL: @test_mm512_mask_scalef_pd
comment|// CHECK: @llvm.x86.avx512.mask.scalef.pd.512
return|return
name|_mm512_mask_scalef_pd
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
name|test_mm512_maskz_scalef_pd
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
comment|// CHECK-LABEL: @test_mm512_maskz_scalef_pd
comment|// CHECK: @llvm.x86.avx512.mask.scalef.pd.512
return|return
name|_mm512_maskz_scalef_pd
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
name|test_mm512_scalef_round_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_scalef_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.scalef.ps.512
return|return
name|_mm512_scalef_round_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_scalef_round_ps
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
comment|// CHECK-LABEL: @test_mm512_mask_scalef_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.scalef.ps.512
return|return
name|_mm512_mask_scalef_round_ps
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_maskz_scalef_round_ps
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
comment|// CHECK-LABEL: @test_mm512_maskz_scalef_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.scalef.ps.512
return|return
name|_mm512_maskz_scalef_round_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_scalef_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_scalef_ps
comment|// CHECK: @llvm.x86.avx512.mask.scalef.ps.512
return|return
name|_mm512_scalef_ps
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
name|test_mm512_mask_scalef_ps
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
comment|// CHECK-LABEL: @test_mm512_mask_scalef_ps
comment|// CHECK: @llvm.x86.avx512.mask.scalef.ps.512
return|return
name|_mm512_mask_scalef_ps
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
name|test_mm512_maskz_scalef_ps
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
comment|// CHECK-LABEL: @test_mm512_maskz_scalef_ps
comment|// CHECK: @llvm.x86.avx512.mask.scalef.ps.512
return|return
name|_mm512_maskz_scalef_ps
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
name|__m128d
name|test_mm_scalef_round_sd
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_scalef_round_sd
comment|// CHECK: @llvm.x86.avx512.mask.scalef
return|return
name|_mm_scalef_round_sd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_scalef_sd
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_scalef_sd
comment|// CHECK: @llvm.x86.avx512.mask.scalef
return|return
name|_mm_scalef_sd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_scalef_sd
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
comment|// CHECK-LABEL: @test_mm_mask_scalef_sd
comment|// CHECK: @llvm.x86.avx512.mask.scalef.sd
return|return
name|_mm_mask_scalef_sd
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
name|__m128d
name|test_mm_mask_scalef_round_sd
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
comment|// CHECK-LABEL: @test_mm_mask_scalef_round_sd
comment|// CHECK: @llvm.x86.avx512.mask.scalef.sd
return|return
name|_mm_mask_scalef_round_sd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_maskz_scalef_sd
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
comment|// CHECK-LABEL: @test_mm_maskz_scalef_sd
comment|// CHECK: @llvm.x86.avx512.mask.scalef.sd
return|return
name|_mm_maskz_scalef_sd
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
name|__m128d
name|test_mm_maskz_scalef_round_sd
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
comment|// CHECK-LABEL: @test_mm_maskz_scalef_round_sd
comment|// CHECK: @llvm.x86.avx512.mask.scalef.sd
return|return
name|_mm_maskz_scalef_round_sd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_scalef_round_ss
parameter_list|(
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_scalef_round_ss
comment|// CHECK: @llvm.x86.avx512.mask.scalef.ss
return|return
name|_mm_scalef_round_ss
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_scalef_ss
parameter_list|(
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_scalef_ss
comment|// CHECK: @llvm.x86.avx512.mask.scalef.ss
return|return
name|_mm_scalef_ss
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_scalef_ss
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
comment|// CHECK-LABEL: @test_mm_mask_scalef_ss
comment|// CHECK: @llvm.x86.avx512.mask.scalef.ss
return|return
name|_mm_mask_scalef_ss
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
name|__m128
name|test_mm_mask_scalef_round_ss
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
comment|// CHECK-LABEL: @test_mm_mask_scalef_round_ss
comment|// CHECK: @llvm.x86.avx512.mask.scalef.ss
return|return
name|_mm_mask_scalef_round_ss
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_maskz_scalef_ss
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
comment|// CHECK-LABEL: @test_mm_maskz_scalef_ss
comment|// CHECK: @llvm.x86.avx512.mask.scalef.ss
return|return
name|_mm_maskz_scalef_ss
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
name|__m128
name|test_mm_maskz_scalef_round_ss
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
comment|// CHECK-LABEL: @test_mm_maskz_scalef_round_ss
comment|// CHECK: @llvm.x86.avx512.mask.scalef.ss
return|return
name|_mm_maskz_scalef_round_ss
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_srai_epi32
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_srai_epi32
comment|// CHECK: @llvm.x86.avx512.psrai.d.512
return|return
name|_mm512_srai_epi32
argument_list|(
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_srai_epi32
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
comment|// CHECK-LABEL: @test_mm512_mask_srai_epi32
comment|// CHECK: @llvm.x86.avx512.psrai.d.512
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_mask_srai_epi32
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_srai_epi32
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_srai_epi32
comment|// CHECK: @llvm.x86.avx512.psrai.d.512
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_maskz_srai_epi32
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_srai_epi64
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_srai_epi64
comment|// CHECK: @llvm.x86.avx512.psrai.q.512
return|return
name|_mm512_srai_epi64
argument_list|(
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_srai_epi64
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
comment|// CHECK-LABEL: @test_mm512_mask_srai_epi64
comment|// CHECK: @llvm.x86.avx512.psrai.q.512
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_mask_srai_epi64
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_srai_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_srai_epi64
comment|// CHECK: @llvm.x86.avx512.psrai.q.512
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_maskz_srai_epi64
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_sll_epi32
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_sll_epi32
comment|// CHECK: @llvm.x86.avx512.psll.d.512
return|return
name|_mm512_sll_epi32
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_sll_epi32
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
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_sll_epi32
comment|// CHECK: @llvm.x86.avx512.psll.d.512
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_mask_sll_epi32
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
name|test_mm512_maskz_sll_epi32
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_sll_epi32
comment|// CHECK: @llvm.x86.avx512.psll.d.512
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_maskz_sll_epi32
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
name|test_mm512_sll_epi64
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_sll_epi64
comment|// CHECK: @llvm.x86.avx512.psll.q.512
return|return
name|_mm512_sll_epi64
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_sll_epi64
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
comment|// CHECK-LABEL: @test_mm512_mask_sll_epi64
comment|// CHECK: @llvm.x86.avx512.psll.q.512
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_mask_sll_epi64
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
name|test_mm512_maskz_sll_epi64
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
comment|// CHECK-LABEL: @test_mm512_maskz_sll_epi64
comment|// CHECK: @llvm.x86.avx512.psll.q.512
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_maskz_sll_epi64
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
name|test_mm512_sllv_epi32
parameter_list|(
name|__m512i
name|__X
parameter_list|,
name|__m512i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_sllv_epi32
comment|// CHECK: @llvm.x86.avx512.psllv.d.512
return|return
name|_mm512_sllv_epi32
argument_list|(
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_sllv_epi32
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512i
name|__X
parameter_list|,
name|__m512i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_sllv_epi32
comment|// CHECK: @llvm.x86.avx512.psllv.d.512
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_mask_sllv_epi32
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_sllv_epi32
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512i
name|__X
parameter_list|,
name|__m512i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_sllv_epi32
comment|// CHECK: @llvm.x86.avx512.psllv.d.512
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_maskz_sllv_epi32
argument_list|(
name|__U
argument_list|,
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_sllv_epi64
parameter_list|(
name|__m512i
name|__X
parameter_list|,
name|__m512i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_sllv_epi64
comment|// CHECK: @llvm.x86.avx512.psllv.q.512
return|return
name|_mm512_sllv_epi64
argument_list|(
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_sllv_epi64
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__X
parameter_list|,
name|__m512i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_sllv_epi64
comment|// CHECK: @llvm.x86.avx512.psllv.q.512
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_mask_sllv_epi64
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_sllv_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__X
parameter_list|,
name|__m512i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_sllv_epi64
comment|// CHECK: @llvm.x86.avx512.psllv.q.512
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_maskz_sllv_epi64
argument_list|(
name|__U
argument_list|,
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_sra_epi32
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_sra_epi32
comment|// CHECK: @llvm.x86.avx512.psra.d.512
return|return
name|_mm512_sra_epi32
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_sra_epi32
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
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_sra_epi32
comment|// CHECK: @llvm.x86.avx512.psra.d.512
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_mask_sra_epi32
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
name|test_mm512_maskz_sra_epi32
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_sra_epi32
comment|// CHECK: @llvm.x86.avx512.psra.d.512
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_maskz_sra_epi32
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
name|test_mm512_sra_epi64
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_sra_epi64
comment|// CHECK: @llvm.x86.avx512.psra.q.512
return|return
name|_mm512_sra_epi64
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_sra_epi64
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
comment|// CHECK-LABEL: @test_mm512_mask_sra_epi64
comment|// CHECK: @llvm.x86.avx512.psra.q.512
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_mask_sra_epi64
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
name|test_mm512_maskz_sra_epi64
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
comment|// CHECK-LABEL: @test_mm512_maskz_sra_epi64
comment|// CHECK: @llvm.x86.avx512.psra.q.512
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_maskz_sra_epi64
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
name|test_mm512_srav_epi32
parameter_list|(
name|__m512i
name|__X
parameter_list|,
name|__m512i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_srav_epi32
comment|// CHECK: @llvm.x86.avx512.psrav.d.512
return|return
name|_mm512_srav_epi32
argument_list|(
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_srav_epi32
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512i
name|__X
parameter_list|,
name|__m512i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_srav_epi32
comment|// CHECK: @llvm.x86.avx512.psrav.d.512
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_mask_srav_epi32
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_srav_epi32
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512i
name|__X
parameter_list|,
name|__m512i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_srav_epi32
comment|// CHECK: @llvm.x86.avx512.psrav.d.512
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_maskz_srav_epi32
argument_list|(
name|__U
argument_list|,
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_srav_epi64
parameter_list|(
name|__m512i
name|__X
parameter_list|,
name|__m512i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_srav_epi64
comment|// CHECK: @llvm.x86.avx512.psrav.q.512
return|return
name|_mm512_srav_epi64
argument_list|(
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_srav_epi64
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__X
parameter_list|,
name|__m512i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_srav_epi64
comment|// CHECK: @llvm.x86.avx512.psrav.q.512
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_mask_srav_epi64
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_srav_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__X
parameter_list|,
name|__m512i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_srav_epi64
comment|// CHECK: @llvm.x86.avx512.psrav.q.512
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_maskz_srav_epi64
argument_list|(
name|__U
argument_list|,
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_srl_epi32
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_srl_epi32
comment|// CHECK: @llvm.x86.avx512.psrl.d.512
return|return
name|_mm512_srl_epi32
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_srl_epi32
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
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_srl_epi32
comment|// CHECK: @llvm.x86.avx512.psrl.d.512
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_mask_srl_epi32
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
name|test_mm512_maskz_srl_epi32
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_srl_epi32
comment|// CHECK: @llvm.x86.avx512.psrl.d.512
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_maskz_srl_epi32
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
name|test_mm512_srl_epi64
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_srl_epi64
comment|// CHECK: @llvm.x86.avx512.psrl.q.512
return|return
name|_mm512_srl_epi64
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_srl_epi64
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
comment|// CHECK-LABEL: @test_mm512_mask_srl_epi64
comment|// CHECK: @llvm.x86.avx512.psrl.q.512
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_mask_srl_epi64
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
name|test_mm512_maskz_srl_epi64
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
comment|// CHECK-LABEL: @test_mm512_maskz_srl_epi64
comment|// CHECK: @llvm.x86.avx512.psrl.q.512
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_maskz_srl_epi64
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
name|test_mm512_srlv_epi32
parameter_list|(
name|__m512i
name|__X
parameter_list|,
name|__m512i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_srlv_epi32
comment|// CHECK: @llvm.x86.avx512.psrlv.d.512
return|return
name|_mm512_srlv_epi32
argument_list|(
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_srlv_epi32
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512i
name|__X
parameter_list|,
name|__m512i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_srlv_epi32
comment|// CHECK: @llvm.x86.avx512.psrlv.d.512
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_mask_srlv_epi32
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_srlv_epi32
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512i
name|__X
parameter_list|,
name|__m512i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_srlv_epi32
comment|// CHECK: @llvm.x86.avx512.psrlv.d.512
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_maskz_srlv_epi32
argument_list|(
name|__U
argument_list|,
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_srlv_epi64
parameter_list|(
name|__m512i
name|__X
parameter_list|,
name|__m512i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_srlv_epi64
comment|// CHECK: @llvm.x86.avx512.psrlv.q.512
return|return
name|_mm512_srlv_epi64
argument_list|(
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_srlv_epi64
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__X
parameter_list|,
name|__m512i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_srlv_epi64
comment|// CHECK: @llvm.x86.avx512.psrlv.q.512
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_mask_srlv_epi64
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_srlv_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__X
parameter_list|,
name|__m512i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_srlv_epi64
comment|// CHECK: @llvm.x86.avx512.psrlv.q.512
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_maskz_srlv_epi64
argument_list|(
name|__U
argument_list|,
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_ternarylogic_epi32
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|,
name|__m512i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_ternarylogic_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pternlog.d.512
return|return
name|_mm512_ternarylogic_epi32
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_ternarylogic_epi32
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512i
name|__B
parameter_list|,
name|__m512i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_ternarylogic_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pternlog.d.512
return|return
name|_mm512_mask_ternarylogic_epi32
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_ternarylogic_epi32
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|,
name|__m512i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_ternarylogic_epi32
comment|// CHECK: @llvm.x86.avx512.maskz.pternlog.d.512
return|return
name|_mm512_maskz_ternarylogic_epi32
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_ternarylogic_epi64
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|,
name|__m512i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_ternarylogic_epi64
comment|// CHECK: @llvm.x86.avx512.mask.pternlog.q.512
return|return
name|_mm512_ternarylogic_epi64
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_ternarylogic_epi64
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__B
parameter_list|,
name|__m512i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_ternarylogic_epi64
comment|// CHECK: @llvm.x86.avx512.mask.pternlog.q.512
return|return
name|_mm512_mask_ternarylogic_epi64
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_ternarylogic_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|,
name|__m512i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_ternarylogic_epi64
comment|// CHECK: @llvm.x86.avx512.maskz.pternlog.q.512
return|return
name|_mm512_maskz_ternarylogic_epi64
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_shuffle_f32x4
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_shuffle_f32x4
comment|// CHECK: @llvm.x86.avx512.mask.shuf.f32x4
return|return
name|_mm512_shuffle_f32x4
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
name|test_mm512_mask_shuffle_f32x4
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
comment|// CHECK-LABEL: @test_mm512_mask_shuffle_f32x4
comment|// CHECK: @llvm.x86.avx512.mask.shuf.f32x4
return|return
name|_mm512_mask_shuffle_f32x4
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
name|test_mm512_maskz_shuffle_f32x4
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
comment|// CHECK-LABEL: @test_mm512_maskz_shuffle_f32x4
comment|// CHECK: @llvm.x86.avx512.mask.shuf.f32x4
return|return
name|_mm512_maskz_shuffle_f32x4
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
name|test_mm512_shuffle_f64x2
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_shuffle_f64x2
comment|// CHECK: @llvm.x86.avx512.mask.shuf.f64x2
return|return
name|_mm512_shuffle_f64x2
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
name|test_mm512_mask_shuffle_f64x2
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
comment|// CHECK-LABEL: @test_mm512_mask_shuffle_f64x2
comment|// CHECK: @llvm.x86.avx512.mask.shuf.f64x2
return|return
name|_mm512_mask_shuffle_f64x2
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
name|test_mm512_maskz_shuffle_f64x2
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
comment|// CHECK-LABEL: @test_mm512_maskz_shuffle_f64x2
comment|// CHECK: @llvm.x86.avx512.mask.shuf.f64x2
return|return
name|_mm512_maskz_shuffle_f64x2
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
name|__m512i
name|test_mm512_shuffle_i32x4
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_shuffle_i32x4
comment|// CHECK: @llvm.x86.avx512.mask.shuf.i32x4
return|return
name|_mm512_shuffle_i32x4
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
name|__m512i
name|test_mm512_mask_shuffle_i32x4
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
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_shuffle_i32x4
comment|// CHECK: @llvm.x86.avx512.mask.shuf.i32x4
return|return
name|_mm512_mask_shuffle_i32x4
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
name|__m512i
name|test_mm512_maskz_shuffle_i32x4
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_shuffle_i32x4
comment|// CHECK: @llvm.x86.avx512.mask.shuf.i32x4
return|return
name|_mm512_maskz_shuffle_i32x4
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
name|__m512i
name|test_mm512_shuffle_i64x2
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_shuffle_i64x2
comment|// CHECK: @llvm.x86.avx512.mask.shuf.i64x2
return|return
name|_mm512_shuffle_i64x2
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
name|__m512i
name|test_mm512_mask_shuffle_i64x2
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
comment|// CHECK-LABEL: @test_mm512_mask_shuffle_i64x2
comment|// CHECK: @llvm.x86.avx512.mask.shuf.i64x2
return|return
name|_mm512_mask_shuffle_i64x2
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
name|__m512i
name|test_mm512_maskz_shuffle_i64x2
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
comment|// CHECK-LABEL: @test_mm512_maskz_shuffle_i64x2
comment|// CHECK: @llvm.x86.avx512.mask.shuf.i64x2
return|return
name|_mm512_maskz_shuffle_i64x2
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
name|test_mm512_shuffle_pd
parameter_list|(
name|__m512d
name|__M
parameter_list|,
name|__m512d
name|__V
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_shuffle_pd
comment|// CHECK: shufflevector<8 x double> %{{.*}},<8 x double> %{{.*}},<8 x i32><i32 0, i32 8, i32 3, i32 10, i32 4, i32 12, i32 6, i32 14>
return|return
name|_mm512_shuffle_pd
argument_list|(
name|__M
argument_list|,
name|__V
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_shuffle_pd
parameter_list|(
name|__m512d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__M
parameter_list|,
name|__m512d
name|__V
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_shuffle_pd
comment|// CHECK: shufflevector<8 x double> %{{.*}},<8 x double> %{{.*}},<8 x i32><i32 0, i32 8, i32 3, i32 10, i32 4, i32 12, i32 6, i32 14>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x double> %{{.*}},<8 x double> %{{.*}}
return|return
name|_mm512_mask_shuffle_pd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__M
argument_list|,
name|__V
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_maskz_shuffle_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__M
parameter_list|,
name|__m512d
name|__V
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_shuffle_pd
comment|// CHECK: shufflevector<8 x double> %{{.*}},<8 x double> %{{.*}},<8 x i32><i32 0, i32 8, i32 3, i32 10, i32 4, i32 12, i32 6, i32 14>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x double> %{{.*}},<8 x double> %{{.*}}
return|return
name|_mm512_maskz_shuffle_pd
argument_list|(
name|__U
argument_list|,
name|__M
argument_list|,
name|__V
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_shuffle_ps
parameter_list|(
name|__m512
name|__M
parameter_list|,
name|__m512
name|__V
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_shuffle_ps
comment|// CHECK: shufflevector<16 x float> %{{.*}},<16 x float> %{{.*}},<16 x i32><i32 0, i32 1, i32 16, i32 16, i32 4, i32 5, i32 20, i32 20, i32 8, i32 9, i32 24, i32 24, i32 12, i32 13, i32 28, i32 28>
return|return
name|_mm512_shuffle_ps
argument_list|(
name|__M
argument_list|,
name|__V
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_shuffle_ps
parameter_list|(
name|__m512
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__M
parameter_list|,
name|__m512
name|__V
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_shuffle_ps
comment|// CHECK: shufflevector<16 x float> %{{.*}},<16 x float> %{{.*}},<16 x i32><i32 0, i32 1, i32 16, i32 16, i32 4, i32 5, i32 20, i32 20, i32 8, i32 9, i32 24, i32 24, i32 12, i32 13, i32 28, i32 28>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x float> %{{.*}},<16 x float> %{{.*}}
return|return
name|_mm512_mask_shuffle_ps
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__M
argument_list|,
name|__V
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_maskz_shuffle_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__M
parameter_list|,
name|__m512
name|__V
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_shuffle_ps
comment|// CHECK: shufflevector<16 x float> %{{.*}},<16 x float> %{{.*}},<16 x i32><i32 0, i32 1, i32 16, i32 16, i32 4, i32 5, i32 20, i32 20, i32 8, i32 9, i32 24, i32 24, i32 12, i32 13, i32 28, i32 28>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x float> %{{.*}},<16 x float> %{{.*}}
return|return
name|_mm512_maskz_shuffle_ps
argument_list|(
name|__U
argument_list|,
name|__M
argument_list|,
name|__V
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_sqrt_round_sd
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_sqrt_round_sd
comment|// CHECK: @llvm.x86.avx512.mask.sqrt.sd
return|return
name|_mm_sqrt_round_sd
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
name|test_mm_mask_sqrt_sd
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
comment|// CHECK: @llvm.x86.avx512.mask.sqrt.sd
return|return
name|_mm_mask_sqrt_sd
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
name|__m128d
name|test_mm_mask_sqrt_round_sd
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
comment|// CHECK: @llvm.x86.avx512.mask.sqrt.sd
return|return
name|_mm_mask_sqrt_round_sd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_maskz_sqrt_sd
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
comment|// CHECK: @llvm.x86.avx512.mask.sqrt.sd
return|return
name|_mm_maskz_sqrt_sd
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
name|__m128d
name|test_mm_maskz_sqrt_round_sd
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
comment|// CHECK: @llvm.x86.avx512.mask.sqrt.sd
return|return
name|_mm_maskz_sqrt_round_sd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_sqrt_round_ss
parameter_list|(
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_sqrt_round_ss
comment|// CHECK: @llvm.x86.avx512.mask.sqrt.ss
return|return
name|_mm_sqrt_round_ss
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
name|test_mm_mask_sqrt_ss
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
comment|// CHECK: @llvm.x86.avx512.mask.sqrt.ss
return|return
name|_mm_mask_sqrt_ss
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
name|__m128
name|test_mm_mask_sqrt_round_ss
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
comment|// CHECK: @llvm.x86.avx512.mask.sqrt.ss
return|return
name|_mm_mask_sqrt_round_ss
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_maskz_sqrt_ss
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
comment|// CHECK: @llvm.x86.avx512.mask.sqrt.ss
return|return
name|_mm_maskz_sqrt_ss
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
name|__m128
name|test_mm_maskz_sqrt_round_ss
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
comment|// CHECK: @llvm.x86.avx512.mask.sqrt.ss
return|return
name|_mm_maskz_sqrt_round_ss
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_broadcast_f32x4
parameter_list|(
name|float
specifier|const
modifier|*
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_broadcast_f32x4
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> %{{.*}},<16 x i32><i32 0, i32 1, i32 2, i32 3, i32 0, i32 1, i32 2, i32 3, i32 0, i32 1, i32 2, i32 3, i32 0, i32 1, i32 2, i32 3>
return|return
name|_mm512_broadcast_f32x4
argument_list|(
name|_mm_loadu_ps
argument_list|(
name|__A
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_broadcast_f32x4
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
comment|// CHECK-LABEL: @test_mm512_mask_broadcast_f32x4
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> %{{.*}},<16 x i32><i32 0, i32 1, i32 2, i32 3, i32 0, i32 1, i32 2, i32 3, i32 0, i32 1, i32 2, i32 3, i32 0, i32 1, i32 2, i32 3>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x float> %{{.*}},<16 x float> %{{.*}}
return|return
name|_mm512_mask_broadcast_f32x4
argument_list|(
name|__O
argument_list|,
name|__M
argument_list|,
name|_mm_loadu_ps
argument_list|(
name|__A
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_maskz_broadcast_f32x4
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
comment|// CHECK-LABEL: @test_mm512_maskz_broadcast_f32x4
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> %{{.*}},<16 x i32><i32 0, i32 1, i32 2, i32 3, i32 0, i32 1, i32 2, i32 3, i32 0, i32 1, i32 2, i32 3, i32 0, i32 1, i32 2, i32 3>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x float> %{{.*}},<16 x float> %{{.*}}
return|return
name|_mm512_maskz_broadcast_f32x4
argument_list|(
name|__M
argument_list|,
name|_mm_loadu_ps
argument_list|(
name|__A
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_broadcast_f64x4
parameter_list|(
name|float
specifier|const
modifier|*
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_broadcast_f64x4
comment|// CHECK: shufflevector<4 x double> %{{.*}},<4 x double> %{{.*}},<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 0, i32 1, i32 2, i32 3>
return|return
name|_mm512_broadcast_f64x4
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
name|__m512d
name|test_mm512_mask_broadcast_f64x4
parameter_list|(
name|__m512d
name|__O
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|float
specifier|const
modifier|*
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_broadcast_f64x4
comment|// CHECK: shufflevector<4 x double> %{{.*}},<4 x double> %{{.*}},<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 0, i32 1, i32 2, i32 3>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x double> %{{.*}},<8 x double> %{{.*}}
return|return
name|_mm512_mask_broadcast_f64x4
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
name|__m512d
name|test_mm512_maskz_broadcast_f64x4
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|float
specifier|const
modifier|*
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_broadcast_f64x4
comment|// CHECK: shufflevector<4 x double> %{{.*}},<4 x double> %{{.*}},<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 0, i32 1, i32 2, i32 3>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x double> %{{.*}},<8 x double> %{{.*}}
return|return
name|_mm512_maskz_broadcast_f64x4
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
name|__m512i
name|test_mm512_broadcast_i32x4
parameter_list|(
name|__m128i
specifier|const
modifier|*
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_broadcast_i32x4
comment|// CHECK: shufflevector<4 x i32> %{{.*}},<4 x i32> %{{.*}},<16 x i32><i32 0, i32 1, i32 2, i32 3, i32 0, i32 1, i32 2, i32 3, i32 0, i32 1, i32 2, i32 3, i32 0, i32 1, i32 2, i32 3>
return|return
name|_mm512_broadcast_i32x4
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
name|test_mm512_mask_broadcast_i32x4
parameter_list|(
name|__m512i
name|__O
parameter_list|,
name|__mmask16
name|__M
parameter_list|,
name|__m128i
specifier|const
modifier|*
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_broadcast_i32x4
comment|// CHECK: shufflevector<4 x i32> %{{.*}},<4 x i32> %{{.*}},<16 x i32><i32 0, i32 1, i32 2, i32 3, i32 0, i32 1, i32 2, i32 3, i32 0, i32 1, i32 2, i32 3, i32 0, i32 1, i32 2, i32 3>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_mask_broadcast_i32x4
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
name|test_mm512_maskz_broadcast_i32x4
parameter_list|(
name|__mmask16
name|__M
parameter_list|,
name|__m128i
specifier|const
modifier|*
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_broadcast_i32x4
comment|// CHECK: shufflevector<4 x i32> %{{.*}},<4 x i32> %{{.*}},<16 x i32><i32 0, i32 1, i32 2, i32 3, i32 0, i32 1, i32 2, i32 3, i32 0, i32 1, i32 2, i32 3, i32 0, i32 1, i32 2, i32 3>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_maskz_broadcast_i32x4
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
name|__m512i
name|test_mm512_broadcast_i64x4
parameter_list|(
name|__m256i
specifier|const
modifier|*
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_broadcast_i64x4
comment|// CHECK: shufflevector<4 x i64> %{{.*}},<4 x i64> %{{.*}},<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 0, i32 1, i32 2, i32 3>
return|return
name|_mm512_broadcast_i64x4
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
name|test_mm512_mask_broadcast_i64x4
parameter_list|(
name|__m512i
name|__O
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m256i
specifier|const
modifier|*
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_broadcast_i64x4
comment|// CHECK: shufflevector<4 x i64> %{{.*}},<4 x i64> %{{.*}},<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 0, i32 1, i32 2, i32 3>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_mask_broadcast_i64x4
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
name|test_mm512_maskz_broadcast_i64x4
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m256i
specifier|const
modifier|*
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_broadcast_i64x4
comment|// CHECK: shufflevector<4 x i64> %{{.*}},<4 x i64> %{{.*}},<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 0, i32 1, i32 2, i32 3>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_maskz_broadcast_i64x4
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
name|__m512d
name|test_mm512_broadcastsd_pd
parameter_list|(
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_broadcastsd_pd
comment|// CHECK: shufflevector<2 x double> %{{.*}},<2 x double> zeroinitializer,<8 x i32> zeroinitializer
return|return
name|_mm512_broadcastsd_pd
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_broadcastsd_pd
parameter_list|(
name|__m512d
name|__O
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_broadcastsd_pd
comment|// CHECK: shufflevector<2 x double> %{{.*}},<2 x double> zeroinitializer,<8 x i32> zeroinitializer
comment|// CHECK: select<8 x i1> %{{.*}},<8 x double> %{{.*}},<8 x double> %{{.*}}
return|return
name|_mm512_mask_broadcastsd_pd
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
name|__m512d
name|test_mm512_maskz_broadcastsd_pd
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_broadcastsd_pd
comment|// CHECK: shufflevector<2 x double> %{{.*}},<2 x double> zeroinitializer,<8 x i32> zeroinitializer
comment|// CHECK: select<8 x i1> %{{.*}},<8 x double> %{{.*}},<8 x double> %{{.*}}
return|return
name|_mm512_maskz_broadcastsd_pd
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
name|test_mm512_broadcastss_ps
parameter_list|(
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_broadcastss_ps
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> zeroinitializer,<16 x i32> zeroinitializer
return|return
name|_mm512_broadcastss_ps
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_broadcastss_ps
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
comment|// CHECK-LABEL: @test_mm512_mask_broadcastss_ps
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> zeroinitializer,<16 x i32> zeroinitializer
comment|// CHECK: select<16 x i1> %{{.*}},<16 x float> %{{.*}},<16 x float> %{{.*}}
return|return
name|_mm512_mask_broadcastss_ps
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
name|test_mm512_maskz_broadcastss_ps
parameter_list|(
name|__mmask16
name|__M
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_broadcastss_ps
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> zeroinitializer,<16 x i32> zeroinitializer
comment|// CHECK: select<16 x i1> %{{.*}},<16 x float> %{{.*}},<16 x float> %{{.*}}
return|return
name|_mm512_maskz_broadcastss_ps
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
name|test_mm512_broadcastd_epi32
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_broadcastd_epi32
comment|// CHECK: shufflevector<4 x i32> %{{.*}},<4 x i32> zeroinitializer,<16 x i32> zeroinitializer
return|return
name|_mm512_broadcastd_epi32
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_broadcastd_epi32
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
comment|// CHECK-LABEL: @test_mm512_mask_broadcastd_epi32
comment|// CHECK: shufflevector<4 x i32> %{{.*}},<4 x i32> zeroinitializer,<16 x i32> zeroinitializer
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_mask_broadcastd_epi32
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
name|test_mm512_maskz_broadcastd_epi32
parameter_list|(
name|__mmask16
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_broadcastd_epi32
comment|// CHECK: shufflevector<4 x i32> %{{.*}},<4 x i32> zeroinitializer,<16 x i32> zeroinitializer
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_maskz_broadcastd_epi32
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
name|test_mm512_broadcastq_epi64
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_broadcastq_epi64
comment|// CHECK: shufflevector<2 x i64> %{{.*}},<2 x i64> zeroinitializer,<8 x i32> zeroinitializer
return|return
name|_mm512_broadcastq_epi64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_broadcastq_epi64
parameter_list|(
name|__m512i
name|__O
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_broadcastq_epi64
comment|// CHECK: shufflevector<2 x i64> %{{.*}},<2 x i64> zeroinitializer,<8 x i32> zeroinitializer
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_mask_broadcastq_epi64
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
name|test_mm512_maskz_broadcastq_epi64
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_broadcastq_epi64
comment|// CHECK: shufflevector<2 x i64> %{{.*}},<2 x i64> zeroinitializer,<8 x i32> zeroinitializer
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_maskz_broadcastq_epi64
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm512_cvtsepi32_epi8
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtsepi32_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.db.512
return|return
name|_mm512_cvtsepi32_epi8
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm512_mask_cvtsepi32_epi8
parameter_list|(
name|__m128i
name|__O
parameter_list|,
name|__mmask16
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtsepi32_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.db.512
return|return
name|_mm512_mask_cvtsepi32_epi8
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
name|__m128i
name|test_mm512_maskz_cvtsepi32_epi8
parameter_list|(
name|__mmask16
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtsepi32_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.db.512
return|return
name|_mm512_maskz_cvtsepi32_epi8
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm512_mask_cvtsepi32_storeu_epi8
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask16
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtsepi32_storeu_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.db.mem.512
return|return
name|_mm512_mask_cvtsepi32_storeu_epi8
argument_list|(
name|__P
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm512_cvtsepi32_epi16
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtsepi32_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.dw.512
return|return
name|_mm512_cvtsepi32_epi16
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm512_mask_cvtsepi32_epi16
parameter_list|(
name|__m256i
name|__O
parameter_list|,
name|__mmask16
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtsepi32_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.dw.512
return|return
name|_mm512_mask_cvtsepi32_epi16
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
name|__m256i
name|test_mm512_maskz_cvtsepi32_epi16
parameter_list|(
name|__mmask16
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtsepi32_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.dw.512
return|return
name|_mm512_maskz_cvtsepi32_epi16
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm512_mask_cvtsepi32_storeu_epi16
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask16
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtsepi32_storeu_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.dw.mem.512
return|return
name|_mm512_mask_cvtsepi32_storeu_epi16
argument_list|(
name|__P
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm512_cvtsepi64_epi8
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtsepi64_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.qb.512
return|return
name|_mm512_cvtsepi64_epi8
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm512_mask_cvtsepi64_epi8
parameter_list|(
name|__m128i
name|__O
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtsepi64_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.qb.512
return|return
name|_mm512_mask_cvtsepi64_epi8
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
name|__m128i
name|test_mm512_maskz_cvtsepi64_epi8
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtsepi64_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.qb.512
return|return
name|_mm512_maskz_cvtsepi64_epi8
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm512_mask_cvtsepi64_storeu_epi8
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtsepi64_storeu_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.qb.mem.512
return|return
name|_mm512_mask_cvtsepi64_storeu_epi8
argument_list|(
name|__P
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm512_cvtsepi64_epi32
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtsepi64_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.qd.512
return|return
name|_mm512_cvtsepi64_epi32
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm512_mask_cvtsepi64_epi32
parameter_list|(
name|__m256i
name|__O
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtsepi64_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.qd.512
return|return
name|_mm512_mask_cvtsepi64_epi32
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
name|__m256i
name|test_mm512_maskz_cvtsepi64_epi32
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtsepi64_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.qd.512
return|return
name|_mm512_maskz_cvtsepi64_epi32
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm512_mask_cvtsepi64_storeu_epi32
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtsepi64_storeu_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.qd.mem.512
return|return
name|_mm512_mask_cvtsepi64_storeu_epi32
argument_list|(
name|__P
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm512_cvtsepi64_epi16
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtsepi64_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.qw.512
return|return
name|_mm512_cvtsepi64_epi16
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm512_mask_cvtsepi64_epi16
parameter_list|(
name|__m128i
name|__O
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtsepi64_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.qw.512
return|return
name|_mm512_mask_cvtsepi64_epi16
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
name|__m128i
name|test_mm512_maskz_cvtsepi64_epi16
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtsepi64_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.qw.512
return|return
name|_mm512_maskz_cvtsepi64_epi16
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm512_mask_cvtsepi64_storeu_epi16
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtsepi64_storeu_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.qw.mem.512
return|return
name|_mm512_mask_cvtsepi64_storeu_epi16
argument_list|(
name|__P
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm512_cvtusepi32_epi8
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtusepi32_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.db.512
return|return
name|_mm512_cvtusepi32_epi8
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm512_mask_cvtusepi32_epi8
parameter_list|(
name|__m128i
name|__O
parameter_list|,
name|__mmask16
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtusepi32_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.db.512
return|return
name|_mm512_mask_cvtusepi32_epi8
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
name|__m128i
name|test_mm512_maskz_cvtusepi32_epi8
parameter_list|(
name|__mmask16
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtusepi32_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.db.512
return|return
name|_mm512_maskz_cvtusepi32_epi8
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm512_mask_cvtusepi32_storeu_epi8
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask16
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtusepi32_storeu_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.db.mem.512
return|return
name|_mm512_mask_cvtusepi32_storeu_epi8
argument_list|(
name|__P
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm512_cvtusepi32_epi16
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtusepi32_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.dw.512
return|return
name|_mm512_cvtusepi32_epi16
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm512_mask_cvtusepi32_epi16
parameter_list|(
name|__m256i
name|__O
parameter_list|,
name|__mmask16
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtusepi32_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.dw.512
return|return
name|_mm512_mask_cvtusepi32_epi16
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
name|__m256i
name|test_mm512_maskz_cvtusepi32_epi16
parameter_list|(
name|__mmask16
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtusepi32_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.dw.512
return|return
name|_mm512_maskz_cvtusepi32_epi16
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm512_mask_cvtusepi32_storeu_epi16
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask16
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtusepi32_storeu_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.dw.mem.512
return|return
name|_mm512_mask_cvtusepi32_storeu_epi16
argument_list|(
name|__P
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm512_cvtusepi64_epi8
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtusepi64_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.qb.512
return|return
name|_mm512_cvtusepi64_epi8
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm512_mask_cvtusepi64_epi8
parameter_list|(
name|__m128i
name|__O
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtusepi64_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.qb.512
return|return
name|_mm512_mask_cvtusepi64_epi8
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
name|__m128i
name|test_mm512_maskz_cvtusepi64_epi8
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtusepi64_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.qb.512
return|return
name|_mm512_maskz_cvtusepi64_epi8
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm512_mask_cvtusepi64_storeu_epi8
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtusepi64_storeu_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.qb.mem.512
return|return
name|_mm512_mask_cvtusepi64_storeu_epi8
argument_list|(
name|__P
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm512_cvtusepi64_epi32
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtusepi64_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.qd.512
return|return
name|_mm512_cvtusepi64_epi32
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm512_mask_cvtusepi64_epi32
parameter_list|(
name|__m256i
name|__O
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtusepi64_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.qd.512
return|return
name|_mm512_mask_cvtusepi64_epi32
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
name|__m256i
name|test_mm512_maskz_cvtusepi64_epi32
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtusepi64_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.qd.512
return|return
name|_mm512_maskz_cvtusepi64_epi32
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm512_mask_cvtusepi64_storeu_epi32
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtusepi64_storeu_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.qd.mem.512
return|return
name|_mm512_mask_cvtusepi64_storeu_epi32
argument_list|(
name|__P
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm512_cvtusepi64_epi16
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtusepi64_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.qw.512
return|return
name|_mm512_cvtusepi64_epi16
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm512_mask_cvtusepi64_epi16
parameter_list|(
name|__m128i
name|__O
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtusepi64_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.qw.512
return|return
name|_mm512_mask_cvtusepi64_epi16
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
name|__m128i
name|test_mm512_maskz_cvtusepi64_epi16
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtusepi64_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.qw.512
return|return
name|_mm512_maskz_cvtusepi64_epi16
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm512_mask_cvtusepi64_storeu_epi16
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtusepi64_storeu_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.qw.mem.512
return|return
name|_mm512_mask_cvtusepi64_storeu_epi16
argument_list|(
name|__P
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm512_cvtepi32_epi8
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtepi32_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmov.db.512
return|return
name|_mm512_cvtepi32_epi8
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm512_mask_cvtepi32_epi8
parameter_list|(
name|__m128i
name|__O
parameter_list|,
name|__mmask16
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtepi32_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmov.db.512
return|return
name|_mm512_mask_cvtepi32_epi8
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
name|__m128i
name|test_mm512_maskz_cvtepi32_epi8
parameter_list|(
name|__mmask16
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtepi32_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmov.db.512
return|return
name|_mm512_maskz_cvtepi32_epi8
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm512_mask_cvtepi32_storeu_epi8
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask16
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtepi32_storeu_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmov.db.mem.512
return|return
name|_mm512_mask_cvtepi32_storeu_epi8
argument_list|(
name|__P
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm512_cvtepi32_epi16
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtepi32_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmov.dw.512
return|return
name|_mm512_cvtepi32_epi16
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm512_mask_cvtepi32_epi16
parameter_list|(
name|__m256i
name|__O
parameter_list|,
name|__mmask16
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtepi32_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmov.dw.512
return|return
name|_mm512_mask_cvtepi32_epi16
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
name|__m256i
name|test_mm512_maskz_cvtepi32_epi16
parameter_list|(
name|__mmask16
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtepi32_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmov.dw.512
return|return
name|_mm512_maskz_cvtepi32_epi16
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm512_mask_cvtepi32_storeu_epi16
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask16
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtepi32_storeu_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmov.dw.mem.512
return|return
name|_mm512_mask_cvtepi32_storeu_epi16
argument_list|(
name|__P
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm512_cvtepi64_epi8
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtepi64_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmov.qb.512
return|return
name|_mm512_cvtepi64_epi8
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm512_mask_cvtepi64_epi8
parameter_list|(
name|__m128i
name|__O
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtepi64_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmov.qb.512
return|return
name|_mm512_mask_cvtepi64_epi8
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
name|__m128i
name|test_mm512_maskz_cvtepi64_epi8
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtepi64_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmov.qb.512
return|return
name|_mm512_maskz_cvtepi64_epi8
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm512_mask_cvtepi64_storeu_epi8
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtepi64_storeu_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmov.qb.mem.512
return|return
name|_mm512_mask_cvtepi64_storeu_epi8
argument_list|(
name|__P
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm512_cvtepi64_epi32
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtepi64_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pmov.qd.512
return|return
name|_mm512_cvtepi64_epi32
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm512_mask_cvtepi64_epi32
parameter_list|(
name|__m256i
name|__O
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtepi64_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pmov.qd.512
return|return
name|_mm512_mask_cvtepi64_epi32
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
name|__m256i
name|test_mm512_maskz_cvtepi64_epi32
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtepi64_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pmov.qd.512
return|return
name|_mm512_maskz_cvtepi64_epi32
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm512_mask_cvtepi64_storeu_epi32
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtepi64_storeu_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pmov.qd.mem.512
return|return
name|_mm512_mask_cvtepi64_storeu_epi32
argument_list|(
name|__P
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm512_cvtepi64_epi16
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtepi64_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmov.qw.512
return|return
name|_mm512_cvtepi64_epi16
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm512_mask_cvtepi64_epi16
parameter_list|(
name|__m128i
name|__O
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtepi64_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmov.qw.512
return|return
name|_mm512_mask_cvtepi64_epi16
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
name|__m128i
name|test_mm512_maskz_cvtepi64_epi16
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtepi64_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmov.qw.512
return|return
name|_mm512_maskz_cvtepi64_epi16
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm512_mask_cvtepi64_storeu_epi16
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtepi64_storeu_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmov.qw.mem.512
return|return
name|_mm512_mask_cvtepi64_storeu_epi16
argument_list|(
name|__P
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm512_extracti32x4_epi32
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_extracti32x4_epi32
comment|// CHECK: shufflevector<16 x i32> %{{.*}},<16 x i32> %{{.*}},<4 x i32><i32 12, i32 13, i32 14, i32 15>
return|return
name|_mm512_extracti32x4_epi32
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
name|test_mm512_mask_extracti32x4_epi32
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
comment|// CHECK-LABEL: @test_mm512_mask_extracti32x4_epi32
comment|// CHECK: shufflevector<16 x i32> %{{.*}},<16 x i32> %{{.*}},<4 x i32><i32 12, i32 13, i32 14, i32 15>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm512_mask_extracti32x4_epi32
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
name|test_mm512_maskz_extracti32x4_epi32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_extracti32x4_epi32
comment|// CHECK: shufflevector<16 x i32> %{{.*}},<16 x i32> %{{.*}},<4 x i32><i32 12, i32 13, i32 14, i32 15>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm512_maskz_extracti32x4_epi32
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
name|test_mm512_extracti64x4_epi64
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_extracti64x4_epi64
comment|// CHECK: shufflevector<8 x i64> %{{.*}},<8 x i64> zeroinitializer,<4 x i32><i32 4, i32 5, i32 6, i32 7>
return|return
name|_mm512_extracti64x4_epi64
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
name|test_mm512_mask_extracti64x4_epi64
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
comment|// CHECK-LABEL: @test_mm512_mask_extracti64x4_epi64
comment|// CHECK: shufflevector<8 x i64> %{{.*}},<8 x i64> zeroinitializer,<4 x i32><i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm512_mask_extracti64x4_epi64
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
name|test_mm512_maskz_extracti64x4_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_extracti64x4_epi64
comment|// CHECK: shufflevector<8 x i64> %{{.*}},<8 x i64> zeroinitializer,<4 x i32><i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm512_maskz_extracti64x4_epi64
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
name|__m512d
name|test_mm512_insertf64x4
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__m256d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_insertf64x4
comment|// CHECK: shufflevector<8 x double> %{{.*}},<8 x double> %{{.*}},<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 8, i32 9, i32 10, i32 11>
return|return
name|_mm512_insertf64x4
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
name|__m512d
name|test_mm512_mask_insertf64x4
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
name|__m256d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_insertf64x4
comment|// CHECK: shufflevector<8 x double> %{{.*}},<8 x double> %{{.*}},<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 8, i32 9, i32 10, i32 11>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x double> %{{.*}},<8 x double> %{{.*}}
return|return
name|_mm512_mask_insertf64x4
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
name|__m512d
name|test_mm512_maskz_insertf64x4
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|,
name|__m256d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_insertf64x4
comment|// CHECK: shufflevector<8 x double> %{{.*}},<8 x double> %{{.*}},<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 8, i32 9, i32 10, i32 11>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x double> %{{.*}},<8 x double> %{{.*}}
return|return
name|_mm512_maskz_insertf64x4
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
name|test_mm512_inserti64x4
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_inserti64x4
comment|// CHECK: shufflevector<8 x i64> %{{.*}},<8 x i64> %{{.*}},<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 8, i32 9, i32 10, i32 11>
return|return
name|_mm512_inserti64x4
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
name|test_mm512_mask_inserti64x4
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
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_inserti64x4
comment|// CHECK: shufflevector<8 x i64> %{{.*}},<8 x i64> %{{.*}},<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 8, i32 9, i32 10, i32 11>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_mask_inserti64x4
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
name|test_mm512_maskz_inserti64x4
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_inserti64x4
comment|// CHECK: shufflevector<8 x i64> %{{.*}},<8 x i64> %{{.*}},<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 8, i32 9, i32 10, i32 11>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_maskz_inserti64x4
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
name|__m512
name|test_mm512_insertf32x4
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_insertf32x4
comment|// CHECK: shufflevector<16 x float> %{{.*}},<16 x float> %{{.*}},<16 x i32><i32 0, i32 1, i32 2, i32 3, i32 16, i32 17, i32 18, i32 19, i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15>
return|return
name|_mm512_insertf32x4
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
name|test_mm512_mask_insertf32x4
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
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_insertf32x4
comment|// CHECK: shufflevector<16 x float> %{{.*}},<16 x float> %{{.*}},<16 x i32><i32 0, i32 1, i32 2, i32 3, i32 16, i32 17, i32 18, i32 19, i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x float> %{{.*}},<16 x float> %{{.*}}
return|return
name|_mm512_mask_insertf32x4
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
name|test_mm512_maskz_insertf32x4
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_insertf32x4
comment|// CHECK: shufflevector<16 x float> %{{.*}},<16 x float> %{{.*}},<16 x i32><i32 0, i32 1, i32 2, i32 3, i32 16, i32 17, i32 18, i32 19, i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x float> %{{.*}},<16 x float> %{{.*}}
return|return
name|_mm512_maskz_insertf32x4
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
name|test_mm512_inserti32x4
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_inserti32x4
comment|// CHECK: shufflevector<16 x i32> %{{.*}},<16 x i32> %{{.*}},<16 x i32><i32 0, i32 1, i32 2, i32 3, i32 16, i32 17, i32 18, i32 19, i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15>
return|return
name|_mm512_inserti32x4
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
name|test_mm512_mask_inserti32x4
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
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_inserti32x4
comment|// CHECK: shufflevector<16 x i32> %{{.*}},<16 x i32> %{{.*}},<16 x i32><i32 0, i32 1, i32 2, i32 3, i32 16, i32 17, i32 18, i32 19, i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_mask_inserti32x4
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
name|test_mm512_maskz_inserti32x4
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_inserti32x4
comment|// CHECK: shufflevector<16 x i32> %{{.*}},<16 x i32> %{{.*}},<16 x i32><i32 0, i32 1, i32 2, i32 3, i32 16, i32 17, i32 18, i32 19, i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_maskz_inserti32x4
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
name|test_mm512_getmant_round_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_getmant_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.getmant.pd.512
return|return
name|_mm512_getmant_round_pd
argument_list|(
name|__A
argument_list|,
name|_MM_MANT_NORM_p5_2
argument_list|,
name|_MM_MANT_SIGN_nan
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_getmant_round_pd
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
comment|// CHECK-LABEL: @test_mm512_mask_getmant_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.getmant.pd.512
return|return
name|_mm512_mask_getmant_round_pd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_MANT_NORM_p5_2
argument_list|,
name|_MM_MANT_SIGN_nan
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_maskz_getmant_round_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_getmant_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.getmant.pd.512
return|return
name|_mm512_maskz_getmant_round_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_MANT_NORM_p5_2
argument_list|,
name|_MM_MANT_SIGN_nan
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_getmant_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_getmant_pd
comment|// CHECK: @llvm.x86.avx512.mask.getmant.pd.512
return|return
name|_mm512_getmant_pd
argument_list|(
name|__A
argument_list|,
name|_MM_MANT_NORM_p5_2
argument_list|,
name|_MM_MANT_SIGN_nan
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_getmant_pd
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
comment|// CHECK-LABEL: @test_mm512_mask_getmant_pd
comment|// CHECK: @llvm.x86.avx512.mask.getmant.pd.512
return|return
name|_mm512_mask_getmant_pd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_MANT_NORM_p5_2
argument_list|,
name|_MM_MANT_SIGN_nan
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_maskz_getmant_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_getmant_pd
comment|// CHECK: @llvm.x86.avx512.mask.getmant.pd.512
return|return
name|_mm512_maskz_getmant_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_MANT_NORM_p5_2
argument_list|,
name|_MM_MANT_SIGN_nan
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_getmant_round_ps
parameter_list|(
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_getmant_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.getmant.ps.512
return|return
name|_mm512_getmant_round_ps
argument_list|(
name|__A
argument_list|,
name|_MM_MANT_NORM_p5_2
argument_list|,
name|_MM_MANT_SIGN_nan
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_getmant_round_ps
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
comment|// CHECK-LABEL: @test_mm512_mask_getmant_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.getmant.ps.512
return|return
name|_mm512_mask_getmant_round_ps
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_MANT_NORM_p5_2
argument_list|,
name|_MM_MANT_SIGN_nan
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_maskz_getmant_round_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_getmant_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.getmant.ps.512
return|return
name|_mm512_maskz_getmant_round_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_MANT_NORM_p5_2
argument_list|,
name|_MM_MANT_SIGN_nan
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_getmant_ps
parameter_list|(
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_getmant_ps
comment|// CHECK: @llvm.x86.avx512.mask.getmant.ps.512
return|return
name|_mm512_getmant_ps
argument_list|(
name|__A
argument_list|,
name|_MM_MANT_NORM_p5_2
argument_list|,
name|_MM_MANT_SIGN_nan
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_getmant_ps
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
comment|// CHECK-LABEL: @test_mm512_mask_getmant_ps
comment|// CHECK: @llvm.x86.avx512.mask.getmant.ps.512
return|return
name|_mm512_mask_getmant_ps
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_MANT_NORM_p5_2
argument_list|,
name|_MM_MANT_SIGN_nan
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_maskz_getmant_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_getmant_ps
comment|// CHECK: @llvm.x86.avx512.mask.getmant.ps.512
return|return
name|_mm512_maskz_getmant_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_MANT_NORM_p5_2
argument_list|,
name|_MM_MANT_SIGN_nan
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_getexp_round_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_getexp_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.getexp.pd.512
return|return
name|_mm512_getexp_round_pd
argument_list|(
name|__A
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_getexp_round_pd
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
comment|// CHECK-LABEL: @test_mm512_mask_getexp_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.getexp.pd.512
return|return
name|_mm512_mask_getexp_round_pd
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
name|__m512d
name|test_mm512_maskz_getexp_round_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_getexp_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.getexp.pd.512
return|return
name|_mm512_maskz_getexp_round_pd
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
name|test_mm512_getexp_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_getexp_pd
comment|// CHECK: @llvm.x86.avx512.mask.getexp.pd.512
return|return
name|_mm512_getexp_pd
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_getexp_pd
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
comment|// CHECK-LABEL: @test_mm512_mask_getexp_pd
comment|// CHECK: @llvm.x86.avx512.mask.getexp.pd.512
return|return
name|_mm512_mask_getexp_pd
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
name|test_mm512_maskz_getexp_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_getexp_pd
comment|// CHECK: @llvm.x86.avx512.mask.getexp.pd.512
return|return
name|_mm512_maskz_getexp_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_getexp_round_ps
parameter_list|(
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_getexp_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.getexp.ps.512
return|return
name|_mm512_getexp_round_ps
argument_list|(
name|__A
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_getexp_round_ps
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
comment|// CHECK-LABEL: @test_mm512_mask_getexp_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.getexp.ps.512
return|return
name|_mm512_mask_getexp_round_ps
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
name|__m512
name|test_mm512_maskz_getexp_round_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_getexp_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.getexp.ps.512
return|return
name|_mm512_maskz_getexp_round_ps
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
name|__m512
name|test_mm512_getexp_ps
parameter_list|(
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_getexp_ps
comment|// CHECK: @llvm.x86.avx512.mask.getexp.ps.512
return|return
name|_mm512_getexp_ps
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_getexp_ps
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
comment|// CHECK-LABEL: @test_mm512_mask_getexp_ps
comment|// CHECK: @llvm.x86.avx512.mask.getexp.ps.512
return|return
name|_mm512_mask_getexp_ps
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
name|__m512
name|test_mm512_maskz_getexp_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_getexp_ps
comment|// CHECK: @llvm.x86.avx512.mask.getexp.ps.512
return|return
name|_mm512_maskz_getexp_ps
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
name|test_mm512_i64gather_ps
parameter_list|(
name|__m512i
name|__index
parameter_list|,
name|void
specifier|const
modifier|*
name|__addr
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_i64gather_ps
comment|// CHECK: @llvm.x86.avx512.gather.qps.512
return|return
name|_mm512_i64gather_ps
argument_list|(
name|__index
argument_list|,
name|__addr
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm512_mask_i64gather_ps
parameter_list|(
name|__m256
name|__v1_old
parameter_list|,
name|__mmask8
name|__mask
parameter_list|,
name|__m512i
name|__index
parameter_list|,
name|void
specifier|const
modifier|*
name|__addr
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_i64gather_ps
comment|// CHECK: @llvm.x86.avx512.gather.qps.512
return|return
name|_mm512_mask_i64gather_ps
argument_list|(
name|__v1_old
argument_list|,
name|__mask
argument_list|,
name|__index
argument_list|,
name|__addr
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm512_i64gather_epi32
parameter_list|(
name|__m512i
name|__index
parameter_list|,
name|void
specifier|const
modifier|*
name|__addr
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_i64gather_epi32
comment|// CHECK: @llvm.x86.avx512.gather.qpi.512
return|return
name|_mm512_i64gather_epi32
argument_list|(
name|__index
argument_list|,
name|__addr
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm512_mask_i64gather_epi32
parameter_list|(
name|__m256i
name|__v1_old
parameter_list|,
name|__mmask8
name|__mask
parameter_list|,
name|__m512i
name|__index
parameter_list|,
name|void
specifier|const
modifier|*
name|__addr
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_i64gather_epi32
comment|// CHECK: @llvm.x86.avx512.gather.qpi.512
return|return
name|_mm512_mask_i64gather_epi32
argument_list|(
name|__v1_old
argument_list|,
name|__mask
argument_list|,
name|__index
argument_list|,
name|__addr
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_i64gather_pd
parameter_list|(
name|__m512i
name|__index
parameter_list|,
name|void
specifier|const
modifier|*
name|__addr
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_i64gather_pd
comment|// CHECK: @llvm.x86.avx512.gather.qpd.512
return|return
name|_mm512_i64gather_pd
argument_list|(
name|__index
argument_list|,
name|__addr
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_i64gather_pd
parameter_list|(
name|__m512d
name|__v1_old
parameter_list|,
name|__mmask8
name|__mask
parameter_list|,
name|__m512i
name|__index
parameter_list|,
name|void
specifier|const
modifier|*
name|__addr
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_i64gather_pd
comment|// CHECK: @llvm.x86.avx512.gather.qpd.512
return|return
name|_mm512_mask_i64gather_pd
argument_list|(
name|__v1_old
argument_list|,
name|__mask
argument_list|,
name|__index
argument_list|,
name|__addr
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_i64gather_epi64
parameter_list|(
name|__m512i
name|__index
parameter_list|,
name|void
specifier|const
modifier|*
name|__addr
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_i64gather_epi64
comment|// CHECK: @llvm.x86.avx512.gather.qpq.512
return|return
name|_mm512_i64gather_epi64
argument_list|(
name|__index
argument_list|,
name|__addr
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_i64gather_epi64
parameter_list|(
name|__m512i
name|__v1_old
parameter_list|,
name|__mmask8
name|__mask
parameter_list|,
name|__m512i
name|__index
parameter_list|,
name|void
specifier|const
modifier|*
name|__addr
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_i64gather_epi64
comment|// CHECK: @llvm.x86.avx512.gather.qpq.512
return|return
name|_mm512_mask_i64gather_epi64
argument_list|(
name|__v1_old
argument_list|,
name|__mask
argument_list|,
name|__index
argument_list|,
name|__addr
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_i32gather_ps
parameter_list|(
name|__m512i
name|__index
parameter_list|,
name|void
specifier|const
modifier|*
name|__addr
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_i32gather_ps
comment|// CHECK: @llvm.x86.avx512.gather.dps.512
return|return
name|_mm512_i32gather_ps
argument_list|(
name|__index
argument_list|,
name|__addr
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_i32gather_ps
parameter_list|(
name|__m512
name|v1_old
parameter_list|,
name|__mmask16
name|__mask
parameter_list|,
name|__m512i
name|__index
parameter_list|,
name|void
specifier|const
modifier|*
name|__addr
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_i32gather_ps
comment|// CHECK: @llvm.x86.avx512.gather.dps.512
return|return
name|_mm512_mask_i32gather_ps
argument_list|(
name|v1_old
argument_list|,
name|__mask
argument_list|,
name|__index
argument_list|,
name|__addr
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_i32gather_epi32
parameter_list|(
name|__m512i
name|__index
parameter_list|,
name|void
specifier|const
modifier|*
name|__addr
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_i32gather_epi32
comment|// CHECK: @llvm.x86.avx512.gather.dpi.512
return|return
name|_mm512_i32gather_epi32
argument_list|(
name|__index
argument_list|,
name|__addr
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_i32gather_epi32
parameter_list|(
name|__m512i
name|__v1_old
parameter_list|,
name|__mmask16
name|__mask
parameter_list|,
name|__m512i
name|__index
parameter_list|,
name|void
specifier|const
modifier|*
name|__addr
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_i32gather_epi32
comment|// CHECK: @llvm.x86.avx512.gather.dpi.512
return|return
name|_mm512_mask_i32gather_epi32
argument_list|(
name|__v1_old
argument_list|,
name|__mask
argument_list|,
name|__index
argument_list|,
name|__addr
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_i32gather_pd
parameter_list|(
name|__m256i
name|__index
parameter_list|,
name|void
specifier|const
modifier|*
name|__addr
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_i32gather_pd
comment|// CHECK: @llvm.x86.avx512.gather.dpd.512
return|return
name|_mm512_i32gather_pd
argument_list|(
name|__index
argument_list|,
name|__addr
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_i32gather_pd
parameter_list|(
name|__m512d
name|__v1_old
parameter_list|,
name|__mmask8
name|__mask
parameter_list|,
name|__m256i
name|__index
parameter_list|,
name|void
specifier|const
modifier|*
name|__addr
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_i32gather_pd
comment|// CHECK: @llvm.x86.avx512.gather.dpd.512
return|return
name|_mm512_mask_i32gather_pd
argument_list|(
name|__v1_old
argument_list|,
name|__mask
argument_list|,
name|__index
argument_list|,
name|__addr
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_i32gather_epi64
parameter_list|(
name|__m256i
name|__index
parameter_list|,
name|void
specifier|const
modifier|*
name|__addr
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_i32gather_epi64
comment|// CHECK: @llvm.x86.avx512.gather.dpq.512
return|return
name|_mm512_i32gather_epi64
argument_list|(
name|__index
argument_list|,
name|__addr
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_i32gather_epi64
parameter_list|(
name|__m512i
name|__v1_old
parameter_list|,
name|__mmask8
name|__mask
parameter_list|,
name|__m256i
name|__index
parameter_list|,
name|void
specifier|const
modifier|*
name|__addr
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_i32gather_epi64
comment|// CHECK: @llvm.x86.avx512.gather.dpq.512
return|return
name|_mm512_mask_i32gather_epi64
argument_list|(
name|__v1_old
argument_list|,
name|__mask
argument_list|,
name|__index
argument_list|,
name|__addr
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm512_i64scatter_ps
parameter_list|(
name|void
modifier|*
name|__addr
parameter_list|,
name|__m512i
name|__index
parameter_list|,
name|__m256
name|__v1
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_i64scatter_ps
comment|// CHECK: @llvm.x86.avx512.scatter.qps.512
return|return
name|_mm512_i64scatter_ps
argument_list|(
name|__addr
argument_list|,
name|__index
argument_list|,
name|__v1
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm512_mask_i64scatter_ps
parameter_list|(
name|void
modifier|*
name|__addr
parameter_list|,
name|__mmask8
name|__mask
parameter_list|,
name|__m512i
name|__index
parameter_list|,
name|__m256
name|__v1
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_i64scatter_ps
comment|// CHECK: @llvm.x86.avx512.scatter.qps.512
return|return
name|_mm512_mask_i64scatter_ps
argument_list|(
name|__addr
argument_list|,
name|__mask
argument_list|,
name|__index
argument_list|,
name|__v1
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm512_i64scatter_epi32
parameter_list|(
name|void
modifier|*
name|__addr
parameter_list|,
name|__m512i
name|__index
parameter_list|,
name|__m256i
name|__v1
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_i64scatter_epi32
comment|// CHECK: @llvm.x86.avx512.scatter.qpi.512
return|return
name|_mm512_i64scatter_epi32
argument_list|(
name|__addr
argument_list|,
name|__index
argument_list|,
name|__v1
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm512_mask_i64scatter_epi32
parameter_list|(
name|void
modifier|*
name|__addr
parameter_list|,
name|__mmask8
name|__mask
parameter_list|,
name|__m512i
name|__index
parameter_list|,
name|__m256i
name|__v1
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_i64scatter_epi32
comment|// CHECK: @llvm.x86.avx512.scatter.qpi.512
return|return
name|_mm512_mask_i64scatter_epi32
argument_list|(
name|__addr
argument_list|,
name|__mask
argument_list|,
name|__index
argument_list|,
name|__v1
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm512_i64scatter_pd
parameter_list|(
name|void
modifier|*
name|__addr
parameter_list|,
name|__m512i
name|__index
parameter_list|,
name|__m512d
name|__v1
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_i64scatter_pd
comment|// CHECK: @llvm.x86.avx512.scatter.qpd.512
return|return
name|_mm512_i64scatter_pd
argument_list|(
name|__addr
argument_list|,
name|__index
argument_list|,
name|__v1
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm512_mask_i64scatter_pd
parameter_list|(
name|void
modifier|*
name|__addr
parameter_list|,
name|__mmask8
name|__mask
parameter_list|,
name|__m512i
name|__index
parameter_list|,
name|__m512d
name|__v1
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_i64scatter_pd
comment|// CHECK: @llvm.x86.avx512.scatter.qpd.512
return|return
name|_mm512_mask_i64scatter_pd
argument_list|(
name|__addr
argument_list|,
name|__mask
argument_list|,
name|__index
argument_list|,
name|__v1
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm512_i64scatter_epi64
parameter_list|(
name|void
modifier|*
name|__addr
parameter_list|,
name|__m512i
name|__index
parameter_list|,
name|__m512i
name|__v1
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_i64scatter_epi64
comment|// CHECK: @llvm.x86.avx512.scatter.qpq.512
return|return
name|_mm512_i64scatter_epi64
argument_list|(
name|__addr
argument_list|,
name|__index
argument_list|,
name|__v1
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm512_mask_i64scatter_epi64
parameter_list|(
name|void
modifier|*
name|__addr
parameter_list|,
name|__mmask8
name|__mask
parameter_list|,
name|__m512i
name|__index
parameter_list|,
name|__m512i
name|__v1
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_i64scatter_epi64
comment|// CHECK: @llvm.x86.avx512.scatter.qpq.512
return|return
name|_mm512_mask_i64scatter_epi64
argument_list|(
name|__addr
argument_list|,
name|__mask
argument_list|,
name|__index
argument_list|,
name|__v1
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm512_i32scatter_ps
parameter_list|(
name|void
modifier|*
name|__addr
parameter_list|,
name|__m512i
name|__index
parameter_list|,
name|__m512
name|__v1
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_i32scatter_ps
comment|// CHECK: @llvm.x86.avx512.scatter.dps.512
return|return
name|_mm512_i32scatter_ps
argument_list|(
name|__addr
argument_list|,
name|__index
argument_list|,
name|__v1
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm512_mask_i32scatter_ps
parameter_list|(
name|void
modifier|*
name|__addr
parameter_list|,
name|__mmask16
name|__mask
parameter_list|,
name|__m512i
name|__index
parameter_list|,
name|__m512
name|__v1
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_i32scatter_ps
comment|// CHECK: @llvm.x86.avx512.scatter.dps.512
return|return
name|_mm512_mask_i32scatter_ps
argument_list|(
name|__addr
argument_list|,
name|__mask
argument_list|,
name|__index
argument_list|,
name|__v1
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm512_i32scatter_epi32
parameter_list|(
name|void
modifier|*
name|__addr
parameter_list|,
name|__m512i
name|__index
parameter_list|,
name|__m512i
name|__v1
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_i32scatter_epi32
comment|// CHECK: @llvm.x86.avx512.scatter.dpi.512
return|return
name|_mm512_i32scatter_epi32
argument_list|(
name|__addr
argument_list|,
name|__index
argument_list|,
name|__v1
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm512_mask_i32scatter_epi32
parameter_list|(
name|void
modifier|*
name|__addr
parameter_list|,
name|__mmask16
name|__mask
parameter_list|,
name|__m512i
name|__index
parameter_list|,
name|__m512i
name|__v1
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_i32scatter_epi32
comment|// CHECK: @llvm.x86.avx512.scatter.dpi.512
return|return
name|_mm512_mask_i32scatter_epi32
argument_list|(
name|__addr
argument_list|,
name|__mask
argument_list|,
name|__index
argument_list|,
name|__v1
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm512_i32scatter_pd
parameter_list|(
name|void
modifier|*
name|__addr
parameter_list|,
name|__m256i
name|__index
parameter_list|,
name|__m512d
name|__v1
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_i32scatter_pd
comment|// CHECK: @llvm.x86.avx512.scatter.dpd.512
return|return
name|_mm512_i32scatter_pd
argument_list|(
name|__addr
argument_list|,
name|__index
argument_list|,
name|__v1
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm512_mask_i32scatter_pd
parameter_list|(
name|void
modifier|*
name|__addr
parameter_list|,
name|__mmask8
name|__mask
parameter_list|,
name|__m256i
name|__index
parameter_list|,
name|__m512d
name|__v1
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_i32scatter_pd
comment|// CHECK: @llvm.x86.avx512.scatter.dpd.512
return|return
name|_mm512_mask_i32scatter_pd
argument_list|(
name|__addr
argument_list|,
name|__mask
argument_list|,
name|__index
argument_list|,
name|__v1
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm512_i32scatter_epi64
parameter_list|(
name|void
modifier|*
name|__addr
parameter_list|,
name|__m256i
name|__index
parameter_list|,
name|__m512i
name|__v1
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_i32scatter_epi64
comment|// CHECK: @llvm.x86.avx512.scatter.dpq.512
return|return
name|_mm512_i32scatter_epi64
argument_list|(
name|__addr
argument_list|,
name|__index
argument_list|,
name|__v1
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm512_mask_i32scatter_epi64
parameter_list|(
name|void
modifier|*
name|__addr
parameter_list|,
name|__mmask8
name|__mask
parameter_list|,
name|__m256i
name|__index
parameter_list|,
name|__m512i
name|__v1
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_i32scatter_epi64
comment|// CHECK: @llvm.x86.avx512.scatter.dpq.512
return|return
name|_mm512_mask_i32scatter_epi64
argument_list|(
name|__addr
argument_list|,
name|__mask
argument_list|,
name|__index
argument_list|,
name|__v1
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_rsqrt14_sd
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
comment|// CHECK-LABEL: @test_mm_mask_rsqrt14_sd
comment|// CHECK: @llvm.x86.avx512.rsqrt14.sd
return|return
name|_mm_mask_rsqrt14_sd
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
name|__m128d
name|test_mm_maskz_rsqrt14_sd
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
comment|// CHECK-LABEL: @test_mm_maskz_rsqrt14_sd
comment|// CHECK: @llvm.x86.avx512.rsqrt14.sd
return|return
name|_mm_maskz_rsqrt14_sd
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
name|__m128
name|test_mm_mask_rsqrt14_ss
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
comment|// CHECK-LABEL: @test_mm_mask_rsqrt14_ss
comment|// CHECK: @llvm.x86.avx512.rsqrt14.ss
return|return
name|_mm_mask_rsqrt14_ss
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
name|__m128
name|test_mm_maskz_rsqrt14_ss
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
comment|// CHECK-LABEL: @test_mm_maskz_rsqrt14_ss
comment|// CHECK: @llvm.x86.avx512.rsqrt14.ss
return|return
name|_mm_maskz_rsqrt14_ss
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
name|test_mm512_mask_rcp14_pd
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
comment|// CHECK-LABEL: @test_mm512_mask_rcp14_pd
comment|// CHECK: @llvm.x86.avx512.rcp14.pd.512
return|return
name|_mm512_mask_rcp14_pd
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
name|test_mm512_maskz_rcp14_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_rcp14_pd
comment|// CHECK: @llvm.x86.avx512.rcp14.pd.512
return|return
name|_mm512_maskz_rcp14_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_rcp14_ps
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
comment|// CHECK-LABEL: @test_mm512_mask_rcp14_ps
comment|// CHECK: @llvm.x86.avx512.rcp14.ps.512
return|return
name|_mm512_mask_rcp14_ps
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
name|__m512
name|test_mm512_maskz_rcp14_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_rcp14_ps
comment|// CHECK: @llvm.x86.avx512.rcp14.ps.512
return|return
name|_mm512_maskz_rcp14_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_rcp14_sd
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
comment|// CHECK-LABEL: @test_mm_mask_rcp14_sd
comment|// CHECK: @llvm.x86.avx512.rcp14.sd
return|return
name|_mm_mask_rcp14_sd
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
name|__m128d
name|test_mm_maskz_rcp14_sd
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
comment|// CHECK-LABEL: @test_mm_maskz_rcp14_sd
comment|// CHECK: @llvm.x86.avx512.rcp14.sd
return|return
name|_mm_maskz_rcp14_sd
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
name|__m128
name|test_mm_mask_rcp14_ss
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
comment|// CHECK-LABEL: @test_mm_mask_rcp14_ss
comment|// CHECK: @llvm.x86.avx512.rcp14.ss
return|return
name|_mm_mask_rcp14_ss
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
name|__m128
name|test_mm_maskz_rcp14_ss
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
comment|// CHECK-LABEL: @test_mm_maskz_rcp14_ss
comment|// CHECK: @llvm.x86.avx512.rcp14.ss
return|return
name|_mm_maskz_rcp14_ss
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
name|__m128d
name|test_mm_mask_getexp_sd
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
comment|// CHECK-LABEL: @test_mm_mask_getexp_sd
comment|// CHECK: @llvm.x86.avx512.mask.getexp.sd
return|return
name|_mm_mask_getexp_sd
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
name|__m128d
name|test_mm_mask_getexp_round_sd
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
comment|// CHECK-LABEL: @test_mm_mask_getexp_round_sd
comment|// CHECK: @llvm.x86.avx512.mask.getexp.sd
return|return
name|_mm_mask_getexp_round_sd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_maskz_getexp_sd
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
comment|// CHECK-LABEL: @test_mm_maskz_getexp_sd
comment|// CHECK: @llvm.x86.avx512.mask.getexp.sd
return|return
name|_mm_maskz_getexp_sd
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
name|__m128d
name|test_mm_maskz_getexp_round_sd
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
comment|// CHECK-LABEL: @test_mm_maskz_getexp_round_sd
comment|// CHECK: @llvm.x86.avx512.mask.getexp.sd
return|return
name|_mm_maskz_getexp_round_sd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_getexp_ss
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
comment|// CHECK-LABEL: @test_mm_mask_getexp_ss
comment|// CHECK: @llvm.x86.avx512.mask.getexp.ss
return|return
name|_mm_mask_getexp_ss
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
name|__m128
name|test_mm_mask_getexp_round_ss
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
comment|// CHECK-LABEL: @test_mm_mask_getexp_round_ss
comment|// CHECK: @llvm.x86.avx512.mask.getexp.ss
return|return
name|_mm_mask_getexp_round_ss
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_maskz_getexp_ss
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
comment|// CHECK-LABEL: @test_mm_maskz_getexp_ss
comment|// CHECK: @llvm.x86.avx512.mask.getexp.ss
return|return
name|_mm_maskz_getexp_ss
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
name|__m128
name|test_mm_maskz_getexp_round_ss
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
comment|// CHECK-LABEL: @test_mm_maskz_getexp_round_ss
comment|// CHECK: @llvm.x86.avx512.mask.getexp.ss
return|return
name|_mm_maskz_getexp_round_ss
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_getmant_sd
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
comment|// CHECK-LABEL: @test_mm_mask_getmant_sd
comment|// CHECK: @llvm.x86.avx512.mask.getmant.sd
return|return
name|_mm_mask_getmant_sd
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
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_getmant_round_sd
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
comment|// CHECK-LABEL: @test_mm_mask_getmant_round_sd
comment|// CHECK: @llvm.x86.avx512.mask.getmant.sd
return|return
name|_mm_mask_getmant_round_sd
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
argument_list|,
literal|2
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_maskz_getmant_sd
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
comment|// CHECK-LABEL: @test_mm_maskz_getmant_sd
comment|// CHECK: @llvm.x86.avx512.mask.getmant.sd
return|return
name|_mm_maskz_getmant_sd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_maskz_getmant_round_sd
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
comment|// CHECK-LABEL: @test_mm_maskz_getmant_round_sd
comment|// CHECK: @llvm.x86.avx512.mask.getmant.sd
return|return
name|_mm_maskz_getmant_round_sd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_getmant_ss
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
comment|// CHECK-LABEL: @test_mm_mask_getmant_ss
comment|// CHECK: @llvm.x86.avx512.mask.getmant.ss
return|return
name|_mm_mask_getmant_ss
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
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_getmant_round_ss
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
comment|// CHECK-LABEL: @test_mm_mask_getmant_round_ss
comment|// CHECK: @llvm.x86.avx512.mask.getmant.ss
return|return
name|_mm_mask_getmant_round_ss
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
argument_list|,
literal|2
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_maskz_getmant_ss
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
comment|// CHECK-LABEL: @test_mm_maskz_getmant_ss
comment|// CHECK: @llvm.x86.avx512.mask.getmant.ss
return|return
name|_mm_maskz_getmant_ss
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_maskz_getmant_round_ss
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
comment|// CHECK-LABEL: @test_mm_maskz_getmant_round_ss
comment|// CHECK: @llvm.x86.avx512.mask.getmant.ss
return|return
name|_mm_maskz_getmant_round_ss
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_fmadd_ss
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
comment|// CHECK-LABEL: @test_mm_mask_fmadd_ss
comment|// CHECK: @llvm.x86.avx512.mask.vfmadd.ss
return|return
name|_mm_mask_fmadd_ss
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
name|__m128
name|test_mm_mask_fmadd_round_ss
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
comment|// CHECK-LABEL: @test_mm_mask_fmadd_round_ss
comment|// CHECK: @llvm.x86.avx512.mask.vfmadd.ss
return|return
name|_mm_mask_fmadd_round_ss
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_maskz_fmadd_ss
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|,
name|__m128
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_fmadd_ss
comment|// CHECK: @llvm.x86.avx512.maskz.vfmadd.ss
return|return
name|_mm_maskz_fmadd_ss
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_maskz_fmadd_round_ss
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|,
name|__m128
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_fmadd_round_ss
comment|// CHECK: @llvm.x86.avx512.maskz.vfmadd.ss
return|return
name|_mm_maskz_fmadd_round_ss
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask3_fmadd_ss
parameter_list|(
name|__m128
name|__W
parameter_list|,
name|__m128
name|__X
parameter_list|,
name|__m128
name|__Y
parameter_list|,
name|__mmask8
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask3_fmadd_ss
comment|// CHECK: @llvm.x86.avx512.mask3.vfmadd.ss
return|return
name|_mm_mask3_fmadd_ss
argument_list|(
name|__W
argument_list|,
name|__X
argument_list|,
name|__Y
argument_list|,
name|__U
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask3_fmadd_round_ss
parameter_list|(
name|__m128
name|__W
parameter_list|,
name|__m128
name|__X
parameter_list|,
name|__m128
name|__Y
parameter_list|,
name|__mmask8
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask3_fmadd_round_ss
comment|// CHECK: @llvm.x86.avx512.mask3.vfmadd.ss
return|return
name|_mm_mask3_fmadd_round_ss
argument_list|(
name|__W
argument_list|,
name|__X
argument_list|,
name|__Y
argument_list|,
name|__U
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_fmsub_ss
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
comment|// CHECK-LABEL: @test_mm_mask_fmsub_ss
comment|// CHECK: @llvm.x86.avx512.mask.vfmadd.ss
return|return
name|_mm_mask_fmsub_ss
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
name|__m128
name|test_mm_mask_fmsub_round_ss
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
comment|// CHECK-LABEL: @test_mm_mask_fmsub_round_ss
comment|// CHECK: @llvm.x86.avx512.mask.vfmadd.ss
return|return
name|_mm_mask_fmsub_round_ss
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_maskz_fmsub_ss
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|,
name|__m128
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_fmsub_ss
comment|// CHECK: @llvm.x86.avx512.maskz.vfmadd.ss
return|return
name|_mm_maskz_fmsub_ss
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_maskz_fmsub_round_ss
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|,
name|__m128
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_fmsub_round_ss
comment|// CHECK: @llvm.x86.avx512.maskz.vfmadd.ss
return|return
name|_mm_maskz_fmsub_round_ss
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask3_fmsub_ss
parameter_list|(
name|__m128
name|__W
parameter_list|,
name|__m128
name|__X
parameter_list|,
name|__m128
name|__Y
parameter_list|,
name|__mmask8
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask3_fmsub_ss
comment|// CHECK: @llvm.x86.avx512.mask3.vfmsub.ss
return|return
name|_mm_mask3_fmsub_ss
argument_list|(
name|__W
argument_list|,
name|__X
argument_list|,
name|__Y
argument_list|,
name|__U
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask3_fmsub_round_ss
parameter_list|(
name|__m128
name|__W
parameter_list|,
name|__m128
name|__X
parameter_list|,
name|__m128
name|__Y
parameter_list|,
name|__mmask8
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask3_fmsub_round_ss
comment|// CHECK: @llvm.x86.avx512.mask3.vfmsub.ss
return|return
name|_mm_mask3_fmsub_round_ss
argument_list|(
name|__W
argument_list|,
name|__X
argument_list|,
name|__Y
argument_list|,
name|__U
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_fnmadd_ss
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
comment|// CHECK-LABEL: @test_mm_mask_fnmadd_ss
comment|// CHECK: @llvm.x86.avx512.mask.vfmadd.ss
return|return
name|_mm_mask_fnmadd_ss
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
name|__m128
name|test_mm_mask_fnmadd_round_ss
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
comment|// CHECK-LABEL: @test_mm_mask_fnmadd_round_ss
comment|// CHECK: @llvm.x86.avx512.mask.vfmadd.ss
return|return
name|_mm_mask_fnmadd_round_ss
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_maskz_fnmadd_ss
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|,
name|__m128
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_fnmadd_ss
comment|// CHECK: @llvm.x86.avx512.maskz.vfmadd.ss
return|return
name|_mm_maskz_fnmadd_ss
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_maskz_fnmadd_round_ss
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|,
name|__m128
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_fnmadd_round_ss
comment|// CHECK: @llvm.x86.avx512.maskz.vfmadd.ss
return|return
name|_mm_maskz_fnmadd_round_ss
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask3_fnmadd_ss
parameter_list|(
name|__m128
name|__W
parameter_list|,
name|__m128
name|__X
parameter_list|,
name|__m128
name|__Y
parameter_list|,
name|__mmask8
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask3_fnmadd_ss
comment|// CHECK: @llvm.x86.avx512.mask3.vfmadd.ss
return|return
name|_mm_mask3_fnmadd_ss
argument_list|(
name|__W
argument_list|,
name|__X
argument_list|,
name|__Y
argument_list|,
name|__U
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask3_fnmadd_round_ss
parameter_list|(
name|__m128
name|__W
parameter_list|,
name|__m128
name|__X
parameter_list|,
name|__m128
name|__Y
parameter_list|,
name|__mmask8
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask3_fnmadd_round_ss
comment|// CHECK: @llvm.x86.avx512.mask3.vfmadd.ss
return|return
name|_mm_mask3_fnmadd_round_ss
argument_list|(
name|__W
argument_list|,
name|__X
argument_list|,
name|__Y
argument_list|,
name|__U
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_fnmsub_ss
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
comment|// CHECK-LABEL: @test_mm_mask_fnmsub_ss
comment|// CHECK: @llvm.x86.avx512.mask.vfmadd.ss
return|return
name|_mm_mask_fnmsub_ss
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
name|__m128
name|test_mm_mask_fnmsub_round_ss
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
comment|// CHECK-LABEL: @test_mm_mask_fnmsub_round_ss
comment|// CHECK: @llvm.x86.avx512.mask.vfmadd.ss
return|return
name|_mm_mask_fnmsub_round_ss
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_maskz_fnmsub_ss
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|,
name|__m128
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_fnmsub_ss
comment|// CHECK: @llvm.x86.avx512.maskz.vfmadd.ss
return|return
name|_mm_maskz_fnmsub_ss
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_maskz_fnmsub_round_ss
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|,
name|__m128
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_fnmsub_round_ss
comment|// CHECK: @llvm.x86.avx512.maskz.vfmadd.ss
return|return
name|_mm_maskz_fnmsub_round_ss
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask3_fnmsub_ss
parameter_list|(
name|__m128
name|__W
parameter_list|,
name|__m128
name|__X
parameter_list|,
name|__m128
name|__Y
parameter_list|,
name|__mmask8
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask3_fnmsub_ss
comment|// CHECK: @llvm.x86.avx512.mask3.vfnmsub.ss
return|return
name|_mm_mask3_fnmsub_ss
argument_list|(
name|__W
argument_list|,
name|__X
argument_list|,
name|__Y
argument_list|,
name|__U
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask3_fnmsub_round_ss
parameter_list|(
name|__m128
name|__W
parameter_list|,
name|__m128
name|__X
parameter_list|,
name|__m128
name|__Y
parameter_list|,
name|__mmask8
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask3_fnmsub_round_ss
comment|// CHECK: @llvm.x86.avx512.mask3.vfnmsub.ss
return|return
name|_mm_mask3_fnmsub_round_ss
argument_list|(
name|__W
argument_list|,
name|__X
argument_list|,
name|__Y
argument_list|,
name|__U
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_fmadd_sd
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
comment|// CHECK-LABEL: @test_mm_mask_fmadd_sd
comment|// CHECK: @llvm.x86.avx512.mask.vfmadd.sd
return|return
name|_mm_mask_fmadd_sd
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
name|__m128d
name|test_mm_mask_fmadd_round_sd
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
comment|// CHECK-LABEL: @test_mm_mask_fmadd_round_sd
comment|// CHECK: @llvm.x86.avx512.mask.vfmadd.sd
return|return
name|_mm_mask_fmadd_round_sd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_maskz_fmadd_sd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|,
name|__m128d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_fmadd_sd
comment|// CHECK: @llvm.x86.avx512.maskz.vfmadd.sd
return|return
name|_mm_maskz_fmadd_sd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_maskz_fmadd_round_sd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|,
name|__m128d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_fmadd_round_sd
comment|// CHECK: @llvm.x86.avx512.maskz.vfmadd.sd
return|return
name|_mm_maskz_fmadd_round_sd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask3_fmadd_sd
parameter_list|(
name|__m128d
name|__W
parameter_list|,
name|__m128d
name|__X
parameter_list|,
name|__m128d
name|__Y
parameter_list|,
name|__mmask8
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask3_fmadd_sd
comment|// CHECK: @llvm.x86.avx512.mask3.vfmadd.sd
return|return
name|_mm_mask3_fmadd_sd
argument_list|(
name|__W
argument_list|,
name|__X
argument_list|,
name|__Y
argument_list|,
name|__U
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask3_fmadd_round_sd
parameter_list|(
name|__m128d
name|__W
parameter_list|,
name|__m128d
name|__X
parameter_list|,
name|__m128d
name|__Y
parameter_list|,
name|__mmask8
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask3_fmadd_round_sd
comment|// CHECK: @llvm.x86.avx512.mask3.vfmadd.sd
return|return
name|_mm_mask3_fmadd_round_sd
argument_list|(
name|__W
argument_list|,
name|__X
argument_list|,
name|__Y
argument_list|,
name|__U
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_fmsub_sd
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
comment|// CHECK-LABEL: @test_mm_mask_fmsub_sd
comment|// CHECK: @llvm.x86.avx512.mask.vfmadd.sd
return|return
name|_mm_mask_fmsub_sd
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
name|__m128d
name|test_mm_mask_fmsub_round_sd
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
comment|// CHECK-LABEL: @test_mm_mask_fmsub_round_sd
comment|// CHECK: @llvm.x86.avx512.mask.vfmadd.sd
return|return
name|_mm_mask_fmsub_round_sd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_maskz_fmsub_sd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|,
name|__m128d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_fmsub_sd
comment|// CHECK: @llvm.x86.avx512.maskz.vfmadd.sd
return|return
name|_mm_maskz_fmsub_sd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_maskz_fmsub_round_sd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|,
name|__m128d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_fmsub_round_sd
comment|// CHECK: @llvm.x86.avx512.maskz.vfmadd.sd
return|return
name|_mm_maskz_fmsub_round_sd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask3_fmsub_sd
parameter_list|(
name|__m128d
name|__W
parameter_list|,
name|__m128d
name|__X
parameter_list|,
name|__m128d
name|__Y
parameter_list|,
name|__mmask8
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask3_fmsub_sd
comment|// CHECK: @llvm.x86.avx512.mask3.vfmsub.sd
return|return
name|_mm_mask3_fmsub_sd
argument_list|(
name|__W
argument_list|,
name|__X
argument_list|,
name|__Y
argument_list|,
name|__U
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask3_fmsub_round_sd
parameter_list|(
name|__m128d
name|__W
parameter_list|,
name|__m128d
name|__X
parameter_list|,
name|__m128d
name|__Y
parameter_list|,
name|__mmask8
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask3_fmsub_round_sd
comment|// CHECK: @llvm.x86.avx512.mask3.vfmsub.sd
return|return
name|_mm_mask3_fmsub_round_sd
argument_list|(
name|__W
argument_list|,
name|__X
argument_list|,
name|__Y
argument_list|,
name|__U
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_fnmadd_sd
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
comment|// CHECK-LABEL: @test_mm_mask_fnmadd_sd
comment|// CHECK: @llvm.x86.avx512.mask.vfmadd.sd
return|return
name|_mm_mask_fnmadd_sd
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
name|__m128d
name|test_mm_mask_fnmadd_round_sd
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
comment|// CHECK-LABEL: @test_mm_mask_fnmadd_round_sd
comment|// CHECK: @llvm.x86.avx512.mask.vfmadd.sd
return|return
name|_mm_mask_fnmadd_round_sd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_maskz_fnmadd_sd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|,
name|__m128d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_fnmadd_sd
comment|// CHECK: @llvm.x86.avx512.maskz.vfmadd.sd
return|return
name|_mm_maskz_fnmadd_sd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_maskz_fnmadd_round_sd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|,
name|__m128d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_fnmadd_round_sd
comment|// CHECK: @llvm.x86.avx512.maskz.vfmadd.sd
return|return
name|_mm_maskz_fnmadd_round_sd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask3_fnmadd_sd
parameter_list|(
name|__m128d
name|__W
parameter_list|,
name|__m128d
name|__X
parameter_list|,
name|__m128d
name|__Y
parameter_list|,
name|__mmask8
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask3_fnmadd_sd
comment|// CHECK: @llvm.x86.avx512.mask3.vfmadd.sd
return|return
name|_mm_mask3_fnmadd_sd
argument_list|(
name|__W
argument_list|,
name|__X
argument_list|,
name|__Y
argument_list|,
name|__U
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask3_fnmadd_round_sd
parameter_list|(
name|__m128d
name|__W
parameter_list|,
name|__m128d
name|__X
parameter_list|,
name|__m128d
name|__Y
parameter_list|,
name|__mmask8
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask3_fnmadd_round_sd
comment|// CHECK: @llvm.x86.avx512.mask3.vfmadd.sd
return|return
name|_mm_mask3_fnmadd_round_sd
argument_list|(
name|__W
argument_list|,
name|__X
argument_list|,
name|__Y
argument_list|,
name|__U
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_fnmsub_sd
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
comment|// CHECK-LABEL: @test_mm_mask_fnmsub_sd
comment|// CHECK: @llvm.x86.avx512.mask.vfmadd.sd
return|return
name|_mm_mask_fnmsub_sd
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
name|__m128d
name|test_mm_mask_fnmsub_round_sd
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
comment|// CHECK-LABEL: @test_mm_mask_fnmsub_round_sd
comment|// CHECK: @llvm.x86.avx512.mask.vfmadd.sd
return|return
name|_mm_mask_fnmsub_round_sd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_maskz_fnmsub_sd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|,
name|__m128d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_fnmsub_sd
comment|// CHECK: @llvm.x86.avx512.maskz.vfmadd.sd
return|return
name|_mm_maskz_fnmsub_sd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_maskz_fnmsub_round_sd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|,
name|__m128d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_fnmsub_round_sd
comment|// CHECK: @llvm.x86.avx512.maskz.vfmadd.sd
return|return
name|_mm_maskz_fnmsub_round_sd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask3_fnmsub_sd
parameter_list|(
name|__m128d
name|__W
parameter_list|,
name|__m128d
name|__X
parameter_list|,
name|__m128d
name|__Y
parameter_list|,
name|__mmask8
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask3_fnmsub_sd
comment|// CHECK: @llvm.x86.avx512.mask3.vfnmsub.sd
return|return
name|_mm_mask3_fnmsub_sd
argument_list|(
name|__W
argument_list|,
name|__X
argument_list|,
name|__Y
argument_list|,
name|__U
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask3_fnmsub_round_sd
parameter_list|(
name|__m128d
name|__W
parameter_list|,
name|__m128d
name|__X
parameter_list|,
name|__m128d
name|__Y
parameter_list|,
name|__mmask8
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask3_fnmsub_round_sd
comment|// CHECK: @llvm.x86.avx512.mask3.vfnmsub.sd
return|return
name|_mm_mask3_fnmsub_round_sd
argument_list|(
name|__W
argument_list|,
name|__X
argument_list|,
name|__Y
argument_list|,
name|__U
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_permutex_pd
parameter_list|(
name|__m512d
name|__X
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_permutex_pd
comment|// CHECK: shufflevector<8 x double> %{{.*}},<8 x double> zeroinitializer,<8 x i32><i32 0, i32 0, i32 0, i32 0, i32 4, i32 4, i32 4, i32 4>
return|return
name|_mm512_permutex_pd
argument_list|(
name|__X
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_permutex_pd
parameter_list|(
name|__m512d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__X
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_permutex_pd
comment|// CHECK: shufflevector<8 x double> %{{.*}},<8 x double> zeroinitializer,<8 x i32><i32 0, i32 0, i32 0, i32 0, i32 4, i32 4, i32 4, i32 4>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x double> %{{.*}},<8 x double> %{{.*}}
return|return
name|_mm512_mask_permutex_pd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__X
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_maskz_permutex_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__X
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_permutex_pd
comment|// CHECK: shufflevector<8 x double> %{{.*}},<8 x double> zeroinitializer,<8 x i32><i32 0, i32 0, i32 0, i32 0, i32 4, i32 4, i32 4, i32 4>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x double> %{{.*}},<8 x double> %{{.*}}
return|return
name|_mm512_maskz_permutex_pd
argument_list|(
name|__U
argument_list|,
name|__X
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_permutex_epi64
parameter_list|(
name|__m512i
name|__X
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_permutex_epi64
comment|// CHECK: shufflevector<8 x i64> %{{.*}},<8 x i64> zeroinitializer,<8 x i32><i32 0, i32 0, i32 0, i32 0, i32 4, i32 4, i32 4, i32 4>
return|return
name|_mm512_permutex_epi64
argument_list|(
name|__X
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_permutex_epi64
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m512i
name|__X
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_permutex_epi64
comment|// CHECK: shufflevector<8 x i64> %{{.*}},<8 x i64> zeroinitializer,<8 x i32><i32 0, i32 0, i32 0, i32 0, i32 4, i32 4, i32 4, i32 4>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_mask_permutex_epi64
argument_list|(
name|__W
argument_list|,
name|__M
argument_list|,
name|__X
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_permutex_epi64
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m512i
name|__X
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_permutex_epi64
comment|// CHECK: shufflevector<8 x i64> %{{.*}},<8 x i64> zeroinitializer,<8 x i32><i32 0, i32 0, i32 0, i32 0, i32 4, i32 4, i32 4, i32 4>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i64> %{{.*}},<8 x i64> %{{.*}}
return|return
name|_mm512_maskz_permutex_epi64
argument_list|(
name|__M
argument_list|,
name|__X
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_permutexvar_pd
parameter_list|(
name|__m512i
name|__X
parameter_list|,
name|__m512d
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_permutexvar_pd
comment|// CHECK: @llvm.x86.avx512.mask.permvar.df.512
return|return
name|_mm512_permutexvar_pd
argument_list|(
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_permutexvar_pd
parameter_list|(
name|__m512d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__X
parameter_list|,
name|__m512d
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_permutexvar_pd
comment|// CHECK: @llvm.x86.avx512.mask.permvar.df.512
return|return
name|_mm512_mask_permutexvar_pd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_maskz_permutexvar_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__X
parameter_list|,
name|__m512d
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_permutexvar_pd
comment|// CHECK: @llvm.x86.avx512.mask.permvar.df.512
return|return
name|_mm512_maskz_permutexvar_pd
argument_list|(
name|__U
argument_list|,
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_permutexvar_epi64
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m512i
name|__X
parameter_list|,
name|__m512i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_permutexvar_epi64
comment|// CHECK: @llvm.x86.avx512.mask.permvar.di.512
return|return
name|_mm512_maskz_permutexvar_epi64
argument_list|(
name|__M
argument_list|,
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_permutexvar_epi64
parameter_list|(
name|__m512i
name|__X
parameter_list|,
name|__m512i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_permutexvar_epi64
comment|// CHECK: @llvm.x86.avx512.mask.permvar.di.512
return|return
name|_mm512_permutexvar_epi64
argument_list|(
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_permutexvar_epi64
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m512i
name|__X
parameter_list|,
name|__m512i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_permutexvar_epi64
comment|// CHECK: @llvm.x86.avx512.mask.permvar.di.512
return|return
name|_mm512_mask_permutexvar_epi64
argument_list|(
name|__W
argument_list|,
name|__M
argument_list|,
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_permutexvar_ps
parameter_list|(
name|__m512i
name|__X
parameter_list|,
name|__m512
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_permutexvar_ps
comment|// CHECK: @llvm.x86.avx512.mask.permvar.sf.512
return|return
name|_mm512_permutexvar_ps
argument_list|(
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_permutexvar_ps
parameter_list|(
name|__m512
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512i
name|__X
parameter_list|,
name|__m512
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_permutexvar_ps
comment|// CHECK: @llvm.x86.avx512.mask.permvar.sf.512
return|return
name|_mm512_mask_permutexvar_ps
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_maskz_permutexvar_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512i
name|__X
parameter_list|,
name|__m512
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_permutexvar_ps
comment|// CHECK: @llvm.x86.avx512.mask.permvar.sf.512
return|return
name|_mm512_maskz_permutexvar_ps
argument_list|(
name|__U
argument_list|,
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_permutexvar_epi32
parameter_list|(
name|__mmask16
name|__M
parameter_list|,
name|__m512i
name|__X
parameter_list|,
name|__m512i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_permutexvar_epi32
comment|// CHECK: @llvm.x86.avx512.mask.permvar.si.512
return|return
name|_mm512_maskz_permutexvar_epi32
argument_list|(
name|__M
argument_list|,
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_permutexvar_epi32
parameter_list|(
name|__m512i
name|__X
parameter_list|,
name|__m512i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_permutexvar_epi32
comment|// CHECK: @llvm.x86.avx512.mask.permvar.si.512
return|return
name|_mm512_permutexvar_epi32
argument_list|(
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_permutexvar_epi32
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask16
name|__M
parameter_list|,
name|__m512i
name|__X
parameter_list|,
name|__m512i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_permutexvar_epi32
comment|// CHECK: @llvm.x86.avx512.mask.permvar.si.512
return|return
name|_mm512_mask_permutexvar_epi32
argument_list|(
name|__W
argument_list|,
name|__M
argument_list|,
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm512_kand
parameter_list|(
name|__mmask16
name|__A
parameter_list|,
name|__mmask16
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_kand
comment|// CHECK: @llvm.x86.avx512.kand.w
return|return
name|_mm512_kand
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm512_kandn
parameter_list|(
name|__mmask16
name|__A
parameter_list|,
name|__mmask16
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_kandn
comment|// CHECK: @llvm.x86.avx512.kandn.w
return|return
name|_mm512_kandn
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm512_kor
parameter_list|(
name|__mmask16
name|__A
parameter_list|,
name|__mmask16
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_kor
comment|// CHECK: @llvm.x86.avx512.kor.w
return|return
name|_mm512_kor
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm512_kortestc
parameter_list|(
name|__mmask16
name|__A
parameter_list|,
name|__mmask16
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_kortestc
comment|// CHECK: @llvm.x86.avx512.kortestc.w
return|return
name|_mm512_kortestc
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm512_kortestz
parameter_list|(
name|__mmask16
name|__A
parameter_list|,
name|__mmask16
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_kortestz
comment|// CHECK: @llvm.x86.avx512.kortestz.w
return|return
name|_mm512_kortestz
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm512_kunpackb
parameter_list|(
name|__mmask16
name|__A
parameter_list|,
name|__mmask16
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_kunpackb
comment|// CHECK: @llvm.x86.avx512.kunpck.bw
return|return
name|_mm512_kunpackb
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm512_kxnor
parameter_list|(
name|__mmask16
name|__A
parameter_list|,
name|__mmask16
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_kxnor
comment|// CHECK: @llvm.x86.avx512.kxnor.w
return|return
name|_mm512_kxnor
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm512_kxor
parameter_list|(
name|__mmask16
name|__A
parameter_list|,
name|__mmask16
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_kxor
comment|// CHECK: @llvm.x86.avx512.kxor.w
return|return
name|_mm512_kxor
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm512_stream_si512
parameter_list|(
name|__m512i
modifier|*
name|__P
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_stream_si512
comment|// CHECK: store<8 x i64> %{{.*}},<8 x i64>* %{{.*}}, align 64, !nontemporal
name|_mm512_stream_si512
argument_list|(
name|__P
argument_list|,
name|__A
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_stream_load_si512
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_stream_load_si512
comment|// CHECK: load<8 x i64>,<8 x i64>* %{{.*}}, align 64, !nontemporal
return|return
name|_mm512_stream_load_si512
argument_list|(
name|__P
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm512_stream_pd
parameter_list|(
name|double
modifier|*
name|__P
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_stream_pd
comment|// CHECK: store<8 x double> %{{.*}},<8 x double>* %{{.*}}, align 64, !nontemporal
return|return
name|_mm512_stream_pd
argument_list|(
name|__P
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm512_stream_ps
parameter_list|(
name|float
modifier|*
name|__P
parameter_list|,
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_stream_ps
comment|// CHECK: store<16 x float> %{{.*}},<16 x float>* %{{.*}}, align 64, !nontemporal
name|_mm512_stream_ps
argument_list|(
name|__P
argument_list|,
name|__A
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_compress_pd
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
comment|// CHECK-LABEL: @test_mm512_mask_compress_pd
comment|// CHECK: @llvm.x86.avx512.mask.compress.pd.512
return|return
name|_mm512_mask_compress_pd
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
name|test_mm512_maskz_compress_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_compress_pd
comment|// CHECK: @llvm.x86.avx512.mask.compress.pd.512
return|return
name|_mm512_maskz_compress_pd
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
name|test_mm512_mask_compress_epi64
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
comment|// CHECK-LABEL: @test_mm512_mask_compress_epi64
comment|// CHECK: @llvm.x86.avx512.mask.compress.q.512
return|return
name|_mm512_mask_compress_epi64
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
name|test_mm512_maskz_compress_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_compress_epi64
comment|// CHECK: @llvm.x86.avx512.mask.compress.q.512
return|return
name|_mm512_maskz_compress_epi64
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_compress_ps
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
comment|// CHECK-LABEL: @test_mm512_mask_compress_ps
comment|// CHECK: @llvm.x86.avx512.mask.compress.ps.512
return|return
name|_mm512_mask_compress_ps
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
name|__m512
name|test_mm512_maskz_compress_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_compress_ps
comment|// CHECK: @llvm.x86.avx512.mask.compress.ps.512
return|return
name|_mm512_maskz_compress_ps
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
name|test_mm512_mask_compress_epi32
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
comment|// CHECK-LABEL: @test_mm512_mask_compress_epi32
comment|// CHECK: @llvm.x86.avx512.mask.compress.d.512
return|return
name|_mm512_mask_compress_epi32
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
name|test_mm512_maskz_compress_epi32
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_compress_epi32
comment|// CHECK: @llvm.x86.avx512.mask.compress.d.512
return|return
name|_mm512_maskz_compress_epi32
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm_cmp_round_ss_mask
parameter_list|(
name|__m128
name|__X
parameter_list|,
name|__m128
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmp_round_ss_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp
return|return
name|_mm_cmp_round_ss_mask
argument_list|(
name|__X
argument_list|,
name|__Y
argument_list|,
literal|5
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm_mask_cmp_round_ss_mask
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128
name|__X
parameter_list|,
name|__m128
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cmp_round_ss_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp
return|return
name|_mm_mask_cmp_round_ss_mask
argument_list|(
name|__M
argument_list|,
name|__X
argument_list|,
name|__Y
argument_list|,
literal|5
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm_cmp_ss_mask
parameter_list|(
name|__m128
name|__X
parameter_list|,
name|__m128
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmp_ss_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp
return|return
name|_mm_cmp_ss_mask
argument_list|(
name|__X
argument_list|,
name|__Y
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm_mask_cmp_ss_mask
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128
name|__X
parameter_list|,
name|__m128
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cmp_ss_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp
return|return
name|_mm_mask_cmp_ss_mask
argument_list|(
name|__M
argument_list|,
name|__X
argument_list|,
name|__Y
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm_cmp_round_sd_mask
parameter_list|(
name|__m128d
name|__X
parameter_list|,
name|__m128d
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmp_round_sd_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp
return|return
name|_mm_cmp_round_sd_mask
argument_list|(
name|__X
argument_list|,
name|__Y
argument_list|,
literal|5
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm_mask_cmp_round_sd_mask
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128d
name|__X
parameter_list|,
name|__m128d
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cmp_round_sd_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp
return|return
name|_mm_mask_cmp_round_sd_mask
argument_list|(
name|__M
argument_list|,
name|__X
argument_list|,
name|__Y
argument_list|,
literal|5
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm_cmp_sd_mask
parameter_list|(
name|__m128d
name|__X
parameter_list|,
name|__m128d
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmp_sd_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp
return|return
name|_mm_cmp_sd_mask
argument_list|(
name|__X
argument_list|,
name|__Y
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm_mask_cmp_sd_mask
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128d
name|__X
parameter_list|,
name|__m128d
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cmp_sd_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp
return|return
name|_mm_mask_cmp_sd_mask
argument_list|(
name|__M
argument_list|,
name|__X
argument_list|,
name|__Y
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_movehdup_ps
parameter_list|(
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_movehdup_ps
comment|// CHECK: shufflevector<16 x float> %{{.*}},<16 x float> %{{.*}},<16 x i32><i32 1, i32 1, i32 3, i32 3, i32 5, i32 5, i32 7, i32 7, i32 9, i32 9, i32 11, i32 11, i32 13, i32 13, i32 15, i32 15>
return|return
name|_mm512_movehdup_ps
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_movehdup_ps
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
comment|// CHECK-LABEL: @test_mm512_mask_movehdup_ps
comment|// CHECK: shufflevector<16 x float> %{{.*}},<16 x float> %{{.*}},<16 x i32><i32 1, i32 1, i32 3, i32 3, i32 5, i32 5, i32 7, i32 7, i32 9, i32 9, i32 11, i32 11, i32 13, i32 13, i32 15, i32 15>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x float> %{{.*}},<16 x float> %{{.*}}
return|return
name|_mm512_mask_movehdup_ps
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
name|__m512
name|test_mm512_maskz_movehdup_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_movehdup_ps
comment|// CHECK: shufflevector<16 x float> %{{.*}},<16 x float> %{{.*}},<16 x i32><i32 1, i32 1, i32 3, i32 3, i32 5, i32 5, i32 7, i32 7, i32 9, i32 9, i32 11, i32 11, i32 13, i32 13, i32 15, i32 15>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x float> %{{.*}},<16 x float> %{{.*}}
return|return
name|_mm512_maskz_movehdup_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_moveldup_ps
parameter_list|(
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_moveldup_ps
comment|// CHECK: shufflevector<16 x float> %{{.*}},<16 x float> %{{.*}},<16 x i32><i32 0, i32 0, i32 2, i32 2, i32 4, i32 4, i32 6, i32 6, i32 8, i32 8, i32 10, i32 10, i32 12, i32 12, i32 14, i32 14>
return|return
name|_mm512_moveldup_ps
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_moveldup_ps
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
comment|// CHECK-LABEL: @test_mm512_mask_moveldup_ps
comment|// CHECK: shufflevector<16 x float> %{{.*}},<16 x float> %{{.*}},<16 x i32><i32 0, i32 0, i32 2, i32 2, i32 4, i32 4, i32 6, i32 6, i32 8, i32 8, i32 10, i32 10, i32 12, i32 12, i32 14, i32 14>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x float> %{{.*}},<16 x float> %{{.*}}
return|return
name|_mm512_mask_moveldup_ps
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
name|__m512
name|test_mm512_maskz_moveldup_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_moveldup_ps
comment|// CHECK: shufflevector<16 x float> %{{.*}},<16 x float> %{{.*}},<16 x i32><i32 0, i32 0, i32 2, i32 2, i32 4, i32 4, i32 6, i32 6, i32 8, i32 8, i32 10, i32 10, i32 12, i32 12, i32 14, i32 14>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x float> %{{.*}},<16 x float> %{{.*}}
return|return
name|_mm512_maskz_moveldup_ps
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
name|test_mm512_shuffle_epi32
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_shuffle_epi32
comment|// CHECK: shufflevector<16 x i32> %{{.*}},<16 x i32> %{{.*}},<16 x i32><i32 1, i32 0, i32 0, i32 0, i32 5, i32 4, i32 4, i32 4, i32 9, i32 8, i32 8, i32 8, i32 13, i32 12, i32 12, i32 12>
return|return
name|_mm512_shuffle_epi32
argument_list|(
name|__A
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_shuffle_epi32
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
comment|// CHECK-LABEL: @test_mm512_mask_shuffle_epi32
comment|// CHECK: shufflevector<16 x i32> %{{.*}},<16 x i32> %{{.*}},<16 x i32><i32 1, i32 0, i32 0, i32 0, i32 5, i32 4, i32 4, i32 4, i32 9, i32 8, i32 8, i32 8, i32 13, i32 12, i32 12, i32 12>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_mask_shuffle_epi32
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
name|__m512i
name|test_mm512_maskz_shuffle_epi32
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_shuffle_epi32
comment|// CHECK: shufflevector<16 x i32> %{{.*}},<16 x i32> %{{.*}},<16 x i32><i32 1, i32 0, i32 0, i32 0, i32 5, i32 4, i32 4, i32 4, i32 9, i32 8, i32 8, i32 8, i32 13, i32 12, i32 12, i32 12>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_maskz_shuffle_epi32
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
name|__m512d
name|test_mm512_mask_expand_pd
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
comment|// CHECK-LABEL: @test_mm512_mask_expand_pd
comment|// CHECK: @llvm.x86.avx512.mask.expand.pd.512
return|return
name|_mm512_mask_expand_pd
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
name|test_mm512_maskz_expand_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_expand_pd
comment|// CHECK: @llvm.x86.avx512.mask.expand.pd.512
return|return
name|_mm512_maskz_expand_pd
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
name|test_mm512_mask_expand_epi64
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
comment|// CHECK-LABEL: @test_mm512_mask_expand_epi64
comment|// CHECK: @llvm.x86.avx512.mask.expand.q.512
return|return
name|_mm512_mask_expand_epi64
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
name|test_mm512_maskz_expand_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_expand_epi64
comment|// CHECK: @llvm.x86.avx512.mask.expand.q.512
return|return
name|_mm512_maskz_expand_epi64
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
name|test_mm512_mask_expandloadu_epi64
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|void
specifier|const
modifier|*
name|__P
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_expandloadu_epi64
comment|// CHECK: @llvm.x86.avx512.mask.expand.load.q.512
return|return
name|_mm512_mask_expandloadu_epi64
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__P
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_expandloadu_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|void
specifier|const
modifier|*
name|__P
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_expandloadu_epi64
comment|// CHECK: @llvm.x86.avx512.mask.expand.load.q.512
return|return
name|_mm512_maskz_expandloadu_epi64
argument_list|(
name|__U
argument_list|,
name|__P
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_expandloadu_pd
parameter_list|(
name|__m512d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|void
specifier|const
modifier|*
name|__P
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_expandloadu_pd
comment|// CHECK: @llvm.x86.avx512.mask.expand.load.pd.512
return|return
name|_mm512_mask_expandloadu_pd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__P
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_maskz_expandloadu_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|void
specifier|const
modifier|*
name|__P
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_expandloadu_pd
comment|// CHECK: @llvm.x86.avx512.mask.expand.load.pd.512
return|return
name|_mm512_maskz_expandloadu_pd
argument_list|(
name|__U
argument_list|,
name|__P
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_expandloadu_epi32
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|void
specifier|const
modifier|*
name|__P
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_expandloadu_epi32
comment|// CHECK: @llvm.x86.avx512.mask.expand.load.d.512
return|return
name|_mm512_mask_expandloadu_epi32
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__P
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_expandloadu_epi32
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|void
specifier|const
modifier|*
name|__P
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_expandloadu_epi32
comment|// CHECK: @llvm.x86.avx512.mask.expand.load.d.512
return|return
name|_mm512_maskz_expandloadu_epi32
argument_list|(
name|__U
argument_list|,
name|__P
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_expand_ps
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
comment|// CHECK-LABEL: @test_mm512_mask_expand_ps
comment|// CHECK: @llvm.x86.avx512.mask.expand.ps.512
return|return
name|_mm512_mask_expand_ps
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
name|__m512
name|test_mm512_maskz_expand_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_expand_ps
comment|// CHECK: @llvm.x86.avx512.mask.expand.ps.512
return|return
name|_mm512_maskz_expand_ps
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
name|test_mm512_mask_expand_epi32
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
comment|// CHECK-LABEL: @test_mm512_mask_expand_epi32
comment|// CHECK: @llvm.x86.avx512.mask.expand.d.512
return|return
name|_mm512_mask_expand_epi32
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
name|test_mm512_maskz_expand_epi32
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_expand_epi32
comment|// CHECK: @llvm.x86.avx512.mask.expand.d.512
return|return
name|_mm512_maskz_expand_epi32
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
name|test_mm512_cvt_roundps_pd
parameter_list|(
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvt_roundps_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2pd.512
return|return
name|_mm512_cvt_roundps_pd
argument_list|(
name|__A
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_cvt_roundps_pd
parameter_list|(
name|__m512d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvt_roundps_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2pd.512
return|return
name|_mm512_mask_cvt_roundps_pd
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
name|__m512d
name|test_mm512_maskz_cvt_roundps_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvt_roundps_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2pd.512
return|return
name|_mm512_maskz_cvt_roundps_pd
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
name|test_mm512_cvtps_pd
parameter_list|(
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtps_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2pd.512
return|return
name|_mm512_cvtps_pd
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_cvtpslo_pd
parameter_list|(
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtpslo_pd
comment|// CHECK: shufflevector<16 x float> %{{.*}},<16 x float> %{{.*}},<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2pd.512
return|return
name|_mm512_cvtpslo_pd
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_cvtps_pd
parameter_list|(
name|__m512d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtps_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2pd.512
return|return
name|_mm512_mask_cvtps_pd
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
name|test_mm512_mask_cvtpslo_pd
parameter_list|(
name|__m512d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtpslo_pd
comment|// CHECK: shufflevector<16 x float> %{{.*}},<16 x float> %{{.*}},<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2pd.512
return|return
name|_mm512_mask_cvtpslo_pd
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
name|test_mm512_maskz_cvtps_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtps_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2pd.512
return|return
name|_mm512_maskz_cvtps_pd
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
name|test_mm512_mask_mov_pd
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
comment|// CHECK-LABEL: @test_mm512_mask_mov_pd
comment|// CHECK: select<8 x i1> %{{.*}},<8 x double> %{{.*}},<8 x double> %{{.*}}
return|return
name|_mm512_mask_mov_pd
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
name|test_mm512_maskz_mov_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_mov_pd
comment|// CHECK: select<8 x i1> %{{.*}},<8 x double> %{{.*}},<8 x double> %{{.*}}
return|return
name|_mm512_maskz_mov_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_mov_ps
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
comment|// CHECK-LABEL: @test_mm512_mask_mov_ps
comment|// CHECK: select<16 x i1> %{{.*}},<16 x float> %{{.*}},<16 x float> %{{.*}}
return|return
name|_mm512_mask_mov_ps
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
name|__m512
name|test_mm512_maskz_mov_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_mov_ps
comment|// CHECK: select<16 x i1> %{{.*}},<16 x float> %{{.*}},<16 x float> %{{.*}}
return|return
name|_mm512_maskz_mov_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm512_mask_compressstoreu_pd
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_compressstoreu_pd
comment|// CHECK: @llvm.x86.avx512.mask.compress.store.pd.512
return|return
name|_mm512_mask_compressstoreu_pd
argument_list|(
name|__P
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm512_mask_compressstoreu_epi64
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_compressstoreu_epi64
comment|// CHECK: @llvm.x86.avx512.mask.compress.store.q.512
return|return
name|_mm512_mask_compressstoreu_epi64
argument_list|(
name|__P
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm512_mask_compressstoreu_ps
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_compressstoreu_ps
comment|// CHECK: @llvm.x86.avx512.mask.compress.store.ps.512
return|return
name|_mm512_mask_compressstoreu_ps
argument_list|(
name|__P
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm512_mask_compressstoreu_epi32
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_compressstoreu_epi32
comment|// CHECK: @llvm.x86.avx512.mask.compress.store.d.512
return|return
name|_mm512_mask_compressstoreu_epi32
argument_list|(
name|__P
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm512_cvtt_roundpd_epu32
parameter_list|(
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtt_roundpd_epu32
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2udq.512
return|return
name|_mm512_cvtt_roundpd_epu32
argument_list|(
name|__A
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm512_mask_cvtt_roundpd_epu32
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtt_roundpd_epu32
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2udq.512
return|return
name|_mm512_mask_cvtt_roundpd_epu32
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
name|__m256i
name|test_mm512_maskz_cvtt_roundpd_epu32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtt_roundpd_epu32
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2udq.512
return|return
name|_mm512_maskz_cvtt_roundpd_epu32
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
name|__m256i
name|test_mm512_cvttpd_epu32
parameter_list|(
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvttpd_epu32
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2udq.512
return|return
name|_mm512_cvttpd_epu32
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm512_mask_cvttpd_epu32
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvttpd_epu32
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2udq.512
return|return
name|_mm512_mask_cvttpd_epu32
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
name|__m256i
name|test_mm512_maskz_cvttpd_epu32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvttpd_epu32
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2udq.512
return|return
name|_mm512_maskz_cvttpd_epu32
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_castpd_ps
parameter_list|(
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_castpd_ps
comment|// CHECK: bitcast<8 x double> %{{.}} to<16 x float>
return|return
name|_mm512_castpd_ps
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_castps_pd
parameter_list|(
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_castps_pd
comment|// CHECK: bitcast<16 x float> %{{.}} to<8 x double>
return|return
name|_mm512_castps_pd
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_castpd_si512
parameter_list|(
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_castpd_si512
comment|// CHECK: bitcast<8 x double> %{{.}} to<8 x i64>
return|return
name|_mm512_castpd_si512
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_castps128_ps512
parameter_list|(
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_castps128_ps512
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> %{{.*}},<16 x i32><i32 0, i32 1, i32 2, i32 3, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
return|return
name|_mm512_castps128_ps512
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_castpd128_pd512
parameter_list|(
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_castpd128_pd512
comment|// CHECK: shufflevector<2 x double> %{{.*}},<2 x double> %{{.*}},<8 x i32><i32 0, i32 1, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
return|return
name|_mm512_castpd128_pd512
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_set1_epi8
parameter_list|(
name|char
name|d
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_set1_epi8
comment|// CHECK: insertelement<64 x i8> {{.*}}, i32 0
comment|// CHECK: insertelement<64 x i8> {{.*}}, i32 1
comment|// CHECK: insertelement<64 x i8> {{.*}}, i32 2
comment|// CHECK: insertelement<64 x i8> {{.*}}, i32 3
comment|// CHECK: insertelement<64 x i8> {{.*}}, i32 4
comment|// CHECK: insertelement<64 x i8> {{.*}}, i32 5
comment|// CHECK: insertelement<64 x i8> {{.*}}, i32 6
comment|// CHECK: insertelement<64 x i8> {{.*}}, i32 7
comment|// CHECK: insertelement<64 x i8> {{.*}}, i32 63
return|return
name|_mm512_set1_epi8
argument_list|(
name|d
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_set1_epi16
parameter_list|(
name|short
name|d
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_set1_epi16
comment|// CHECK: insertelement<32 x i16> {{.*}}, i32 0
comment|// CHECK: insertelement<32 x i16> {{.*}}, i32 1
comment|// CHECK: insertelement<32 x i16> {{.*}}, i32 2
comment|// CHECK: insertelement<32 x i16> {{.*}}, i32 3
comment|// CHECK: insertelement<32 x i16> {{.*}}, i32 4
comment|// CHECK: insertelement<32 x i16> {{.*}}, i32 5
comment|// CHECK: insertelement<32 x i16> {{.*}}, i32 6
comment|// CHECK: insertelement<32 x i16> {{.*}}, i32 7
comment|// CHECK: insertelement<32 x i16> {{.*}}, i32 31
return|return
name|_mm512_set1_epi16
argument_list|(
name|d
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_set4_epi32
parameter_list|(
name|int
name|__A
parameter_list|,
name|int
name|__B
parameter_list|,
name|int
name|__C
parameter_list|,
name|int
name|__D
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_set4_epi32
comment|// CHECK: insertelement<16 x i32> {{.*}}, i32 15
return|return
name|_mm512_set4_epi32
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__D
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_set4_epi64
parameter_list|(
name|long
name|long
name|__A
parameter_list|,
name|long
name|long
name|__B
parameter_list|,
name|long
name|long
name|__C
parameter_list|,
name|long
name|long
name|__D
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_set4_epi64
comment|// CHECK: insertelement<8 x i64> {{.*}}, i32 7
return|return
name|_mm512_set4_epi64
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__D
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_set4_pd
parameter_list|(
name|double
name|__A
parameter_list|,
name|double
name|__B
parameter_list|,
name|double
name|__C
parameter_list|,
name|double
name|__D
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_set4_pd
comment|// CHECK: insertelement<8 x double> {{.*}}, i32 7
return|return
name|_mm512_set4_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__D
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_set4_ps
parameter_list|(
name|float
name|__A
parameter_list|,
name|float
name|__B
parameter_list|,
name|float
name|__C
parameter_list|,
name|float
name|__D
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_set4_ps
comment|// CHECK: insertelement<16 x float> {{.*}}, i32 15
return|return
name|_mm512_set4_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__D
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_setr4_epi32
parameter_list|(
name|int
name|e0
parameter_list|,
name|int
name|e1
parameter_list|,
name|int
name|e2
parameter_list|,
name|int
name|e3
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_setr4_epi32
comment|// CHECK: insertelement<16 x i32> {{.*}}, i32 15
return|return
name|_mm512_setr4_epi32
argument_list|(
name|e0
argument_list|,
name|e1
argument_list|,
name|e2
argument_list|,
name|e3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_setr4_epi64
parameter_list|(
name|long
name|long
name|e0
parameter_list|,
name|long
name|long
name|e1
parameter_list|,
name|long
name|long
name|e2
parameter_list|,
name|long
name|long
name|e3
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_setr4_epi64
comment|// CHECK: insertelement<8 x i64> {{.*}}, i32 7
return|return
name|_mm512_setr4_epi64
argument_list|(
name|e0
argument_list|,
name|e1
argument_list|,
name|e2
argument_list|,
name|e3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_setr4_pd
parameter_list|(
name|double
name|e0
parameter_list|,
name|double
name|e1
parameter_list|,
name|double
name|e2
parameter_list|,
name|double
name|e3
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_setr4_pd
comment|// CHECK: insertelement<8 x double> {{.*}}, i32 7
return|return
name|_mm512_setr4_pd
argument_list|(
name|e0
argument_list|,
name|e1
argument_list|,
name|e2
argument_list|,
name|e3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_setr4_ps
parameter_list|(
name|float
name|e0
parameter_list|,
name|float
name|e1
parameter_list|,
name|float
name|e2
parameter_list|,
name|float
name|e3
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_setr4_ps
comment|// CHECK: insertelement<16 x float> {{.*}}, i32 15
return|return
name|_mm512_setr4_ps
argument_list|(
name|e0
argument_list|,
name|e1
argument_list|,
name|e2
argument_list|,
name|e3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_castpd256_pd512
parameter_list|(
name|__m256d
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_castpd256_pd512
comment|// CHECK: shufflevector<4 x double> {{.*}}<i32 0, i32 1, i32 2, i32 3, i32 undef, i32 undef, i32 undef, i32 undef>
return|return
name|_mm512_castpd256_pd512
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm512_castpd512_pd256
parameter_list|(
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_castpd512_pd256
comment|// CHECK: shufflevector<8 x double> %{{.}},<8 x double> %{{.}},<4 x i32><i32 0, i32 1, i32 2, i32 3>
return|return
name|_mm512_castpd512_pd256
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm512_castps512_ps256
parameter_list|(
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_castps512_ps256
comment|// CHECK: shufflevector<16 x float> %{{.}},<16 x float> %{{.}},<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
return|return
name|_mm512_castps512_ps256
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_castps_si512
parameter_list|(
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_castps_si512
comment|// CHECK: bitcast<16 x float> %{{.}} to<8 x i64>
return|return
name|_mm512_castps_si512
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_castsi128_si512
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_castsi128_si512
comment|// CHECK: shufflevector<2 x i64> %{{.*}},<2 x i64> %{{.*}},<8 x i32><i32 0, i32 1, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
return|return
name|_mm512_castsi128_si512
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_castsi256_si512
parameter_list|(
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_castsi256_si512
comment|// CHECK: shufflevector<4 x i64> %{{.*}},<4 x i64> %{{.*}},<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 undef, i32 undef, i32 undef, i32 undef>
return|return
name|_mm512_castsi256_si512
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_castsi512_ps
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_castsi512_ps
comment|// CHECK: bitcast<8 x i64> %{{.}} to<16 x float>
return|return
name|_mm512_castsi512_ps
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_castsi512_pd
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_castsi512_pd
comment|// CHECK: bitcast<8 x i64> %{{.}} to<8 x double>
return|return
name|_mm512_castsi512_pd
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm512_castsi512_si128
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_castsi512_si128
comment|// CHECK: shufflevector<8 x i64> %{{.}},<8 x i64> %{{.}},<2 x i32><i32 0, i32 1>
return|return
name|_mm512_castsi512_si128
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm512_castsi512_si256
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_castsi512_si256
comment|// CHECK: shufflevector<8 x i64> %{{.}},<8 x i64> %{{.}},<4 x i32><i32 0, i32 1, i32 2, i32 3>
return|return
name|_mm512_castsi512_si256
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_cvt_roundsd_ss
parameter_list|(
name|__m128
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvt_roundsd_ss
comment|// CHECK: @llvm.x86.avx512.mask.cvtsd2ss.round
return|return
name|_mm_cvt_roundsd_ss
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_cvt_roundsd_ss
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
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cvt_roundsd_ss
comment|// CHECK: @llvm.x86.avx512.mask.cvtsd2ss.round
return|return
name|_mm_mask_cvt_roundsd_ss
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_maskz_cvt_roundsd_ss
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvt_roundsd_ss
comment|// CHECK: @llvm.x86.avx512.mask.cvtsd2ss.round
return|return
name|_mm_maskz_cvt_roundsd_ss
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|__x86_64__
end_ifdef

begin_function
name|__m128d
name|test_mm_cvt_roundi64_sd
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|long
name|long
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvt_roundi64_sd
comment|// CHECK: @llvm.x86.avx512.cvtsi2sd64
return|return
name|_mm_cvt_roundi64_sd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_cvt_roundsi64_sd
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|long
name|long
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvt_roundsi64_sd
comment|// CHECK: @llvm.x86.avx512.cvtsi2sd64
return|return
name|_mm_cvt_roundsi64_sd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|__m128
name|test_mm_cvt_roundsi32_ss
parameter_list|(
name|__m128
name|__A
parameter_list|,
name|int
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvt_roundsi32_ss
comment|// CHECK: @llvm.x86.avx512.cvtsi2ss32
return|return
name|_mm_cvt_roundsi32_ss
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_cvt_roundi32_ss
parameter_list|(
name|__m128
name|__A
parameter_list|,
name|int
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvt_roundi32_ss
comment|// CHECK: @llvm.x86.avx512.cvtsi2ss32
return|return
name|_mm_cvt_roundi32_ss
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|__x86_64__
end_ifdef

begin_function
name|__m128
name|test_mm_cvt_roundsi64_ss
parameter_list|(
name|__m128
name|__A
parameter_list|,
name|long
name|long
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvt_roundsi64_ss
comment|// CHECK: @llvm.x86.avx512.cvtsi2ss64
return|return
name|_mm_cvt_roundsi64_ss
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_cvt_roundi64_ss
parameter_list|(
name|__m128
name|__A
parameter_list|,
name|long
name|long
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvt_roundi64_ss
comment|// CHECK: @llvm.x86.avx512.cvtsi2ss64
return|return
name|_mm_cvt_roundi64_ss
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|__m128d
name|test_mm_cvt_roundss_sd
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvt_roundss_sd
comment|// CHECK: @llvm.x86.avx512.mask.cvtss2sd.round
return|return
name|_mm_cvt_roundss_sd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_cvt_roundss_sd
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
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cvt_roundss_sd
comment|// CHECK: @llvm.x86.avx512.mask.cvtss2sd.round
return|return
name|_mm_mask_cvt_roundss_sd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_maskz_cvt_roundss_sd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvt_roundss_sd
comment|// CHECK: @llvm.x86.avx512.mask.cvtss2sd.round
return|return
name|_mm_maskz_cvt_roundss_sd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_cvtu32_sd
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|unsigned
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtu32_sd
comment|// CHECK: @llvm.x86.avx512.cvtusi2sd
return|return
name|_mm_cvtu32_sd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|__x86_64__
end_ifdef

begin_function
name|__m128d
name|test_mm_cvt_roundu64_sd
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|unsigned
name|long
name|long
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvt_roundu64_sd
comment|// CHECK: @llvm.x86.avx512.cvtusi642sd
return|return
name|_mm_cvt_roundu64_sd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_cvtu64_sd
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|unsigned
name|long
name|long
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtu64_sd
comment|// CHECK: @llvm.x86.avx512.cvtusi642sd
return|return
name|_mm_cvtu64_sd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|__m128
name|test_mm_cvt_roundu32_ss
parameter_list|(
name|__m128
name|__A
parameter_list|,
name|unsigned
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvt_roundu32_ss
comment|// CHECK: @llvm.x86.avx512.cvtusi2ss
return|return
name|_mm_cvt_roundu32_ss
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_cvtu32_ss
parameter_list|(
name|__m128
name|__A
parameter_list|,
name|unsigned
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtu32_ss
comment|// CHECK: @llvm.x86.avx512.cvtusi2ss
return|return
name|_mm_cvtu32_ss
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|__x86_64__
end_ifdef

begin_function
name|__m128
name|test_mm_cvt_roundu64_ss
parameter_list|(
name|__m128
name|__A
parameter_list|,
name|unsigned
name|long
name|long
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvt_roundu64_ss
comment|// CHECK: @llvm.x86.avx512.cvtusi642ss
return|return
name|_mm_cvt_roundu64_ss
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_cvtu64_ss
parameter_list|(
name|__m128
name|__A
parameter_list|,
name|unsigned
name|long
name|long
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtu64_ss
comment|// CHECK: @llvm.x86.avx512.cvtusi642ss
return|return
name|_mm_cvtu64_ss
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|__m512i
name|test_mm512_mask_cvttps_epu32
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvttps_epu32
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2udq.512
return|return
name|_mm512_mask_cvttps_epu32
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
name|test_mm512_maskz_cvttps_epu32
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvttps_epu32
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2udq.512
return|return
name|_mm512_maskz_cvttps_epu32
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_cvtepu32_ps
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtepu32_ps
comment|// CHECK:  @llvm.x86.avx512.mask.cvtudq2ps.512
return|return
name|_mm512_cvtepu32_ps
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_cvtepu32_ps
parameter_list|(
name|__m512
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtepu32_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtudq2ps.512
return|return
name|_mm512_mask_cvtepu32_ps
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
name|__m512
name|test_mm512_maskz_cvtepu32_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtepu32_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtudq2ps.512
return|return
name|_mm512_maskz_cvtepu32_ps
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
name|test_mm512_cvtepi32_pd
parameter_list|(
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtepi32_pd
comment|// CHECK: sitofp<8 x i32> %{{.*}} to<8 x double>
return|return
name|_mm512_cvtepi32_pd
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_cvtepi32_pd
parameter_list|(
name|__m512d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtepi32_pd
comment|// CHECK: sitofp<8 x i32> %{{.*}} to<8 x double>
comment|// CHECK: select<8 x i1> {{.*}},<8 x double> {{.*}},<8 x double> {{.*}}
return|return
name|_mm512_mask_cvtepi32_pd
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
name|test_mm512_maskz_cvtepi32_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtepi32_pd
comment|// CHECK: sitofp<8 x i32> %{{.*}} to<8 x double>
comment|// CHECK: select<8 x i1> {{.*}},<8 x double> {{.*}},<8 x double> {{.*}}
return|return
name|_mm512_maskz_cvtepi32_pd
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
name|test_mm512_cvtepi32lo_pd
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtepi32lo_pd
comment|// CHECK: shufflevector<8 x i64> %{{.*}},<8 x i64> %{{.*}},<4 x i32><i32 0, i32 1, i32 2, i32 3>
comment|// CHECK: sitofp<8 x i32> %{{.*}} to<8 x double>
return|return
name|_mm512_cvtepi32lo_pd
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_cvtepi32lo_pd
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
comment|// CHECK-LABEL: @test_mm512_mask_cvtepi32lo_pd
comment|// CHECK: shufflevector<8 x i64> %{{.*}},<8 x i64> %{{.*}},<4 x i32><i32 0, i32 1, i32 2, i32 3>
comment|// CHECK: sitofp<8 x i32> %{{.*}} to<8 x double>
comment|// CHECK: select<8 x i1> {{.*}},<8 x double> {{.*}},<8 x double> {{.*}}
return|return
name|_mm512_mask_cvtepi32lo_pd
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
name|__m512
name|test_mm512_cvtepi32_ps
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtepi32_ps
comment|// CHECK:  @llvm.x86.avx512.mask.cvtdq2ps.512
return|return
name|_mm512_cvtepi32_ps
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_cvtepi32_ps
parameter_list|(
name|__m512
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtepi32_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtdq2ps.512
return|return
name|_mm512_mask_cvtepi32_ps
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
name|__m512
name|test_mm512_maskz_cvtepi32_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtepi32_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtdq2ps.512
return|return
name|_mm512_maskz_cvtepi32_ps
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
name|test_mm512_cvtepu32_pd
parameter_list|(
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtepu32_pd
comment|// CHECK: uitofp<8 x i32> %{{.*}} to<8 x double>
return|return
name|_mm512_cvtepu32_pd
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_cvtepu32_pd
parameter_list|(
name|__m512d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtepu32_pd
comment|// CHECK: uitofp<8 x i32> %{{.*}} to<8 x double>
comment|// CHECK: select<8 x i1> {{.*}},<8 x double> {{.*}},<8 x double> {{.*}}
return|return
name|_mm512_mask_cvtepu32_pd
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
name|test_mm512_maskz_cvtepu32_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtepu32_pd
comment|// CHECK: uitofp<8 x i32> %{{.*}} to<8 x double>
comment|// CHECK: select<8 x i1> {{.*}},<8 x double> {{.*}},<8 x double> {{.*}}
return|return
name|_mm512_maskz_cvtepu32_pd
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
name|test_mm512_cvtepu32lo_pd
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtepu32lo_pd
comment|// CHECK: shufflevector<8 x i64> %{{.*}},<8 x i64> %{{.*}},<4 x i32><i32 0, i32 1, i32 2, i32 3>
comment|// CHECK: uitofp<8 x i32> %{{.*}} to<8 x double>
return|return
name|_mm512_cvtepu32lo_pd
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_cvtepu32lo_pd
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
comment|// CHECK-LABEL: @test_mm512_mask_cvtepu32lo_pd
comment|// CHECK: shufflevector<8 x i64> %{{.*}},<8 x i64> %{{.*}},<4 x i32><i32 0, i32 1, i32 2, i32 3>
comment|// CHECK: uitofp<8 x i32> %{{.*}} to<8 x double>
comment|// CHECK: select<8 x i1> {{.*}},<8 x double> {{.*}},<8 x double> {{.*}}
return|return
name|_mm512_mask_cvtepu32lo_pd
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
name|test_mm512_cvtpd_ps
parameter_list|(
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtpd_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2ps.512
return|return
name|_mm512_cvtpd_ps
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm512_mask_cvtpd_ps
parameter_list|(
name|__m256
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtpd_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2ps.512
return|return
name|_mm512_mask_cvtpd_ps
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
name|test_mm512_cvtpd_pslo
parameter_list|(
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtpd_pslo
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2ps.512
comment|// CHECK: zeroinitializer
comment|// CHECK: shufflevector<8 x float> %{{.*}},<8 x float> %{{.*}},<16 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15>
return|return
name|_mm512_cvtpd_pslo
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_cvtpd_pslo
parameter_list|(
name|__m512
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtpd_pslo
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2ps.512
comment|// CHECK: zeroinitializer
comment|// CHECK: shufflevector<8 x float> %{{.*}},<8 x float> %{{.*}},<16 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15>
return|return
name|_mm512_mask_cvtpd_pslo
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
name|test_mm512_maskz_cvtpd_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtpd_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2ps.512
return|return
name|_mm512_maskz_cvtpd_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_cvtph_ps
parameter_list|(
name|__m512
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtph_ps
comment|// CHECK: @llvm.x86.avx512.mask.vcvtph2ps.512
return|return
name|_mm512_mask_cvtph_ps
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
name|__m512
name|test_mm512_maskz_cvtph_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtph_ps
comment|// CHECK: @llvm.x86.avx512.mask.vcvtph2ps.512
return|return
name|_mm512_maskz_cvtph_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm512_mask_cvttpd_epi32
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvttpd_epi32
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2dq.512
return|return
name|_mm512_mask_cvttpd_epi32
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
name|__m256i
name|test_mm512_maskz_cvttpd_epi32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvttpd_epi32
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2dq.512
return|return
name|_mm512_maskz_cvttpd_epi32
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
name|test_mm512_mask_cvttps_epi32
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvttps_epi32
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2dq.512
return|return
name|_mm512_mask_cvttps_epi32
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
name|test_mm512_maskz_cvttps_epi32
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvttps_epi32
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2dq.512
return|return
name|_mm512_maskz_cvttps_epi32
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
name|test_mm512_cvtps_epi32
parameter_list|(
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtps_epi32
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2dq.512
return|return
name|_mm512_cvtps_epi32
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_cvtps_epi32
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtps_epi32
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2dq.512
return|return
name|_mm512_mask_cvtps_epi32
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
name|test_mm512_maskz_cvtps_epi32
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtps_epi32
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2dq.512
return|return
name|_mm512_maskz_cvtps_epi32
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm512_cvtpd_epi32
parameter_list|(
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtpd_epi32
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2dq.512
return|return
name|_mm512_cvtpd_epi32
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm512_mask_cvtpd_epi32
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtpd_epi32
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2dq.512
return|return
name|_mm512_mask_cvtpd_epi32
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
name|__m256i
name|test_mm512_maskz_cvtpd_epi32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtpd_epi32
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2dq.512
return|return
name|_mm512_maskz_cvtpd_epi32
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm512_cvtpd_epu32
parameter_list|(
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtpd_epu32
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2udq.512
return|return
name|_mm512_cvtpd_epu32
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm512_mask_cvtpd_epu32
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtpd_epu32
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2udq.512
return|return
name|_mm512_mask_cvtpd_epu32
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
name|__m256i
name|test_mm512_maskz_cvtpd_epu32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtpd_epu32
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2udq.512
return|return
name|_mm512_maskz_cvtpd_epu32
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm512_mask_cvtps_ph
parameter_list|(
name|__m256i
name|src
parameter_list|,
name|__mmask16
name|k
parameter_list|,
name|__m512
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtps_ph
comment|// CHECK: @llvm.x86.avx512.mask.vcvtps2ph.512
return|return
name|_mm512_mask_cvtps_ph
argument_list|(
name|src
argument_list|,
name|k
argument_list|,
name|a
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm512_maskz_cvtps_ph
parameter_list|(
name|__mmask16
name|k
parameter_list|,
name|__m512
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtps_ph
comment|// CHECK: @llvm.x86.avx512.mask.vcvtps2ph.512
return|return
name|_mm512_maskz_cvtps_ph
argument_list|(
name|k
argument_list|,
name|a
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_cvtps_epu32
parameter_list|(
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtps_epu32
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2udq.512
return|return
name|_mm512_cvtps_epu32
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_cvtps_epu32
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtps_epu32
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2udq.512
return|return
name|_mm512_mask_cvtps_epu32
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
name|test_mm512_maskz_cvtps_epu32
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtps_epu32
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2udq.512
return|return
name|_mm512_maskz_cvtps_epu32
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|double
name|test_mm512_cvtsd_f64
parameter_list|(
name|__m512d
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm512_cvtsd_f64
comment|// CHECK: extractelement<8 x double> %{{.*}}, i32 0
return|return
name|_mm512_cvtsd_f64
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|float
name|test_mm512_cvtss_f32
parameter_list|(
name|__m512
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm512_cvtss_f32
comment|// CHECK: extractelement<16 x float> %{{.*}}, i32 0
return|return
name|_mm512_cvtss_f32
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_max_pd
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
comment|// CHECK-LABEL: @test_mm512_mask_max_pd
comment|// CHECK: @llvm.x86.avx512.mask.max.pd.512
return|return
name|_mm512_mask_max_pd
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
name|test_mm512_maskz_max_pd
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
comment|// CHECK-LABEL: @test_mm512_maskz_max_pd
comment|// CHECK: @llvm.x86.avx512.mask.max.pd.512
return|return
name|_mm512_maskz_max_pd
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
name|test_mm512_mask_max_ps
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
comment|// CHECK-LABEL: @test_mm512_mask_max_ps
comment|// CHECK: @llvm.x86.avx512.mask.max.ps.512
return|return
name|_mm512_mask_max_ps
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
name|test_mm512_mask_max_round_pd
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
comment|// CHECK-LABEL: @test_mm512_mask_max_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.max.pd.512
return|return
name|_mm512_mask_max_round_pd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_maskz_max_round_pd
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
comment|// CHECK-LABEL: @test_mm512_maskz_max_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.max.pd.512
return|return
name|_mm512_maskz_max_round_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_max_round_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_max_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.max.pd.512
return|return
name|_mm512_max_round_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_maskz_max_ps
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
comment|// CHECK-LABEL: @test_mm512_maskz_max_ps
comment|// CHECK: @llvm.x86.avx512.mask.max.ps.512
return|return
name|_mm512_maskz_max_ps
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
name|test_mm512_mask_max_round_ps
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
comment|// CHECK-LABEL: @test_mm512_mask_max_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.max.ps.512
return|return
name|_mm512_mask_max_round_ps
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_maskz_max_round_ps
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
comment|// CHECK-LABEL: @test_mm512_maskz_max_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.max.ps.512
return|return
name|_mm512_maskz_max_round_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_max_round_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_max_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.max.ps.512
return|return
name|_mm512_max_round_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_min_pd
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
comment|// CHECK-LABEL: @test_mm512_mask_min_pd
comment|// CHECK: @llvm.x86.avx512.mask.min.pd.512
return|return
name|_mm512_mask_min_pd
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
name|test_mm512_maskz_min_pd
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
comment|// CHECK-LABEL: @test_mm512_maskz_min_pd
comment|// CHECK: @llvm.x86.avx512.mask.min.pd.512
return|return
name|_mm512_maskz_min_pd
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
name|test_mm512_mask_min_round_pd
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
comment|// CHECK-LABEL: @test_mm512_mask_min_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.min.pd.512
return|return
name|_mm512_mask_min_round_pd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_maskz_min_round_pd
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
comment|// CHECK-LABEL: @test_mm512_maskz_min_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.min.pd.512
return|return
name|_mm512_maskz_min_round_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_min_round_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_min_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.min.pd.512
return|return
name|_mm512_min_round_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_min_ps
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
comment|// CHECK-LABEL: @test_mm512_mask_min_ps
comment|// CHECK: @llvm.x86.avx512.mask.min.ps.512
return|return
name|_mm512_mask_min_ps
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
name|test_mm512_maskz_min_ps
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
comment|// CHECK-LABEL: @test_mm512_maskz_min_ps
comment|// CHECK: @llvm.x86.avx512.mask.min.ps.512
return|return
name|_mm512_maskz_min_ps
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
name|test_mm512_mask_min_round_ps
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
comment|// CHECK-LABEL: @test_mm512_mask_min_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.min.ps.512
return|return
name|_mm512_mask_min_round_ps
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_maskz_min_round_ps
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
comment|// CHECK-LABEL: @test_mm512_maskz_min_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.min.ps.512
return|return
name|_mm512_maskz_min_round_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_min_round_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_min_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.min.ps.512
return|return
name|_mm512_min_round_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_floor_ps
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
comment|// CHECK-LABEL: @test_mm512_mask_floor_ps
comment|// CHECK: @llvm.x86.avx512.mask.rndscale.ps.512
return|return
name|_mm512_mask_floor_ps
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
name|test_mm512_mask_floor_pd
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
comment|// CHECK-LABEL: @test_mm512_mask_floor_pd
comment|// CHECK: @llvm.x86.avx512.mask.rndscale.pd.512
return|return
name|_mm512_mask_floor_pd
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
name|__m512
name|test_mm512_mask_ceil_ps
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
comment|// CHECK-LABEL: @test_mm512_mask_ceil_ps
comment|// CHECK: @llvm.x86.avx512.mask.rndscale.ps.512
return|return
name|_mm512_mask_ceil_ps
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
name|test_mm512_mask_ceil_pd
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
comment|// CHECK-LABEL: @test_mm512_mask_ceil_pd
comment|// CHECK: @llvm.x86.avx512.mask.rndscale.pd.512
return|return
name|_mm512_mask_ceil_pd
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
name|__m512
name|test_mm512_mask_roundscale_ps
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
comment|// CHECK-LABEL: @test_mm512_mask_roundscale_ps
comment|// CHECK: @llvm.x86.avx512.mask.rndscale.ps.512
return|return
name|_mm512_mask_roundscale_ps
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
name|__m512
name|test_mm512_maskz_roundscale_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_roundscale_ps
comment|// CHECK: @llvm.x86.avx512.mask.rndscale.ps.512
return|return
name|_mm512_maskz_roundscale_ps
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
name|__m512
name|test_mm512_mask_roundscale_round_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_roundscale_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.rndscale.ps.512
return|return
name|_mm512_mask_roundscale_round_ps
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__C
argument_list|,
literal|3
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_maskz_roundscale_round_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__mmask16
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_roundscale_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.rndscale.ps.512
return|return
name|_mm512_maskz_roundscale_round_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
literal|3
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_roundscale_round_ps
parameter_list|(
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_roundscale_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.rndscale.ps.512
return|return
name|_mm512_roundscale_round_ps
argument_list|(
name|__A
argument_list|,
literal|3
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_roundscale_pd
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
comment|// CHECK-LABEL: @test_mm512_mask_roundscale_pd
comment|// CHECK: @llvm.x86.avx512.mask.rndscale.pd.512
return|return
name|_mm512_mask_roundscale_pd
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
name|__m512d
name|test_mm512_maskz_roundscale_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_roundscale_pd
comment|// CHECK: @llvm.x86.avx512.mask.rndscale.pd.512
return|return
name|_mm512_maskz_roundscale_pd
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
name|__m512d
name|test_mm512_mask_roundscale_round_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_roundscale_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.rndscale.pd.512
return|return
name|_mm512_mask_roundscale_round_pd
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__C
argument_list|,
literal|3
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_maskz_roundscale_round_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_roundscale_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.rndscale.pd.512
return|return
name|_mm512_maskz_roundscale_round_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
literal|3
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_roundscale_round_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_roundscale_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.rndscale.pd.512
return|return
name|_mm512_roundscale_round_pd
argument_list|(
name|__A
argument_list|,
literal|3
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_max_epi32
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_max_epi32
comment|// CHECK:       [[CMP:%.*]] = icmp sgt<16 x i32> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<16 x i1> [[CMP]],<16 x i32> [[X]],<16 x i32> [[Y]]
return|return
name|_mm512_max_epi32
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_max_epi32
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask16
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_max_epi32
comment|// CHECK:       [[CMP:%.*]] = icmp sgt<16 x i32> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<16 x i1> [[CMP]],<16 x i32> [[X]],<16 x i32> [[Y]]
comment|// CHECK:       select<16 x i1> {{.*}},<16 x i32> [[RES]],<16 x i32> {{.*}}
return|return
name|_mm512_mask_max_epi32
argument_list|(
name|__W
argument_list|,
name|__M
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
name|test_mm512_maskz_max_epi32
parameter_list|(
name|__mmask16
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_max_epi32
comment|// CHECK:       [[CMP:%.*]] = icmp sgt<16 x i32> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<16 x i1> [[CMP]],<16 x i32> [[X]],<16 x i32> [[Y]]
comment|// CHECK:       select<16 x i1> {{.*}},<16 x i32> [[RES]],<16 x i32> {{.*}}
return|return
name|_mm512_maskz_max_epi32
argument_list|(
name|__M
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
name|test_mm512_max_epi64
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_max_epi64
comment|// CHECK:       [[CMP:%.*]] = icmp sgt<8 x i64> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<8 x i1> [[CMP]],<8 x i64> [[X]],<8 x i64> [[Y]]
return|return
name|_mm512_max_epi64
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_max_epi64
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_max_epi64
comment|// CHECK:       [[CMP:%.*]] = icmp sgt<8 x i64> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<8 x i1> [[CMP]],<8 x i64> [[X]],<8 x i64> [[Y]]
comment|// CHECK:       select<8 x i1> {{.*}},<8 x i64> [[RES]],<8 x i64> {{.*}}
return|return
name|_mm512_mask_max_epi64
argument_list|(
name|__W
argument_list|,
name|__M
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
name|test_mm512_maskz_max_epi64
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_max_epi64
comment|// CHECK:       [[CMP:%.*]] = icmp sgt<8 x i64> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<8 x i1> [[CMP]],<8 x i64> [[X]],<8 x i64> [[Y]]
comment|// CHECK:       select<8 x i1> {{.*}},<8 x i64> [[RES]],<8 x i64> {{.*}}
return|return
name|_mm512_maskz_max_epi64
argument_list|(
name|__M
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
name|test_mm512_max_epu64
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_max_epu64
comment|// CHECK:       [[CMP:%.*]] = icmp ugt<8 x i64> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<8 x i1> [[CMP]],<8 x i64> [[X]],<8 x i64> [[Y]]
return|return
name|_mm512_max_epu64
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_max_epu64
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_max_epu64
comment|// CHECK:       [[CMP:%.*]] = icmp ugt<8 x i64> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<8 x i1> [[CMP]],<8 x i64> [[X]],<8 x i64> [[Y]]
comment|// CHECK:       select<8 x i1> {{.*}},<8 x i64> [[RES]],<8 x i64> {{.*}}
return|return
name|_mm512_mask_max_epu64
argument_list|(
name|__W
argument_list|,
name|__M
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
name|test_mm512_maskz_max_epu64
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_max_epu64
comment|// CHECK:       [[CMP:%.*]] = icmp ugt<8 x i64> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<8 x i1> [[CMP]],<8 x i64> [[X]],<8 x i64> [[Y]]
comment|// CHECK:       select<8 x i1> {{.*}},<8 x i64> [[RES]],<8 x i64> {{.*}}
return|return
name|_mm512_maskz_max_epu64
argument_list|(
name|__M
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
name|test_mm512_max_epu32
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_max_epu32
comment|// CHECK:       [[CMP:%.*]] = icmp ugt<16 x i32> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<16 x i1> [[CMP]],<16 x i32> [[X]],<16 x i32> [[Y]]
return|return
name|_mm512_max_epu32
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_max_epu32
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask16
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_max_epu32
comment|// CHECK:       [[CMP:%.*]] = icmp ugt<16 x i32> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<16 x i1> [[CMP]],<16 x i32> [[X]],<16 x i32> [[Y]]
comment|// CHECK:       select<16 x i1> {{.*}},<16 x i32> [[RES]],<16 x i32> {{.*}}
return|return
name|_mm512_mask_max_epu32
argument_list|(
name|__W
argument_list|,
name|__M
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
name|test_mm512_maskz_max_epu32
parameter_list|(
name|__mmask16
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_max_epu32
comment|// CHECK:       [[CMP:%.*]] = icmp ugt<16 x i32> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<16 x i1> [[CMP]],<16 x i32> [[X]],<16 x i32> [[Y]]
comment|// CHECK:       select<16 x i1> {{.*}},<16 x i32> [[RES]],<16 x i32> {{.*}}
return|return
name|_mm512_maskz_max_epu32
argument_list|(
name|__M
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
name|test_mm512_min_epi32
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_min_epi32
comment|// CHECK:       [[CMP:%.*]] = icmp slt<16 x i32> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<16 x i1> [[CMP]],<16 x i32> [[X]],<16 x i32> [[Y]]
return|return
name|_mm512_min_epi32
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_min_epi32
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask16
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_min_epi32
comment|// CHECK:       [[CMP:%.*]] = icmp slt<16 x i32> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<16 x i1> [[CMP]],<16 x i32> [[X]],<16 x i32> [[Y]]
comment|// CHECK:       select<16 x i1> {{.*}},<16 x i32> [[RES]],<16 x i32> {{.*}}
return|return
name|_mm512_mask_min_epi32
argument_list|(
name|__W
argument_list|,
name|__M
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
name|test_mm512_maskz_min_epi32
parameter_list|(
name|__mmask16
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_min_epi32
comment|// CHECK:       [[CMP:%.*]] = icmp slt<16 x i32> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<16 x i1> [[CMP]],<16 x i32> [[X]],<16 x i32> [[Y]]
comment|// CHECK:       select<16 x i1> {{.*}},<16 x i32> [[RES]],<16 x i32> {{.*}}
return|return
name|_mm512_maskz_min_epi32
argument_list|(
name|__M
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
name|test_mm512_min_epu32
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_min_epu32
comment|// CHECK:       [[CMP:%.*]] = icmp ult<16 x i32> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<16 x i1> [[CMP]],<16 x i32> [[X]],<16 x i32> [[Y]]
return|return
name|_mm512_min_epu32
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_min_epu32
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask16
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_min_epu32
comment|// CHECK:       [[CMP:%.*]] = icmp ult<16 x i32> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<16 x i1> [[CMP]],<16 x i32> [[X]],<16 x i32> [[Y]]
comment|// CHECK:       select<16 x i1> {{.*}},<16 x i32> [[RES]],<16 x i32> {{.*}}
return|return
name|_mm512_mask_min_epu32
argument_list|(
name|__W
argument_list|,
name|__M
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
name|test_mm512_maskz_min_epu32
parameter_list|(
name|__mmask16
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_min_epu32
comment|// CHECK:       [[CMP:%.*]] = icmp ult<16 x i32> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<16 x i1> [[CMP]],<16 x i32> [[X]],<16 x i32> [[Y]]
comment|// CHECK:       select<16 x i1> {{.*}},<16 x i32> [[RES]],<16 x i32> {{.*}}
return|return
name|_mm512_maskz_min_epu32
argument_list|(
name|__M
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
name|test_mm512_min_epi64
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_min_epi64
comment|// CHECK:       [[CMP:%.*]] = icmp slt<8 x i64> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<8 x i1> [[CMP]],<8 x i64> [[X]],<8 x i64> [[Y]]
return|return
name|_mm512_min_epi64
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_min_epi64
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_min_epi64
comment|// CHECK:       [[CMP:%.*]] = icmp slt<8 x i64> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<8 x i1> [[CMP]],<8 x i64> [[X]],<8 x i64> [[Y]]
comment|// CHECK:       select<8 x i1> {{.*}},<8 x i64> [[RES]],<8 x i64> {{.*}}
return|return
name|_mm512_mask_min_epi64
argument_list|(
name|__W
argument_list|,
name|__M
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
name|test_mm512_maskz_min_epi64
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_min_epi64
comment|// CHECK:       [[CMP:%.*]] = icmp slt<8 x i64> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<8 x i1> [[CMP]],<8 x i64> [[X]],<8 x i64> [[Y]]
comment|// CHECK:       select<8 x i1> {{.*}},<8 x i64> [[RES]],<8 x i64> {{.*}}
return|return
name|_mm512_maskz_min_epi64
argument_list|(
name|__M
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
name|test_mm512_min_epu64
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_min_epu64
comment|// CHECK:       [[CMP:%.*]] = icmp ult<8 x i64> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<8 x i1> [[CMP]],<8 x i64> [[X]],<8 x i64> [[Y]]
return|return
name|_mm512_min_epu64
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_min_epu64
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_min_epu64
comment|// CHECK:       [[CMP:%.*]] = icmp ult<8 x i64> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<8 x i1> [[CMP]],<8 x i64> [[X]],<8 x i64> [[Y]]
comment|// CHECK:       select<8 x i1> {{.*}},<8 x i64> [[RES]],<8 x i64> {{.*}}
return|return
name|_mm512_mask_min_epu64
argument_list|(
name|__W
argument_list|,
name|__M
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
name|test_mm512_maskz_min_epu64
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_min_epu64
comment|// CHECK:       [[CMP:%.*]] = icmp ult<8 x i64> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<8 x i1> [[CMP]],<8 x i64> [[X]],<8 x i64> [[Y]]
comment|// CHECK:       select<8 x i1> {{.*}},<8 x i64> [[RES]],<8 x i64> {{.*}}
return|return
name|_mm512_maskz_min_epu64
argument_list|(
name|__M
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
name|test_mm512_mask_set1_epi32
parameter_list|(
name|__m512i
name|__O
parameter_list|,
name|__mmask16
name|__M
parameter_list|,
name|int
name|__A
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_mask_set1_epi32
comment|//CHECK: @llvm.x86.avx512.mask.pbroadcast.d.gpr.512
return|return
name|_mm512_mask_set1_epi32
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
name|test_mm512_set_epi8
parameter_list|(
name|char
name|e63
parameter_list|,
name|char
name|e62
parameter_list|,
name|char
name|e61
parameter_list|,
name|char
name|e60
parameter_list|,
name|char
name|e59
parameter_list|,
name|char
name|e58
parameter_list|,
name|char
name|e57
parameter_list|,
name|char
name|e56
parameter_list|,
name|char
name|e55
parameter_list|,
name|char
name|e54
parameter_list|,
name|char
name|e53
parameter_list|,
name|char
name|e52
parameter_list|,
name|char
name|e51
parameter_list|,
name|char
name|e50
parameter_list|,
name|char
name|e49
parameter_list|,
name|char
name|e48
parameter_list|,
name|char
name|e47
parameter_list|,
name|char
name|e46
parameter_list|,
name|char
name|e45
parameter_list|,
name|char
name|e44
parameter_list|,
name|char
name|e43
parameter_list|,
name|char
name|e42
parameter_list|,
name|char
name|e41
parameter_list|,
name|char
name|e40
parameter_list|,
name|char
name|e39
parameter_list|,
name|char
name|e38
parameter_list|,
name|char
name|e37
parameter_list|,
name|char
name|e36
parameter_list|,
name|char
name|e35
parameter_list|,
name|char
name|e34
parameter_list|,
name|char
name|e33
parameter_list|,
name|char
name|e32
parameter_list|,
name|char
name|e31
parameter_list|,
name|char
name|e30
parameter_list|,
name|char
name|e29
parameter_list|,
name|char
name|e28
parameter_list|,
name|char
name|e27
parameter_list|,
name|char
name|e26
parameter_list|,
name|char
name|e25
parameter_list|,
name|char
name|e24
parameter_list|,
name|char
name|e23
parameter_list|,
name|char
name|e22
parameter_list|,
name|char
name|e21
parameter_list|,
name|char
name|e20
parameter_list|,
name|char
name|e19
parameter_list|,
name|char
name|e18
parameter_list|,
name|char
name|e17
parameter_list|,
name|char
name|e16
parameter_list|,
name|char
name|e15
parameter_list|,
name|char
name|e14
parameter_list|,
name|char
name|e13
parameter_list|,
name|char
name|e12
parameter_list|,
name|char
name|e11
parameter_list|,
name|char
name|e10
parameter_list|,
name|char
name|e9
parameter_list|,
name|char
name|e8
parameter_list|,
name|char
name|e7
parameter_list|,
name|char
name|e6
parameter_list|,
name|char
name|e5
parameter_list|,
name|char
name|e4
parameter_list|,
name|char
name|e3
parameter_list|,
name|char
name|e2
parameter_list|,
name|char
name|e1
parameter_list|,
name|char
name|e0
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_set_epi8
comment|//CHECK: load i8, i8* %e63.addr, align 1
comment|//CHECK: load i8, i8* %e62.addr, align 1
comment|//CHECK: load i8, i8* %e61.addr, align 1
comment|//CHECK: load i8, i8* %e60.addr, align 1
comment|//CHECK: load i8, i8* %e59.addr, align 1
comment|//CHECK: load i8, i8* %e58.addr, align 1
comment|//CHECK: load i8, i8* %e57.addr, align 1
comment|//CHECK: load i8, i8* %e56.addr, align 1
comment|//CHECK: load i8, i8* %e55.addr, align 1
comment|//CHECK: load i8, i8* %e54.addr, align 1
comment|//CHECK: load i8, i8* %e53.addr, align 1
comment|//CHECK: load i8, i8* %e52.addr, align 1
comment|//CHECK: load i8, i8* %e51.addr, align 1
comment|//CHECK: load i8, i8* %e50.addr, align 1
comment|//CHECK: load i8, i8* %e49.addr, align 1
comment|//CHECK: load i8, i8* %e48.addr, align 1
comment|//CHECK: load i8, i8* %e47.addr, align 1
comment|//CHECK: load i8, i8* %e46.addr, align 1
comment|//CHECK: load i8, i8* %e45.addr, align 1
comment|//CHECK: load i8, i8* %e44.addr, align 1
comment|//CHECK: load i8, i8* %e43.addr, align 1
comment|//CHECK: load i8, i8* %e42.addr, align 1
comment|//CHECK: load i8, i8* %e41.addr, align 1
comment|//CHECK: load i8, i8* %e40.addr, align 1
comment|//CHECK: load i8, i8* %e39.addr, align 1
comment|//CHECK: load i8, i8* %e38.addr, align 1
comment|//CHECK: load i8, i8* %e37.addr, align 1
comment|//CHECK: load i8, i8* %e36.addr, align 1
comment|//CHECK: load i8, i8* %e35.addr, align 1
comment|//CHECK: load i8, i8* %e34.addr, align 1
comment|//CHECK: load i8, i8* %e33.addr, align 1
comment|//CHECK: load i8, i8* %e32.addr, align 1
comment|//CHECK: load i8, i8* %e31.addr, align 1
comment|//CHECK: load i8, i8* %e30.addr, align 1
comment|//CHECK: load i8, i8* %e29.addr, align 1
comment|//CHECK: load i8, i8* %e28.addr, align 1
comment|//CHECK: load i8, i8* %e27.addr, align 1
comment|//CHECK: load i8, i8* %e26.addr, align 1
comment|//CHECK: load i8, i8* %e25.addr, align 1
comment|//CHECK: load i8, i8* %e24.addr, align 1
comment|//CHECK: load i8, i8* %e23.addr, align 1
comment|//CHECK: load i8, i8* %e22.addr, align 1
comment|//CHECK: load i8, i8* %e21.addr, align 1
comment|//CHECK: load i8, i8* %e20.addr, align 1
comment|//CHECK: load i8, i8* %e19.addr, align 1
comment|//CHECK: load i8, i8* %e18.addr, align 1
comment|//CHECK: load i8, i8* %e17.addr, align 1
comment|//CHECK: load i8, i8* %e16.addr, align 1
comment|//CHECK: load i8, i8* %e15.addr, align 1
comment|//CHECK: load i8, i8* %e14.addr, align 1
comment|//CHECK: load i8, i8* %e13.addr, align 1
comment|//CHECK: load i8, i8* %e12.addr, align 1
comment|//CHECK: load i8, i8* %e11.addr, align 1
comment|//CHECK: load i8, i8* %e10.addr, align 1
comment|//CHECK: load i8, i8* %e9.addr, align 1
comment|//CHECK: load i8, i8* %e8.addr, align 1
comment|//CHECK: load i8, i8* %e7.addr, align 1
comment|//CHECK: load i8, i8* %e6.addr, align 1
comment|//CHECK: load i8, i8* %e5.addr, align 1
comment|//CHECK: load i8, i8* %e4.addr, align 1
comment|//CHECK: load i8, i8* %e3.addr, align 1
comment|//CHECK: load i8, i8* %e2.addr, align 1
comment|//CHECK: load i8, i8* %e1.addr, align 1
comment|//CHECK: load i8, i8* %e0.addr, align 1
return|return
name|_mm512_set_epi8
argument_list|(
name|e63
argument_list|,
name|e62
argument_list|,
name|e61
argument_list|,
name|e60
argument_list|,
name|e59
argument_list|,
name|e58
argument_list|,
name|e57
argument_list|,
name|e56
argument_list|,
name|e55
argument_list|,
name|e54
argument_list|,
name|e53
argument_list|,
name|e52
argument_list|,
name|e51
argument_list|,
name|e50
argument_list|,
name|e49
argument_list|,
name|e48
argument_list|,
name|e47
argument_list|,
name|e46
argument_list|,
name|e45
argument_list|,
name|e44
argument_list|,
name|e43
argument_list|,
name|e42
argument_list|,
name|e41
argument_list|,
name|e40
argument_list|,
name|e39
argument_list|,
name|e38
argument_list|,
name|e37
argument_list|,
name|e36
argument_list|,
name|e35
argument_list|,
name|e34
argument_list|,
name|e33
argument_list|,
name|e32
argument_list|,
name|e31
argument_list|,
name|e30
argument_list|,
name|e29
argument_list|,
name|e28
argument_list|,
name|e27
argument_list|,
name|e26
argument_list|,
name|e25
argument_list|,
name|e24
argument_list|,
name|e23
argument_list|,
name|e22
argument_list|,
name|e21
argument_list|,
name|e20
argument_list|,
name|e19
argument_list|,
name|e18
argument_list|,
name|e17
argument_list|,
name|e16
argument_list|,
name|e15
argument_list|,
name|e14
argument_list|,
name|e13
argument_list|,
name|e12
argument_list|,
name|e11
argument_list|,
name|e10
argument_list|,
name|e9
argument_list|,
name|e8
argument_list|,
name|e7
argument_list|,
name|e6
argument_list|,
name|e5
argument_list|,
name|e4
argument_list|,
name|e3
argument_list|,
name|e2
argument_list|,
name|e1
argument_list|,
name|e0
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_set_epi16
parameter_list|(
name|short
name|e31
parameter_list|,
name|short
name|e30
parameter_list|,
name|short
name|e29
parameter_list|,
name|short
name|e28
parameter_list|,
name|short
name|e27
parameter_list|,
name|short
name|e26
parameter_list|,
name|short
name|e25
parameter_list|,
name|short
name|e24
parameter_list|,
name|short
name|e23
parameter_list|,
name|short
name|e22
parameter_list|,
name|short
name|e21
parameter_list|,
name|short
name|e20
parameter_list|,
name|short
name|e19
parameter_list|,
name|short
name|e18
parameter_list|,
name|short
name|e17
parameter_list|,
name|short
name|e16
parameter_list|,
name|short
name|e15
parameter_list|,
name|short
name|e14
parameter_list|,
name|short
name|e13
parameter_list|,
name|short
name|e12
parameter_list|,
name|short
name|e11
parameter_list|,
name|short
name|e10
parameter_list|,
name|short
name|e9
parameter_list|,
name|short
name|e8
parameter_list|,
name|short
name|e7
parameter_list|,
name|short
name|e6
parameter_list|,
name|short
name|e5
parameter_list|,
name|short
name|e4
parameter_list|,
name|short
name|e3
parameter_list|,
name|short
name|e2
parameter_list|,
name|short
name|e1
parameter_list|,
name|short
name|e0
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_set_epi16
comment|//CHECK: insertelement{{.*}}i32 0
comment|//CHECK: insertelement{{.*}}i32 1
comment|//CHECK: insertelement{{.*}}i32 2
comment|//CHECK: insertelement{{.*}}i32 3
comment|//CHECK: insertelement{{.*}}i32 4
comment|//CHECK: insertelement{{.*}}i32 5
comment|//CHECK: insertelement{{.*}}i32 6
comment|//CHECK: insertelement{{.*}}i32 7
comment|//CHECK: insertelement{{.*}}i32 8
comment|//CHECK: insertelement{{.*}}i32 9
comment|//CHECK: insertelement{{.*}}i32 10
comment|//CHECK: insertelement{{.*}}i32 11
comment|//CHECK: insertelement{{.*}}i32 12
comment|//CHECK: insertelement{{.*}}i32 13
comment|//CHECK: insertelement{{.*}}i32 14
comment|//CHECK: insertelement{{.*}}i32 15
comment|//CHECK: insertelement{{.*}}i32 16
comment|//CHECK: insertelement{{.*}}i32 17
comment|//CHECK: insertelement{{.*}}i32 18
comment|//CHECK: insertelement{{.*}}i32 19
comment|//CHECK: insertelement{{.*}}i32 20
comment|//CHECK: insertelement{{.*}}i32 21
comment|//CHECK: insertelement{{.*}}i32 22
comment|//CHECK: insertelement{{.*}}i32 23
comment|//CHECK: insertelement{{.*}}i32 24
comment|//CHECK: insertelement{{.*}}i32 25
comment|//CHECK: insertelement{{.*}}i32 26
comment|//CHECK: insertelement{{.*}}i32 27
comment|//CHECK: insertelement{{.*}}i32 28
comment|//CHECK: insertelement{{.*}}i32 29
comment|//CHECK: insertelement{{.*}}i32 30
comment|//CHECK: insertelement{{.*}}i32 31
return|return
name|_mm512_set_epi16
argument_list|(
name|e31
argument_list|,
name|e30
argument_list|,
name|e29
argument_list|,
name|e28
argument_list|,
name|e27
argument_list|,
name|e26
argument_list|,
name|e25
argument_list|,
name|e24
argument_list|,
name|e23
argument_list|,
name|e22
argument_list|,
name|e21
argument_list|,
name|e20
argument_list|,
name|e19
argument_list|,
name|e18
argument_list|,
name|e17
argument_list|,
name|e16
argument_list|,
name|e15
argument_list|,
name|e14
argument_list|,
name|e13
argument_list|,
name|e12
argument_list|,
name|e11
argument_list|,
name|e10
argument_list|,
name|e9
argument_list|,
name|e8
argument_list|,
name|e7
argument_list|,
name|e6
argument_list|,
name|e5
argument_list|,
name|e4
argument_list|,
name|e3
argument_list|,
name|e2
argument_list|,
name|e1
argument_list|,
name|e0
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_set_epi32
parameter_list|(
name|int
name|__A
parameter_list|,
name|int
name|__B
parameter_list|,
name|int
name|__C
parameter_list|,
name|int
name|__D
parameter_list|,
name|int
name|__E
parameter_list|,
name|int
name|__F
parameter_list|,
name|int
name|__G
parameter_list|,
name|int
name|__H
parameter_list|,
name|int
name|__I
parameter_list|,
name|int
name|__J
parameter_list|,
name|int
name|__K
parameter_list|,
name|int
name|__L
parameter_list|,
name|int
name|__M
parameter_list|,
name|int
name|__N
parameter_list|,
name|int
name|__O
parameter_list|,
name|int
name|__P
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_set_epi32
comment|//CHECK: insertelement{{.*}}i32 0
comment|//CHECK: insertelement{{.*}}i32 1
comment|//CHECK: insertelement{{.*}}i32 2
comment|//CHECK: insertelement{{.*}}i32 3
comment|//CHECK: insertelement{{.*}}i32 4
comment|//CHECK: insertelement{{.*}}i32 5
comment|//CHECK: insertelement{{.*}}i32 6
comment|//CHECK: insertelement{{.*}}i32 7
comment|//CHECK: insertelement{{.*}}i32 8
comment|//CHECK: insertelement{{.*}}i32 9
comment|//CHECK: insertelement{{.*}}i32 10
comment|//CHECK: insertelement{{.*}}i32 11
comment|//CHECK: insertelement{{.*}}i32 12
comment|//CHECK: insertelement{{.*}}i32 13
comment|//CHECK: insertelement{{.*}}i32 14
comment|//CHECK: insertelement{{.*}}i32 15
return|return
name|_mm512_set_epi32
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__D
argument_list|,
name|__E
argument_list|,
name|__F
argument_list|,
name|__G
argument_list|,
name|__H
argument_list|,
name|__I
argument_list|,
name|__J
argument_list|,
name|__K
argument_list|,
name|__L
argument_list|,
name|__M
argument_list|,
name|__N
argument_list|,
name|__O
argument_list|,
name|__P
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_setr_epi32
parameter_list|(
name|int
name|__A
parameter_list|,
name|int
name|__B
parameter_list|,
name|int
name|__C
parameter_list|,
name|int
name|__D
parameter_list|,
name|int
name|__E
parameter_list|,
name|int
name|__F
parameter_list|,
name|int
name|__G
parameter_list|,
name|int
name|__H
parameter_list|,
name|int
name|__I
parameter_list|,
name|int
name|__J
parameter_list|,
name|int
name|__K
parameter_list|,
name|int
name|__L
parameter_list|,
name|int
name|__M
parameter_list|,
name|int
name|__N
parameter_list|,
name|int
name|__O
parameter_list|,
name|int
name|__P
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_setr_epi32
comment|//CHECK: load{{.*}}%__P.addr, align 4
comment|//CHECK: load{{.*}}%__O.addr, align 4
comment|//CHECK: load{{.*}}%__N.addr, align 4
comment|//CHECK: load{{.*}}%__M.addr, align 4
comment|//CHECK: load{{.*}}%__L.addr, align 4
comment|//CHECK: load{{.*}}%__K.addr, align 4
comment|//CHECK: load{{.*}}%__J.addr, align 4
comment|//CHECK: load{{.*}}%__I.addr, align 4
comment|//CHECK: load{{.*}}%__H.addr, align 4
comment|//CHECK: load{{.*}}%__G.addr, align 4
comment|//CHECK: load{{.*}}%__F.addr, align 4
comment|//CHECK: load{{.*}}%__E.addr, align 4
comment|//CHECK: load{{.*}}%__D.addr, align 4
comment|//CHECK: load{{.*}}%__C.addr, align 4
comment|//CHECK: load{{.*}}%__B.addr, align 4
comment|//CHECK: load{{.*}}%__A.addr, align 4
comment|//CHECK: insertelement{{.*}}i32 0
comment|//CHECK: insertelement{{.*}}i32 1
comment|//CHECK: insertelement{{.*}}i32 2
comment|//CHECK: insertelement{{.*}}i32 3
comment|//CHECK: insertelement{{.*}}i32 4
comment|//CHECK: insertelement{{.*}}i32 5
comment|//CHECK: insertelement{{.*}}i32 6
comment|//CHECK: insertelement{{.*}}i32 7
comment|//CHECK: insertelement{{.*}}i32 8
comment|//CHECK: insertelement{{.*}}i32 9
comment|//CHECK: insertelement{{.*}}i32 10
comment|//CHECK: insertelement{{.*}}i32 11
comment|//CHECK: insertelement{{.*}}i32 12
comment|//CHECK: insertelement{{.*}}i32 13
comment|//CHECK: insertelement{{.*}}i32 14
comment|//CHECK: insertelement{{.*}}i32 15
return|return
name|_mm512_setr_epi32
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__D
argument_list|,
name|__E
argument_list|,
name|__F
argument_list|,
name|__G
argument_list|,
name|__H
argument_list|,
name|__I
argument_list|,
name|__J
argument_list|,
name|__K
argument_list|,
name|__L
argument_list|,
name|__M
argument_list|,
name|__N
argument_list|,
name|__O
argument_list|,
name|__P
argument_list|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|__x86_64__
end_ifdef

begin_function
name|__m512i
name|test_mm512_mask_set1_epi64
parameter_list|(
name|__m512i
name|__O
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|long
name|long
name|__A
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_mask_set1_epi64
comment|//CHECK: @llvm.x86.avx512.mask.pbroadcast.q.gpr.512
return|return
name|_mm512_mask_set1_epi64
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

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|__m512i
name|test_mm512_set_epi64
parameter_list|(
name|long
name|long
name|__A
parameter_list|,
name|long
name|long
name|__B
parameter_list|,
name|long
name|long
name|__C
parameter_list|,
name|long
name|long
name|__D
parameter_list|,
name|long
name|long
name|__E
parameter_list|,
name|long
name|long
name|__F
parameter_list|,
name|long
name|long
name|__G
parameter_list|,
name|long
name|long
name|__H
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_set_epi64
comment|//CHECK: insertelement{{.*}}i32 0
comment|//CHECK: insertelement{{.*}}i32 1
comment|//CHECK: insertelement{{.*}}i32 2
comment|//CHECK: insertelement{{.*}}i32 3
comment|//CHECK: insertelement{{.*}}i32 4
comment|//CHECK: insertelement{{.*}}i32 5
comment|//CHECK: insertelement{{.*}}i32 6
comment|//CHECK: insertelement{{.*}}i32 7
return|return
name|_mm512_set_epi64
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__D
argument_list|,
name|__E
argument_list|,
name|__F
argument_list|,
name|__G
argument_list|,
name|__H
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_setr_epi64
parameter_list|(
name|long
name|long
name|__A
parameter_list|,
name|long
name|long
name|__B
parameter_list|,
name|long
name|long
name|__C
parameter_list|,
name|long
name|long
name|__D
parameter_list|,
name|long
name|long
name|__E
parameter_list|,
name|long
name|long
name|__F
parameter_list|,
name|long
name|long
name|__G
parameter_list|,
name|long
name|long
name|__H
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_setr_epi64
comment|//CHECK: load{{.*}}%__H.addr, align 8
comment|//CHECK: load{{.*}}%__G.addr, align 8
comment|//CHECK: load{{.*}}%__F.addr, align 8
comment|//CHECK: load{{.*}}%__E.addr, align 8
comment|//CHECK: load{{.*}}%__D.addr, align 8
comment|//CHECK: load{{.*}}%__C.addr, align 8
comment|//CHECK: load{{.*}}%__B.addr, align 8
comment|//CHECK: load{{.*}}%__A.addr, align 8
comment|//CHECK: insertelement{{.*}}i32 0
comment|//CHECK: insertelement{{.*}}i32 1
comment|//CHECK: insertelement{{.*}}i32 2
comment|//CHECK: insertelement{{.*}}i32 3
comment|//CHECK: insertelement{{.*}}i32 4
comment|//CHECK: insertelement{{.*}}i32 5
comment|//CHECK: insertelement{{.*}}i32 6
comment|//CHECK: insertelement{{.*}}i32 7
return|return
name|_mm512_setr_epi64
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__D
argument_list|,
name|__E
argument_list|,
name|__F
argument_list|,
name|__G
argument_list|,
name|__H
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_set_pd
parameter_list|(
name|double
name|__A
parameter_list|,
name|double
name|__B
parameter_list|,
name|double
name|__C
parameter_list|,
name|double
name|__D
parameter_list|,
name|double
name|__E
parameter_list|,
name|double
name|__F
parameter_list|,
name|double
name|__G
parameter_list|,
name|double
name|__H
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_set_pd
comment|//CHECK: insertelement{{.*}}i32 0
comment|//CHECK: insertelement{{.*}}i32 1
comment|//CHECK: insertelement{{.*}}i32 2
comment|//CHECK: insertelement{{.*}}i32 3
comment|//CHECK: insertelement{{.*}}i32 4
comment|//CHECK: insertelement{{.*}}i32 5
comment|//CHECK: insertelement{{.*}}i32 6
comment|//CHECK: insertelement{{.*}}i32 7
return|return
name|_mm512_set_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__D
argument_list|,
name|__E
argument_list|,
name|__F
argument_list|,
name|__G
argument_list|,
name|__H
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_setr_pd
parameter_list|(
name|double
name|__A
parameter_list|,
name|double
name|__B
parameter_list|,
name|double
name|__C
parameter_list|,
name|double
name|__D
parameter_list|,
name|double
name|__E
parameter_list|,
name|double
name|__F
parameter_list|,
name|double
name|__G
parameter_list|,
name|double
name|__H
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_setr_pd
comment|//CHECK: load{{.*}}%__H.addr, align 8
comment|//CHECK: load{{.*}}%__G.addr, align 8
comment|//CHECK: load{{.*}}%__F.addr, align 8
comment|//CHECK: load{{.*}}%__E.addr, align 8
comment|//CHECK: load{{.*}}%__D.addr, align 8
comment|//CHECK: load{{.*}}%__C.addr, align 8
comment|//CHECK: load{{.*}}%__B.addr, align 8
comment|//CHECK: load{{.*}}%__A.addr, align 8
comment|//CHECK: insertelement{{.*}}i32 0
comment|//CHECK: insertelement{{.*}}i32 1
comment|//CHECK: insertelement{{.*}}i32 2
comment|//CHECK: insertelement{{.*}}i32 3
comment|//CHECK: insertelement{{.*}}i32 4
comment|//CHECK: insertelement{{.*}}i32 5
comment|//CHECK: insertelement{{.*}}i32 6
comment|//CHECK: insertelement{{.*}}i32 7
return|return
name|_mm512_setr_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__D
argument_list|,
name|__E
argument_list|,
name|__F
argument_list|,
name|__G
argument_list|,
name|__H
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_set_ps
parameter_list|(
name|float
name|__A
parameter_list|,
name|float
name|__B
parameter_list|,
name|float
name|__C
parameter_list|,
name|float
name|__D
parameter_list|,
name|float
name|__E
parameter_list|,
name|float
name|__F
parameter_list|,
name|float
name|__G
parameter_list|,
name|float
name|__H
parameter_list|,
name|float
name|__I
parameter_list|,
name|float
name|__J
parameter_list|,
name|float
name|__K
parameter_list|,
name|float
name|__L
parameter_list|,
name|float
name|__M
parameter_list|,
name|float
name|__N
parameter_list|,
name|float
name|__O
parameter_list|,
name|float
name|__P
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_set_ps
comment|//CHECK: insertelement{{.*}}i32 0
comment|//CHECK: insertelement{{.*}}i32 1
comment|//CHECK: insertelement{{.*}}i32 2
comment|//CHECK: insertelement{{.*}}i32 3
comment|//CHECK: insertelement{{.*}}i32 4
comment|//CHECK: insertelement{{.*}}i32 5
comment|//CHECK: insertelement{{.*}}i32 6
comment|//CHECK: insertelement{{.*}}i32 7
comment|//CHECK: insertelement{{.*}}i32 8
comment|//CHECK: insertelement{{.*}}i32 9
comment|//CHECK: insertelement{{.*}}i32 10
comment|//CHECK: insertelement{{.*}}i32 11
comment|//CHECK: insertelement{{.*}}i32 12
comment|//CHECK: insertelement{{.*}}i32 13
comment|//CHECK: insertelement{{.*}}i32 14
comment|//CHECK: insertelement{{.*}}i32 15
return|return
name|_mm512_set_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__D
argument_list|,
name|__E
argument_list|,
name|__F
argument_list|,
name|__G
argument_list|,
name|__H
argument_list|,
name|__I
argument_list|,
name|__J
argument_list|,
name|__K
argument_list|,
name|__L
argument_list|,
name|__M
argument_list|,
name|__N
argument_list|,
name|__O
argument_list|,
name|__P
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_abs_epi64
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
comment|// CHECK-LABEL: @test_mm512_mask_abs_epi64
comment|// CHECK: @llvm.x86.avx512.mask.pabs.q.512
return|return
name|_mm512_mask_abs_epi64
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
name|test_mm512_maskz_abs_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_abs_epi64
comment|// CHECK: @llvm.x86.avx512.mask.pabs.q.512
return|return
name|_mm512_maskz_abs_epi64
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
name|test_mm512_mask_abs_epi32
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
comment|// CHECK-LABEL: @test_mm512_mask_abs_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pabs.d.512
return|return
name|_mm512_mask_abs_epi32
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
name|test_mm512_maskz_abs_epi32
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_abs_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pabs.d.512
return|return
name|_mm512_maskz_abs_epi32
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_setr_ps
parameter_list|(
name|float
name|__A
parameter_list|,
name|float
name|__B
parameter_list|,
name|float
name|__C
parameter_list|,
name|float
name|__D
parameter_list|,
name|float
name|__E
parameter_list|,
name|float
name|__F
parameter_list|,
name|float
name|__G
parameter_list|,
name|float
name|__H
parameter_list|,
name|float
name|__I
parameter_list|,
name|float
name|__J
parameter_list|,
name|float
name|__K
parameter_list|,
name|float
name|__L
parameter_list|,
name|float
name|__M
parameter_list|,
name|float
name|__N
parameter_list|,
name|float
name|__O
parameter_list|,
name|float
name|__P
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_setr_ps
comment|//CHECK: load{{.*}}%__P.addr, align 4
comment|//CHECK: load{{.*}}%__O.addr, align 4
comment|//CHECK: load{{.*}}%__N.addr, align 4
comment|//CHECK: load{{.*}}%__M.addr, align 4
comment|//CHECK: load{{.*}}%__L.addr, align 4
comment|//CHECK: load{{.*}}%__K.addr, align 4
comment|//CHECK: load{{.*}}%__J.addr, align 4
comment|//CHECK: load{{.*}}%__I.addr, align 4
comment|//CHECK: load{{.*}}%__H.addr, align 4
comment|//CHECK: load{{.*}}%__G.addr, align 4
comment|//CHECK: load{{.*}}%__F.addr, align 4
comment|//CHECK: load{{.*}}%__E.addr, align 4
comment|//CHECK: load{{.*}}%__D.addr, align 4
comment|//CHECK: load{{.*}}%__C.addr, align 4
comment|//CHECK: load{{.*}}%__B.addr, align 4
comment|//CHECK: load{{.*}}%__A.addr, align 4
comment|//CHECK: insertelement{{.*}}i32 0
comment|//CHECK: insertelement{{.*}}i32 1
comment|//CHECK: insertelement{{.*}}i32 2
comment|//CHECK: insertelement{{.*}}i32 3
comment|//CHECK: insertelement{{.*}}i32 4
comment|//CHECK: insertelement{{.*}}i32 5
comment|//CHECK: insertelement{{.*}}i32 6
comment|//CHECK: insertelement{{.*}}i32 7
comment|//CHECK: insertelement{{.*}}i32 8
comment|//CHECK: insertelement{{.*}}i32 9
comment|//CHECK: insertelement{{.*}}i32 10
comment|//CHECK: insertelement{{.*}}i32 11
comment|//CHECK: insertelement{{.*}}i32 12
comment|//CHECK: insertelement{{.*}}i32 13
comment|//CHECK: insertelement{{.*}}i32 14
comment|//CHECK: insertelement{{.*}}i32 15
return|return
name|_mm512_setr_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__D
argument_list|,
name|__E
argument_list|,
name|__F
argument_list|,
name|__G
argument_list|,
name|__H
argument_list|,
name|__I
argument_list|,
name|__J
argument_list|,
name|__K
argument_list|,
name|__L
argument_list|,
name|__M
argument_list|,
name|__N
argument_list|,
name|__O
argument_list|,
name|__P
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm_cvtss_i32
parameter_list|(
name|__m128
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvtss_i32
comment|// CHECK: call i32 @llvm.x86.sse.cvtss2si(<4 x float> %{{.*}})
return|return
name|_mm_cvtss_i32
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|__x86_64__
end_ifdef

begin_function
name|long
name|long
name|test_mm_cvtss_i64
parameter_list|(
name|__m128
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvtss_i64
comment|// CHECK: call i64 @llvm.x86.sse.cvtss2si64(<4 x float> %{{.*}})
return|return
name|_mm_cvtss_i64
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|__m128d
name|test_mm_cvti32_sd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|int
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvti32_sd
comment|// CHECK: sitofp i32 %{{.*}} to double
comment|// CHECK: insertelement<2 x double> %{{.*}}, double %{{.*}}, i32 0
return|return
name|_mm_cvti32_sd
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|__x86_64__
end_ifdef

begin_function
name|__m128d
name|test_mm_cvti64_sd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|long
name|long
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvti64_sd
comment|// CHECK: sitofp i64 %{{.*}} to double
comment|// CHECK: insertelement<2 x double> %{{.*}}, double %{{.*}}, i32 0
return|return
name|_mm_cvti64_sd
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|__m128
name|test_mm_cvti32_ss
parameter_list|(
name|__m128
name|A
parameter_list|,
name|int
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvti32_ss
comment|// CHECK: sitofp i32 %{{.*}} to float
comment|// CHECK: insertelement<4 x float> %{{.*}}, float %{{.*}}, i32 0
return|return
name|_mm_cvti32_ss
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|__x86_64__
end_ifdef

begin_function
name|__m128
name|test_mm_cvti64_ss
parameter_list|(
name|__m128
name|A
parameter_list|,
name|long
name|long
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvti64_ss
comment|// CHECK: sitofp i64 %{{.*}} to float
comment|// CHECK: insertelement<4 x float> %{{.*}}, float %{{.*}}, i32 0
return|return
name|_mm_cvti64_ss
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|int
name|test_mm_cvtsd_i32
parameter_list|(
name|__m128d
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvtsd_i32
comment|// CHECK: call i32 @llvm.x86.sse2.cvtsd2si(<2 x double> %{{.*}})
return|return
name|_mm_cvtsd_i32
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|__x86_64__
end_ifdef

begin_function
name|long
name|long
name|test_mm_cvtsd_i64
parameter_list|(
name|__m128d
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvtsd_i64
comment|// CHECK: call i64 @llvm.x86.sse2.cvtsd2si64(<2 x double> %{{.*}})
return|return
name|_mm_cvtsd_i64
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|__m128d
name|test_mm_mask_cvtss_sd
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
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cvtss_sd
comment|// CHECK: @llvm.x86.avx512.mask.cvtss2sd.round
return|return
name|_mm_mask_cvtss_sd
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
name|__m128d
name|test_mm_maskz_cvtss_sd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtss_sd
comment|// CHECK: @llvm.x86.avx512.mask.cvtss2sd.round
return|return
name|_mm_maskz_cvtss_sd
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
name|__m128
name|test_mm_mask_cvtsd_ss
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
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cvtsd_ss
comment|// CHECK: @llvm.x86.avx512.mask.cvtsd2ss.round
return|return
name|_mm_mask_cvtsd_ss
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
name|__m128
name|test_mm_maskz_cvtsd_ss
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtsd_ss
comment|// CHECK: @llvm.x86.avx512.mask.cvtsd2ss.round
return|return
name|_mm_maskz_cvtsd_ss
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
name|test_mm512_setzero_epi32
parameter_list|()
block|{
comment|// CHECK-LABEL: @test_mm512_setzero_epi32
comment|// CHECK: zeroinitializer
return|return
name|_mm512_setzero_epi32
argument_list|()
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_setzero
parameter_list|()
block|{
comment|// CHECK-LABEL: @test_mm512_setzero
comment|// CHECK: zeroinitializer
return|return
name|_mm512_setzero
argument_list|()
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_setzero_si512
parameter_list|()
block|{
comment|// CHECK-LABEL: @test_mm512_setzero_si512
comment|// CHECK: zeroinitializer
return|return
name|_mm512_setzero_si512
argument_list|()
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_setzero_ps
parameter_list|()
block|{
comment|// CHECK-LABEL: @test_mm512_setzero_ps
comment|// CHECK: zeroinitializer
return|return
name|_mm512_setzero_ps
argument_list|()
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_setzero_pd
parameter_list|()
block|{
comment|// CHECK-LABEL: @test_mm512_setzero_pd
comment|// CHECK: zeroinitializer
return|return
name|_mm512_setzero_pd
argument_list|()
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm512_int2mask
parameter_list|(
name|int
name|__a
parameter_list|)
block|{
comment|// O2-LABEL: test_mm512_int2mask
comment|// O2: trunc i32 %__a to i16
return|return
name|_mm512_int2mask
argument_list|(
name|__a
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm512_mask2int
parameter_list|(
name|__mmask16
name|__a
parameter_list|)
block|{
comment|// O2-LABEL: test_mm512_mask2int
comment|// O2: zext i16 %__a to i32
return|return
name|_mm512_mask2int
argument_list|(
name|__a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_move_ss
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
comment|// O2-LABEL: @test_mm_mask_move_ss
comment|// O2: %[[M:.*]] = and i8 %__U, 1
comment|// O2: %[[M2:.*]] = icmp
comment|// O2: %[[ELM1:.*]] = extractelement<4 x float>
comment|// O2: %[[ELM2:.*]] = extractelement<4 x float>
comment|// O2: %[[SEL:.*]] = select i1 %[[M2]]
comment|// O2: %[[RES:.*]] = insertelement<4 x float> %__A, float %[[SEL]], i32 0
comment|// O2: ret<4 x float> %[[RES]]
return|return
name|_mm_mask_move_ss
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
name|__m128
name|test_mm_maskz_move_ss
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
comment|// O2-LABEL: @test_mm_maskz_move_ss
comment|// O2: %[[M:.*]] = and i8 %__U, 1
comment|// O2: %[[M2:.*]] = icmp
comment|// O2: %[[ELM1:.*]] = extractelement<4 x float> %__B, i32 0
comment|// O2: %[[SEL:.*]] = select i1 %[[M2]]
comment|// O2: %[[RES:.*]] = insertelement<4 x float> %__A, float %[[SEL]], i32 0
comment|// O2: ret<4 x float> %[[RES]]
return|return
name|_mm_maskz_move_ss
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
name|__m128d
name|test_mm_mask_move_sd
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
comment|// O2-LABEL: @test_mm_mask_move_sd
comment|// O2: %[[M:.*]] = and i8 %__U, 1
comment|// O2: %[[M2:.*]] = icmp
comment|// O2: %[[ELM1:.*]] = extractelement<2 x double>
comment|// O2: %[[ELM2:.*]] = extractelement<2 x double>
comment|// O2: %[[SEL:.*]] = select i1 %[[M2]]
comment|// O2: %[[RES:.*]] = insertelement<2 x double> %__A, double %[[SEL]], i32 0
comment|// O2: ret<2 x double> %[[RES]]
return|return
name|_mm_mask_move_sd
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
name|__m128d
name|test_mm_maskz_move_sd
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
comment|// O2-LABEL: @test_mm_maskz_move_sd
comment|// O2: %[[M:.*]] = and i8 %__U, 1
comment|// O2: %[[M2:.*]] = icmp
comment|// O2: %[[ELM1:.*]] = extractelement<2 x double> %__B, i32 0
comment|// O2: %[[SEL:.*]] = select i1 %[[M2]]
comment|// O2: %[[RES:.*]] = insertelement<2 x double> %__A, double %[[SEL]], i32 0
comment|// O2: ret<2 x double> %[[RES]]
return|return
name|_mm_maskz_move_sd
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
name|void
name|test_mm_mask_store_ss
parameter_list|(
name|float
modifier|*
name|__P
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// O2-LABEL: @test_mm_mask_store_ss
comment|// O2: %[[CAST:.*]] = bitcast float* %__P to<16 x float>*
comment|// O2: %[[SHUFFLE:.*]] = shufflevector<4 x float> %__A,<4 x float> undef,<16 x i32><i32 0, i32 1, i32 2, i32 3, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// O2: %[[MASK1:.*]] = and i8 %__U, 1
comment|// O2: %[[MASK2:.*]] = zext i8 %[[MASK1]] to i16
comment|// O2: %[[MASK3:.*]] = bitcast i16 %[[MASK2]] to<16 x i1>
comment|// O2: tail call void @llvm.masked.store.v16f32.p0v16f32(<16 x float> %[[SHUFFLE]],<16 x float>* %[[CAST]], i32 16,<16 x i1> %[[MASK3]])
name|_mm_mask_store_ss
argument_list|(
name|__P
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_mm_mask_store_sd
parameter_list|(
name|double
modifier|*
name|__P
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// O2-LABEL: @test_mm_mask_store_sd
comment|// O2: %[[CAST:.*]] = bitcast double* %__P to<8 x double>*
comment|// O2: %[[SHUFFLE:.*]] = shufflevector<2 x double> %__A,<2 x double> undef,<8 x i32><i32 0, i32 1, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// O2: %[[MASK1:.*]] = and i8 %__U, 1
comment|// O2: %[[MASK2:.*]] = bitcast i8 %[[MASK1]] to<8 x i1>
comment|// O2: tail call void @llvm.masked.store.v8f64.p0v8f64(<8 x double> %[[SHUFFLE]],<8 x double>* %[[CAST]], i32 16,<8 x i1> %[[MASK2]])
name|_mm_mask_store_sd
argument_list|(
name|__P
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_load_ss
parameter_list|(
name|__m128
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
specifier|const
name|float
modifier|*
name|__W
parameter_list|)
block|{
comment|// O2-LABEL: @test_mm_mask_load_ss
comment|// O2: %[[SHUF:.*]] = shufflevector<4 x float> %__A,<4 x float><float 0.000000e+00, float undef, float undef, float undef>,<4 x i32><i32 0, i32 4, i32 4, i32 4>
comment|// O2: %[[PTR:.*]] = bitcast float* %__W to<16 x float>*
comment|// O2: %[[SHUF2:.*]] = shufflevector<4 x float> %[[SHUF]],<4 x float> undef,<16 x i32><i32 0, i32 1, i32 2, i32 3, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// O2: %[[AND:.*]] = and i8 %__U, 1
comment|// O2: %[[MASK:.*]] = zext i8 %[[AND]] to i16
comment|// O2: %[[MASK2:.*]] = bitcast i16 %[[MASK]] to<16 x i1>
comment|// O2: %[[RES:.*]] = tail call<16 x float> @llvm.masked.load.v16f32.p0v16f32(<16 x float>* %[[PTR]], i32 16,<16 x i1> %[[MASK2]],<16 x float> %[[SHUF2]])
comment|// O2: shufflevector<16 x float> %[[RES]],<16 x float> undef,<4 x i32><i32 0, i32 1, i32 2, i32 3>
return|return
name|_mm_mask_load_ss
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__W
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_maskz_load_ss
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
specifier|const
name|float
modifier|*
name|__W
parameter_list|)
block|{
comment|// O2-LABEL: @test_mm_maskz_load_ss
comment|// O2: %[[PTR:.*]] = bitcast float* %__W to<16 x float>*
comment|// O2: %[[AND:.*]] = and i8 %__U, 1
comment|// O2: %[[MASK:.*]] = zext i8 %[[AND]] to i16
comment|// O2: %[[MASK2:.*]] = bitcast i16 %[[MASK]] to<16 x i1>
comment|// O2: %[[RES:.*]] = tail call<16 x float> @llvm.masked.load.v16f32.p0v16f32(<16 x float>* %[[PTR]], i32 16,<16 x i1> %[[MASK2]],<16 x float> zeroinitializer)
comment|// O2: shufflevector<16 x float> %[[RES]],<16 x float> undef,<4 x i32><i32 0, i32 1, i32 2, i32 3>
return|return
name|_mm_maskz_load_ss
argument_list|(
name|__U
argument_list|,
name|__W
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_load_sd
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
specifier|const
name|double
modifier|*
name|__W
parameter_list|)
block|{
comment|// O2-LABEL: @test_mm_mask_load_sd
comment|// O2: %[[SHUF:.*]] = insertelement<2 x double> %__A, double 0.000000e+00, i32 1
comment|// O2: %[[PTR:.*]] = bitcast double* %__W to<8 x double>*
comment|// O2: %[[SHUF2:.*]] = shufflevector<2 x double> %[[SHUF]],<2 x double> undef,<8 x i32><i32 0, i32 1, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// O2: %[[AND:.*]] = and i8 %__U, 1
comment|// O2: %[[MASK:.*]] = bitcast i8 %[[AND]] to<8 x i1>
comment|// O2: %[[RES:.*]] = tail call<8 x double> @llvm.masked.load.v8f64.p0v8f64(<8 x double>* %[[PTR]], i32 16,<8 x i1> %[[MASK]],<8 x double> %[[SHUF2]])
comment|// O2: shufflevector<8 x double> %[[RES]],<8 x double> undef,<2 x i32><i32 0, i32 1>
return|return
name|_mm_mask_load_sd
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__W
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_maskz_load_sd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
specifier|const
name|double
modifier|*
name|__W
parameter_list|)
block|{
comment|// O2-LABEL: @test_mm_maskz_load_sd
comment|// O2: %[[PTR:.*]] = bitcast double* %__W to<8 x double>*
comment|// O2: %[[AND:.*]] = and i8 %__U, 1
comment|// O2: %[[MASK:.*]] = bitcast i8 %[[AND]] to<8 x i1>
comment|// O2: %[[RES:.*]] = tail call<8 x double> @llvm.masked.load.v8f64.p0v8f64(<8 x double>* %[[PTR]], i32 16,<8 x i1> %[[MASK]],<8 x double> zeroinitializer)
comment|// O2: shufflevector<8 x double> %[[RES]],<8 x double> undef,<2 x i32><i32 0, i32 1>
return|return
name|_mm_maskz_load_sd
argument_list|(
name|__U
argument_list|,
name|__W
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_abs_pd
parameter_list|(
name|__m512d
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_abs_pd
comment|// CHECK: and<8 x i64>
return|return
name|_mm512_abs_pd
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_abs_pd
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
comment|// CHECK-LABEL: @test_mm512_mask_abs_pd
comment|// CHECK: %[[AND_RES:.*]] = and<8 x i64>
comment|// CHECK: %[[MASK:.*]] = bitcast i8 %{{.*}} to<8 x i1>
comment|// CHECK: select<8 x i1> %[[MASK]],<8 x i64> %[[AND_RES]],<8 x i64> %{{.*}}
return|return
name|_mm512_mask_abs_pd
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
name|__m512
name|test_mm512_abs_ps
parameter_list|(
name|__m512
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_abs_ps
comment|// CHECK: and<16 x i32>
return|return
name|_mm512_abs_ps
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_abs_ps
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
comment|// CHECK-LABEL: @test_mm512_mask_abs_ps
comment|// CHECK: and<16 x i32>
comment|// CHECK: %[[MASK:.*]] = bitcast i16 %{{.*}} to<16 x i1>
comment|// CHECK: select<16 x i1> %[[MASK]],<16 x i32> %{{.*}},<16 x i32> %{{.*}}
return|return
name|_mm512_mask_abs_ps
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
name|test_mm512_zextpd128_pd512
parameter_list|(
name|__m128d
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm512_zextpd128_pd512
comment|// CHECK: store<2 x double> zeroinitializer
comment|// CHECK: shufflevector<2 x double> %{{.*}},<2 x double> %{{.*}},<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 2, i32 3, i32 2, i32 3>
return|return
name|_mm512_zextpd128_pd512
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_zextpd256_pd512
parameter_list|(
name|__m256d
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm512_zextpd256_pd512
comment|// CHECK: store<4 x double> zeroinitializer
comment|// CHECK: shufflevector<4 x double> %{{.*}},<4 x double> %{{.*}},<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
return|return
name|_mm512_zextpd256_pd512
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_zextps128_ps512
parameter_list|(
name|__m128
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm512_zextps128_ps512
comment|// CHECK: store<4 x float> zeroinitializer
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> %{{.*}},<16 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 4, i32 5, i32 6, i32 7, i32 4, i32 5, i32 6, i32 7>
return|return
name|_mm512_zextps128_ps512
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_zextps256_ps512
parameter_list|(
name|__m256
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm512_zextps256_ps512
comment|// CHECK: store<8 x float> zeroinitializer
comment|// CHECK: shufflevector<8 x float> %{{.*}},<8 x float> %{{.*}},<16 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15>
return|return
name|_mm512_zextps256_ps512
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_zextsi128_si512
parameter_list|(
name|__m128i
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm512_zextsi128_si512
comment|// CHECK: store<2 x i64> zeroinitializer
comment|// CHECK: shufflevector<2 x i64> %{{.*}},<2 x i64> %{{.*}},<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 2, i32 3, i32 2, i32 3>
return|return
name|_mm512_zextsi128_si512
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_zextsi256_si512
parameter_list|(
name|__m256i
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm512_zextsi256_si512
comment|// CHECK: store<4 x i64> zeroinitializer
comment|// CHECK: shufflevector<4 x i64> %{{.*}},<4 x i64> %{{.*}},<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
return|return
name|_mm512_zextsi256_si512
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

end_unit

