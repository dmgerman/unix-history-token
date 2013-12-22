begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -O3 -triple=x86_64-unknown-unknown -target-feature +3dnow -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// Don't include mm_malloc.h, it's system specific.
end_comment

begin_define
define|#
directive|define
name|__MM_MALLOC_H
end_define

begin_include
include|#
directive|include
file|<x86intrin.h>
end_include

begin_function
name|__m64
name|test_m_pavgusb
parameter_list|(
name|__m64
name|m1
parameter_list|,
name|__m64
name|m2
parameter_list|)
block|{
comment|// CHECK-LABEL: define i64 @test_m_pavgusb
comment|// CHECK: @llvm.x86.3dnow.pavgusb
return|return
name|_m_pavgusb
argument_list|(
name|m1
argument_list|,
name|m2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_m_pf2id
parameter_list|(
name|__m64
name|m
parameter_list|)
block|{
comment|// CHECK-LABEL: define i64 @test_m_pf2id
comment|// CHECK: @llvm.x86.3dnow.pf2id
return|return
name|_m_pf2id
argument_list|(
name|m
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_m_pfacc
parameter_list|(
name|__m64
name|m1
parameter_list|,
name|__m64
name|m2
parameter_list|)
block|{
comment|// CHECK-LABEL: define i64 @test_m_pfacc
comment|// CHECK: @llvm.x86.3dnow.pfacc
return|return
name|_m_pfacc
argument_list|(
name|m1
argument_list|,
name|m2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_m_pfadd
parameter_list|(
name|__m64
name|m1
parameter_list|,
name|__m64
name|m2
parameter_list|)
block|{
comment|// CHECK-LABEL: define i64 @test_m_pfadd
comment|// CHECK: @llvm.x86.3dnow.pfadd
return|return
name|_m_pfadd
argument_list|(
name|m1
argument_list|,
name|m2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_m_pfcmpeq
parameter_list|(
name|__m64
name|m1
parameter_list|,
name|__m64
name|m2
parameter_list|)
block|{
comment|// CHECK-LABEL: define i64 @test_m_pfcmpeq
comment|// CHECK: @llvm.x86.3dnow.pfcmpeq
return|return
name|_m_pfcmpeq
argument_list|(
name|m1
argument_list|,
name|m2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_m_pfcmpge
parameter_list|(
name|__m64
name|m1
parameter_list|,
name|__m64
name|m2
parameter_list|)
block|{
comment|// CHECK-LABEL: define i64 @test_m_pfcmpge
comment|// CHECK: @llvm.x86.3dnow.pfcmpge
return|return
name|_m_pfcmpge
argument_list|(
name|m1
argument_list|,
name|m2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_m_pfcmpgt
parameter_list|(
name|__m64
name|m1
parameter_list|,
name|__m64
name|m2
parameter_list|)
block|{
comment|// CHECK-LABEL: define i64 @test_m_pfcmpgt
comment|// CHECK: @llvm.x86.3dnow.pfcmpgt
return|return
name|_m_pfcmpgt
argument_list|(
name|m1
argument_list|,
name|m2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_m_pfmax
parameter_list|(
name|__m64
name|m1
parameter_list|,
name|__m64
name|m2
parameter_list|)
block|{
comment|// CHECK-LABEL: define i64 @test_m_pfmax
comment|// CHECK: @llvm.x86.3dnow.pfmax
return|return
name|_m_pfmax
argument_list|(
name|m1
argument_list|,
name|m2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_m_pfmin
parameter_list|(
name|__m64
name|m1
parameter_list|,
name|__m64
name|m2
parameter_list|)
block|{
comment|// CHECK-LABEL: define i64 @test_m_pfmin
comment|// CHECK: @llvm.x86.3dnow.pfmin
return|return
name|_m_pfmin
argument_list|(
name|m1
argument_list|,
name|m2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_m_pfmul
parameter_list|(
name|__m64
name|m1
parameter_list|,
name|__m64
name|m2
parameter_list|)
block|{
comment|// CHECK-LABEL: define i64 @test_m_pfmul
comment|// CHECK: @llvm.x86.3dnow.pfmul
return|return
name|_m_pfmul
argument_list|(
name|m1
argument_list|,
name|m2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_m_pfrcp
parameter_list|(
name|__m64
name|m
parameter_list|)
block|{
comment|// CHECK-LABEL: define i64 @test_m_pfrcp
comment|// CHECK: @llvm.x86.3dnow.pfrcp
return|return
name|_m_pfrcp
argument_list|(
name|m
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_m_pfrcpit1
parameter_list|(
name|__m64
name|m1
parameter_list|,
name|__m64
name|m2
parameter_list|)
block|{
comment|// CHECK-LABEL: define i64 @test_m_pfrcpit1
comment|// CHECK: @llvm.x86.3dnow.pfrcpit1
return|return
name|_m_pfrcpit1
argument_list|(
name|m1
argument_list|,
name|m2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_m_pfrcpit2
parameter_list|(
name|__m64
name|m1
parameter_list|,
name|__m64
name|m2
parameter_list|)
block|{
comment|// CHECK-LABEL: define i64 @test_m_pfrcpit2
comment|// CHECK: @llvm.x86.3dnow.pfrcpit2
return|return
name|_m_pfrcpit2
argument_list|(
name|m1
argument_list|,
name|m2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_m_pfrsqrt
parameter_list|(
name|__m64
name|m
parameter_list|)
block|{
comment|// CHECK-LABEL: define i64 @test_m_pfrsqrt
comment|// CHECK: @llvm.x86.3dnow.pfrsqrt
return|return
name|_m_pfrsqrt
argument_list|(
name|m
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_m_pfrsqrtit1
parameter_list|(
name|__m64
name|m1
parameter_list|,
name|__m64
name|m2
parameter_list|)
block|{
comment|// CHECK-LABEL: define i64 @test_m_pfrsqrtit1
comment|// CHECK: @llvm.x86.3dnow.pfrsqit1
return|return
name|_m_pfrsqrtit1
argument_list|(
name|m1
argument_list|,
name|m2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_m_pfsub
parameter_list|(
name|__m64
name|m1
parameter_list|,
name|__m64
name|m2
parameter_list|)
block|{
comment|// CHECK-LABEL: define i64 @test_m_pfsub
comment|// CHECK: @llvm.x86.3dnow.pfsub
return|return
name|_m_pfsub
argument_list|(
name|m1
argument_list|,
name|m2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_m_pfsubr
parameter_list|(
name|__m64
name|m1
parameter_list|,
name|__m64
name|m2
parameter_list|)
block|{
comment|// CHECK-LABEL: define i64 @test_m_pfsubr
comment|// CHECK: @llvm.x86.3dnow.pfsubr
return|return
name|_m_pfsubr
argument_list|(
name|m1
argument_list|,
name|m2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_m_pi2fd
parameter_list|(
name|__m64
name|m
parameter_list|)
block|{
comment|// CHECK-LABEL: define i64 @test_m_pi2fd
comment|// CHECK: @llvm.x86.3dnow.pi2fd
return|return
name|_m_pi2fd
argument_list|(
name|m
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_m_pmulhrw
parameter_list|(
name|__m64
name|m1
parameter_list|,
name|__m64
name|m2
parameter_list|)
block|{
comment|// CHECK-LABEL: define i64 @test_m_pmulhrw
comment|// CHECK: @llvm.x86.3dnow.pmulhrw
return|return
name|_m_pmulhrw
argument_list|(
name|m1
argument_list|,
name|m2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_m_pf2iw
parameter_list|(
name|__m64
name|m
parameter_list|)
block|{
comment|// CHECK-LABEL: define i64 @test_m_pf2iw
comment|// CHECK: @llvm.x86.3dnowa.pf2iw
return|return
name|_m_pf2iw
argument_list|(
name|m
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_m_pfnacc
parameter_list|(
name|__m64
name|m1
parameter_list|,
name|__m64
name|m2
parameter_list|)
block|{
comment|// CHECK-LABEL: define i64 @test_m_pfnacc
comment|// CHECK: @llvm.x86.3dnowa.pfnacc
return|return
name|_m_pfnacc
argument_list|(
name|m1
argument_list|,
name|m2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_m_pfpnacc
parameter_list|(
name|__m64
name|m1
parameter_list|,
name|__m64
name|m2
parameter_list|)
block|{
comment|// CHECK-LABEL: define i64 @test_m_pfpnacc
comment|// CHECK: @llvm.x86.3dnowa.pfpnacc
return|return
name|_m_pfpnacc
argument_list|(
name|m1
argument_list|,
name|m2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_m_pi2fw
parameter_list|(
name|__m64
name|m
parameter_list|)
block|{
comment|// CHECK-LABEL: define i64 @test_m_pi2fw
comment|// CHECK: @llvm.x86.3dnowa.pi2fw
return|return
name|_m_pi2fw
argument_list|(
name|m
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_m_pswapdsf
parameter_list|(
name|__m64
name|m
parameter_list|)
block|{
comment|// CHECK-LABEL: define i64 @test_m_pswapdsf
comment|// CHECK: @llvm.x86.3dnowa.pswapd
return|return
name|_m_pswapdsf
argument_list|(
name|m
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_m_pswapdsi
parameter_list|(
name|__m64
name|m
parameter_list|)
block|{
comment|// CHECK-LABEL: define i64 @test_m_pswapdsi
comment|// CHECK: @llvm.x86.3dnowa.pswapd
return|return
name|_m_pswapdsi
argument_list|(
name|m
argument_list|)
return|;
block|}
end_function

end_unit

