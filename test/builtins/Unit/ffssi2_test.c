begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_builtins %s %librt -o %t&& %run %t
end_comment

begin_comment
comment|//===-- ffssi2_test.c - Test __ffssi2 -------------------------------------===//
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
comment|// This file tests __ffssi2 for the compiler_rt library.
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
comment|// Returns: the index of the least significant 1-bit in a, or
end_comment

begin_comment
comment|// the value zero if a is zero. The least significant bit is index one.
end_comment

begin_function_decl
name|COMPILER_RT_ABI
name|si_int
name|__ffssi2
parameter_list|(
name|si_int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|test__ffssi2
parameter_list|(
name|si_int
name|a
parameter_list|,
name|si_int
name|expected
parameter_list|)
block|{
name|si_int
name|x
init|=
name|__ffssi2
argument_list|(
name|a
argument_list|)
decl_stmt|;
if|if
condition|(
name|x
operator|!=
name|expected
condition|)
name|printf
argument_list|(
literal|"error in __ffssi2(0x%X) = %d, expected %d\n"
argument_list|,
name|a
argument_list|,
name|x
argument_list|,
name|expected
argument_list|)
expr_stmt|;
return|return
name|x
operator|!=
name|expected
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
name|test__ffssi2
argument_list|(
literal|0x00000000
argument_list|,
literal|0
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__ffssi2
argument_list|(
literal|0x00000001
argument_list|,
literal|1
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__ffssi2
argument_list|(
literal|0x00000002
argument_list|,
literal|2
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__ffssi2
argument_list|(
literal|0x00000003
argument_list|,
literal|1
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__ffssi2
argument_list|(
literal|0x00000004
argument_list|,
literal|3
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__ffssi2
argument_list|(
literal|0x00000005
argument_list|,
literal|1
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__ffssi2
argument_list|(
literal|0x0000000A
argument_list|,
literal|2
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__ffssi2
argument_list|(
literal|0x10000000
argument_list|,
literal|29
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__ffssi2
argument_list|(
literal|0x20000000
argument_list|,
literal|30
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__ffssi2
argument_list|(
literal|0x60000000
argument_list|,
literal|30
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__ffssi2
argument_list|(
literal|0x80000000u
argument_list|,
literal|32
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

