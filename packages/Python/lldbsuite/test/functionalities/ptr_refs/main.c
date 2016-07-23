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
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_struct
struct|struct
name|referent
block|{
specifier|const
name|char
modifier|*
name|p
decl_stmt|;
block|}
struct|;
end_struct

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
specifier|const
name|char
modifier|*
name|my_ptr
init|=
name|strdup
argument_list|(
literal|"hello"
argument_list|)
decl_stmt|;
name|struct
name|referent
modifier|*
name|r
init|=
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|referent
argument_list|)
argument_list|)
decl_stmt|;
name|r
operator|->
name|p
operator|=
name|my_ptr
expr_stmt|;
name|printf
argument_list|(
literal|"%p\n"
argument_list|,
name|r
argument_list|)
expr_stmt|;
comment|// break here
return|return
literal|0
return|;
block|}
end_function

end_unit

