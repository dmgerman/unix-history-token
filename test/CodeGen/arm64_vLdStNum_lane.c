begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -O1 -triple arm64-apple-ios7 -target-feature +neon -ffreestanding -S -o - -emit-llvm %s | FileCheck %s
end_comment

begin_comment
comment|// Test ARM64 SIMD load and stores of an N-element structure  intrinsics
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_function
name|int64x2x2_t
name|test_vld2q_lane_s64
parameter_list|(
specifier|const
name|void
modifier|*
name|a1
parameter_list|,
name|int64x2x2_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vld2q_lane_s64
return|return
name|vld2q_lane_s64
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.ld2lane.v2i64.p0i8
block|}
end_function

begin_function
name|uint64x2x2_t
name|test_vld2q_lane_u64
parameter_list|(
specifier|const
name|void
modifier|*
name|a1
parameter_list|,
name|uint64x2x2_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vld2q_lane_u64
return|return
name|vld2q_lane_u64
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.ld2lane.v2i64.p0i8
block|}
end_function

begin_function
name|int64x1x2_t
name|test_vld2_lane_s64
parameter_list|(
specifier|const
name|void
modifier|*
name|a1
parameter_list|,
name|int64x1x2_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vld2_lane_s64
return|return
name|vld2_lane_s64
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.ld2lane.v1i64.p0i8
block|}
end_function

begin_function
name|uint64x1x2_t
name|test_vld2_lane_u64
parameter_list|(
specifier|const
name|void
modifier|*
name|a1
parameter_list|,
name|uint64x1x2_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vld2_lane_u64
return|return
name|vld2_lane_u64
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.ld2lane.v1i64.p0i8
block|}
end_function

begin_function
name|poly8x16x2_t
name|test_vld2q_lane_p8
parameter_list|(
specifier|const
name|void
modifier|*
name|a1
parameter_list|,
name|poly8x16x2_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vld2q_lane_p8
return|return
name|vld2q_lane_p8
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: extractvalue {{.*}} 0{{ *$}}
comment|// CHECK: extractvalue {{.*}} 1{{ *$}}
block|}
end_function

begin_function
name|uint8x16x2_t
name|test_vld2q_lane_u8
parameter_list|(
specifier|const
name|void
modifier|*
name|a1
parameter_list|,
name|uint8x16x2_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vld2q_lane_u8
return|return
name|vld2q_lane_u8
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.ld2lane.v16i8.p0i8
block|}
end_function

begin_function
name|int64x2x3_t
name|test_vld3q_lane_s64
parameter_list|(
specifier|const
name|void
modifier|*
name|a1
parameter_list|,
name|int64x2x3_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vld3q_lane_s64
return|return
name|vld3q_lane_s64
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.ld3lane.v2i64.p0i8
block|}
end_function

begin_function
name|uint64x2x3_t
name|test_vld3q_lane_u64
parameter_list|(
specifier|const
name|void
modifier|*
name|a1
parameter_list|,
name|uint64x2x3_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vld3q_lane_u64
return|return
name|vld3q_lane_u64
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.ld3lane.v2i64.p0i8
block|}
end_function

begin_function
name|int64x1x3_t
name|test_vld3_lane_s64
parameter_list|(
specifier|const
name|void
modifier|*
name|a1
parameter_list|,
name|int64x1x3_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vld3_lane_s64
return|return
name|vld3_lane_s64
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.ld3lane.v1i64.p0i8
block|}
end_function

begin_function
name|uint64x1x3_t
name|test_vld3_lane_u64
parameter_list|(
specifier|const
name|void
modifier|*
name|a1
parameter_list|,
name|uint64x1x3_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vld3_lane_u64
return|return
name|vld3_lane_u64
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.ld3lane.v1i64.p0i8
block|}
end_function

begin_function
name|int8x8x3_t
name|test_vld3_lane_s8
parameter_list|(
specifier|const
name|void
modifier|*
name|a1
parameter_list|,
name|int8x8x3_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vld3_lane_s8
return|return
name|vld3_lane_s8
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.ld3lane.v8i8.p0i8
block|}
end_function

