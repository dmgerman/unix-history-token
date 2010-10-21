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
comment|// CONFIG C
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<Block_private.h>
end_include

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
name|void
function_decl|(
modifier|^
name|inner
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
lambda|^
block|{
name|printf
argument_list|(
literal|"argc was %d\n"
argument_list|,
name|argc
argument_list|)
function_decl|;
block|}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
function_decl|(
modifier|^
name|outer
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
lambda|^
block|{
name|inner
argument_list|()
function_decl|;
end_function_decl

begin_expr_stmt
name|inner
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|//printf("size of inner is %ld\n", Block_size(inner));
end_comment

begin_comment
comment|//printf("size of outer is %ld\n", Block_size(outer));
end_comment

begin_if
if|if
condition|(
name|Block_size
argument_list|(
name|inner
argument_list|)
operator|!=
name|Block_size
argument_list|(
name|outer
argument_list|)
condition|)
block|{
name|printf
argument_list|(
literal|"not the same size, using old compiler??\n"
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

