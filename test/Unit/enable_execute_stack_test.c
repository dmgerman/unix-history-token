begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- enable_execute_stack_test.c - Test __enable_execute_stack ----------===//
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
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<sys/mman.h>
end_include

begin_function_decl
specifier|extern
name|void
name|__clear_cache
parameter_list|(
name|void
modifier|*
name|start
parameter_list|,
name|void
modifier|*
name|end
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|__enable_execute_stack
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|pfunc
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_function
name|int
name|func1
parameter_list|()
block|{
return|return
literal|1
return|;
block|}
end_function

begin_function
name|int
name|func2
parameter_list|()
block|{
return|return
literal|2
return|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|()
block|{
name|unsigned
name|char
name|execution_buffer
index|[
literal|128
index|]
decl_stmt|;
comment|// mark stack page containing execution_buffer to be executable
name|__enable_execute_stack
argument_list|(
name|execution_buffer
argument_list|)
expr_stmt|;
comment|// verify you can copy and execute a function
name|memcpy
argument_list|(
name|execution_buffer
argument_list|,
operator|(
name|void
operator|*
operator|)
operator|(
name|uintptr_t
operator|)
operator|&
name|func1
argument_list|,
literal|128
argument_list|)
expr_stmt|;
name|__clear_cache
argument_list|(
name|execution_buffer
argument_list|,
operator|&
name|execution_buffer
index|[
literal|128
index|]
argument_list|)
expr_stmt|;
name|pfunc
name|f1
init|=
operator|(
name|pfunc
operator|)
operator|(
name|uintptr_t
operator|)
name|execution_buffer
decl_stmt|;
if|if
condition|(
call|(
modifier|*
name|f1
call|)
argument_list|()
operator|!=
literal|1
condition|)
return|return
literal|1
return|;
comment|// verify you can overwrite a function with another
name|memcpy
argument_list|(
name|execution_buffer
argument_list|,
operator|(
name|void
operator|*
operator|)
operator|(
name|uintptr_t
operator|)
operator|&
name|func2
argument_list|,
literal|128
argument_list|)
expr_stmt|;
name|__clear_cache
argument_list|(
name|execution_buffer
argument_list|,
operator|&
name|execution_buffer
index|[
literal|128
index|]
argument_list|)
expr_stmt|;
name|pfunc
name|f2
init|=
operator|(
name|pfunc
operator|)
operator|(
name|uintptr_t
operator|)
name|execution_buffer
decl_stmt|;
if|if
condition|(
call|(
modifier|*
name|f2
call|)
argument_list|()
operator|!=
literal|2
condition|)
return|return
literal|1
return|;
return|return
literal|0
return|;
block|}
end_function

end_unit

