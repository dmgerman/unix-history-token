begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
comment|//  byrefaccess.m
end_comment

begin_comment
comment|//  test that byref access to locals is accurate
end_comment

begin_comment
comment|//  testObjects
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Created by Blaine Garst on 5/13/08.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CONFIG
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function
name|void
name|callVoidVoid
parameter_list|(
name|void
function_decl|(
modifier|^
name|closure
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
block|{
name|closure
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
specifier|__block
name|int
name|i
init|=
literal|10
decl_stmt|;
name|callVoidVoid
argument_list|(
lambda|^
block|{
operator|++
name|i
expr_stmt|;
block|}
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|!=
literal|11
condition|)
block|{
name|printf
argument_list|(
literal|"*** %s didn't update i\n"
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
name|printf
argument_list|(
literal|"%s: success\n"
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

