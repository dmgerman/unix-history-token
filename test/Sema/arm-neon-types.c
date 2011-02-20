begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-apple-darwin10 -target-cpu cortex-a8 -fsyntax-only -Wvector-conversions -ffreestanding -verify %s
end_comment

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
literal|0
argument_list|)
return|;
comment|// expected-warning {{incompatible vector types}}
block|}
end_function

end_unit

