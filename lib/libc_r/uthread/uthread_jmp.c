begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2000 Jason Evans<jasone@freebsd.org>.  * All rights reserved.  * Copyright (C) 2000 Daniel M. Eischen<eischen@vigrid.com>.  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice(s), this list of conditions and the following disclaimer as  *    the first lines of this file unmodified other than the possible  *    addition of one or more copyright notices.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice(s), this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER(S) ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT HOLDER(S) BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE  * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/user.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_THREAD_SAFE
end_ifdef

begin_include
include|#
directive|include
file|<machine/reg.h>
end_include

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_include
include|#
directive|include
file|"pthread_private.h"
end_include

begin_comment
comment|/* Prototypes: */
end_comment

begin_function_decl
specifier|static
specifier|inline
name|int
name|check_stack
parameter_list|(
name|pthread_t
name|thread
parameter_list|,
name|void
modifier|*
name|stackp
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|siglongjmp
parameter_list|(
name|sigjmp_buf
name|env
parameter_list|,
name|int
name|savemask
parameter_list|)
block|{
if|if
condition|(
name|check_stack
argument_list|(
name|_thread_run
argument_list|,
operator|(
name|void
operator|*
operator|)
name|GET_STACK_SJB
argument_list|(
name|env
argument_list|)
argument_list|)
condition|)
name|PANIC
argument_list|(
literal|"siglongjmp()ing between thread contexts is undefined by "
literal|"POSIX 1003.1"
argument_list|)
expr_stmt|;
comment|/* 	 * The stack pointer is somewhere within the threads stack. 	 * Jump to the users context. 	 */
name|__siglongjmp
argument_list|(
name|env
argument_list|,
name|savemask
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|longjmp
parameter_list|(
name|jmp_buf
name|env
parameter_list|,
name|int
name|val
parameter_list|)
block|{
if|if
condition|(
name|check_stack
argument_list|(
name|_thread_run
argument_list|,
operator|(
name|void
operator|*
operator|)
name|GET_STACK_JB
argument_list|(
name|env
argument_list|)
argument_list|)
condition|)
name|PANIC
argument_list|(
literal|"longjmp()ing between thread contexts is undefined by "
literal|"POSIX 1003.1"
argument_list|)
expr_stmt|;
comment|/* 	 * The stack pointer is somewhere within the threads stack. 	 * Jump to the users context. 	 */
name|__longjmp
argument_list|(
name|env
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|_longjmp
parameter_list|(
name|jmp_buf
name|env
parameter_list|,
name|int
name|val
parameter_list|)
block|{
if|if
condition|(
name|check_stack
argument_list|(
name|_thread_run
argument_list|,
operator|(
name|void
operator|*
operator|)
name|GET_STACK_JB
argument_list|(
name|env
argument_list|)
argument_list|)
condition|)
name|PANIC
argument_list|(
literal|"_longjmp()ing between thread contexts is undefined by "
literal|"POSIX 1003.1"
argument_list|)
expr_stmt|;
comment|/* 	 * The stack pointer is somewhere within the threads stack. 	 * Jump to the users context. 	 */
name|___longjmp
argument_list|(
name|env
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Returns 0 if stack check is OK, non-zero otherwise. */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|check_stack
parameter_list|(
name|pthread_t
name|thread
parameter_list|,
name|void
modifier|*
name|stackp
parameter_list|)
block|{
name|void
modifier|*
name|stack_begin
decl_stmt|,
modifier|*
name|stack_end
decl_stmt|;
comment|/* Get the bounds of the current threads stack. */
name|PTHREAD_ASSERT
argument_list|(
name|thread
operator|->
name|stack
operator|!=
name|NULL
argument_list|,
literal|"Thread stack pointer is null"
argument_list|)
expr_stmt|;
name|stack_begin
operator|=
name|thread
operator|->
name|stack
expr_stmt|;
name|stack_end
operator|=
name|stack_begin
operator|+
name|thread
operator|->
name|attr
operator|.
name|stacksize_attr
expr_stmt|;
comment|/* 	 * Make sure we aren't jumping to a different stack.  Make sure 	 * jmp_stackp is between stack_begin and stack end, to correctly detect 	 * this condition regardless of whether the stack grows up or down. 	 */
if|if
condition|(
operator|(
operator|(
name|stackp
operator|<
name|stack_begin
operator|)
operator|&&
operator|(
name|stackp
operator|<
name|stack_end
operator|)
operator|)
operator|||
operator|(
operator|(
name|stackp
operator|>
name|stack_begin
operator|)
operator|&&
operator|(
name|stackp
operator|>
name|stack_end
operator|)
operator|)
condition|)
return|return
operator|(
literal|1
operator|)
return|;
else|else
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

