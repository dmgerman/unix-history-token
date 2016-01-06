begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- main.c --------------------------------------------------*- C++ -*-===//
end_comment

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
comment|//===----------------------------------------------------------------------===//
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|// breakpoint set -n foo
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_function
name|int
name|foo
parameter_list|(
name|int
name|value
parameter_list|)
block|{
name|printf
argument_list|(
literal|"I got the value: %d.\n"
argument_list|,
name|value
argument_list|)
expr_stmt|;
return|return
literal|0
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
modifier|*
name|argv
parameter_list|)
block|{
name|foo
argument_list|(
name|argc
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Hello there: %d.\n"
argument_list|,
name|argc
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

