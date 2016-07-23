begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-none-eabi %s -target-feature +neon -target-feature -fp16 -fsyntax-only -verify
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_function
name|float16x4_t
name|test_vcvt_f16_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vcvt_f16_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// expected-warning{{implicit declaration of function 'vcvt_f16_f32'}}  expected-error{{returning 'int' from a function with incompatible result type 'float16x4_t'}}
block|}
end_function

begin_function
name|float32x4_t
name|test_vcvt_f32_f16
parameter_list|(
name|float16x4_t
name|a
parameter_list|)
block|{
return|return
name|vcvt_f32_f16
argument_list|(
name|a
argument_list|)
return|;
comment|// expected-warning{{implicit declaration of function 'vcvt_f32_f16'}} expected-error{{returning 'int' from a function with incompatible result type 'float32x4_t'}}
block|}
end_function

end_unit

