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
comment|//
end_comment

begin_comment
comment|//  constassign.c
end_comment

begin_comment
comment|//  bocktest
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Created by Blaine Garst on 3/21/08.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// shouldn't be able to assign to a const pointer
end_comment

begin_comment
comment|// CONFIG error: assignment of read-only
end_comment

begin_empty
empty|#import<stdio.h>
end_empty

begin_function
name|void
name|foo
parameter_list|(
name|void
parameter_list|)
block|{
name|printf
argument_list|(
literal|"I'm in foo\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|bar
parameter_list|(
name|void
parameter_list|)
block|{
name|printf
argument_list|(
literal|"I'm in bar\n"
argument_list|)
expr_stmt|;
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
name|void
argument_list|(
operator|*
specifier|const
name|fptr
argument_list|)
argument_list|(
name|void
argument_list|)
operator|=
name|foo
expr_stmt|;
name|void
argument_list|(
operator|^
specifier|const
name|blockA
argument_list|)
argument_list|(
name|void
argument_list|)
operator|=
lambda|^
block|{
name|printf
argument_list|(
literal|"hello\n"
argument_list|)
expr_stmt|;
block|}
expr_stmt|;
name|blockA
operator|=
lambda|^
block|{
name|printf
argument_list|(
literal|"world\n"
argument_list|)
expr_stmt|;
block|}
expr_stmt|;
name|fptr
operator|=
name|bar
expr_stmt|;
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
return|return
literal|0
return|;
block|}
end_function

end_unit

