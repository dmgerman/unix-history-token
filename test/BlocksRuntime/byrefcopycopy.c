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
comment|// CONFIG rdar://6255170
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdbool.h>
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

begin_include
include|#
directive|include
file|<Block_private.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
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
name|int
name|var
init|=
literal|0
decl_stmt|;
name|int
name|shouldbe
init|=
literal|0
decl_stmt|;
name|void
function_decl|(
modifier|^
name|b
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
lambda|^
block|{
name|var
operator|++
function_decl|;
comment|/*printf("var is at %p with value %d\n",&var, var);*/
block|}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|__typeof
argument_list|(
argument|b
argument_list|)
end_macro

begin_expr_stmt
name|_b
expr_stmt|;
end_expr_stmt

begin_comment
comment|//printf("before copy...\n");
end_comment

begin_expr_stmt
name|b
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|++
name|shouldbe
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|size_t
name|i
decl_stmt|;
end_decl_stmt

begin_for
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|10
condition|;
name|i
operator|++
control|)
block|{
name|_b
operator|=
name|Block_copy
argument_list|(
name|b
argument_list|)
expr_stmt|;
comment|// make a new copy each time
name|assert
argument_list|(
name|_b
argument_list|)
expr_stmt|;
operator|++
name|shouldbe
expr_stmt|;
name|_b
argument_list|()
expr_stmt|;
comment|// should still update the stack
name|Block_release
argument_list|(
name|_b
argument_list|)
expr_stmt|;
block|}
end_for

begin_comment
comment|//printf("after...\n");
end_comment

begin_expr_stmt
name|b
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|++
name|shouldbe
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|var
operator|!=
name|shouldbe
condition|)
block|{
name|printf
argument_list|(
literal|"Hmm, var is %d but should be %d\n"
argument_list|,
name|var
argument_list|,
name|shouldbe
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
literal|"%s: Success!!\n"
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

