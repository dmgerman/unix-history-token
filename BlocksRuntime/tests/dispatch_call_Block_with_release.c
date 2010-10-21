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

begin_include
include|#
directive|include
file|<Block.h>
end_include

begin_comment
comment|// CONFIG
end_comment

begin_function
name|void
name|callsomething
parameter_list|(
specifier|const
name|char
modifier|*
name|format
parameter_list|,
name|int
name|argument
parameter_list|)
block|{ }
end_function

begin_function
name|void
name|dispatch_call_Block_with_release2
parameter_list|(
name|void
modifier|*
name|block
parameter_list|)
block|{
name|void
function_decl|(
modifier|^
name|b
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
operator|(
name|void
argument_list|(
operator|^
argument_list|)
operator|(
name|void
operator|)
operator|)
name|block
function_decl|;
name|b
argument_list|()
expr_stmt|;
name|Block_release
argument_list|(
name|b
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
name|void
function_decl|(
modifier|^
name|b1
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
lambda|^
block|{
name|callsomething
argument_list|(
literal|"argc is %d\n"
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
name|b2
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
lambda|^
block|{
name|callsomething
argument_list|(
literal|"hellow world\n"
argument_list|,
literal|0
argument_list|)
function_decl|;
end_function_decl

begin_comment
unit|};
comment|// global block now
end_comment

begin_expr_stmt
name|dispatch_call_Block_with_release2
argument_list|(
name|Block_copy
argument_list|(
name|b1
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|dispatch_call_Block_with_release2
argument_list|(
name|Block_copy
argument_list|(
name|b2
argument_list|)
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

