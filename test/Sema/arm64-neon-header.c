begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple arm64-apple-darwin -target-feature +neon -Wvector-conversion -fsyntax-only -ffreestanding -verify %s
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_function
name|int16x8_t
name|foo
parameter_list|(
name|int8x8_t
name|p0
parameter_list|,
name|int16x8_t
name|p1
parameter_list|)
block|{
return|return
name|vqmovun_high_s16
argument_list|(
name|p0
argument_list|,
name|p1
argument_list|)
return|;
comment|// expected-warning {{incompatible vector types returning 'uint8x16_t'}}
block|}
end_function

end_unit

