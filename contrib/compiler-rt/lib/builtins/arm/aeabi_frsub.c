begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- lib/arm/aeabi_frsub.c - Single-precision subtraction --------------===//
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

begin_define
define|#
directive|define
name|SINGLE_PRECISION
end_define

begin_include
include|#
directive|include
file|"../fp_lib.h"
end_include

begin_function_decl
name|COMPILER_RT_ABI
name|fp_t
name|__aeabi_fsub
parameter_list|(
name|fp_t
parameter_list|,
name|fp_t
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|COMPILER_RT_ABI
name|fp_t
name|__aeabi_frsub
parameter_list|(
name|fp_t
name|a
parameter_list|,
name|fp_t
name|b
parameter_list|)
block|{
return|return
name|__aeabi_fsub
argument_list|(
name|b
argument_list|,
name|a
argument_list|)
return|;
block|}
end_function

end_unit

