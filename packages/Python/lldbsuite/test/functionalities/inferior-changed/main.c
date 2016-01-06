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
literal|"Hello, segfault!\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Now crash %d\n"
argument_list|,
operator|*
name|null_ptr
argument_list|)
expr_stmt|;
comment|// Crash here.
block|}
end_function

end_unit

