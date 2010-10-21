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
comment|// CONFIG open rdar://6416474
end_comment

begin_comment
comment|// was  rdar://5847976
end_comment

begin_comment
comment|// was  rdar://6348320
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

begin_decl_stmt
name|int
name|verbose
init|=
literal|0
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
modifier|*
name|argv
index|[]
parameter_list|)
block|{
if|if
condition|(
name|argc
operator|>
literal|1
condition|)
name|verbose
operator|=
literal|1
expr_stmt|;
specifier|__block
name|void
function_decl|(
modifier|^
name|recursive_local_block
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
if|if
condition|(
name|verbose
condition|)
name|printf
argument_list|(
literal|"recursive_local_block is a local recursive block\n"
argument_list|)
expr_stmt|;
name|recursive_local_block
operator|=
lambda|^
parameter_list|(
name|int
name|i
parameter_list|)
block|{
if|if
condition|(
name|verbose
condition|)
name|printf
argument_list|(
literal|"%d\n"
argument_list|,
name|i
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|>
literal|0
condition|)
block|{
name|recursive_local_block
argument_list|(
name|i
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
expr_stmt|;
if|if
condition|(
name|verbose
condition|)
name|printf
argument_list|(
literal|"recursive_local_block's address is %p, running it:\n"
argument_list|,
operator|(
name|void
operator|*
operator|)
name|recursive_local_block
argument_list|)
expr_stmt|;
name|recursive_local_block
argument_list|(
literal|5
argument_list|)
expr_stmt|;
if|if
condition|(
name|verbose
condition|)
name|printf
argument_list|(
literal|"Creating other_local_block: a local block that calls recursive_local_block\n"
argument_list|)
expr_stmt|;
name|void
function_decl|(
modifier|^
name|other_local_block
function_decl|)
parameter_list|(
name|int
parameter_list|)
init|=
lambda|^
parameter_list|(
name|int
name|i
parameter_list|)
block|{
if|if
condition|(
name|verbose
condition|)
name|printf
argument_list|(
literal|"other_local_block running\n"
argument_list|)
expr_stmt|;
name|recursive_local_block
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_if
if|if
condition|(
name|verbose
condition|)
name|printf
argument_list|(
literal|"other_local_block's address is %p, running it:\n"
argument_list|,
operator|(
name|void
operator|*
operator|)
name|other_local_block
argument_list|)
expr_stmt|;
end_if

begin_expr_stmt
name|other_local_block
argument_list|(
literal|5
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|#
directive|if
name|__APPLE_CC__
operator|>=
literal|5627
end_if

begin_if
if|if
condition|(
name|verbose
condition|)
name|printf
argument_list|(
literal|"Creating other_copied_block: a Block_copy of a block that will call recursive_local_block\n"
argument_list|)
expr_stmt|;
end_if

begin_function_decl
name|void
function_decl|(
modifier|^
name|other_copied_block
function_decl|)
parameter_list|(
name|int
parameter_list|)
init|=
name|Block_copy
argument_list|(
lambda|^
parameter_list|(
name|int
name|i
parameter_list|)
block|{
end_function_decl

begin_if
if|if
condition|(
name|verbose
condition|)
name|printf
argument_list|(
literal|"other_copied_block running\n"
argument_list|)
expr_stmt|;
end_if

begin_expr_stmt
name|recursive_local_block
argument_list|(
name|i
argument_list|)
expr_stmt|;
end_expr_stmt

begin_empty_stmt
unit|})
empty_stmt|;
end_empty_stmt

begin_if
if|if
condition|(
name|verbose
condition|)
name|printf
argument_list|(
literal|"other_copied_block's address is %p, running it:\n"
argument_list|,
operator|(
name|void
operator|*
operator|)
name|other_copied_block
argument_list|)
expr_stmt|;
end_if

begin_expr_stmt
name|other_copied_block
argument_list|(
literal|5
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|__block
name|void
function_decl|(
modifier|^
name|recursive_copy_block
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|if
condition|(
name|verbose
condition|)
name|printf
argument_list|(
literal|"Creating recursive_copy_block: a Block_copy of a block that will call recursive_copy_block recursively\n"
argument_list|)
expr_stmt|;
end_if

begin_expr_stmt
name|recursive_copy_block
operator|=
name|Block_copy
argument_list|(
lambda|^
parameter_list|(
name|int
name|i
parameter_list|)
block|{
if|if
condition|(
name|verbose
condition|)
name|printf
argument_list|(
literal|"%d\n"
argument_list|,
name|i
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|>
literal|0
condition|)
block|{
name|recursive_copy_block
argument_list|(
name|i
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|verbose
condition|)
name|printf
argument_list|(
literal|"recursive_copy_block's address is %p, running it:\n"
argument_list|,
operator|(
name|void
operator|*
operator|)
name|recursive_copy_block
argument_list|)
expr_stmt|;
end_if

begin_expr_stmt
name|recursive_copy_block
argument_list|(
literal|5
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|printf
argument_list|(
literal|"%s: Success\n"
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

