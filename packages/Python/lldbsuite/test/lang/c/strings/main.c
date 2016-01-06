begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- main.c ----------------------------------------------------*- C -*-===//
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

begin_function
name|int
name|main
parameter_list|()
block|{
specifier|const
name|char
name|a
index|[]
init|=
literal|"abcde"
decl_stmt|;
specifier|const
name|char
modifier|*
name|z
init|=
literal|"vwxyz"
decl_stmt|;
name|printf
argument_list|(
literal|"%s %s"
argument_list|,
name|a
argument_list|,
name|z
argument_list|)
expr_stmt|;
comment|// breakpoint 1
block|}
end_function

end_unit

