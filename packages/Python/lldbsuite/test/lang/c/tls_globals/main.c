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
file|<pthread.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_function_decl
name|void
name|shared_check
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// On some OS's (darwin) you must actually access a thread local variable
end_comment

begin_comment
comment|// before you can read it
end_comment

begin_function_decl
name|int
name|touch_shared
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// Create some TLS storage within the static executable.
end_comment

begin_decl_stmt
name|__thread
name|int
name|var_static
init|=
literal|44
decl_stmt|;
end_decl_stmt

begin_function
name|void
modifier|*
name|fn_static
parameter_list|(
name|void
modifier|*
name|param
parameter_list|)
block|{
name|var_static
operator|*=
literal|2
expr_stmt|;
name|shared_check
argument_list|()
expr_stmt|;
name|usleep
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|// thread breakpoint
for|for
control|(
init|;
condition|;
control|)
name|usleep
argument_list|(
literal|1
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
specifier|const
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|pthread_t
name|handle
decl_stmt|;
name|pthread_create
argument_list|(
operator|&
name|handle
argument_list|,
name|NULL
argument_list|,
operator|&
name|fn_static
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|touch_shared
argument_list|()
expr_stmt|;
for|for
control|(
init|;
name|var_static
condition|;
control|)
block|{
name|usleep
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|// main breakpoint
block|}
return|return
literal|0
return|;
block|}
end_function

end_unit

