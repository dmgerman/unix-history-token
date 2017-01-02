begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ffreestanding %s -triple=x86_64-apple-darwin -target-feature +sse3 -emit-llvm -o - -Wall -Werror | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<x86intrin.h>
end_include

begin_comment
comment|// NOTE: This should match the tests in llvm/test/CodeGen/X86/sse3-intrinsics-fast-isel.ll
end_comment

begin_function
name|__m128d
name|test_mm_addsub_pd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_addsub_pd
comment|// CHECK: call<2 x double> @llvm.x86.sse3.addsub.pd(<2 x double> %{{.*}},<2 x double> %{{.*}})
return|return
name|_mm_addsub_pd
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
name|test_mm_addsub_ps
parameter_list|(
name|__m128
name|A
parameter_list|,
name|__m128
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_addsub_ps
comment|// CHECK: call<4 x float> @llvm.x86.sse3.addsub.ps(<4 x float> %{{.*}},<4 x float> %{{.*}})
return|return
name|_mm_addsub_ps
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_hadd_pd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_hadd_pd
comment|// CHECK: call<2 x double> @llvm.x86.sse3.hadd.pd(<2 x double> %{{.*}},<2 x double> %{{.*}})
return|return
name|_mm_hadd_pd
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
name|test_mm_hadd_ps
parameter_list|(
name|__m128
name|A
parameter_list|,
name|__m128
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_hadd_ps
comment|// CHECK: call<4 x float> @llvm.x86.sse3.hadd.ps(<4 x float> %{{.*}},<4 x float> %{{.*}})
return|return
name|_mm_hadd_ps
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_hsub_pd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_hsub_pd
comment|// CHECK: call<2 x double> @llvm.x86.sse3.hsub.pd(<2 x double> %{{.*}},<2 x double> %{{.*}})
return|return
name|_mm_hsub_pd
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
name|test_mm_hsub_ps
parameter_list|(
name|__m128
name|A
parameter_list|,
name|__m128
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_hsub_ps
comment|// CHECK: call<4 x float> @llvm.x86.sse3.hsub.ps(<4 x float> %{{.*}},<4 x float> %{{.*}})
return|return
name|_mm_hsub_ps
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_lddqu_si128
parameter_list|(
name|__m128i
specifier|const
modifier|*
name|P
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_lddqu_si128
comment|// CHECK: call<16 x i8> @llvm.x86.sse3.ldu.dq(i8* %{{.*}})
return|return
name|_mm_lddqu_si128
argument_list|(
name|P
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_loaddup_pd
parameter_list|(
name|double
specifier|const
modifier|*
name|P
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_loaddup_pd
comment|// CHECK: load double*
comment|// CHECK: insertelement<2 x double> undef, double %{{.*}}, i32 0
comment|// CHECK: insertelement<2 x double> %{{.*}}, double %{{.*}}, i32 1
return|return
name|_mm_loaddup_pd
argument_list|(
name|P
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_movedup_pd
parameter_list|(
name|__m128d
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_movedup_pd
comment|// CHECK: shufflevector<2 x double> %{{.*}},<2 x double> %{{.*}},<2 x i32> zeroinitializer
return|return
name|_mm_movedup_pd
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_movehdup_ps
parameter_list|(
name|__m128
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_movehdup_ps
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> %{{.*}},<4 x i32><i32 1, i32 1, i32 3, i32 3>
return|return
name|_mm_movehdup_ps
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_moveldup_ps
parameter_list|(
name|__m128
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_moveldup_ps
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> %{{.*}},<4 x i32><i32 0, i32 0, i32 2, i32 2>
return|return
name|_mm_moveldup_ps
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

end_unit

