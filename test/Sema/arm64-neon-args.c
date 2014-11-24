begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple arm64-apple-darwin -target-feature +neon -fsyntax-only -ffreestanding -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple arm64_be-none-linux-gnu -target-feature +neon -fsyntax-only -ffreestanding -verify %s
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_comment
comment|// rdar://13527900
end_comment

begin_function
name|void
name|vcopy_reject
parameter_list|(
name|float32x4_t
name|vOut0
parameter_list|,
name|float32x4_t
name|vAlpha
parameter_list|,
name|int
name|t
parameter_list|)
block|{
name|vcopyq_laneq_f32
argument_list|(
name|vOut0
argument_list|,
literal|1
argument_list|,
name|vAlpha
argument_list|,
name|t
argument_list|)
expr_stmt|;
comment|// expected-error {{argument to '__builtin_neon_vgetq_lane_f32' must be a constant integer}}
block|}
end_function

begin_comment
comment|// rdar://problem/15256199
end_comment

begin_function
name|float32x4_t
name|test_vmlsq_lane
parameter_list|(
name|float32x4_t
name|accum
parameter_list|,
name|float32x4_t
name|lhs
parameter_list|,
name|float32x2_t
name|rhs
parameter_list|)
block|{
return|return
name|vmlsq_lane_f32
argument_list|(
name|accum
argument_list|,
name|lhs
argument_list|,
name|rhs
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

end_unit

