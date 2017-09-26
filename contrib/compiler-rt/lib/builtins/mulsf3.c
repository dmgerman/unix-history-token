begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- lib/mulsf3.c - Single-precision multiplication ------------*- C -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is dual licensed under the MIT and the University of Illinois Open
end_comment

begin_comment
comment|// Source Licenses. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file implements single-precision soft-float multiplication
end_comment

begin_comment
comment|// with the IEEE-754 default rounding (to nearest, ties to even).
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_define
define|#
directive|define
name|SINGLE_PRECISION
end_define

begin_include
include|#
directive|include
file|"fp_mul_impl.inc"
end_include

begin_function
name|COMPILER_RT_ABI
name|fp_t
name|__mulsf3
parameter_list|(
name|fp_t
name|a
parameter_list|,
name|fp_t
name|b
parameter_list|)
block|{
return|return
name|__mulXf3__
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ARM_EABI__
argument_list|)
end_if

begin_function
name|AEABI_RTABI
name|fp_t
name|__aeabi_fmul
parameter_list|(
name|fp_t
name|a
parameter_list|,
name|fp_t
name|b
parameter_list|)
block|{
return|return
name|__mulsf3
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

