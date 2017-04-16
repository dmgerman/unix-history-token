begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_builtins %s %librt -o %t&& %run %t
end_comment

begin_comment
comment|//===-- udivdi3_test.c - Test __udivdi3 -----------------------------------===//
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
comment|// This file tests __udivdi3 for the compiler_rt library.
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
name|COMPILER_RT_ABI
name|du_int
name|__udivdi3
parameter_list|(
name|du_int
name|a
parameter_list|,
name|du_int
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|test__udivdi3
parameter_list|(
name|du_int
name|a
parameter_list|,
name|du_int
name|b
parameter_list|,
name|du_int
name|expected_q
parameter_list|)
block|{
name|du_int
name|q
init|=
name|__udivdi3
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
decl_stmt|;
if|if
condition|(
name|q
operator|!=
name|expected_q
condition|)
name|printf
argument_list|(
literal|"error in __udivdi3: %lld / %lld = %lld, expected %lld\n"
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|q
argument_list|,
name|expected_q
argument_list|)
expr_stmt|;
return|return
name|q
operator|!=
name|expected_q
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
name|test__udivdi3
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__udivdi3
argument_list|(
literal|2
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__udivdi3
argument_list|(
literal|0x8000000000000000uLL
argument_list|,
literal|1
argument_list|,
literal|0x8000000000000000uLL
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__udivdi3
argument_list|(
literal|0x8000000000000000uLL
argument_list|,
literal|2
argument_list|,
literal|0x4000000000000000uLL
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__udivdi3
argument_list|(
literal|0xFFFFFFFFFFFFFFFFuLL
argument_list|,
literal|2
argument_list|,
literal|0x7FFFFFFFFFFFFFFFuLL
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

