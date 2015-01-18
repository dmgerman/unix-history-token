begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ffreestanding -triple x86_64-apple-macosx10.8.0 -target-feature +sse4.1 -emit-llvm %s -o - | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<xmmintrin.h>
end_include

begin_include
include|#
directive|include
file|<emmintrin.h>
end_include

begin_include
include|#
directive|include
file|<smmintrin.h>
end_include

begin_function
name|__m128
name|test_rsqrt_ss
parameter_list|(
name|__m128
name|x
parameter_list|)
block|{
comment|// CHECK: define {{.*}} @test_rsqrt_ss
comment|// CHECK: call<4 x float> @llvm.x86.sse.rsqrt.ss
comment|// CHECK: extractelement<4 x float> {{.*}}, i32 0
comment|// CHECK: extractelement<4 x float> {{.*}}, i32 1
comment|// CHECK: extractelement<4 x float> {{.*}}, i32 2
comment|// CHECK: extractelement<4 x float> {{.*}}, i32 3
return|return
name|_mm_rsqrt_ss
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_rcp_ss
parameter_list|(
name|__m128
name|x
parameter_list|)
block|{
comment|// CHECK: define {{.*}} @test_rcp_ss
comment|// CHECK: call<4 x float> @llvm.x86.sse.rcp.ss
comment|// CHECK: extractelement<4 x float> {{.*}}, i32 0
comment|// CHECK: extractelement<4 x float> {{.*}}, i32 1
comment|// CHECK: extractelement<4 x float> {{.*}}, i32 2
comment|// CHECK: extractelement<4 x float> {{.*}}, i32 3
return|return
name|_mm_rcp_ss
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_sqrt_ss
parameter_list|(
name|__m128
name|x
parameter_list|)
block|{
comment|// CHECK: define {{.*}} @test_sqrt_ss
comment|// CHECK: call<4 x float> @llvm.x86.sse.sqrt.ss
comment|// CHECK: extractelement<4 x float> {{.*}}, i32 0
comment|// CHECK: extractelement<4 x float> {{.*}}, i32 1
comment|// CHECK: extractelement<4 x float> {{.*}}, i32 2
comment|// CHECK: extractelement<4 x float> {{.*}}, i32 3
return|return
name|_mm_sqrt_ss
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_loadl_pi
parameter_list|(
name|__m128
name|x
parameter_list|,
name|void
modifier|*
name|y
parameter_list|)
block|{
comment|// CHECK: define {{.*}} @test_loadl_pi
comment|// CHECK: load<2 x float>* {{.*}}, align 1{{$}}
comment|// CHECK: shufflevector {{.*}}<4 x i32><i32 0, i32 1
comment|// CHECK: shufflevector {{.*}}<4 x i32><i32 4, i32 5, i32 2, i32 3>
return|return
name|_mm_loadl_pi
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_loadh_pi
parameter_list|(
name|__m128
name|x
parameter_list|,
name|void
modifier|*
name|y
parameter_list|)
block|{
comment|// CHECK: define {{.*}} @test_loadh_pi
comment|// CHECK: load<2 x float>* {{.*}}, align 1{{$}}
comment|// CHECK: shufflevector {{.*}}<4 x i32><i32 0, i32 1
comment|// CHECK: shufflevector {{.*}}<4 x i32><i32 0, i32 1, i32 4, i32 5>
return|return
name|_mm_loadh_pi
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_load_ss
parameter_list|(
name|void
modifier|*
name|y
parameter_list|)
block|{
comment|// CHECK: define {{.*}} @test_load_ss
comment|// CHECK: load float* {{.*}}, align 1{{$}}
return|return
name|_mm_load_ss
argument_list|(
name|y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_load1_ps
parameter_list|(
name|void
modifier|*
name|y
parameter_list|)
block|{
comment|// CHECK: define {{.*}} @test_load1_ps
comment|// CHECK: load float* {{.*}}, align 1{{$}}
return|return
name|_mm_load1_ps
argument_list|(
name|y
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_store_ss
parameter_list|(
name|__m128
name|x
parameter_list|,
name|void
modifier|*
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: define void @test_store_ss
comment|// CHECK: store {{.*}} float* {{.*}}, align 1{{$}}
name|_mm_store_ss
argument_list|(
name|y
argument_list|,
name|x
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|__m128d
name|test_load1_pd
parameter_list|(
name|__m128
name|x
parameter_list|,
name|void
modifier|*
name|y
parameter_list|)
block|{
comment|// CHECK: define {{.*}} @test_load1_pd
comment|// CHECK: load double* {{.*}}, align 1{{$}}
return|return
name|_mm_load1_pd
argument_list|(
name|y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_loadr_pd
parameter_list|(
name|__m128
name|x
parameter_list|,
name|void
modifier|*
name|y
parameter_list|)
block|{
comment|// CHECK: define {{.*}} @test_loadr_pd
comment|// CHECK: load<2 x double>* {{.*}}, align 16{{$}}
return|return
name|_mm_loadr_pd
argument_list|(
name|y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_load_sd
parameter_list|(
name|void
modifier|*
name|y
parameter_list|)
block|{
comment|// CHECK: define {{.*}} @test_load_sd
comment|// CHECK: load double* {{.*}}, align 1{{$}}
return|return
name|_mm_load_sd
argument_list|(
name|y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_loadh_pd
parameter_list|(
name|__m128d
name|x
parameter_list|,
name|void
modifier|*
name|y
parameter_list|)
block|{
comment|// CHECK: define {{.*}} @test_loadh_pd
comment|// CHECK: load double* {{.*}}, align 1{{$}}
return|return
name|_mm_loadh_pd
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_loadl_pd
parameter_list|(
name|__m128d
name|x
parameter_list|,
name|void
modifier|*
name|y
parameter_list|)
block|{
comment|// CHECK: define {{.*}} @test_loadl_pd
comment|// CHECK: load double* {{.*}}, align 1{{$}}
return|return
name|_mm_loadl_pd
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_store_sd
parameter_list|(
name|__m128d
name|x
parameter_list|,
name|void
modifier|*
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: define void @test_store_sd
comment|// CHECK: store {{.*}} double* {{.*}}, align 1{{$}}
name|_mm_store_sd
argument_list|(
name|y
argument_list|,
name|x
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_store1_pd
parameter_list|(
name|__m128d
name|x
parameter_list|,
name|void
modifier|*
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: define void @test_store1_pd
comment|// CHECK: store {{.*}} double* {{.*}}, align 1{{$}}
comment|// CHECK: store {{.*}} double* {{.*}}, align 1{{$}}
name|_mm_store1_pd
argument_list|(
name|y
argument_list|,
name|x
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_storer_pd
parameter_list|(
name|__m128d
name|x
parameter_list|,
name|void
modifier|*
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: define void @test_storer_pd
comment|// CHECK: store {{.*}}<2 x double>* {{.*}}, align 16{{$}}
name|_mm_storer_pd
argument_list|(
name|y
argument_list|,
name|x
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_storeh_pd
parameter_list|(
name|__m128d
name|x
parameter_list|,
name|void
modifier|*
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: define void @test_storeh_pd
comment|// CHECK: store {{.*}} double* {{.*}}, align 1{{$}}
name|_mm_storeh_pd
argument_list|(
name|y
argument_list|,
name|x
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_storel_pd
parameter_list|(
name|__m128d
name|x
parameter_list|,
name|void
modifier|*
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: define void @test_storel_pd
comment|// CHECK: store {{.*}} double* {{.*}}, align 1{{$}}
name|_mm_storel_pd
argument_list|(
name|y
argument_list|,
name|x
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|__m128i
name|test_loadl_epi64
parameter_list|(
name|void
modifier|*
name|y
parameter_list|)
block|{
comment|// CHECK: define {{.*}} @test_loadl_epi64
comment|// CHECK: load i64* {{.*}}, align 1{{$}}
return|return
name|_mm_loadl_epi64
argument_list|(
name|y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_minpos_epu16
parameter_list|(
name|__m128i
name|x
parameter_list|)
block|{
comment|// CHECK: define {{.*}} @test_mm_minpos_epu16
comment|// CHECK: @llvm.x86.sse41.phminposuw
return|return
name|_mm_minpos_epu16
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mpsadbw_epu8
parameter_list|(
name|__m128i
name|x
parameter_list|,
name|__m128i
name|y
parameter_list|)
block|{
comment|// CHECK: define {{.*}} @test_mm_mpsadbw_epu8
comment|// CHECK: @llvm.x86.sse41.mpsadbw
return|return
name|_mm_mpsadbw_epu8
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_dp_ps
parameter_list|(
name|__m128
name|x
parameter_list|,
name|__m128
name|y
parameter_list|)
block|{
comment|// CHECK: define {{.*}} @test_mm_dp_ps
comment|// CHECK: @llvm.x86.sse41.dpps
return|return
name|_mm_dp_ps
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_dp_pd
parameter_list|(
name|__m128d
name|x
parameter_list|,
name|__m128d
name|y
parameter_list|)
block|{
comment|// CHECK: define {{.*}} @test_mm_dp_pd
comment|// CHECK: @llvm.x86.sse41.dppd
return|return
name|_mm_dp_pd
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_round_ps
parameter_list|(
name|__m128
name|x
parameter_list|)
block|{
comment|// CHECK: define {{.*}} @test_mm_round_ps
comment|// CHECK: @llvm.x86.sse41.round.ps
return|return
name|_mm_round_ps
argument_list|(
name|x
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_round_ss
parameter_list|(
name|__m128
name|x
parameter_list|,
name|__m128
name|y
parameter_list|)
block|{
comment|// CHECK: define {{.*}} @test_mm_round_ss
comment|// CHECK: @llvm.x86.sse41.round.ss
return|return
name|_mm_round_ss
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_round_pd
parameter_list|(
name|__m128d
name|x
parameter_list|)
block|{
comment|// CHECK: define {{.*}} @test_mm_round_pd
comment|// CHECK: @llvm.x86.sse41.round.pd
return|return
name|_mm_round_pd
argument_list|(
name|x
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_round_sd
parameter_list|(
name|__m128d
name|x
parameter_list|,
name|__m128d
name|y
parameter_list|)
block|{
comment|// CHECK: define {{.*}} @test_mm_round_sd
comment|// CHECK: @llvm.x86.sse41.round.sd
return|return
name|_mm_round_sd
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_storel_epi64
parameter_list|(
name|__m128i
name|x
parameter_list|,
name|void
modifier|*
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: define void @test_storel_epi64
comment|// CHECK: store {{.*}} i64* {{.*}}, align 1{{$}}
name|_mm_storel_epi64
argument_list|(
name|y
argument_list|,
name|x
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_stream_si32
parameter_list|(
name|int
name|x
parameter_list|,
name|void
modifier|*
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: define void @test_stream_si32
comment|// CHECK: store {{.*}} i32* {{.*}}, align 1, !nontemporal
name|_mm_stream_si32
argument_list|(
name|y
argument_list|,
name|x
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_stream_si64
parameter_list|(
name|long
name|long
name|x
parameter_list|,
name|void
modifier|*
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: define void @test_stream_si64
comment|// CHECK: store {{.*}} i64* {{.*}}, align 1, !nontemporal
name|_mm_stream_si64
argument_list|(
name|y
argument_list|,
name|x
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_stream_si128
parameter_list|(
name|__m128i
name|x
parameter_list|,
name|void
modifier|*
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: define void @test_stream_si128
comment|// CHECK: store {{.*}}<2 x i64>* {{.*}}, align 16, !nontemporal
name|_mm_stream_si128
argument_list|(
name|y
argument_list|,
name|x
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_extract_epi16
parameter_list|(
name|__m128i
name|__a
parameter_list|)
block|{
comment|// CHECK-LABEL: define void @test_extract_epi16
comment|// CHECK: [[x:%.*]] = and i32 %{{.*}}, 7
comment|// CHECK: extractelement<8 x i16> %{{.*}}, i32 [[x]]
name|_mm_extract_epi16
argument_list|(
name|__a
argument_list|,
literal|8
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|test_extract_ps
parameter_list|(
name|__m128i
name|__a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_extract_ps
comment|// CHECK: extractelement<4 x float> %{{.*}}, i32 0
return|return
name|_mm_extract_ps
argument_list|(
name|__a
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_extract_epi8
parameter_list|(
name|__m128i
name|__a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_extract_epi8
comment|// CHECK: extractelement<16 x i8> %{{.*}}, i32 0
return|return
name|_mm_extract_epi8
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
name|test_extract_epi32
parameter_list|(
name|__m128i
name|__a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_extract_epi32
comment|// CHECK: extractelement<4 x i32> %{{.*}}, i32 0
return|return
name|_mm_extract_epi32
argument_list|(
name|__a
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_insert_epi32
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|int
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_insert_epi32
comment|// CHECK: insertelement<4 x i32> %{{.*}}, i32 %{{.*}}, i32 0
name|_mm_insert_epi32
argument_list|(
name|__a
argument_list|,
name|b
argument_list|,
literal|4
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|__m128d
name|test_blend_pd
parameter_list|(
name|__m128d
name|V1
parameter_list|,
name|__m128d
name|V2
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_blend_pd
comment|// CHECK: shufflevector<2 x double> %{{.*}},<2 x double> %{{.*}},<2 x i32><i32 2, i32 1>
return|return
name|_mm_blend_pd
argument_list|(
name|V1
argument_list|,
name|V2
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_blend_ps
parameter_list|(
name|__m128
name|V1
parameter_list|,
name|__m128
name|V2
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_blend_ps
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> %{{.*}},<4 x i32><i32 4, i32 1, i32 6, i32 3>
return|return
name|_mm_blend_ps
argument_list|(
name|V1
argument_list|,
name|V2
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_blend_epi16
parameter_list|(
name|__m128i
name|V1
parameter_list|,
name|__m128i
name|V2
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_blend_epi16
comment|// CHECK: shufflevector<8 x i16> %{{.*}},<8 x i16> %{{.*}},<8 x i32><i32 0, i32 9, i32 2, i32 11, i32 4, i32 13, i32 6, i32 7>
return|return
name|_mm_blend_epi16
argument_list|(
name|V1
argument_list|,
name|V2
argument_list|,
literal|42
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_cmpeq_ss
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpeq_ss
comment|// CHECK: @llvm.x86.sse.cmp.ss(<4 x float> %{{.*}},<4 x float> %{{.*}}, i8 0)
return|return
name|_mm_cmpeq_ss
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_cmplt_ss
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmplt_ss
comment|// CHECK: @llvm.x86.sse.cmp.ss(<4 x float> %{{.*}},<4 x float> %{{.*}}, i8 1)
return|return
name|_mm_cmplt_ss
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_cmple_ss
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmple_ss
comment|// CHECK: @llvm.x86.sse.cmp.ss(<4 x float> %{{.*}},<4 x float> %{{.*}}, i8 2)
return|return
name|_mm_cmple_ss
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_cmpunord_ss
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpunord_ss
comment|// CHECK: @llvm.x86.sse.cmp.ss(<4 x float> %{{.*}},<4 x float> %{{.*}}, i8 3)
return|return
name|_mm_cmpunord_ss
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_cmpneq_ss
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpneq_ss
comment|// CHECK: @llvm.x86.sse.cmp.ss(<4 x float> %{{.*}},<4 x float> %{{.*}}, i8 4)
return|return
name|_mm_cmpneq_ss
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_cmpnlt_ss
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpnlt_ss
comment|// CHECK: @llvm.x86.sse.cmp.ss(<4 x float> %{{.*}},<4 x float> %{{.*}}, i8 5)
return|return
name|_mm_cmpnlt_ss
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_cmpnle_ss
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpnle_ss
comment|// CHECK: @llvm.x86.sse.cmp.ss(<4 x float> %{{.*}},<4 x float> %{{.*}}, i8 6)
return|return
name|_mm_cmpnle_ss
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_cmpord_ss
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpord_ss
comment|// CHECK: @llvm.x86.sse.cmp.ss(<4 x float> %{{.*}},<4 x float> %{{.*}}, i8 7)
return|return
name|_mm_cmpord_ss
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_cmpgt_ss
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpgt_ss
comment|// CHECK: @llvm.x86.sse.cmp.ss(<4 x float> %{{.*}},<4 x float> %{{.*}}, i8 1)
return|return
name|_mm_cmpgt_ss
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_cmpge_ss
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpge_ss
comment|// CHECK: @llvm.x86.sse.cmp.ss(<4 x float> %{{.*}},<4 x float> %{{.*}}, i8 2)
return|return
name|_mm_cmpge_ss
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_cmpngt_ss
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpngt_ss
comment|// CHECK: @llvm.x86.sse.cmp.ss(<4 x float> %{{.*}},<4 x float> %{{.*}}, i8 5)
return|return
name|_mm_cmpngt_ss
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_cmpnge_ss
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpnge_ss
comment|// CHECK: @llvm.x86.sse.cmp.ss(<4 x float> %{{.*}},<4 x float> %{{.*}}, i8 6)
return|return
name|_mm_cmpnge_ss
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_cmpeq_ps
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpeq_ps
comment|// CHECK: @llvm.x86.sse.cmp.ps(<4 x float> %{{.*}},<4 x float> %{{.*}}, i8 0)
return|return
name|_mm_cmpeq_ps
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_cmplt_ps
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmplt_ps
comment|// CHECK: @llvm.x86.sse.cmp.ps(<4 x float> %{{.*}},<4 x float> %{{.*}}, i8 1)
return|return
name|_mm_cmplt_ps
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_cmple_ps
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmple_ps
comment|// CHECK: @llvm.x86.sse.cmp.ps(<4 x float> %{{.*}},<4 x float> %{{.*}}, i8 2)
return|return
name|_mm_cmple_ps
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_cmpunord_ps
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpunord_ps
comment|// CHECK: @llvm.x86.sse.cmp.ps(<4 x float> %{{.*}},<4 x float> %{{.*}}, i8 3)
return|return
name|_mm_cmpunord_ps
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_cmpneq_ps
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpneq_ps
comment|// CHECK: @llvm.x86.sse.cmp.ps(<4 x float> %{{.*}},<4 x float> %{{.*}}, i8 4)
return|return
name|_mm_cmpneq_ps
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_cmpnlt_ps
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpnlt_ps
comment|// CHECK: @llvm.x86.sse.cmp.ps(<4 x float> %{{.*}},<4 x float> %{{.*}}, i8 5)
return|return
name|_mm_cmpnlt_ps
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_cmpnle_ps
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpnle_ps
comment|// CHECK: @llvm.x86.sse.cmp.ps(<4 x float> %{{.*}},<4 x float> %{{.*}}, i8 6)
return|return
name|_mm_cmpnle_ps
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_cmpord_ps
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpord_ps
comment|// CHECK: @llvm.x86.sse.cmp.ps(<4 x float> %{{.*}},<4 x float> %{{.*}}, i8 7)
return|return
name|_mm_cmpord_ps
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_cmpgt_ps
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpgt_ps
comment|// CHECK: @llvm.x86.sse.cmp.ps(<4 x float> %{{.*}},<4 x float> %{{.*}}, i8 1)
return|return
name|_mm_cmpgt_ps
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_cmpge_ps
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpge_ps
comment|// CHECK: @llvm.x86.sse.cmp.ps(<4 x float> %{{.*}},<4 x float> %{{.*}}, i8 2)
return|return
name|_mm_cmpge_ps
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_cmpngt_ps
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpngt_ps
comment|// CHECK: @llvm.x86.sse.cmp.ps(<4 x float> %{{.*}},<4 x float> %{{.*}}, i8 5)
return|return
name|_mm_cmpngt_ps
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_cmpnge_ps
parameter_list|(
name|__m128
name|__a
parameter_list|,
name|__m128
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpnge_ps
comment|// CHECK: @llvm.x86.sse.cmp.ps(<4 x float> %{{.*}},<4 x float> %{{.*}}, i8 6)
return|return
name|_mm_cmpnge_ps
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_cmpeq_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpeq_sd
comment|// CHECK: @llvm.x86.sse2.cmp.sd(<2 x double> %{{.*}},<2 x double> %{{.*}}, i8 0)
return|return
name|_mm_cmpeq_sd
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_cmplt_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmplt_sd
comment|// CHECK: @llvm.x86.sse2.cmp.sd(<2 x double> %{{.*}},<2 x double> %{{.*}}, i8 1)
return|return
name|_mm_cmplt_sd
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_cmple_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmple_sd
comment|// CHECK: @llvm.x86.sse2.cmp.sd(<2 x double> %{{.*}},<2 x double> %{{.*}}, i8 2)
return|return
name|_mm_cmple_sd
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_cmpunord_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpunord_sd
comment|// CHECK: @llvm.x86.sse2.cmp.sd(<2 x double> %{{.*}},<2 x double> %{{.*}}, i8 3)
return|return
name|_mm_cmpunord_sd
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_cmpneq_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpneq_sd
comment|// CHECK: @llvm.x86.sse2.cmp.sd(<2 x double> %{{.*}},<2 x double> %{{.*}}, i8 4)
return|return
name|_mm_cmpneq_sd
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_cmpnlt_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpnlt_sd
comment|// CHECK: @llvm.x86.sse2.cmp.sd(<2 x double> %{{.*}},<2 x double> %{{.*}}, i8 5)
return|return
name|_mm_cmpnlt_sd
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_cmpnle_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpnle_sd
comment|// CHECK: @llvm.x86.sse2.cmp.sd(<2 x double> %{{.*}},<2 x double> %{{.*}}, i8 6)
return|return
name|_mm_cmpnle_sd
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_cmpord_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpord_sd
comment|// CHECK: @llvm.x86.sse2.cmp.sd(<2 x double> %{{.*}},<2 x double> %{{.*}}, i8 7)
return|return
name|_mm_cmpord_sd
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_cmpgt_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpgt_sd
comment|// CHECK: @llvm.x86.sse2.cmp.sd(<2 x double> %{{.*}},<2 x double> %{{.*}}, i8 1)
return|return
name|_mm_cmpgt_sd
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_cmpge_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpge_sd
comment|// CHECK: @llvm.x86.sse2.cmp.sd(<2 x double> %{{.*}},<2 x double> %{{.*}}, i8 2)
return|return
name|_mm_cmpge_sd
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_cmpngt_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpngt_sd
comment|// CHECK: @llvm.x86.sse2.cmp.sd(<2 x double> %{{.*}},<2 x double> %{{.*}}, i8 5)
return|return
name|_mm_cmpngt_sd
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_cmpnge_sd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpnge_sd
comment|// CHECK: @llvm.x86.sse2.cmp.sd(<2 x double> %{{.*}},<2 x double> %{{.*}}, i8 6)
return|return
name|_mm_cmpnge_sd
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_cmpeq_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpeq_pd
comment|// CHECK: @llvm.x86.sse2.cmp.pd(<2 x double> %{{.*}},<2 x double> %{{.*}}, i8 0)
return|return
name|_mm_cmpeq_pd
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_cmplt_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmplt_pd
comment|// CHECK: @llvm.x86.sse2.cmp.pd(<2 x double> %{{.*}},<2 x double> %{{.*}}, i8 1)
return|return
name|_mm_cmplt_pd
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_cmple_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmple_pd
comment|// CHECK: @llvm.x86.sse2.cmp.pd(<2 x double> %{{.*}},<2 x double> %{{.*}}, i8 2)
return|return
name|_mm_cmple_pd
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_cmpunord_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpunord_pd
comment|// CHECK: @llvm.x86.sse2.cmp.pd(<2 x double> %{{.*}},<2 x double> %{{.*}}, i8 3)
return|return
name|_mm_cmpunord_pd
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_cmpneq_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpneq_pd
comment|// CHECK: @llvm.x86.sse2.cmp.pd(<2 x double> %{{.*}},<2 x double> %{{.*}}, i8 4)
return|return
name|_mm_cmpneq_pd
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_cmpnlt_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpnlt_pd
comment|// CHECK: @llvm.x86.sse2.cmp.pd(<2 x double> %{{.*}},<2 x double> %{{.*}}, i8 5)
return|return
name|_mm_cmpnlt_pd
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_cmpnle_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpnle_pd
comment|// CHECK: @llvm.x86.sse2.cmp.pd(<2 x double> %{{.*}},<2 x double> %{{.*}}, i8 6)
return|return
name|_mm_cmpnle_pd
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_cmpord_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpord_pd
comment|// CHECK: @llvm.x86.sse2.cmp.pd(<2 x double> %{{.*}},<2 x double> %{{.*}}, i8 7)
return|return
name|_mm_cmpord_pd
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_cmpgt_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpgt_pd
comment|// CHECK: @llvm.x86.sse2.cmp.pd(<2 x double> %{{.*}},<2 x double> %{{.*}}, i8 1)
return|return
name|_mm_cmpgt_pd
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_cmpge_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpge_pd
comment|// CHECK: @llvm.x86.sse2.cmp.pd(<2 x double> %{{.*}},<2 x double> %{{.*}}, i8 2)
return|return
name|_mm_cmpge_pd
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_cmpngt_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpngt_pd
comment|// CHECK: @llvm.x86.sse2.cmp.pd(<2 x double> %{{.*}},<2 x double> %{{.*}}, i8 5)
return|return
name|_mm_cmpngt_pd
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_cmpnge_pd
parameter_list|(
name|__m128d
name|__a
parameter_list|,
name|__m128d
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpnge_pd
comment|// CHECK: @llvm.x86.sse2.cmp.pd(<2 x double> %{{.*}},<2 x double> %{{.*}}, i8 6)
return|return
name|_mm_cmpnge_pd
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

end_unit

