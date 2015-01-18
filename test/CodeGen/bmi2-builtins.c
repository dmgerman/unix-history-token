begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -O3 -triple=x86_64-apple-darwin -target-feature +bmi2 -emit-llvm -o - | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -O3 -triple=i386-apple-darwin -target-feature +bmi2 -emit-llvm -o - | FileCheck %s --check-prefix=B32
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
name|unsigned
name|int
name|test_bzhi_u32
parameter_list|(
name|unsigned
name|int
name|__X
parameter_list|,
name|unsigned
name|int
name|__Y
parameter_list|)
block|{
comment|// CHECK: @llvm.x86.bmi.bzhi.32
return|return
name|_bzhi_u32
argument_list|(
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|int
name|test_pdep_u32
parameter_list|(
name|unsigned
name|int
name|__X
parameter_list|,
name|unsigned
name|int
name|__Y
parameter_list|)
block|{
comment|// CHECK: @llvm.x86.bmi.pdep.32
return|return
name|_pdep_u32
argument_list|(
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|int
name|test_pext_u32
parameter_list|(
name|unsigned
name|int
name|__X
parameter_list|,
name|unsigned
name|int
name|__Y
parameter_list|)
block|{
comment|// CHECK: @llvm.x86.bmi.pext.32
return|return
name|_pext_u32
argument_list|(
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|int
name|test_mulx_u32
parameter_list|(
name|unsigned
name|int
name|__X
parameter_list|,
name|unsigned
name|int
name|__Y
parameter_list|,
name|unsigned
name|int
modifier|*
name|__P
parameter_list|)
block|{
comment|// CHECK: @test_mulx_u32
comment|// CHECK-NOT: mul nuw i64
comment|// B32: @test_mulx_u32
comment|// B32: mul nuw i64
return|return
name|_mulx_u32
argument_list|(
name|__X
argument_list|,
name|__Y
argument_list|,
name|__P
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|long
name|long
name|test_bzhi_u64
parameter_list|(
name|unsigned
name|long
name|long
name|__X
parameter_list|,
name|unsigned
name|long
name|long
name|__Y
parameter_list|)
block|{
comment|// CHECK: @llvm.x86.bmi.bzhi.64
return|return
name|_bzhi_u64
argument_list|(
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|long
name|long
name|test_pdep_u64
parameter_list|(
name|unsigned
name|long
name|long
name|__X
parameter_list|,
name|unsigned
name|long
name|long
name|__Y
parameter_list|)
block|{
comment|// CHECK: @llvm.x86.bmi.pdep.64
return|return
name|_pdep_u64
argument_list|(
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|long
name|long
name|test_pext_u64
parameter_list|(
name|unsigned
name|long
name|long
name|__X
parameter_list|,
name|unsigned
name|long
name|long
name|__Y
parameter_list|)
block|{
comment|// CHECK: @llvm.x86.bmi.pext.64
return|return
name|_pext_u64
argument_list|(
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|unsigned
name|long
name|long
name|test_mulx_u64
parameter_list|(
name|unsigned
name|long
name|long
name|__X
parameter_list|,
name|unsigned
name|long
name|long
name|__Y
parameter_list|,
name|unsigned
name|long
name|long
modifier|*
name|__P
parameter_list|)
block|{
comment|// CHECK: @test_mulx_u64
comment|// CHECK: mul nuw i128
return|return
name|_mulx_u64
argument_list|(
name|__X
argument_list|,
name|__Y
argument_list|,
name|__P
argument_list|)
return|;
block|}
end_function

end_unit

