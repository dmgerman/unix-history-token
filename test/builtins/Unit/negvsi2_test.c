begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_builtins %s %librt -o %t&& %run %t
end_comment

begin_comment
comment|//===-- negvsi2_test.c - Test __negvsi2 -----------------------------------===//
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
comment|// This file tests __negvsi2 for the compiler_rt library.
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
comment|// Returns: -a
end_comment

begin_comment
comment|// Effects: aborts if -a overflows
end_comment

begin_function_decl
name|COMPILER_RT_ABI
name|si_int
name|__negvsi2
parameter_list|(
name|si_int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|test__negvsi2
parameter_list|(
name|si_int
name|a
parameter_list|)
block|{
name|si_int
name|x
init|=
name|__negvsi2
argument_list|(
name|a
argument_list|)
decl_stmt|;
name|si_int
name|expected
init|=
operator|-
name|a
decl_stmt|;
if|if
condition|(
name|x
operator|!=
name|expected
condition|)
name|printf
argument_list|(
literal|"error in __negvsi2(0x%X) = %d, expected %d\n"
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
comment|//     if (test__negvsi2(0x80000000))  // should abort
comment|//         return 1;
if|if
condition|(
name|test__negvsi2
argument_list|(
literal|0x00000000
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__negvsi2
argument_list|(
literal|0x00000001
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__negvsi2
argument_list|(
literal|0x00000002
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__negvsi2
argument_list|(
literal|0x7FFFFFFE
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__negvsi2
argument_list|(
literal|0x7FFFFFFF
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__negvsi2
argument_list|(
literal|0x80000001
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__negvsi2
argument_list|(
literal|0x80000002
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__negvsi2
argument_list|(
literal|0xFFFFFFFE
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__negvsi2
argument_list|(
literal|0xFFFFFFFF
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

