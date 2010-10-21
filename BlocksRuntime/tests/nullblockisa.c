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
comment|//  nullblockisa.m
end_comment

begin_comment
comment|//  testObjects
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Created by Blaine Garst on 9/24/08.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CONFIG rdar://6244520
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
file|<Block_private.h>
end_include

begin_function
name|void
name|check
parameter_list|(
name|void
function_decl|(
modifier|^
name|b
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
block|{
struct|struct
name|_custom
block|{
name|struct
name|Block_layout
name|layout
decl_stmt|;
name|struct
name|Block_byref
modifier|*
name|innerp
decl_stmt|;
block|}
modifier|*
name|custom
init|=
operator|(
expr|struct
name|_custom
operator|*
operator|)
operator|(
name|void
operator|*
operator|)
operator|(
name|b
operator|)
struct|;
comment|//printf("block is at %p, size is %lx, inner is %p\n", (void *)b, Block_size(b), innerp);
if|if
condition|(
name|custom
operator|->
name|innerp
operator|->
name|isa
operator|!=
operator|(
name|void
operator|*
operator|)
name|NULL
condition|)
block|{
name|printf
argument_list|(
literal|"not a NULL __block isa\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
return|return;
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
decl_stmt|;
name|check
argument_list|(
lambda|^
block|{
name|printf
argument_list|(
literal|"%d\n"
argument_list|,
operator|++
name|i
argument_list|)
expr_stmt|;
block|}
argument_list|)
expr_stmt|;
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

