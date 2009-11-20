begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009 Advanced Computing Technologies LLC  * Written by: John H. Baldwin<jhb@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|"namespace.h"
end_include

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_include
include|#
directive|include
file|"un-namespace.h"
end_include

begin_include
include|#
directive|include
file|"libc_private.h"
end_include

begin_comment
comment|/*  * This implements pthread_once() for the single-threaded case.  It is  * non-static so that it can be used by _pthread_stubs.c.  */
end_comment

begin_function
name|int
name|_libc_once
parameter_list|(
name|pthread_once_t
modifier|*
name|once_control
parameter_list|,
name|void
function_decl|(
modifier|*
name|init_routine
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
block|{
if|if
condition|(
name|once_control
operator|->
name|state
operator|==
name|PTHREAD_DONE_INIT
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|init_routine
argument_list|()
expr_stmt|;
name|once_control
operator|->
name|state
operator|=
name|PTHREAD_DONE_INIT
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * This is the internal interface provided to libc.  It will use  * pthread_once() from the threading library in a multi-threaded  * process and _libc_once() for a single-threaded library.  Because  * _libc_once() uses the same ABI for the values in the pthread_once_t  * structure as the threading library, it is safe for a process to  * switch from _libc_once() to pthread_once() when threading is  * enabled.  */
end_comment

begin_function
name|int
name|_once
parameter_list|(
name|pthread_once_t
modifier|*
name|once_control
parameter_list|,
name|void
function_decl|(
modifier|*
name|init_routine
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
block|{
if|if
condition|(
name|__isthreaded
condition|)
return|return
operator|(
name|_pthread_once
argument_list|(
name|once_control
argument_list|,
name|init_routine
argument_list|)
operator|)
return|;
return|return
operator|(
name|_libc_once
argument_list|(
name|once_control
argument_list|,
name|init_routine
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

