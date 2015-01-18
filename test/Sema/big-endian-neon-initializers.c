begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -triple aarch64_be -target-feature +neon -verify -fsyntax-only -ffreestanding
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -triple armebv7 -target-cpu cortex-a8 -verify -fsyntax-only -ffreestanding
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_decl_stmt
name|int32x4_t
name|x
init|=
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{vector initializers are not compatible with NEON intrinsics}} expected-note{{consider using vld1q_s32() to initialize a vector from memory, or vcombine_s32(vcreate_s32(), vcreate_s32()) to initialize from integer constants}}
end_comment

begin_decl_stmt
name|int16x4_t
name|y
init|=
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{vector initializers are not compatible with NEON intrinsics}} expected-note{{consider using vld1_s16() to initialize a vector from memory, or vcreate_s16() to initialize from an integer constant}}
end_comment

begin_decl_stmt
name|int64x2_t
name|z
init|=
block|{
literal|1
block|,
literal|2
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{vector initializers are not compatible with NEON intrinsics}} expected-note{{consider using vld1q_s64() to initialize a vector from memory, or vcombine_s64(vcreate_s64(), vcreate_s64()) to initialize from integer constants}}
end_comment

begin_decl_stmt
name|float32x2_t
name|b
init|=
block|{
literal|1
block|,
literal|2
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{vector initializers are not compatible with NEON intrinsics}} expected-note{{consider using vld1_f32() to initialize a vector from memory, or vcreate_f32() to initialize from an integer constant}}
end_comment

begin_comment
comment|// No warning expected here.
end_comment

begin_typedef
typedef|typedef
name|int
name|v4si
name|__attribute__
typedef|((
name|vector_size
typedef|(16)));
end_typedef

begin_decl_stmt
name|v4si
name|c
init|=
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|}
decl_stmt|;
end_decl_stmt

end_unit

