begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- a.c -----------------------------------------------------*- C++ -*-===//
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
file|<unistd.h>
end_include

begin_decl_stmt
name|__thread
name|int
name|var_shared
init|=
literal|33
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|touch_shared
parameter_list|()
block|{
return|return
name|var_shared
return|;
block|}
end_function

begin_function
name|void
name|shared_check
parameter_list|()
block|{
name|var_shared
operator|*=
literal|2
expr_stmt|;
name|usleep
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|// shared thread breakpoint
block|}
end_function

end_unit

