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
comment|// CONFIG  rdar://6339747 but wasn't
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function_decl
name|int
function_decl|(
modifier|*
name|funcptr
function_decl|)
parameter_list|(
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|int
argument_list|(
operator|*
call|(
modifier|^
name|b
call|)
argument_list|(
name|char
argument_list|)
argument_list|)
argument_list|(
name|long
argument_list|)
expr_stmt|;
end_expr_stmt

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
comment|// implicit is fine
name|b
operator|=
lambda|^
parameter_list|(
name|char
name|x
parameter_list|)
block|{
return|return
name|funcptr
return|;
block|}
expr_stmt|;
comment|// explicit never parses
name|b
operator|=
lambda|^
name|int
parameter_list|(
lambda|*
parameter_list|(
name|char
name|x
parameter_list|)
block|)
parameter_list|(
name|long
parameter_list|)
block|{
return|return
name|funcptr
return|;
block|}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

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

