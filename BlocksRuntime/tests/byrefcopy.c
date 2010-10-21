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
comment|//  byrefcopy.m
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

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<Block.h>
end_include

begin_include
include|#
directive|include
file|<Block_private.h>
end_include

begin_comment
comment|// CONFIG
end_comment

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
name|int
specifier|__block
name|i
init|=
literal|10
decl_stmt|;
name|void
function_decl|(
modifier|^
name|block
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
lambda|^
block|{
operator|++
name|i
function_decl|;
block|}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|//printf("original (old style) is  %s\n", _Block_dump_old(block));
end_comment

begin_comment
comment|//printf("original (new style) is %s\n", _Block_dump(block));
end_comment

begin_function_decl
name|void
function_decl|(
modifier|^
name|blockcopy
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
name|Block_copy
argument_list|(
name|block
argument_list|)
function_decl|;
end_function_decl

begin_comment
comment|//printf("copy is %s\n", _Block_dump(blockcopy));
end_comment

begin_comment
comment|// use a copy& see that it updates i
end_comment

begin_expr_stmt
name|callVoidVoid
argument_list|(
name|block
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
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
end_if

begin_expr_stmt
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
end_expr_stmt

begin_return
return|return
literal|0
return|;
end_return

unit|}
end_unit

