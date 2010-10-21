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
comment|//  nestedimport.m
end_comment

begin_comment
comment|//  testObjects
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Created by Blaine Garst on 6/24/08.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// pure C nothing more needed
end_comment

begin_comment
comment|// CONFIG
end_comment

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

begin_decl_stmt
name|int
name|Global
init|=
literal|0
decl_stmt|;
end_decl_stmt

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
name|i
init|=
literal|1
decl_stmt|;
name|void
function_decl|(
modifier|^
name|vv
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
lambda|^
block|{
if|if
condition|(
name|argc
operator|>
literal|0
condition|)
block|{
name|callVoidVoid
argument_list|(
lambda|^
block|{
name|Global
operator|=
name|i
expr_stmt|;
block|}
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|i
operator|=
literal|2
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|vv
argument_list|()
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|Global
operator|!=
literal|1
condition|)
block|{
name|printf
argument_list|(
literal|"%s: error, Global not set to captured value\n"
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
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

