begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_builtins %s %librt -o %t&& %run %t
end_comment

begin_comment
comment|//===-- negvdi2_test.c - Test __negvdi2 -----------------------------------===//
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
comment|// This file tests __negvdi2 for the compiler_rt library.
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
name|di_int
name|__negvdi2
parameter_list|(
name|di_int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|test__negvdi2
parameter_list|(
name|di_int
name|a
parameter_list|)
block|{
name|di_int
name|x
init|=
name|__negvdi2
argument_list|(
name|a
argument_list|)
decl_stmt|;
name|di_int
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
literal|"error in __negvdi2(0x%llX) = %lld, expected %lld\n"
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
comment|//     if (test__negvdi2(0x8000000000000000LL))  // should abort
comment|//         return 1;
if|if
condition|(
name|test__negvdi2
argument_list|(
literal|0x0000000000000000LL
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__negvdi2
argument_list|(
literal|0x0000000000000001LL
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__negvdi2
argument_list|(
literal|0x0000000000000002LL
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__negvdi2
argument_list|(
literal|0x7FFFFFFFFFFFFFFELL
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__negvdi2
argument_list|(
literal|0x7FFFFFFFFFFFFFFFLL
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__negvdi2
argument_list|(
literal|0x8000000000000001LL
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__negvdi2
argument_list|(
literal|0x8000000000000002LL
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__negvdi2
argument_list|(
literal|0xFFFFFFFFFFFFFFFELL
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__negvdi2
argument_list|(
literal|0xFFFFFFFFFFFFFFFFLL
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

