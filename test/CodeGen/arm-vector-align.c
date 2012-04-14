begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
comment|// Radar 9311427: Check that alignment specifier is used in Neon load/store
end_comment

begin_comment
comment|// intrinsics.
end_comment

begin_typedef
typedef|typedef
name|float
name|AlignedAddr
name|__attribute__
typedef|((
name|aligned
typedef|(16)));
end_typedef

begin_function
name|void
name|t1
parameter_list|(
name|AlignedAddr
modifier|*
name|addr1
parameter_list|,
name|AlignedAddr
modifier|*
name|addr2
parameter_list|)
block|{
comment|// CHECK: @t1
comment|// CHECK: call<4 x float> @llvm.arm.neon.vld1.v4f32(i8* %{{.*}}, i32 16)
name|float32x4_t
name|a
init|=
name|vld1q_f32
argument_list|(
name|addr1
argument_list|)
decl_stmt|;
comment|// CHECK: call void @llvm.arm.neon.vst1.v4f32(i8* %{{.*}},<4 x float> %{{.*}}, i32 16)
name|vst1q_f32
argument_list|(
name|addr2
argument_list|,
name|a
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Radar 10538555: Make sure unaligned load/stores do not gain alignment.
end_comment

begin_function
name|void
name|t2
parameter_list|(
name|char
modifier|*
name|addr
parameter_list|)
block|{
comment|// CHECK: @t2
comment|// CHECK: load i32* %{{.*}}, align 1
name|int32x2_t
name|vec
init|=
name|vld1_dup_s32
argument_list|(
name|addr
argument_list|)
decl_stmt|;
comment|// CHECK: store i32 %{{.*}}, i32* {{.*}}, align 1
name|vst1_lane_s32
argument_list|(
name|addr
argument_list|,
name|vec
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

