begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_builtins %s %librt -fnested-functions -o %t&& %run %t
end_comment

begin_comment
comment|/* ===-- trampoline_setup_test.c - Test __trampoline_setup -----------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===----------------------------------------------------------------------===  */
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

begin_comment
comment|/*  * Tests nested functions  * The ppc compiler generates a call to __trampoline_setup  * The i386 and x86_64 compilers generate a call to ___enable_execute_stack  */
end_comment

begin_comment
comment|/*  * Note that, nested functions are not ISO C and are not supported in Clang.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__clang__
argument_list|)
end_if

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|nested_func_t
function_decl|)
parameter_list|(
name|int
name|x
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
name|nested_func_t
name|proc
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|main
parameter_list|()
block|{
comment|/* Some locals */
name|int
name|c
init|=
literal|10
decl_stmt|;
name|int
name|d
init|=
literal|7
decl_stmt|;
comment|/* Define a nested function: */
name|int
name|bar
parameter_list|(
name|int
name|x
parameter_list|)
block|{
return|return
name|x
operator|*
literal|5
operator|+
name|c
operator|*
name|d
return|;
block|}
empty_stmt|;
comment|/* Assign global to point to nested function      * (really points to trampoline). */
name|proc
operator|=
name|bar
expr_stmt|;
comment|/* Invoke nested function: */
name|c
operator|=
literal|4
expr_stmt|;
if|if
condition|(
call|(
modifier|*
name|proc
call|)
argument_list|(
literal|3
argument_list|)
operator|!=
literal|43
condition|)
return|return
literal|1
return|;
name|d
operator|=
literal|5
expr_stmt|;
if|if
condition|(
call|(
modifier|*
name|proc
call|)
argument_list|(
literal|4
argument_list|)
operator|!=
literal|40
condition|)
return|return
literal|1
return|;
comment|/* Success. */
return|return
literal|0
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_function
name|int
name|main
parameter_list|()
block|{
name|printf
argument_list|(
literal|"skipped\n"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

