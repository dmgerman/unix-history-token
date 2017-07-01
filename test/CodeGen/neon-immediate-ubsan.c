begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple armv7s-linux-gnu -target-abi apcs-gnu -emit-llvm -o - %s \
end_comment

begin_comment
comment|// RUN:     -target-feature +neon -target-cpu cortex-a8 \
end_comment

begin_comment
comment|// RUN:     -fsanitize=signed-integer-overflow \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK --check-prefix=ARMV7
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple aarch64-unknown-unknown -emit-llvm -o - %s \
end_comment

begin_comment
comment|// RUN:     -target-feature +neon -target-cpu cortex-a53 \
end_comment

begin_comment
comment|// RUN:     -fsanitize=signed-integer-overflow \
end_comment

begin_comment
comment|// RUN:   | FileCheck %s --check-prefix=CHECK --check-prefix=AARCH64
end_comment

begin_comment
comment|// Verify we emit constants for "immediate" builtin arguments.
end_comment

begin_comment
comment|// Emitting a scalar expression can make the immediate be generated as
end_comment

begin_comment
comment|// overflow intrinsics, if the overflow sanitizer is enabled.
end_comment

begin_comment
comment|// PR23517
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_function
name|int32x2_t
name|test_vqrshrn_n_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vqrshrn_n_s64
comment|// CHECK-AARCH64: call<2 x i32> @llvm.aarch64.neon.sqrshrn.v2i32(<2 x i64> {{.*}}, i32 1)
comment|// CHECK-ARMV7: call<2 x i32> @llvm.arm.neon.vqrshiftns.v2i32(<2 x i64> {{.*}},<2 x i64><i64 -1, i64 -1>)
return|return
name|vqrshrn_n_s64
argument_list|(
name|a
argument_list|,
literal|0
operator|+
literal|1
argument_list|)
return|;
block|}
end_function

end_unit

