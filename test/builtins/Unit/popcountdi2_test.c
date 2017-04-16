begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_builtins %s %librt -o %t&& %run %t
end_comment

begin_comment
comment|//===-- popcountdi2_test.c - Test __popcountdi2 ----------------------------===//
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
comment|// This file tests __popcountdi2 for the compiler_rt library.
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
comment|// Returns: count of 1 bits
end_comment

begin_function_decl
name|COMPILER_RT_ABI
name|si_int
name|__popcountdi2
parameter_list|(
name|di_int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|naive_popcount
parameter_list|(
name|di_int
name|a
parameter_list|)
block|{
name|int
name|r
init|=
literal|0
decl_stmt|;
for|for
control|(
init|;
name|a
condition|;
name|a
operator|=
operator|(
name|du_int
operator|)
name|a
operator|>>
literal|1
control|)
name|r
operator|+=
name|a
operator|&
literal|1
expr_stmt|;
return|return
name|r
return|;
block|}
end_function

begin_function
name|int
name|test__popcountdi2
parameter_list|(
name|di_int
name|a
parameter_list|)
block|{
name|si_int
name|x
init|=
name|__popcountdi2
argument_list|(
name|a
argument_list|)
decl_stmt|;
name|si_int
name|expected
init|=
name|naive_popcount
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
literal|"error in __popcountdi2(0x%llX) = %d, expected %d\n"
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

begin_decl_stmt
name|char
name|assumption_1
index|[
sizeof|sizeof
argument_list|(
name|di_int
argument_list|)
operator|==
literal|2
operator|*
sizeof|sizeof
argument_list|(
name|si_int
argument_list|)
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|assumption_2
index|[
sizeof|sizeof
argument_list|(
name|si_int
argument_list|)
operator|*
name|CHAR_BIT
operator|==
literal|32
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|main
parameter_list|()
block|{
if|if
condition|(
name|test__popcountdi2
argument_list|(
literal|0
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__popcountdi2
argument_list|(
literal|1
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__popcountdi2
argument_list|(
literal|2
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__popcountdi2
argument_list|(
literal|0xFFFFFFFFFFFFFFFDLL
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__popcountdi2
argument_list|(
literal|0xFFFFFFFFFFFFFFFELL
argument_list|)
condition|)
return|return
literal|1
return|;
if|if
condition|(
name|test__popcountdi2
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
name|test__popcountdi2
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

