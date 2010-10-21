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
comment|//  byrefcopystack.m
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

begin_comment
comment|// CONFIG rdar://6255170
end_comment

begin_function_decl
name|void
function_decl|(
modifier|^
name|bumpi
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
function_decl|(
modifier|^
name|geti
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|setClosures
parameter_list|()
block|{
name|int
specifier|__block
name|i
init|=
literal|10
decl_stmt|;
name|bumpi
operator|=
name|Block_copy
argument_list|(
lambda|^
block|{
operator|++
name|i
expr_stmt|;
block|}
argument_list|)
expr_stmt|;
name|geti
operator|=
name|Block_copy
argument_list|(
lambda|^
block|{
return|return
name|i
return|;
block|}
argument_list|)
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
name|setClosures
argument_list|()
expr_stmt|;
name|bumpi
argument_list|()
expr_stmt|;
name|int
name|i
init|=
name|geti
argument_list|()
decl_stmt|;
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

