begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_builtins %s %librt -o %t&& %run %t
end_comment

begin_comment
comment|//===-- udivmodsi4_test.c - Test __udivmodsi4 -----------------------------===//
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
comment|// This file tests __udivmodsi4 for the compiler_rt library.
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

begin_comment
comment|// Returns: a / b
end_comment

begin_function_decl
specifier|extern
name|COMPILER_RT_ABI
name|su_int
name|__udivmodsi4
parameter_list|(
name|su_int
name|a
parameter_list|,
name|su_int
name|b
parameter_list|,
name|su_int
modifier|*
name|rem
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|test__udivmodsi4
parameter_list|(
name|su_int
name|a
parameter_list|,
name|su_int
name|b
parameter_list|,
name|su_int
name|expected_result
parameter_list|,
name|su_int
name|expected_rem
parameter_list|)
block|{
name|su_int
name|rem
decl_stmt|;
name|su_int
name|result
init|=
name|__udivmodsi4
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
operator|&
name|rem
argument_list|)
decl_stmt|;
if|if
condition|(
name|result
operator|!=
name|expected_result
condition|)
block|{
name|printf
argument_list|(
literal|"error in __udivmodsi4: %u / %u = %u, expected %u\n"
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|result
argument_list|,
name|expected_result
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
if|if
condition|(
name|rem
operator|!=
name|expected_rem
condition|)
block|{
name|printf
argument_list|(
literal|"error in __udivmodsi4: %u mod %u = %u, expected %u\n"
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|rem
argument_list|,
name|expected_rem
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
name|test__udivmodsi4
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__udivmodsi4
argument_list|(
literal|2
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__udivmodsi4
argument_list|(
literal|19
argument_list|,
literal|5
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__udivmodsi4
argument_list|(
literal|0x80000000
argument_list|,
literal|8
argument_list|,
literal|0x10000000
argument_list|,
literal|0
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__udivmodsi4
argument_list|(
literal|0x80000003
argument_list|,
literal|8
argument_list|,
literal|0x10000000
argument_list|,
literal|3
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

