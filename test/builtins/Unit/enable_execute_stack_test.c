begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: native-run
end_comment

begin_comment
comment|// RUN: %clang_builtins %s %librt -o %t&& %run %t
end_comment

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
comment|// This file is dual licensed under the MIT and the University of Illinois Open
end_comment

begin_comment
comment|// Source Licenses. See LICENSE.TXT for details.
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

begin_comment
comment|// Make these static to avoid ILT jumps for incremental linking on Windows.
end_comment

begin_function
specifier|static
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
specifier|static
name|int
name|func2
parameter_list|()
block|{
return|return
literal|2
return|;
block|}
end_function

begin_decl_stmt
name|void
modifier|*
name|__attribute__
argument_list|(
operator|(
name|noinline
operator|)
argument_list|)
name|memcpy_f
argument_list|(
name|void
operator|*
name|dst
argument_list|,
specifier|const
name|void
operator|*
name|src
argument_list|,
name|size_t
name|n
argument_list|)
block|{
comment|// ARM and MIPS nartually align functions, but use the LSB for ISA selection
comment|// (THUMB, MIPS16/uMIPS respectively).  Ensure that the ISA bit is ignored in
comment|// the memcpy
if|#
directive|if
name|defined
argument_list|(
name|__arm__
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips__
argument_list|)
return|return
operator|(
name|void
operator|*
operator|)
operator|(
operator|(
name|uintptr_t
operator|)
name|memcpy
argument_list|(
name|dst
argument_list|,
operator|(
name|void
operator|*
operator|)
operator|(
operator|(
name|uintptr_t
operator|)
name|src
operator|&
operator|~
literal|1
operator|)
argument_list|,
name|n
argument_list|)
operator||
operator|(
operator|(
name|uintptr_t
operator|)
name|src
operator|&
literal|1
operator|)
operator|)
return|;
else|#
directive|else
return|return
name|memcpy
argument_list|(
name|dst
argument_list|,
operator|(
name|void
operator|*
operator|)
operator|(
operator|(
name|uintptr_t
operator|)
name|src
operator|)
argument_list|,
name|n
argument_list|)
return|;
endif|#
directive|endif
block|}
end_decl_stmt

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
name|pfunc
name|f1
init|=
operator|(
name|pfunc
operator|)
name|memcpy_f
argument_list|(
name|execution_buffer
argument_list|,
name|func1
argument_list|,
literal|128
argument_list|)
decl_stmt|;
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
name|printf
argument_list|(
literal|"f1: %p\n"
argument_list|,
name|f1
argument_list|)
expr_stmt|;
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
name|pfunc
name|f2
init|=
operator|(
name|pfunc
operator|)
name|memcpy_f
argument_list|(
name|execution_buffer
argument_list|,
name|func2
argument_list|,
literal|128
argument_list|)
decl_stmt|;
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

