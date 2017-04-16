begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_builtins %s %librt -o %t&& %run %t
end_comment

begin_comment
comment|//===-- absvsi2_test.c - Test __absvsi2 -----------------------------------===//
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
comment|// This file tests __absvsi2 for the compiler_rt library.
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

begin_comment
comment|// Returns: absolute value
end_comment

begin_comment
comment|// Effects: aborts if abs(x)< 0
end_comment

begin_function_decl
name|COMPILER_RT_ABI
name|si_int
name|__absvsi2
parameter_list|(
name|si_int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|test__absvsi2
parameter_list|(
name|si_int
name|a
parameter_list|)
block|{
name|si_int
name|x
init|=
name|__absvsi2
argument_list|(
name|a
argument_list|)
decl_stmt|;
name|si_int
name|expected
init|=
name|a
decl_stmt|;
if|if
condition|(
name|expected
operator|<
literal|0
condition|)
name|expected
operator|=
operator|-
name|expected
expr_stmt|;
if|if
condition|(
name|x
operator|!=
name|expected
operator|||
name|expected
operator|<
literal|0
condition|)
name|printf
argument_list|(
literal|"error in __absvsi2(0x%X) = %d, expected positive %d\n"
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
comment|//     if (test__absvsi2(0x80000000))  // should abort
comment|//         return 1;
if|if
condition|(
name|test__absvsi2
argument_list|(
literal|0x00000000
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__absvsi2
argument_list|(
literal|0x00000001
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__absvsi2
argument_list|(
literal|0x00000002
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__absvsi2
argument_list|(
literal|0x7FFFFFFE
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__absvsi2
argument_list|(
literal|0x7FFFFFFF
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__absvsi2
argument_list|(
literal|0x80000001
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__absvsi2
argument_list|(
literal|0x80000002
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__absvsi2
argument_list|(
literal|0xFFFFFFFE
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__absvsi2
argument_list|(
literal|0xFFFFFFFF
argument_list|)
condition|)
return|return
literal|1
return|;
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|10000
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|test__absvsi2
argument_list|(
name|rand
argument_list|()
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

