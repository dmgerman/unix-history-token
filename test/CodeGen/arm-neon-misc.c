begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: arm-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-apple-darwin \
end_comment

begin_comment
comment|// RUN:   -target-abi apcs-gnu \
end_comment

begin_comment
comment|// RUN:   -target-cpu cortex-a8 \
end_comment

begin_comment
comment|// RUN:   -mfloat-abi soft \
end_comment

begin_comment
comment|// RUN:   -target-feature +soft-float-abi \
end_comment

begin_comment
comment|// RUN:   -ffreestanding \
end_comment

begin_comment
comment|// RUN:   -emit-llvm -w -o - %s | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_comment
comment|// Radar 11998303: Avoid using i64 types for vld1q_lane and vst1q_lane Neon
end_comment

begin_comment
comment|// intrinsics with<2 x i64> vectors to avoid poor code for i64 in the backend.
end_comment

begin_function
name|void
name|t1
parameter_list|(
name|uint64_t
modifier|*
name|src
parameter_list|,
name|uint8_t
modifier|*
name|dst
parameter_list|)
block|{
comment|// CHECK: @t1
name|uint64x2_t
name|q
init|=
name|vld1q_u64
argument_list|(
name|src
argument_list|)
decl_stmt|;
comment|// CHECK: call<2 x i64> @llvm.arm.neon.vld1.v2i64
name|vst1q_lane_u64
argument_list|(
name|dst
argument_list|,
name|q
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: bitcast<16 x i8> %{{.*}} to<2 x i64>
comment|// CHECK: shufflevector<2 x i64>
comment|// CHECK: call void @llvm.arm.neon.vst1.v1i64
block|}
end_function

begin_function
name|void
name|t2
parameter_list|(
name|uint64_t
modifier|*
name|src1
parameter_list|,
name|uint8_t
modifier|*
name|src2
parameter_list|,
name|uint64x2_t
modifier|*
name|dst
parameter_list|)
block|{
comment|// CHECK: @t2
name|uint64x2_t
name|q
init|=
name|vld1q_u64
argument_list|(
name|src1
argument_list|)
decl_stmt|;
comment|// CHECK: call<2 x i64> @llvm.arm.neon.vld1.v2i64
name|q
operator|=
name|vld1q_lane_u64
argument_list|(
name|src2
argument_list|,
name|q
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: shufflevector<2 x i64>
comment|// CHECK: call<1 x i64> @llvm.arm.neon.vld1.v1i64
comment|// CHECK: shufflevector<1 x i64>
operator|*
name|dst
operator|=
name|q
expr_stmt|;
comment|// CHECK: store<2 x i64>
block|}
end_function

end_unit

