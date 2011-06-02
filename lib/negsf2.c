begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- lib/negsf2.c - single-precision negation ------------------*- C -*-===//
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
comment|// This file implements single-precision soft-float negation.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_include
include|#
directive|include
file|"abi.h"
end_include

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

begin_expr_stmt
name|ARM_EABI_FNALIAS
argument_list|(
name|fneg
argument_list|,
name|negsf2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|COMPILER_RT_ABI
name|fp_t
name|__negsf2
parameter_list|(
name|fp_t
name|a
parameter_list|)
block|{
return|return
name|fromRep
argument_list|(
name|toRep
argument_list|(
name|a
argument_list|)
operator|^
name|signBit
argument_list|)
return|;
block|}
end_function

end_unit

