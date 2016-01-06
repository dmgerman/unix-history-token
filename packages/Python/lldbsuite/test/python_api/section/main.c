begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- main.c --------------------------------------------------*- C++ -*-===//
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
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
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
file|<string.h>
end_include

begin_comment
comment|// This simple program is to test the lldb Python API SBSection. It includes
end_comment

begin_comment
comment|// somes global data, and so the build process produces a DATA section, which
end_comment

begin_comment
comment|// the test code can use to query for the target byte size
end_comment

begin_decl_stmt
name|char
name|my_global_var_of_char_type
init|=
literal|'X'
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
specifier|const
modifier|*
name|argv
index|[]
parameter_list|)
block|{
comment|// this code just "does something" with the global so that it is not
comment|// optimised away
if|if
condition|(
name|argc
operator|>
literal|1
operator|&&
name|strlen
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|)
condition|)
block|{
name|my_global_var_of_char_type
operator|+=
name|argv
index|[
literal|1
index|]
index|[
literal|0
index|]
expr_stmt|;
block|}
return|return
name|my_global_var_of_char_type
return|;
block|}
end_function

end_unit

