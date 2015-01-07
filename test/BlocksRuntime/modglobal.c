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

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|// CONFIG
end_comment

begin_decl_stmt
name|int
name|AGlobal
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
name|void
function_decl|(
modifier|^
name|f
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
lambda|^
block|{
name|AGlobal
operator|++
function_decl|;
block|}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

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

