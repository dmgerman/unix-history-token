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

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_decl_stmt
specifier|const
name|char
modifier|*
name|hello_world
init|=
literal|"Hello, assertion!"
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|int
modifier|*
name|null_ptr
init|=
literal|0
decl_stmt|;
name|printf
argument_list|(
literal|"%s\n"
argument_list|,
name|hello_world
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|null_ptr
argument_list|)
expr_stmt|;
comment|// Assert here.
block|}
end_function

end_unit

