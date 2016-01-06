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

begin_decl_stmt
name|char
modifier|*
name|pointer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|another_pointer
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|f1
parameter_list|()
block|{
name|pointer
operator|=
name|malloc
argument_list|(
literal|10
argument_list|)
expr_stmt|;
comment|// malloc line
name|another_pointer
operator|=
name|malloc
argument_list|(
literal|20
argument_list|)
expr_stmt|;
comment|// malloc2 line
block|}
end_function

begin_function
name|void
name|f2
parameter_list|()
block|{
name|free
argument_list|(
name|pointer
argument_list|)
expr_stmt|;
comment|// free line
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
name|f1
argument_list|()
expr_stmt|;
name|f2
argument_list|()
expr_stmt|;
name|printf
argument_list|(
literal|"Hello world!\n"
argument_list|)
expr_stmt|;
comment|// break line
name|pointer
index|[
literal|0
index|]
operator|=
literal|'A'
expr_stmt|;
comment|// BOOM line
return|return
literal|0
return|;
block|}
end_function

end_unit

