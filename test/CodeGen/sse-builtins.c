begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ffreestanding %s -triple=x86_64-apple-darwin -target-feature +sse -emit-llvm -o - -Wall -Werror | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<x86intrin.h>
end_include

begin_comment
comment|// NOTE: This should match the tests in llvm/test/CodeGen/X86/sse-intrinsics-fast-isel.ll
end_comment

begin_function
name|__m128
name|test_mm_add_ps
parameter_list|(
name|__m128
name|A
parameter_list|,
name|__m128
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_add_ps
comment|// CHECK: fadd<4 x float>
return|return
name|_mm_add_ps
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_add_ss
parameter_list|(
name|__m128
name|A
parameter_list|,
name|__m128
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_add_ss
comment|// CHECK: extractelement<4 x float> %{{.*}}, i32 0
comment|// CHECK: extractelement<4 x float> %{{.*}}, i32 0
comment|// CHECK: fadd float
comment|// CHECK: insertelement<4 x float> %{{.*}}, float %{{.*}}, i32 0
return|return
name|_mm_add_ss
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_and_ps
parameter_list|(
name|__m128
name|A
parameter_list|,
name|__m128
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_and_ps
comment|// CHECK: and<4 x i32>
return|return
name|_mm_and_ps
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_andnot_ps
parameter_list|(
name|__m128
name|A
parameter_list|,
name|__m128
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_andnot_ps
comment|// CHECK: xor<4 x i32> %{{.*}},<i32 -1, i32 -1, i32 -1, i32 -1>
comment|// CHECK: and<4 x i32>
return|return
name|_mm_andnot_ps
argument_list|(
name|A
argument_list|,
name|B
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
comment|// CHECK:         [[CMP:%.*]] = fcmp oeq<4 x float>
comment|// CHECK-NEXT:    [[SEXT:%.*]] = sext<4 x i1> [[CMP]] to<4 x i32>
comment|// CHECK-NEXT:    [[BC:%.*]] = bitcast<4 x i32> [[SEXT]] to<4 x float>
comment|// CHECK-NEXT:    ret<4 x float> [[BC]]
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
comment|// CHECK:         [[CMP:%.*]] = fcmp ole<4 x float>
comment|// CHECK-NEXT:    [[SEXT:%.*]] = sext<4 x i1> [[CMP]] to<4 x i32>
comment|// CHECK-NEXT:    [[BC:%.*]] = bitcast<4 x i32> [[SEXT]] to<4 x float>
comment|// CHECK-NEXT:    ret<4 x float> [[BC]]
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
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> %{{.*}},<4 x i32><i32 4, i32 1, i32 2, i32 3>
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
comment|// CHECK:         [[CMP:%.*]] = fcmp olt<4 x float>
comment|// CHECK-NEXT:    [[SEXT:%.*]] = sext<4 x i1> [[CMP]] to<4 x i32>
comment|// CHECK-NEXT:    [[BC:%.*]] = bitcast<4 x i32> [[SEXT]] to<4 x float>
comment|// CHECK-NEXT:    ret<4 x float> [[BC]]
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
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> %{{.*}},<4 x i32><i32 4, i32 1, i32 2, i32 3>
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
comment|// CHECK:         [[CMP:%.*]] = fcmp ole<4 x float>
comment|// CHECK-NEXT:    [[SEXT:%.*]] = sext<4 x i1> [[CMP]] to<4 x i32>
comment|// CHECK-NEXT:    [[BC:%.*]] = bitcast<4 x i32> [[SEXT]] to<4 x float>
comment|// CHECK-NEXT:    ret<4 x float> [[BC]]
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
comment|// CHECK:         [[CMP:%.*]] = fcmp olt<4 x float>
comment|// CHECK-NEXT:    [[SEXT:%.*]] = sext<4 x i1> [[CMP]] to<4 x i32>
comment|// CHECK-NEXT:    [[BC:%.*]] = bitcast<4 x i32> [[SEXT]] to<4 x float>
comment|// CHECK-NEXT:    ret<4 x float> [[BC]]
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
comment|// CHECK:         [[CMP:%.*]] = fcmp une<4 x float>
comment|// CHECK-NEXT:    [[SEXT:%.*]] = sext<4 x i1> [[CMP]] to<4 x i32>
comment|// CHECK-NEXT:    [[BC:%.*]] = bitcast<4 x i32> [[SEXT]] to<4 x float>
comment|// CHECK-NEXT:    ret<4 x float> [[BC]]
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
comment|// CHECK:         [[CMP:%.*]] = fcmp ugt<4 x float>
comment|// CHECK-NEXT:    [[SEXT:%.*]] = sext<4 x i1> [[CMP]] to<4 x i32>
comment|// CHECK-NEXT:    [[BC:%.*]] = bitcast<4 x i32> [[SEXT]] to<4 x float>
comment|// CHECK-NEXT:    ret<4 x float> [[BC]]
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
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> %{{.*}},<4 x i32><i32 4, i32 1, i32 2, i32 3>
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
comment|// CHECK:         [[CMP:%.*]] = fcmp uge<4 x float>
comment|// CHECK-NEXT:    [[SEXT:%.*]] = sext<4 x i1> [[CMP]] to<4 x i32>
comment|// CHECK-NEXT:    [[BC:%.*]] = bitcast<4 x i32> [[SEXT]] to<4 x float>
comment|// CHECK-NEXT:    ret<4 x float> [[BC]]
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
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> %{{.*}},<4 x i32><i32 4, i32 1, i32 2, i32 3>
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
comment|// CHECK:         [[CMP:%.*]] = fcmp ugt<4 x float>
comment|// CHECK-NEXT:    [[SEXT:%.*]] = sext<4 x i1> [[CMP]] to<4 x i32>
comment|// CHECK-NEXT:    [[BC:%.*]] = bitcast<4 x i32> [[SEXT]] to<4 x float>
comment|// CHECK-NEXT:    ret<4 x float> [[BC]]
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
comment|// CHECK:         [[CMP:%.*]] = fcmp uge<4 x float>
comment|// CHECK-NEXT:    [[SEXT:%.*]] = sext<4 x i1> [[CMP]] to<4 x i32>
comment|// CHECK-NEXT:    [[BC:%.*]] = bitcast<4 x i32> [[SEXT]] to<4 x float>
comment|// CHECK-NEXT:    ret<4 x float> [[BC]]
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
comment|// CHECK:         [[CMP:%.*]] = fcmp ord<4 x float>
comment|// CHECK-NEXT:    [[SEXT:%.*]] = sext<4 x i1> [[CMP]] to<4 x i32>
comment|// CHECK-NEXT:    [[BC:%.*]] = bitcast<4 x i32> [[SEXT]] to<4 x float>
comment|// CHECK-NEXT:    ret<4 x float> [[BC]]
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
comment|// CHECK:         [[CMP:%.*]] = fcmp uno<4 x float>
comment|// CHECK-NEXT:    [[SEXT:%.*]] = sext<4 x i1> [[CMP]] to<4 x i32>
comment|// CHECK-NEXT:    [[BC:%.*]] = bitcast<4 x i32> [[SEXT]] to<4 x float>
comment|// CHECK-NEXT:    ret<4 x float> [[BC]]
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
name|int
name|test_mm_comieq_ss
parameter_list|(
name|__m128
name|A
parameter_list|,
name|__m128
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comieq_ss
comment|// CHECK: call i32 @llvm.x86.sse.comieq.ss(<4 x float> %{{.*}},<4 x float> %{{.*}})
return|return
name|_mm_comieq_ss
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
name|test_mm_comige_ss
parameter_list|(
name|__m128
name|A
parameter_list|,
name|__m128
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comige_ss
comment|// CHECK: call i32 @llvm.x86.sse.comige.ss(<4 x float> %{{.*}},<4 x float> %{{.*}})
return|return
name|_mm_comige_ss
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
name|test_mm_comigt_ss
parameter_list|(
name|__m128
name|A
parameter_list|,
name|__m128
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comigt_ss
comment|// CHECK: call i32 @llvm.x86.sse.comigt.ss(<4 x float> %{{.*}},<4 x float> %{{.*}})
return|return
name|_mm_comigt_ss
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
name|test_mm_comile_ss
parameter_list|(
name|__m128
name|A
parameter_list|,
name|__m128
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comile_ss
comment|// CHECK: call i32 @llvm.x86.sse.comile.ss(<4 x float> %{{.*}},<4 x float> %{{.*}})
return|return
name|_mm_comile_ss
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
name|test_mm_comilt_ss
parameter_list|(
name|__m128
name|A
parameter_list|,
name|__m128
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comilt_ss
comment|// CHECK: call i32 @llvm.x86.sse.comilt.ss(<4 x float> %{{.*}},<4 x float> %{{.*}})
return|return
name|_mm_comilt_ss
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
name|test_mm_comineq_ss
parameter_list|(
name|__m128
name|A
parameter_list|,
name|__m128
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_comineq_ss
comment|// CHECK: call i32 @llvm.x86.sse.comineq.ss(<4 x float> %{{.*}},<4 x float> %{{.*}})
return|return
name|_mm_comineq_ss
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
name|test_mm_cvt_ss2si
parameter_list|(
name|__m128
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvt_ss2si
comment|// CHECK: call i32 @llvm.x86.sse.cvtss2si(<4 x float> %{{.*}})
return|return
name|_mm_cvt_ss2si
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_cvtsi32_ss
parameter_list|(
name|__m128
name|A
parameter_list|,
name|int
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvtsi32_ss
comment|// CHECK: sitofp i32 %{{.*}} to float
comment|// CHECK: insertelement<4 x float> %{{.*}}, float %{{.*}}, i32 0
return|return
name|_mm_cvtsi32_ss
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_cvtsi64_ss
parameter_list|(
name|__m128
name|A
parameter_list|,
name|long
name|long
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvtsi64_ss
comment|// CHECK: sitofp i64 %{{.*}} to float
comment|// CHECK: insertelement<4 x float> %{{.*}}, float %{{.*}}, i32 0
return|return
name|_mm_cvtsi64_ss
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|float
name|test_mm_cvtss_f32
parameter_list|(
name|__m128
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvtss_f32
comment|// CHECK: extractelement<4 x float> %{{.*}}, i32 0
return|return
name|_mm_cvtss_f32
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm_cvtss_si32
parameter_list|(
name|__m128
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvtss_si32
comment|// CHECK: call i32 @llvm.x86.sse.cvtss2si(<4 x float> %{{.*}})
return|return
name|_mm_cvtss_si32
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|long
name|long
name|test_mm_cvtss_si64
parameter_list|(
name|__m128
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvtss_si64
comment|// CHECK: call i64 @llvm.x86.sse.cvtss2si64(<4 x float> %{{.*}})
return|return
name|_mm_cvtss_si64
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm_cvtt_ss2si
parameter_list|(
name|__m128
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvtt_ss2si
comment|// CHECK: call i32 @llvm.x86.sse.cvttss2si(<4 x float> %{{.*}})
return|return
name|_mm_cvtt_ss2si
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm_cvttss_si32
parameter_list|(
name|__m128
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvttss_si32
comment|// CHECK: call i32 @llvm.x86.sse.cvttss2si(<4 x float> %{{.*}})
return|return
name|_mm_cvttss_si32
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|long
name|long
name|test_mm_cvttss_si64
parameter_list|(
name|__m128
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvttss_si64
comment|// CHECK: call i64 @llvm.x86.sse.cvttss2si64(<4 x float> %{{.*}})
return|return
name|_mm_cvttss_si64
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_div_ps
parameter_list|(
name|__m128
name|A
parameter_list|,
name|__m128
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_div_ps
comment|// CHECK: fdiv<4 x float>
return|return
name|_mm_div_ps
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_div_ss
parameter_list|(
name|__m128
name|A
parameter_list|,
name|__m128
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_div_ss
comment|// CHECK: extractelement<4 x float> %{{.*}}, i32 0
comment|// CHECK: extractelement<4 x float> %{{.*}}, i32 0
comment|// CHECK: fdiv float
comment|// CHECK: insertelement<4 x float> %{{.*}}, float %{{.*}}, i32 0
return|return
name|_mm_div_ss
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|int
name|test_MM_GET_EXCEPTION_MASK
parameter_list|()
block|{
comment|// CHECK-LABEL: test_MM_GET_EXCEPTION_MASK
comment|// CHECK: call void @llvm.x86.sse.stmxcsr(i8* %{{.*}})
comment|// CHECK: and i32 %{{.*}}, 8064
return|return
name|_MM_GET_EXCEPTION_MASK
argument_list|()
return|;
block|}
end_function

begin_function
name|unsigned
name|int
name|test_MM_GET_EXCEPTION_STATE
parameter_list|()
block|{
comment|// CHECK-LABEL: test_MM_GET_EXCEPTION_STATE
comment|// CHECK: call void @llvm.x86.sse.stmxcsr(i8* %{{.*}})
comment|// CHECK: and i32 %{{.*}}, 63
return|return
name|_MM_GET_EXCEPTION_STATE
argument_list|()
return|;
block|}
end_function

begin_function
name|unsigned
name|int
name|test_MM_GET_FLUSH_ZERO_MODE
parameter_list|()
block|{
comment|// CHECK-LABEL: test_MM_GET_FLUSH_ZERO_MODE
comment|// CHECK: call void @llvm.x86.sse.stmxcsr(i8* %{{.*}})
comment|// CHECK: and i32 %{{.*}}, 32768
return|return
name|_MM_GET_FLUSH_ZERO_MODE
argument_list|()
return|;
block|}
end_function

begin_function
name|unsigned
name|int
name|test_MM_GET_ROUNDING_MODE
parameter_list|()
block|{
comment|// CHECK-LABEL: test_MM_GET_ROUNDING_MODE
comment|// CHECK: call void @llvm.x86.sse.stmxcsr(i8* %{{.*}})
comment|// CHECK: and i32 %{{.*}}, 24576
return|return
name|_MM_GET_ROUNDING_MODE
argument_list|()
return|;
block|}
end_function

begin_function
name|unsigned
name|int
name|test_mm_getcsr
parameter_list|()
block|{
comment|// CHECK-LABEL: test_mm_getcsr
comment|// CHECK: call void @llvm.x86.sse.stmxcsr(i8* %{{.*}})
comment|// CHECK: load i32
return|return
name|_mm_getcsr
argument_list|()
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_load_ps
parameter_list|(
name|float
modifier|*
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_load_ps
comment|// CHECK: load<4 x float>,<4 x float>* {{.*}}, align 16
return|return
name|_mm_load_ps
argument_list|(
name|y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_load_ps1
parameter_list|(
name|float
modifier|*
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_load_ps1
comment|// CHECK: load float, float* %{{.*}}, align 4
comment|// CHECK: insertelement<4 x float> undef, float %{{.*}}, i32 0
comment|// CHECK: insertelement<4 x float> %{{.*}}, float %{{.*}}, i32 1
comment|// CHECK: insertelement<4 x float> %{{.*}}, float %{{.*}}, i32 2
comment|// CHECK: insertelement<4 x float> %{{.*}}, float %{{.*}}, i32 3
return|return
name|_mm_load_ps1
argument_list|(
name|y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_load_ss
parameter_list|(
name|float
modifier|*
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_load_ss
comment|// CHECK: load float, float* {{.*}}, align 1{{$}}
comment|// CHECK: insertelement<4 x float> undef, float %{{.*}}, i32 0
comment|// CHECK: insertelement<4 x float> %{{.*}}, float 0.000000e+00, i32 1
comment|// CHECK: insertelement<4 x float> %{{.*}}, float 0.000000e+00, i32 2
comment|// CHECK: insertelement<4 x float> %{{.*}}, float 0.000000e+00, i32 3
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
name|test_mm_load1_ps
parameter_list|(
name|float
modifier|*
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_load1_ps
comment|// CHECK: load float, float* %{{.*}}, align 4
comment|// CHECK: insertelement<4 x float> undef, float %{{.*}}, i32 0
comment|// CHECK: insertelement<4 x float> %{{.*}}, float %{{.*}}, i32 1
comment|// CHECK: insertelement<4 x float> %{{.*}}, float %{{.*}}, i32 2
comment|// CHECK: insertelement<4 x float> %{{.*}}, float %{{.*}}, i32 3
return|return
name|_mm_load1_ps
argument_list|(
name|y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_loadh_pi
parameter_list|(
name|__m128
name|x
parameter_list|,
name|__m64
modifier|*
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_loadh_pi
comment|// CHECK: load<2 x float>,<2 x float>* {{.*}}, align 1{{$}}
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
name|test_mm_loadl_pi
parameter_list|(
name|__m128
name|x
parameter_list|,
name|__m64
modifier|*
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_loadl_pi
comment|// CHECK: load<2 x float>,<2 x float>* {{.*}}, align 1{{$}}
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
name|test_mm_loadr_ps
parameter_list|(
name|float
modifier|*
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_loadr_ps
comment|// CHECK: load<4 x float>,<4 x float>* %{{.*}}, align 16
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> %{{.*}},<4 x i32><i32 3, i32 2, i32 1, i32 0>
return|return
name|_mm_loadr_ps
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_loadu_ps
parameter_list|(
name|float
modifier|*
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_loadu_ps
comment|// CHECK: load<4 x float>,<4 x float>* %{{.*}}, align 1{{$}}
return|return
name|_mm_loadu_ps
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_max_ps
parameter_list|(
name|__m128
name|A
parameter_list|,
name|__m128
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_max_ps
comment|// CHECK: @llvm.x86.sse.max.ps(<4 x float> %{{.*}},<4 x float> %{{.*}})
return|return
name|_mm_max_ps
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_max_ss
parameter_list|(
name|__m128
name|A
parameter_list|,
name|__m128
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_max_ss
comment|// CHECK: @llvm.x86.sse.max.ss(<4 x float> %{{.*}},<4 x float> %{{.*}})
return|return
name|_mm_max_ss
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_min_ps
parameter_list|(
name|__m128
name|A
parameter_list|,
name|__m128
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_min_ps
comment|// CHECK: @llvm.x86.sse.min.ps(<4 x float> %{{.*}},<4 x float> %{{.*}})
return|return
name|_mm_min_ps
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_min_ss
parameter_list|(
name|__m128
name|A
parameter_list|,
name|__m128
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_min_ss
comment|// CHECK: @llvm.x86.sse.min.ss(<4 x float> %{{.*}},<4 x float> %{{.*}})
return|return
name|_mm_min_ss
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_move_ss
parameter_list|(
name|__m128
name|A
parameter_list|,
name|__m128
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_move_ss
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> %{{.*}},<4 x i32><i32 4, i32 1, i32 2, i32 3>
return|return
name|_mm_move_ss
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_movehl_ps
parameter_list|(
name|__m128
name|A
parameter_list|,
name|__m128
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_movehl_ps
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> %{{.*}},<4 x i32><i32 6, i32 7, i32 2, i32 3>
return|return
name|_mm_movehl_ps
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_movelh_ps
parameter_list|(
name|__m128
name|A
parameter_list|,
name|__m128
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_movelh_ps
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> %{{.*}},<4 x i32><i32 0, i32 1, i32 4, i32 5>
return|return
name|_mm_movelh_ps
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
name|test_mm_movemask_ps
parameter_list|(
name|__m128
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_movemask_ps
comment|// CHECK: call i32 @llvm.x86.sse.movmsk.ps(<4 x float> %{{.*}})
return|return
name|_mm_movemask_ps
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mul_ps
parameter_list|(
name|__m128
name|A
parameter_list|,
name|__m128
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_mul_ps
comment|// CHECK: fmul<4 x float>
return|return
name|_mm_mul_ps
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mul_ss
parameter_list|(
name|__m128
name|A
parameter_list|,
name|__m128
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_mul_ss
comment|// CHECK: extractelement<4 x float> %{{.*}}, i32 0
comment|// CHECK: extractelement<4 x float> %{{.*}}, i32 0
comment|// CHECK: fmul float
comment|// CHECK: insertelement<4 x float> %{{.*}}, float %{{.*}}, i32 0
return|return
name|_mm_mul_ss
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_or_ps
parameter_list|(
name|__m128
name|A
parameter_list|,
name|__m128
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_or_ps
comment|// CHECK: or<4 x i32>
return|return
name|_mm_or_ps
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm_prefetch
parameter_list|(
name|char
specifier|const
modifier|*
name|p
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_prefetch
comment|// CHECK: call void @llvm.prefetch(i8* {{.*}}, i32 0, i32 0, i32 1)
name|_mm_prefetch
argument_list|(
name|p
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|__m128
name|test_mm_rcp_ps
parameter_list|(
name|__m128
name|x
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_rcp_ps
comment|// CHECK: call<4 x float> @llvm.x86.sse.rcp.ps(<4 x float> {{.*}})
return|return
name|_mm_rcp_ps
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_rcp_ss
parameter_list|(
name|__m128
name|x
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_rcp_ss
comment|// CHECK: call<4 x float> @llvm.x86.sse.rcp.ss(<4 x float> {{.*}})
comment|// CHECK: extractelement<4 x float> {{.*}}, i32 0
comment|// CHECK: insertelement<4 x float> undef, float {{.*}}, i32 0
comment|// CHECK: extractelement<4 x float> {{.*}}, i32 1
comment|// CHECK: insertelement<4 x float> {{.*}}, float {{.*}}, i32 1
comment|// CHECK: extractelement<4 x float> {{.*}}, i32 2
comment|// CHECK: insertelement<4 x float> {{.*}}, float {{.*}}, i32 2
comment|// CHECK: extractelement<4 x float> {{.*}}, i32 3
comment|// CHECK: insertelement<4 x float> {{.*}}, float {{.*}}, i32 3
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
name|test_mm_rsqrt_ps
parameter_list|(
name|__m128
name|x
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_rsqrt_ps
comment|// CHECK: call<4 x float> @llvm.x86.sse.rsqrt.ps(<4 x float> {{.*}})
return|return
name|_mm_rsqrt_ps
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_rsqrt_ss
parameter_list|(
name|__m128
name|x
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_rsqrt_ss
comment|// CHECK: call<4 x float> @llvm.x86.sse.rsqrt.ss(<4 x float> {{.*}})
comment|// CHECK: extractelement<4 x float> {{.*}}, i32 0
comment|// CHECK: insertelement<4 x float> undef, float {{.*}}, i32 0
comment|// CHECK: extractelement<4 x float> {{.*}}, i32 1
comment|// CHECK: insertelement<4 x float> {{.*}}, float {{.*}}, i32 1
comment|// CHECK: extractelement<4 x float> {{.*}}, i32 2
comment|// CHECK: insertelement<4 x float> {{.*}}, float {{.*}}, i32 2
comment|// CHECK: extractelement<4 x float> {{.*}}, i32 3
comment|// CHECK: insertelement<4 x float> {{.*}}, float {{.*}}, i32 3
return|return
name|_mm_rsqrt_ss
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_MM_SET_EXCEPTION_MASK
parameter_list|(
name|unsigned
name|int
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_MM_SET_EXCEPTION_MASK
comment|// CHECK: call void @llvm.x86.sse.stmxcsr(i8* {{.*}})
comment|// CHECK: load i32
comment|// CHECK: and i32 {{.*}}, -8065
comment|// CHECK: or i32
comment|// CHECK: store i32
comment|// CHECK: call void @llvm.x86.sse.ldmxcsr(i8* {{.*}})
name|_MM_SET_EXCEPTION_MASK
argument_list|(
name|A
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_MM_SET_EXCEPTION_STATE
parameter_list|(
name|unsigned
name|int
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_MM_SET_EXCEPTION_STATE
comment|// CHECK: call void @llvm.x86.sse.stmxcsr(i8* {{.*}})
comment|// CHECK: load i32
comment|// CHECK: and i32 {{.*}}, -64
comment|// CHECK: or i32
comment|// CHECK: store i32
comment|// CHECK: call void @llvm.x86.sse.ldmxcsr(i8* {{.*}})
name|_MM_SET_EXCEPTION_STATE
argument_list|(
name|A
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_MM_SET_FLUSH_ZERO_MODE
parameter_list|(
name|unsigned
name|int
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_MM_SET_FLUSH_ZERO_MODE
comment|// CHECK: call void @llvm.x86.sse.stmxcsr(i8* {{.*}})
comment|// CHECK: load i32
comment|// CHECK: and i32 {{.*}}, -32769
comment|// CHECK: or i32
comment|// CHECK: store i32
comment|// CHECK: call void @llvm.x86.sse.ldmxcsr(i8* {{.*}})
name|_MM_SET_FLUSH_ZERO_MODE
argument_list|(
name|A
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|__m128
name|test_mm_set_ps
parameter_list|(
name|float
name|A
parameter_list|,
name|float
name|B
parameter_list|,
name|float
name|C
parameter_list|,
name|float
name|D
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_set_ps
comment|// CHECK: insertelement<4 x float> undef, float {{.*}}, i32 0
comment|// CHECK: insertelement<4 x float> {{.*}}, float {{.*}}, i32 1
comment|// CHECK: insertelement<4 x float> {{.*}}, float {{.*}}, i32 2
comment|// CHECK: insertelement<4 x float> {{.*}}, float {{.*}}, i32 3
return|return
name|_mm_set_ps
argument_list|(
name|A
argument_list|,
name|B
argument_list|,
name|C
argument_list|,
name|D
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_set_ps1
parameter_list|(
name|float
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_set_ps1
comment|// CHECK: insertelement<4 x float> undef, float {{.*}}, i32 0
comment|// CHECK: insertelement<4 x float> {{.*}}, float {{.*}}, i32 1
comment|// CHECK: insertelement<4 x float> {{.*}}, float {{.*}}, i32 2
comment|// CHECK: insertelement<4 x float> {{.*}}, float {{.*}}, i32 3
return|return
name|_mm_set_ps1
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_MM_SET_ROUNDING_MODE
parameter_list|(
name|unsigned
name|int
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_MM_SET_ROUNDING_MODE
comment|// CHECK: call void @llvm.x86.sse.stmxcsr(i8* {{.*}})
comment|// CHECK: load i32
comment|// CHECK: and i32 {{.*}}, -24577
comment|// CHECK: or i32
comment|// CHECK: store i32
comment|// CHECK: call void @llvm.x86.sse.ldmxcsr(i8* {{.*}})
name|_MM_SET_ROUNDING_MODE
argument_list|(
name|A
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|__m128
name|test_mm_set_ss
parameter_list|(
name|float
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_set_ss
comment|// CHECK: insertelement<4 x float> undef, float {{.*}}, i32 0
comment|// CHECK: insertelement<4 x float> {{.*}}, float 0.000000e+00, i32 1
comment|// CHECK: insertelement<4 x float> {{.*}}, float 0.000000e+00, i32 2
comment|// CHECK: insertelement<4 x float> {{.*}}, float 0.000000e+00, i32 3
return|return
name|_mm_set_ss
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_set1_ps
parameter_list|(
name|float
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_set1_ps
comment|// CHECK: insertelement<4 x float> undef, float {{.*}}, i32 0
comment|// CHECK: insertelement<4 x float> {{.*}}, float {{.*}}, i32 1
comment|// CHECK: insertelement<4 x float> {{.*}}, float {{.*}}, i32 2
comment|// CHECK: insertelement<4 x float> {{.*}}, float {{.*}}, i32 3
return|return
name|_mm_set1_ps
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm_setcsr
parameter_list|(
name|unsigned
name|int
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_setcsr
comment|// CHECK: store i32
comment|// CHECK: call void @llvm.x86.sse.ldmxcsr(i8* {{.*}})
name|_mm_setcsr
argument_list|(
name|A
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|__m128
name|test_mm_setr_ps
parameter_list|(
name|float
name|A
parameter_list|,
name|float
name|B
parameter_list|,
name|float
name|C
parameter_list|,
name|float
name|D
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_setr_ps
comment|// CHECK: insertelement<4 x float> undef, float {{.*}}, i32 0
comment|// CHECK: insertelement<4 x float> {{.*}}, float {{.*}}, i32 1
comment|// CHECK: insertelement<4 x float> {{.*}}, float {{.*}}, i32 2
comment|// CHECK: insertelement<4 x float> {{.*}}, float {{.*}}, i32 3
return|return
name|_mm_setr_ps
argument_list|(
name|A
argument_list|,
name|B
argument_list|,
name|C
argument_list|,
name|D
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_setzero_ps
parameter_list|()
block|{
comment|// CHECK-LABEL: test_mm_setzero_ps
comment|// CHECK: store<4 x float> zeroinitializer
return|return
name|_mm_setzero_ps
argument_list|()
return|;
block|}
end_function

begin_function
name|void
name|test_mm_sfence
parameter_list|()
block|{
comment|// CHECK-LABEL: test_mm_sfence
comment|// CHECK: call void @llvm.x86.sse.sfence()
name|_mm_sfence
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|__m128
name|test_mm_shuffle_ps
parameter_list|(
name|__m128
name|A
parameter_list|,
name|__m128
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_shuffle_ps
comment|// CHECK: shufflevector<4 x float> {{.*}},<4 x float> {{.*}},<4 x i32><i32 0, i32 0, i32 4, i32 4>
return|return
name|_mm_shuffle_ps
argument_list|(
name|A
argument_list|,
name|B
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_sqrt_ps
parameter_list|(
name|__m128
name|x
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_sqrt_ps
comment|// CHECK: call<4 x float> @llvm.x86.sse.sqrt.ps(<4 x float> {{.*}})
return|return
name|_mm_sqrt_ps
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
comment|// CHECK: insertelement<4 x float> undef, float {{.*}}, i32 0
comment|// CHECK: extractelement<4 x float> {{.*}}, i32 1
comment|// CHECK: insertelement<4 x float> {{.*}}, float {{.*}}, i32 1
comment|// CHECK: extractelement<4 x float> {{.*}}, i32 2
comment|// CHECK: insertelement<4 x float> {{.*}}, float {{.*}}, i32 2
comment|// CHECK: extractelement<4 x float> {{.*}}, i32 3
comment|// CHECK: insertelement<4 x float> {{.*}}, float {{.*}}, i32 3
return|return
name|_mm_sqrt_ss
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm_store_ps
parameter_list|(
name|float
modifier|*
name|x
parameter_list|,
name|__m128
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_store_ps
comment|// CHECK: store<4 x float> %{{.*}},<4 x float>* {{.*}}, align 16
name|_mm_store_ps
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_mm_store_ps1
parameter_list|(
name|float
modifier|*
name|x
parameter_list|,
name|__m128
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_store_ps1
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> %{{.*}},<4 x i32> zeroinitializer
comment|// CHECK: store<4 x float> %{{.*}},<4 x float>* %{{.*}}, align 16
name|_mm_store_ps1
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_mm_store_ss
parameter_list|(
name|float
modifier|*
name|x
parameter_list|,
name|__m128
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_store_ss
comment|// CHECK: extractelement<4 x float> {{.*}}, i32 0
comment|// CHECK: store float %{{.*}}, float* {{.*}}, align 1{{$}}
name|_mm_store_ss
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_mm_store1_ps
parameter_list|(
name|float
modifier|*
name|x
parameter_list|,
name|__m128
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_store1_ps
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> %{{.*}},<4 x i32> zeroinitializer
comment|// CHECK: store<4 x float> %{{.*}},<4 x float>* %{{.*}}, align 16
name|_mm_store1_ps
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_mm_storeh_pi
parameter_list|(
name|__m64
modifier|*
name|x
parameter_list|,
name|__m128
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_storeh_pi
comment|// CHECK: bitcast<4 x float> %{{.*}} to<2 x i64>
comment|// CHECK: extractelement<2 x i64> %{{.*}}, i64 1
comment|// CHECK: store i64 %{{.*}}, i64* {{.*}}
name|_mm_storeh_pi
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_mm_storel_pi
parameter_list|(
name|__m64
modifier|*
name|x
parameter_list|,
name|__m128
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_storel_pi
comment|// CHECK: bitcast<4 x float> %{{.*}} to<2 x i64>
comment|// CHECK: extractelement<2 x i64> %{{.*}}, i64 0
comment|// CHECK: store i64 %{{.*}}, i64* {{.*}}
name|_mm_storel_pi
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_mm_storer_ps
parameter_list|(
name|float
modifier|*
name|x
parameter_list|,
name|__m128
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_storer_ps
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> %{{.*}},<4 x i32><i32 3, i32 2, i32 1, i32 0>
comment|// CHECK: store<4 x float> %{{.*}},<4 x float>* {{.*}}, align 16
name|_mm_storer_ps
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_mm_storeu_ps
parameter_list|(
name|float
modifier|*
name|x
parameter_list|,
name|__m128
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_storeu_ps
comment|// CHECK: store<4 x float> %{{.*}},<4 x float>* %{{.*}}, align 1{{$}}
comment|// CHECK-NEXT: ret void
name|_mm_storeu_ps
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_mm_stream_ps
parameter_list|(
name|float
modifier|*
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_stream_ps
comment|// CHECK: store<4 x float> %{{.*}},<4 x float>* %{{.*}}, align 16, !nontemporal
name|_mm_stream_ps
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|__m128
name|test_mm_sub_ps
parameter_list|(
name|__m128
name|A
parameter_list|,
name|__m128
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_sub_ps
comment|// CHECK: fsub<4 x float>
return|return
name|_mm_sub_ps
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_sub_ss
parameter_list|(
name|__m128
name|A
parameter_list|,
name|__m128
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_sub_ss
comment|// CHECK: extractelement<4 x float> %{{.*}}, i32 0
comment|// CHECK: extractelement<4 x float> %{{.*}}, i32 0
comment|// CHECK: fsub float
comment|// CHECK: insertelement<4 x float> %{{.*}}, float %{{.*}}, i32 0
return|return
name|_mm_sub_ss
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_MM_TRANSPOSE4_PS
parameter_list|(
name|__m128
modifier|*
name|A
parameter_list|,
name|__m128
modifier|*
name|B
parameter_list|,
name|__m128
modifier|*
name|C
parameter_list|,
name|__m128
modifier|*
name|D
parameter_list|)
block|{
comment|// CHECK-LABEL: test_MM_TRANSPOSE4_PS
comment|// CHECK: shufflevector<4 x float> {{.*}},<4 x float> {{.*}},<4 x i32><i32 0, i32 4, i32 1, i32 5>
comment|// CHECK: shufflevector<4 x float> {{.*}},<4 x float> {{.*}},<4 x i32><i32 0, i32 4, i32 1, i32 5>
comment|// CHECK: shufflevector<4 x float> {{.*}},<4 x float> {{.*}},<4 x i32><i32 2, i32 6, i32 3, i32 7>
comment|// CHECK: shufflevector<4 x float> {{.*}},<4 x float> {{.*}},<4 x i32><i32 2, i32 6, i32 3, i32 7>
comment|// CHECK: shufflevector<4 x float> {{.*}},<4 x float> {{.*}},<4 x i32><i32 0, i32 1, i32 4, i32 5>
comment|// CHECK: shufflevector<4 x float> {{.*}},<4 x float> {{.*}},<4 x i32><i32 6, i32 7, i32 2, i32 3>
comment|// CHECK: shufflevector<4 x float> {{.*}},<4 x float> {{.*}},<4 x i32><i32 0, i32 1, i32 4, i32 5>
comment|// CHECK: shufflevector<4 x float> {{.*}},<4 x float> {{.*}},<4 x i32><i32 6, i32 7, i32 2, i32 3>
name|_MM_TRANSPOSE4_PS
argument_list|(
operator|*
name|A
argument_list|,
operator|*
name|B
argument_list|,
operator|*
name|C
argument_list|,
operator|*
name|D
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|test_mm_ucomieq_ss
parameter_list|(
name|__m128
name|A
parameter_list|,
name|__m128
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_ucomieq_ss
comment|// CHECK: call i32 @llvm.x86.sse.ucomieq.ss(<4 x float> %{{.*}},<4 x float> %{{.*}})
return|return
name|_mm_ucomieq_ss
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
name|test_mm_ucomige_ss
parameter_list|(
name|__m128
name|A
parameter_list|,
name|__m128
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_ucomige_ss
comment|// CHECK: call i32 @llvm.x86.sse.ucomige.ss(<4 x float> %{{.*}},<4 x float> %{{.*}})
return|return
name|_mm_ucomige_ss
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
name|test_mm_ucomigt_ss
parameter_list|(
name|__m128
name|A
parameter_list|,
name|__m128
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_ucomigt_ss
comment|// CHECK: call i32 @llvm.x86.sse.ucomigt.ss(<4 x float> %{{.*}},<4 x float> %{{.*}})
return|return
name|_mm_ucomigt_ss
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
name|test_mm_ucomile_ss
parameter_list|(
name|__m128
name|A
parameter_list|,
name|__m128
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_ucomile_ss
comment|// CHECK: call i32 @llvm.x86.sse.ucomile.ss(<4 x float> %{{.*}},<4 x float> %{{.*}})
return|return
name|_mm_ucomile_ss
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
name|test_mm_ucomilt_ss
parameter_list|(
name|__m128
name|A
parameter_list|,
name|__m128
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_ucomilt_ss
comment|// CHECK: call i32 @llvm.x86.sse.ucomilt.ss(<4 x float> %{{.*}},<4 x float> %{{.*}})
return|return
name|_mm_ucomilt_ss
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
name|test_mm_ucomineq_ss
parameter_list|(
name|__m128
name|A
parameter_list|,
name|__m128
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_ucomineq_ss
comment|// CHECK: call i32 @llvm.x86.sse.ucomineq.ss(<4 x float> %{{.*}},<4 x float> %{{.*}})
return|return
name|_mm_ucomineq_ss
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_undefined_ps
parameter_list|()
block|{
comment|// CHECK-LABEL: @test_mm_undefined_ps
comment|// CHECK: ret<4 x float> zeroinitializer
return|return
name|_mm_undefined_ps
argument_list|()
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_unpackhi_ps
parameter_list|(
name|__m128
name|A
parameter_list|,
name|__m128
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_unpackhi_ps
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> %{{.*}},<4 x i32><i32 2, i32 6, i32 3, i32 7>
return|return
name|_mm_unpackhi_ps
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_unpacklo_ps
parameter_list|(
name|__m128
name|A
parameter_list|,
name|__m128
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_unpacklo_ps
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> %{{.*}},<4 x i32><i32 0, i32 4, i32 1, i32 5>
return|return
name|_mm_unpacklo_ps
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_xor_ps
parameter_list|(
name|__m128
name|A
parameter_list|,
name|__m128
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_xor_ps
comment|// CHECK: xor<4 x i32>
return|return
name|_mm_xor_ps
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

end_unit

