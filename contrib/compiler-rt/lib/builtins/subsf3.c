begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- lib/subsf3.c - Single-precision subtraction ---------------*- C -*-===//
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
comment|// This file implements single-precision soft-float subtraction with the
end_comment

begin_comment
comment|// IEEE-754 default rounding (to nearest, ties to even).
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
file|"fp_lib.h"
end_include

begin_comment
comment|// Subtraction; flip the sign bit of b and add.
end_comment

begin_function
name|COMPILER_RT_ABI
name|fp_t
name|__subsf3
parameter_list|(
name|fp_t
name|a
parameter_list|,
name|fp_t
name|b
parameter_list|)
block|{
return|return
name|__addsf3
argument_list|(
name|a
argument_list|,
name|fromRep
argument_list|(
name|toRep
argument_list|(
name|b
argument_list|)
operator|^
name|signBit
argument_list|)
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
name|__aeabi_fsub
parameter_list|(
name|fp_t
name|a
parameter_list|,
name|fp_t
name|b
parameter_list|)
block|{
return|return
name|__subsf3
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

