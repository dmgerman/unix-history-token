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
comment|/*  *  rettypepromotion.c  *  testObjects  *  *  Created by Blaine Garst on 11/3/08.  *  */
end_comment

begin_comment
comment|// CONFIG error:
end_comment

begin_comment
comment|// C++ and C give different errors so we don't check for an exact match.
end_comment

begin_comment
comment|// The error is that enum's are defined to be ints, always, even if defined with explicit long values
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

begin_enum
enum|enum
block|{
name|LESS
init|=
operator|-
literal|1
block|,
name|EQUAL
block|,
name|GREATER
block|}
enum|;
end_enum

begin_function
name|void
name|sortWithBlock
parameter_list|(
name|long
function_decl|(
modifier|^
name|comp
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg1
parameter_list|,
name|void
modifier|*
name|arg2
parameter_list|)
parameter_list|)
block|{ }
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
name|sortWithBlock
argument_list|(
lambda|^
parameter_list|(
name|void
modifier|*
name|arg1
parameter_list|,
name|void
modifier|*
name|arg2
parameter_list|)
block|{
if|if
condition|(
name|random
argument_list|()
condition|)
return|return
name|LESS
return|;
if|if
condition|(
name|random
argument_list|()
condition|)
return|return
name|EQUAL
return|;
if|if
condition|(
name|random
argument_list|()
condition|)
return|return
name|GREATER
return|;
block|}
argument_list|)
expr_stmt|;
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
return|return
literal|0
return|;
block|}
end_function

end_unit

