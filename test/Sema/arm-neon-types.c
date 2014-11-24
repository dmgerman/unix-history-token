begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-apple-darwin10 -target-cpu cortex-a8 -fsyntax-only -Wvector-conversion -ffreestanding -verify %s
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INCLUDE
end_ifndef

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_comment
comment|// Radar 8228022: Should not report incompatible vector types.
end_comment

begin_function
name|int32x2_t
name|test
parameter_list|(
name|int32x2_t
name|x
parameter_list|)
block|{
return|return
name|vshr_n_s32
argument_list|(
name|x
argument_list|,
literal|31
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// ...but should warn when the types really do not match.
end_comment

begin_function
name|float32x2_t
name|test2
parameter_list|(
name|uint32x2_t
name|x
parameter_list|)
block|{
return|return
name|vcvt_n_f32_s32
argument_list|(
name|x
argument_list|,
literal|9
argument_list|)
return|;
comment|// expected-warning {{incompatible vector types}}
block|}
end_function

begin_comment
comment|// Check immediate range for vcvt_n intrinsics is 1 to 32.  Radar 9558930.
end_comment

begin_function
name|float32x2_t
name|test3
parameter_list|(
name|uint32x2_t
name|x
parameter_list|)
block|{
comment|// FIXME: The "incompatible result type" error is due to pr10112 and should be
comment|// removed when that is fixed.
return|return
name|vcvt_n_f32_u32
argument_list|(
name|x
argument_list|,
literal|0
argument_list|)
return|;
comment|// expected-error {{argument should be a value from 1 to 32}}
block|}
end_function

begin_typedef
typedef|typedef
name|signed
name|int
name|vSInt32
name|__attribute__
typedef|((
name|__vector_size__
typedef|(16)));
end_typedef

begin_function
name|int32x4_t
name|test4
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|vSInt32
name|b
parameter_list|)
block|{
name|a
operator|+=
name|b
expr_stmt|;
name|b
operator|+=
name|a
expr_stmt|;
return|return
name|b
operator|+=
name|a
return|;
block|}
end_function

begin_comment
comment|// Warn for incompatible pointer types used with vld/vst intrinsics.
end_comment

begin_function
name|int16x8_t
name|test5
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
block|{
return|return
name|vld1q_s16
argument_list|(
name|p
argument_list|)
return|;
comment|// expected-warning {{incompatible pointer types}}
block|}
end_function

begin_function
name|void
name|test6
parameter_list|(
name|float
modifier|*
name|p
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
return|return
name|vst1_s32
argument_list|(
name|p
argument_list|,
name|v
argument_list|)
return|;
comment|// expected-warning {{incompatible pointer types}}
block|}
end_function

begin_define
define|#
directive|define
name|INCLUDE
end_define

begin_include
include|#
directive|include
file|"arm-neon-types.c"
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|// Make sure we don't get a warning about using a static function in an
end_comment

begin_comment
comment|// extern inline function from a header.
end_comment

begin_function
specifier|extern
specifier|inline
name|uint8x8_t
name|test7
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
return|return
name|vadd_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

