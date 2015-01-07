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
comment|/*  *  localisglobal.c  *  testObjects  *  *  Created by Blaine Garst on 9/29/08.  *  *  works in all configurations  *  CONFIG   rdar://6230297  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function_decl
name|void
function_decl|(
modifier|^
name|global
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
lambda|^
block|{
name|printf
argument_list|(
literal|"hello world\n"
argument_list|)
function_decl|;
end_function_decl

begin_function
unit|};
name|int
name|aresame
parameter_list|(
name|void
modifier|*
name|first
parameter_list|,
name|void
modifier|*
name|second
parameter_list|)
block|{
name|long
modifier|*
name|f
init|=
operator|(
name|long
operator|*
operator|)
name|first
decl_stmt|;
name|long
modifier|*
name|s
init|=
operator|(
name|long
operator|*
operator|)
name|second
decl_stmt|;
return|return
operator|*
name|f
operator|==
operator|*
name|s
return|;
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
name|int
name|i
init|=
literal|10
decl_stmt|;
name|void
function_decl|(
modifier|^
name|local
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
lambda|^
block|{
name|printf
argument_list|(
literal|"hi %d\n"
argument_list|,
name|i
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
name|localisglobal
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
lambda|^
block|{
name|printf
argument_list|(
literal|"hi\n"
argument_list|)
function_decl|;
end_function_decl

begin_if
unit|};
if|if
condition|(
name|aresame
argument_list|(
name|local
argument_list|,
name|localisglobal
argument_list|)
condition|)
block|{
name|printf
argument_list|(
literal|"local block could be global, but isn't\n"
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
end_if

begin_if
if|if
condition|(
operator|!
name|aresame
argument_list|(
name|global
argument_list|,
name|localisglobal
argument_list|)
condition|)
block|{
name|printf
argument_list|(
literal|"local block is not global, not stack, what is it??\n"
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

