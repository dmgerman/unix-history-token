begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// FIXME: XFAIL as currently it cannot be built by lit properly.
end_comment

begin_comment
comment|// XFAIL: *
end_comment

begin_comment
comment|// RUN: %clangxx_builtins %s %librt -o %t&& %run %t
end_comment

begin_comment
comment|/* ===-- gcc_personality_test.c - Tests __gcc_personality_v0 -------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===----------------------------------------------------------------------===  */
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function_decl
specifier|extern
name|void
name|foo_clean
parameter_list|(
name|void
modifier|*
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bar_clean
parameter_list|(
name|void
modifier|*
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|register_foo_local
parameter_list|(
name|int
modifier|*
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|register_bar_local
parameter_list|(
name|int
modifier|*
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|done_foo
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|done_bar
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * foo() is called by main() in gcc_personality_test_helper.cxx.  * done_bar() is implemented in C++ and will throw an exception.  * main() will catch the exception and verify that the cleanup  * routines for foo() and bar() were called by the personality  * function.  */
end_comment

begin_function
name|void
name|bar
parameter_list|()
block|{
name|int
name|x
name|__attribute__
argument_list|(
operator|(
name|cleanup
argument_list|(
name|bar_clean
argument_list|)
operator|)
argument_list|)
init|=
literal|0
decl_stmt|;
name|register_bar_local
argument_list|(
operator|&
name|x
argument_list|)
expr_stmt|;
name|done_bar
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|foo
parameter_list|()
block|{
name|int
name|x
name|__attribute__
argument_list|(
operator|(
name|cleanup
argument_list|(
name|foo_clean
argument_list|)
operator|)
argument_list|)
init|=
literal|0
decl_stmt|;
name|register_foo_local
argument_list|(
operator|&
name|x
argument_list|)
expr_stmt|;
name|bar
argument_list|()
expr_stmt|;
name|done_foo
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

