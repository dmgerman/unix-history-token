begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- lib/adddf3.c - Double-precision subtraction ---------------*- C -*-===//
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
comment|// This file implements double-precision soft-float subtraction with the
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
name|DOUBLE_PRECISION
end_define

begin_include
include|#
directive|include
file|"fp_lib.h"
end_include

begin_function_decl
name|fp_t
name|COMPILER_RT_ABI
name|__adddf3
parameter_list|(
name|fp_t
name|a
parameter_list|,
name|fp_t
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|ARM_EABI_FNALIAS
argument_list|(
argument|dsub
argument_list|,
argument|subdf3
argument_list|)
end_macro

begin_comment
comment|// Subtraction; flip the sign bit of b and add.
end_comment

begin_function
name|COMPILER_RT_ABI
name|fp_t
name|__subdf3
parameter_list|(
name|fp_t
name|a
parameter_list|,
name|fp_t
name|b
parameter_list|)
block|{
return|return
name|__adddf3
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

begin_comment
comment|/* FIXME: rsub for ARM EABI */
end_comment

end_unit