begin_function
name|poly8x16x3_t
name|test_vld3q_lane_p8
parameter_list|(
specifier|const
name|void
modifier|*
name|a1
parameter_list|,
name|poly8x16x3_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vld3q_lane_p8
return|return
name|vld3q_lane_p8
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.ld3lane.v16i8.p0i8
block|}
end_function

begin_function
name|uint8x16x3_t
name|test_vld3q_lane_u8
parameter_list|(
specifier|const
name|void
modifier|*
name|a1
parameter_list|,
name|uint8x16x3_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vld3q_lane_u8
return|return
name|vld3q_lane_u8
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.ld3lane.v16i8.p0i8
block|}
end_function

begin_function
name|int64x2x4_t
name|test_vld4q_lane_s64
parameter_list|(
specifier|const
name|void
modifier|*
name|a1
parameter_list|,
name|int64x2x4_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vld4q_lane_s64
return|return
name|vld4q_lane_s64
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.ld4lane.v2i64.p0i8
block|}
end_function

begin_function
name|uint64x2x4_t
name|test_vld4q_lane_u64
parameter_list|(
specifier|const
name|void
modifier|*
name|a1
parameter_list|,
name|uint64x2x4_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vld4q_lane_u64
return|return
name|vld4q_lane_u64
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.ld4lane.v2i64.p0i8
block|}
end_function

begin_function
name|int64x1x4_t
name|test_vld4_lane_s64
parameter_list|(
specifier|const
name|void
modifier|*
name|a1
parameter_list|,
name|int64x1x4_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vld4_lane_s64
return|return
name|vld4_lane_s64
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.ld4lane.v1i64.p0i8
block|}
end_function

begin_function
name|uint64x1x4_t
name|test_vld4_lane_u64
parameter_list|(
specifier|const
name|void
modifier|*
name|a1
parameter_list|,
name|uint64x1x4_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vld4_lane_u64
return|return
name|vld4_lane_u64
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.ld4lane.v1i64.p0i8
block|}
end_function

begin_function
name|int8x8x4_t
name|test_vld4_lane_s8
parameter_list|(
specifier|const
name|void
modifier|*
name|a1
parameter_list|,
name|int8x8x4_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vld4_lane_s8
return|return
name|vld4_lane_s8
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.ld4lane.v8i8.p0i8
block|}
end_function

begin_function
name|uint8x8x4_t
name|test_vld4_lane_u8
parameter_list|(
specifier|const
name|void
modifier|*
name|a1
parameter_list|,
name|uint8x8x4_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vld4_lane_u8
return|return
name|vld4_lane_u8
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.ld4lane.v8i8.p0i8
block|}
end_function

begin_function
name|poly8x16x4_t
name|test_vld4q_lane_p8
parameter_list|(
specifier|const
name|void
modifier|*
name|a1
parameter_list|,
name|poly8x16x4_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vld4q_lane_p8
return|return
name|vld4q_lane_p8
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.ld4lane.v16i8.p0i8
block|}
end_function

begin_function
name|int8x16x4_t
name|test_vld4q_lane_s8
parameter_list|(
specifier|const
name|void
modifier|*
name|a1
parameter_list|,
name|int8x16x4_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vld4q_lane_s8
return|return
name|vld4q_lane_s8
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: extractvalue {{.*}} 0{{ *$}}
comment|// CHECK: extractvalue {{.*}} 1{{ *$}}
comment|// CHECK: extractvalue {{.*}} 2{{ *$}}
comment|// CHECK: extractvalue {{.*}} 3{{ *$}}
block|}
end_function

begin_function
name|uint8x16x4_t
name|test_vld4q_lane_u8
parameter_list|(
specifier|const
name|void
modifier|*
name|a1
parameter_list|,
name|uint8x16x4_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vld4q_lane_u8
return|return
name|vld4q_lane_u8
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.ld4lane.v16i8.p0i8
block|}
end_function

end_unit

