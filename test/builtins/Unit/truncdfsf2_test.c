begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_builtins %s %librt -o %t&& %run %t
end_comment

begin_comment
comment|//===--------------- truncdfsf2_test.c - Test __truncdfsf2 ----------------===//
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
comment|// This file tests __truncdfsf2 for the compiler_rt library.
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
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"fp_test.h"
end_include

begin_function_decl
name|float
name|__truncdfsf2
parameter_list|(
name|double
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|test__truncdfsf2
parameter_list|(
name|double
name|a
parameter_list|)
block|{
name|float
name|actual
init|=
name|__truncdfsf2
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
block|{
name|printf
argument_list|(
literal|"error in test__truncdfsf2(%lf) = %f, "
literal|"expected %f\n"
argument_list|,
name|a
argument_list|,
name|actual
argument_list|,
name|expected
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
return|return
literal|0
return|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|()
block|{
if|if
condition|(
name|test__truncdfsf2
argument_list|(
literal|340282366920938463463374607431768211456.0
argument_list|)
condition|)
return|return
literal|1
return|;
return|return
literal|0
return|;
block|}
end_function

end_unit

