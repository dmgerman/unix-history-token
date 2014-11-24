begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -O1 -triple arm64-apple-ios7 -target-feature +neon -ffreestanding -S -o - -emit-llvm %s | FileCheck %s
end_comment

begin_comment
comment|// Test ARM64 SIMD negate and saturating negate intrinsics
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_function
name|int64x2_t
name|test_vnegq_s64
parameter_list|(
name|int64x2_t
name|a1
parameter_list|)
block|{
comment|// CHECK: test_vnegq_s64
return|return
name|vnegq_s64
argument_list|(
name|a1
argument_list|)
return|;
comment|// CHECK: sub<2 x i64> zeroinitializer, %a1
comment|// CHECK-NEXT: ret
block|}
end_function

begin_function
name|int64x2_t
name|test_vqnegq_s64
parameter_list|(
name|int64x2_t
name|a1
parameter_list|)
block|{
comment|// CHECK: test_vqnegq_s64
return|return
name|vqnegq_s64
argument_list|(
name|a1
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.sqneg.v2i64
comment|// CHECK-NEXT: ret
block|}
end_function

end_unit

