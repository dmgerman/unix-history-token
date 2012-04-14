begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ffreestanding -triple i386-apple-darwin9 -target-cpu pentium4 -target-feature +sse4.1 -g -emit-llvm %s -o - | FileCheck %s
end_comment

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
comment|// CHECK: define void @test_store_ss
comment|// CHECK: store {{.*}} float* {{.*}}, align 1,
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
comment|// CHECK: define void @test_store_sd
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
comment|// CHECK: define void @test_store1_pd
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
comment|// CHECK: define void @test_storer_pd
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
comment|// CHECK: define void @test_storeh_pd
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
comment|// CHECK: define void @test_storel_pd
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

end_unit

