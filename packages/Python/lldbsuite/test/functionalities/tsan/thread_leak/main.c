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
file|<pthread.h>
end_include

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

begin_function
name|void
modifier|*
name|f1
parameter_list|(
name|void
modifier|*
name|p
parameter_list|)
block|{
name|printf
argument_list|(
literal|"hello\n"
argument_list|)
expr_stmt|;
return|return
name|NULL
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
specifier|const
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|pthread_t
name|t1
decl_stmt|;
name|pthread_create
argument_list|(
operator|&
name|t1
argument_list|,
name|NULL
argument_list|,
name|f1
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

