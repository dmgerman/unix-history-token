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
comment|/*  *  recursiveassign.c  *  testObjects  *  *  Created by Blaine Garst on 12/3/08.  *  */
end_comment

begin_comment
comment|// CONFIG  rdar://6639533
end_comment

begin_comment
comment|// The compiler is prefetching x->forwarding before evaluting code that recomputes forwarding and so the value goes to a place that is never seen again.
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

begin_include
include|#
directive|include
file|<Block.h>
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
specifier|__block
name|void
function_decl|(
modifier|^
name|recursive_copy_block
function_decl|)
parameter_list|(
name|int
parameter_list|)
init|=
lambda|^
parameter_list|(
name|int
name|arg
parameter_list|)
block|{
name|printf
argument_list|(
literal|"got wrong Block\n"
argument_list|)
function_decl|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

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
else|else
block|{
name|printf
argument_list|(
literal|"done!\n"
argument_list|)
expr_stmt|;
block|}
block|}
argument_list|)
expr_stmt|;
end_expr_stmt

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

