begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -ffreestanding -triple x86_64-apple-macosx10.9.0 -emit-llvm -o - | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<xmmintrin.h>
end_include

begin_comment
comment|// Make sure the last step of _mm_cvtps_pi16 converts<4 x i32> to<4 x i16> by
end_comment

begin_comment
comment|// checking that clang emits PACKSSDW instead of PACKSSWB.
end_comment

begin_comment
comment|// CHECK: define i64 @test_mm_cvtps_pi16
end_comment

begin_comment
comment|// CHECK: call x86_mmx @llvm.x86.mmx.packssdw
end_comment

begin_function
name|__m64
name|test_mm_cvtps_pi16
parameter_list|(
name|__m128
name|a
parameter_list|)
block|{
return|return
name|_mm_cvtps_pi16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

end_unit

