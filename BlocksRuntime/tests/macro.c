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
comment|// CONFIG open rdar://6718399
end_comment

begin_include
include|#
directive|include
file|<Block.h>
end_include

begin_function
name|void
name|foo
parameter_list|()
block|{
name|void
function_decl|(
modifier|^
name|bbb
function_decl|)
parameter_list|(
name|void
parameter_list|)
init|=
name|Block_copy
argument_list|(
lambda|^
block|{
name|int
name|j
block|,
name|cnt
function_decl|;
block|}
end_function

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

unit|}
end_unit

