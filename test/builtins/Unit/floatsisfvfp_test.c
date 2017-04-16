begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_builtins %s %librt -o %t&& %run %t
end_comment

begin_comment
comment|//===-- floatsisfvfp_test.c - Test __floatsisfvfp -------------------------===//
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
comment|// This file tests __floatsisfvfp for the compiler_rt library.
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
file|"int_lib.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_function_decl
specifier|extern
name|COMPILER_RT_ABI
name|float
name|__floatsisfvfp
parameter_list|(
name|int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|__arm__
operator|&&
name|__VFP_FP__
end_if

begin_function
name|int
name|test__floatsisfvfp
parameter_list|(
name|int
name|a
parameter_list|)
block|{
name|float
name|actual
init|=
name|__floatsisfvfp
argument_list|(
name|a
argument_list|)
decl_stmt|;
name|float
name|expected
init|=
name|a
decl_stmt|;
if|if
condition|(
name|actual
operator|!=
name|expected
condition|)
name|printf
argument_list|(
literal|"error in test__floatsisfvfp(%d) = %f, expected %f\n"
argument_list|,
name|a
argument_list|,
name|actual
argument_list|,
name|expected
argument_list|)
expr_stmt|;
return|return
name|actual
operator|!=
name|expected
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|int
name|main
parameter_list|()
block|{
if|#
directive|if
name|__arm__
operator|&&
name|__VFP_FP__
if|if
condition|(
name|test__floatsisfvfp
argument_list|(
literal|0
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__floatsisfvfp
argument_list|(
literal|1
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__floatsisfvfp
argument_list|(
operator|-
literal|1
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__floatsisfvfp
argument_list|(
literal|0x7FFFFFFF
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__floatsisfvfp
argument_list|(
literal|0x80000000
argument_list|)
condition|)
return|return
literal|1
return|;
else|#
directive|else
name|printf
argument_list|(
literal|"skipped\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
literal|0
return|;
block|}
end_function

end_unit

