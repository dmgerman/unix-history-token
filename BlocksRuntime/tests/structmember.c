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
comment|/*  *  structmember.c  *  testObjects  *  *  Created by Blaine Garst on 9/30/08.  *  CONFIG  */
end_comment

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
file|<stdio.h>
end_include

begin_comment
comment|// CONFIG
end_comment

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
struct|struct
name|stuff
block|{
name|long
name|int
name|a
decl_stmt|;
name|long
name|int
name|b
decl_stmt|;
name|long
name|int
name|c
decl_stmt|;
block|}
name|localStuff
init|=
block|{
literal|10
block|,
literal|20
block|,
literal|30
block|}
struct|;
name|int
name|d
decl_stmt|;
name|void
function_decl|(
modifier|^
name|a
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
lambda|^
block|{
name|printf
argument_list|(
literal|"d is %d"
argument_list|,
name|d
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
name|b
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
lambda|^
block|{
name|printf
argument_list|(
literal|"d is %d, localStuff.a is %lu"
argument_list|,
name|d
argument_list|,
name|localStuff
operator|.
name|a
argument_list|)
function_decl|;
end_function_decl

begin_decl_stmt
unit|};
name|unsigned
name|nominalsize
init|=
name|Block_size
argument_list|(
name|b
argument_list|)
operator|-
name|Block_size
argument_list|(
name|a
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|__cplusplus__
end_if

begin_comment
comment|// need copy+dispose helper for C++ structures
end_comment

begin_expr_stmt
name|nominalsize
operator|+=
literal|2
operator|*
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|if
condition|(
operator|(
name|Block_size
argument_list|(
name|b
argument_list|)
operator|-
name|Block_size
argument_list|(
name|a
argument_list|)
operator|)
operator|!=
name|nominalsize
condition|)
block|{
name|printf
argument_list|(
literal|"sizeof a is %ld, sizeof b is %ld, expected %d\n"
argument_list|,
name|Block_size
argument_list|(
name|a
argument_list|)
argument_list|,
name|Block_size
argument_list|(
name|b
argument_list|)
argument_list|,
name|nominalsize
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"dump of b is %s\n"
argument_list|,
name|_Block_dump
argument_list|(
name|b
argument_list|)
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

