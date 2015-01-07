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
comment|/*  *  voidarg.c  *  testObjects  *  *  Created by Blaine Garst on 2/17/09.  *  */
end_comment

begin_comment
comment|// PURPOSE should complain about missing 'void' but both GCC and clang are supporting K&R instead
end_comment

begin_comment
comment|// CONFIG open error:
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_decl_stmt
name|int
name|Global
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
function_decl|(
modifier|^
name|globalBlock
function_decl|)
parameter_list|()
init|=
lambda|^
block|{
operator|++
name|Global
function_decl|;
end_function_decl

begin_comment
unit|};
comment|// should be void (^gb)(void) = ...
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
name|printf
argument_list|(
literal|"%s: success"
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

