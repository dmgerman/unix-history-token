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
comment|//  c99.m
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CONFIG C99 rdar://problem/6399225
end_comment

begin_empty
empty|#import<stdio.h>
end_empty

begin_empty
empty|#import<stdlib.h>
end_empty

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
name|blockA
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
lambda|^
block|{
function_decl|;
block|}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|blockA
argument_list|()
expr_stmt|;
end_expr_stmt

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

begin_expr_stmt
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

unit|}
end_unit

