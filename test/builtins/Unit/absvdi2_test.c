begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_builtins %s %librt -o %t&& %run %t
end_comment

begin_comment
comment|//===-- absvdi2_test.c - Test __absvdi2 -----------------------------------===//
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
comment|// This file tests __absvdi2 for the compiler_rt library.
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
name|di_int
name|__absvdi2
parameter_list|(
name|di_int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|test__absvdi2
parameter_list|(
name|di_int
name|a
parameter_list|)
block|{
name|di_int
name|x
init|=
name|__absvdi2
argument_list|(
name|a
argument_list|)
decl_stmt|;
name|di_int
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
literal|"error in __absvdi2(0x%llX) = %lld, expected positive %lld\n"
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
comment|//     if (test__absvdi2(0x8000000000000000LL))  // should abort
comment|//         return 1;
if|if
condition|(
name|test__absvdi2
argument_list|(
literal|0x0000000000000000LL
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__absvdi2
argument_list|(
literal|0x0000000000000001LL
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__absvdi2
argument_list|(
literal|0x0000000000000002LL
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__absvdi2
argument_list|(
literal|0x7FFFFFFFFFFFFFFELL
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__absvdi2
argument_list|(
literal|0x7FFFFFFFFFFFFFFFLL
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__absvdi2
argument_list|(
literal|0x8000000000000001LL
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__absvdi2
argument_list|(
literal|0x8000000000000002LL
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__absvdi2
argument_list|(
literal|0xFFFFFFFFFFFFFFFELL
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__absvdi2
argument_list|(
literal|0xFFFFFFFFFFFFFFFFLL
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
name|test__absvdi2
argument_list|(
operator|(
operator|(
name|di_int
operator|)
name|rand
argument_list|()
operator|<<
literal|32
operator|)
operator||
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

